/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <ostream>
#include <utility>
#include <iostream>
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
                // Write all of the data that has been read so far.
                //std::cout << context->response_buffer.get( ) << std::flush;

                // Continue reading remaining data until EOF.
                asio::async_read( *context->socket,
                                  *context->response_buffer,
                                  asio::transfer_at_least( 1 ),
                                  bind( handle_read_body, _1, context ) );
            }
            else if ( error not_eq asio::error::eof )
            {
                fprintf( stderr, "handle_read_body Error: \n" );
                //std::cout << "Error: " << err << "\n";
            }

            std::stringstream body_stream;
            body_stream << context->response_buffer.get( );
            auto body = body_stream.str( );

            fprintf( stderr, "%s\n", body.data( ) );
//            std::cout << "BODY" << std::endl << std::flush;
//            std::cout << context->response_buffer.get( ) << std::flush;

            if ( context->has_callbacks )
            {
                context.reset( );
            }
        }

        void HttpSessionImpl::handle_read_status( const error_code& error, shared_ptr< HttpContextImpl >& context )
        {
            if ( not error )
            {
                // Check that response is OK.
                istream response_stream( context->response_buffer.get( ) );
                string http_version;
                response_stream >> http_version;

                long status_code;
                response_stream >> status_code;

                context->response.status_code = status_code;

                string status_message;
                getline( response_stream, status_message );

                if ( not response_stream or http_version.substr( 0, 5 ) not_eq "HTTP/" )
                {
                    std::cout << "Invalid response\n";
                    return;
                }
                if ( status_code not_eq 200 )
                {
                    std::cout << "Response returned with status code ";
                    std::cout << status_code << "\n";
                    return;
                }

                // Read the response headers, which are terminated by a blank line.
                asio::async_read_until( *context->socket,
                                        *context->response_buffer,
                                        "\r\n\r\n",
                                        bind( handle_read_headers, _1, context ) );
            }
            else
            {
                fprintf( stderr, "handle_read_status_line Error: \n" );
                //std::cout << "handle_read_status_line Error: " << err << "\n";
            }
        }

        void HttpSessionImpl::handle_read_headers( const error_code& error, shared_ptr< HttpContextImpl >& context )
        {
            if ( not error )
            {
                // Process the response headers.
                istream response_stream( context->response_buffer.get( ) );

                string header;

                while ( getline( response_stream, header ) and header not_eq "\r" )
                {
                    std::cout << header << "\n";
                }

                //std::cout << "\n";

                // Write whatever content we already have to output.
                if ( context->response_buffer->size() > 0 )
                {
                    std::cout << context->response_buffer.get( );
                }

                // Start reading remaining data until EOF.
                asio::async_read( *context->socket,
                                  *context->response_buffer,
                                  asio::transfer_at_least( 1 ),
                                  bind( handle_read_body, _1, context ) );
            }
            else
            {
                fprintf( stderr, "handle_read_headers Error: \n" );
                //std::cout << "handle_read_headers Error: " << err << "\n";
            }
        }

        void HttpSessionImpl::handle_write_request( const error_code& error, shared_ptr< HttpContextImpl >& context )
        {
            if ( not error )
            {
                // Read the response status line. The response streambuf will
                // automatically grow to accommodate the entire line. The growth may be
                // limited by passing a maximum size to the streambuf constructor.
                asio::async_read_until( *context->socket,
                                        *context->response_buffer,
                                        "\r\n",
                                        bind( handle_read_status, _1, context ) );
            }
            else
            {
                fprintf( stderr, "handle_write_request Error: \n" );
                //std::cout << "handle_write_request Error: " << err.message() << "\n";
            }
        }

        void HttpSessionImpl::handle_connect( const error_code& error, tcp::resolver::iterator endpoint_iterator, shared_ptr< HttpContextImpl >& context )
        {
            if ( not error )
            {
                // The connection was successful. Send the request.
                asio::async_write( *context->socket,
                                   *context->request_buffer,
                                   bind( handle_write_request, _1, context ) );
            }
            else if ( endpoint_iterator not_eq tcp::resolver::iterator( ) )
            {
                // The connection failed. Try the next endpoint in the list.
                context->socket->close( );

                tcp::endpoint endpoint = *endpoint_iterator;

                context->socket->async_connect( endpoint, //*endpoint_iterator,
                                               bind( handle_connect, _1, ++endpoint_iterator, context ) );
            }
            else
            {
                fprintf( stderr, "handle_connect Error: \n" );
                //std::cout << "handle_connect Error: " << err.message() << "\n";
            }
        }

        void HttpSessionImpl::handle_resolve( const error_code& error, tcp::resolver::iterator endpoint_iterator, shared_ptr< HttpContextImpl >& context )
        {
            if ( not error )
            {
                // Attempt a connection to the first endpoint in the list. Each endpoint
                // will be tried until we successfully establish a connection.
                tcp::endpoint endpoint = *endpoint_iterator;

                context->socket->async_connect( endpoint, //*endpointer_iterator,
                                                bind( handle_connect, _1, ++endpoint_iterator, context ) );
            }
            else
            {
                fprintf( stderr, "handle_resolve Error: \n" );
                //std::cout << "handle_resolve Error: " << err.message() << "\n";
            }
        }
    }
}
