/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <ostream>
#include <utility>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <functional>

//Project Includes
#include "corvusoft/framework/uri.h"
#include "corvusoft/framework/map.h"
#include "corvusoft/framework/string.h"
#include "corvusoft/framework/http_request.h"
#include "corvusoft/framework/http_response.h"
#include "corvusoft/framework/detail/http_context_impl.h"
#include "corvusoft/framework/detail/http_session_impl.h"

//External Includes

//System Namespaces
using std::queue;
using std::string;
using std::vector;
using std::istream;
using std::ostream;
using std::getline;
using std::multimap;
using std::function;
using std::make_pair;
using std::shared_ptr;
using std::make_shared;
using std::stringstream;
using std::runtime_error;
using std::placeholders::_1;
using std::placeholders::_2;

//Project Namespaces

//External Namespaces
using asio::ip::tcp;
using asio::streambuf;
using asio::error_code;
using asio::io_service;
using asio::system_error;

namespace framework
{
    namespace detail
    {
        HttpSessionImpl::HttpSessionImpl( const Uri& value ) : m_uri( value ),
            m_cookies( ),
            m_headers( )
        {
            return;
        }
        
        HttpSessionImpl::HttpSessionImpl( const HttpSessionImpl& original ) : m_uri( original.m_uri ),
            m_cookies( original.m_cookies ),
            m_headers( original.m_headers )
        {
            return;
        }
        
        HttpSessionImpl::~HttpSessionImpl( void )
        {
            return;
        }

        HttpResponse HttpSessionImpl::perform( const string& method, const HttpRequest& value )
        {
            HttpRequest request = value;
            request.method = method;

            io_service service;

            auto context = setup( request, service );

            service.run( );

            return context->response;
        }

        void HttpSessionImpl::batch( queue< HttpRequest >& requests,
                                     const function< bool ( const HttpRequest&, const HttpResponse& ) >& success_handler,
                                     const function< bool ( const HttpRequest&, const HttpResponse& ) >& error_handler )
        {
            while ( not requests.empty( ) )
            {
                io_service service;
                auto request = requests.front( );
                auto context = setup( request, service );
                service.run( );

                bool proceed = false;

                if ( context->response.status_code < 400 )
                {
                    proceed = success_handler( context->request, context->response );
                }
                else
                {
                    proceed = error_handler( context->request, context->response );
                }

                if ( proceed == false )
                {
                    break;
                }

                requests.pop( );
            }
        }

        void HttpSessionImpl::batch( const vector< HttpRequest >& requests,
                                     const function< void ( const HttpRequest&, const HttpResponse& ) >& success_handler,
                                     const function< void ( const HttpRequest&, const HttpResponse& ) >& error_handler )
        {
            vector< shared_ptr< HttpContextImpl > > contexts;

            io_service service;

            for ( auto request : requests )
            {
                auto context = setup( request, service );
                context->has_callbacks = true;
                context->error_handler = error_handler;
                context->success_handler = success_handler;

                contexts.push_back( context );
            }

            service.run( );
        }

        Uri HttpSessionImpl::get_uri( void ) const
        {
            return m_uri;
        }

        string HttpSessionImpl::get_cookie( const string& name ) const
        {
            string value = String::empty;

            auto iterator = m_cookies.find( name );

            if ( iterator not_eq m_cookies.end( ) )
            {
                value = iterator->second;
            }

            return value;
        }

        multimap< string, string > HttpSessionImpl::get_cookies( void ) const
        {
            return m_cookies;
        }

        multimap< string, string > HttpSessionImpl::get_cookies( const string& name ) const
        {
            return multimap< string, string>( m_cookies.lower_bound( name ), m_cookies.upper_bound( name ) );
        }

        string HttpSessionImpl::get_header( const string& name )
        {
            string value = String::empty;

            const auto iterator = Map::find_ignoring_case( name, m_headers );

            if ( iterator not_eq m_headers.end( ) )
            {
                value = iterator->second;
            }

            return value;
        }

        multimap< string, string > HttpSessionImpl::get_headers( void ) const
        {
            return m_headers;
        }

        multimap< string, string > HttpSessionImpl::get_headers( const string& name ) const
        {
            multimap< string, string > headers;

            auto key = String::lowercase( name );

            for ( auto header : m_headers )
            {
                if ( String::lowercase( header.first ) == key )
                {
                    headers.insert( header );
                }
            }

            return headers;
        }

        void HttpSessionImpl::set_cookie( const string& name, const string& value )
        {
            m_cookies.insert( make_pair( name, value ) );
        }

        void HttpSessionImpl::set_cookies( const multimap< string, string >& values )
        {
            m_cookies = values;
        }
        
        void HttpSessionImpl::set_header( const string& name, const string& value )
        {
            m_headers.insert( make_pair( name, value ) );
        }
        
        void HttpSessionImpl::set_headers( const multimap< string, string >& values )
        {
            m_headers = values;
        }

        HttpSessionImpl& HttpSessionImpl::operator =( const HttpSessionImpl& rhs )
        {
            m_uri = rhs.m_uri;

            m_cookies = rhs.m_cookies;

            m_headers = rhs.m_headers;

            return *this;
        }

        shared_ptr< HttpContextImpl > HttpSessionImpl::setup( const HttpRequest& request, io_service& service )
        {
            auto context = make_shared< HttpContextImpl >( );
            context->resolver = make_shared< tcp::resolver >( service );
            context->socket = make_shared< tcp::socket >( service );
            context->request_buffer = make_shared< asio::streambuf >( );
            context->response_buffer = make_shared< asio::streambuf >( );

            //add session.headers and session.cookies

            //if ( response_ == nullptr ) fprintf( stderr, "socket null\n\n" );
            // Form the request. We specify the "Connection: close" header so that the
            // server will close the socket after transmitting the response. This will
            // allow us to treat all data up until the EOF as the content.
            ostream request_stream( context->request_buffer.get( ) );
            request_stream << "GET " << "/" << " HTTP/1.1\r\n";
            request_stream << "Host: " << "www.corvusoft.co.uk" << "\r\n";
            request_stream << "Accept: */*\r\n";
            request_stream << "Connection: close\r\n\r\n";

            // Start an asynchronous resolve to translate the server and service names
            // into a list of endpoints.
            tcp::resolver::query query( "www.corvusoft.co.uk", "http" );

            context->resolver->async_resolve( query, bind( handle_resolve, _1, _2, context ) );

            return context;
        }

        void HttpSessionImpl::handle_read_body( const error_code& error, shared_ptr< HttpContextImpl >& context )
        {
            if ( not error )
            {
                asio::async_read( *context->socket, *context->response_buffer, asio::transfer_at_least( 1 ), bind( handle_read_body, _1, context ) );
            }
            else if ( error not_eq asio::error::eof )
            {
                throw runtime_error( error.message( ) );
            }

            auto data = asio::buffer_cast< const unsigned char* >( context->response_buffer->data( ) );
            context->response.body = Bytes( data, data + context->response_buffer->size( ) );

            if ( context->has_callbacks )
            {
                context.reset( );
            }
        }

        void HttpSessionImpl::handle_read_status( const error_code& error, shared_ptr< HttpContextImpl >& context )
        {
            if ( error )
            {
                throw runtime_error( error.message( ) );
            }

            istream response_stream( context->response_buffer.get( ) );

            string value = String::empty;
            response_stream >> value;

            auto delimiter = value.find( "/" );
            if ( delimiter == value.length( ) )
            {
                throw runtime_error( "invalid response line: " + value );
            }

            context->response.protocol = value.substr( 0, delimiter );
            context->response.version = stod( value.substr( delimiter + 1 ) );

            response_stream >> context->response.status_code;

            getline( response_stream, context->response.status_message );

            asio::async_read_until( *context->socket, *context->response_buffer, "\r\n\r\n", bind( handle_read_headers, _1, context ) );
        }

        void HttpSessionImpl::handle_read_headers( const error_code& error, shared_ptr< HttpContextImpl >& context )
        {
            if ( error )
            {
                throw runtime_error( error.message( ) );
            }

            string header = String::empty;
            istream response_stream( context->response_buffer.get( ) );

            while ( getline( response_stream, header ) and header not_eq "\r" )
            {
                const auto values = String::split( header, ':' );

                if ( not values.empty( ) )
                {
                    const auto& name = values[ 0 ];
                    auto value = values.size( ) == 2 ? values[ 1 ] : String::empty;

                    if ( value[ 0 ] == ' ' )
                    {
                        value.erase( value.begin( ) );
                    }

                    context->request.headers.insert( make_pair( name, value ) );
                }
            }

            asio::async_read( *context->socket, *context->response_buffer, asio::transfer_at_least( 1 ), bind( handle_read_body, _1, context ) );
        }

        void HttpSessionImpl::handle_write_request( const error_code& error, shared_ptr< HttpContextImpl >& context )
        {
            if ( error )
            {
                throw runtime_error( error.message( ) );
            }

            asio::async_read_until( *context->socket, *context->response_buffer, "\r\n", bind( handle_read_status, _1, context ) );
        }

        void HttpSessionImpl::handle_connect( const error_code& error, tcp::resolver::iterator endpoint, shared_ptr< HttpContextImpl >& context )
        {
            if ( not error )
            {
                asio::async_write( *context->socket, *context->request_buffer, bind( handle_write_request, _1, context ) );
            }
            else if ( endpoint not_eq tcp::resolver::iterator( ) )
            {
                context->socket->close( );
                context->socket->async_connect( *endpoint, bind( handle_connect, _1, ++endpoint, context ) );
            }
            else
            {
                throw runtime_error( error.message( ) );
            }
        }

        void HttpSessionImpl::handle_resolve( const error_code& error, tcp::resolver::iterator endpoint, shared_ptr< HttpContextImpl >& context )
        {
            if ( error )
            {
                throw runtime_error( error.message( ) );
            }

            context->socket->async_connect( *endpoint, bind( handle_connect, _1, ++endpoint, context ) );
        }
    }
}
