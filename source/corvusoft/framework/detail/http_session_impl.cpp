/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <regex>
#include <ostream>
#include <utility>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <functional>

//Project Includes
#include "corvusoft/framework/uri.h"
#include "corvusoft/framework/map.h"
#include "corvusoft/framework/regex.h"
#include "corvusoft/framework/string.h"
#include "corvusoft/framework/http_request.h"
#include "corvusoft/framework/http_response.h"
#include "corvusoft/framework/detail/http_context_impl.h"
#include "corvusoft/framework/detail/http_session_impl.h"

//External Includes

//System Namespaces
using std::map;
using std::queue;
using std::regex;
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
using std::regex_match;
using std::stringstream;
using std::setprecision;
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

        map< string, string > HttpSessionImpl::parse_cookie( const string& definition )
        {
            map< string, string > result;

            auto items = String::split( definition, ';' );

            for ( auto item : items )
            {
                auto name_value = String::split( item, '=' );

                auto name = String::lowercase( String::trim( name_value[ 0 ] ) );
                auto value = name_value.size( ) == 2 ? String::trim( name_value[ 1 ] ) : String::empty;

                if ( name == "path" )
                {
                    result[ name ] = value;
                }
                else if ( name == "domain" )
                {
                    bool has_pattern = ( value.front( ) == '.' );

                    value = Regex::escape( value );

                    if ( has_pattern )
                    {
                        value = ".*" + value;
                    }

                    result[ name ] = value;
                }
            }

            return result;
        }

        shared_ptr< HttpContextImpl > HttpSessionImpl::setup( const HttpRequest& request, io_service& service )
        {
            //break this up into methods!
            auto context = make_shared< HttpContextImpl >( );
            context->request = request;
            context->resolver = make_shared< tcp::resolver >( service );
            context->socket = make_shared< tcp::socket >( service );
            context->request_buffer = make_shared< asio::streambuf >( );
            context->response_buffer = make_shared< asio::streambuf >( );

            ostream request_stream( context->request_buffer.get( ) );
            request_stream << request.method << " " << request.path << " " << "HTTP/" << setprecision( 2 ) << request.version << "\r\n";

            string cookie_header = String::empty;

            for ( auto cookie : m_cookies )
            {
                auto cookie_config = parse_cookie( cookie.second );

                if ( regex_match( m_uri.get_authority( ), regex( cookie_config[ "domain" ] ) ) )
                {
                    if ( cookie_config[ "path" ] == "/" or cookie_config[ "path" ] == request.path )
                    {
                        cookie_header += cookie.first + "=" + cookie.second.substr( 0, cookie.second.find( ";" ) ) + ";";
                    }
                }
            }

            if ( not cookie_header.empty( ) )
            {
                context->request.headers.insert( make_pair( "Cookie", cookie_header.substr( 0, cookie_header.length( ) -1 ) ) );
            }

            context->request.headers.insert( m_headers.begin( ), m_headers.end( ) );

            for ( auto header : context->request.headers )
            {
                request_stream << header.first << ": " << header.second << "\r\n";
            }

            //use content-length or transfer-encoding
            request_stream << "Connection: close\r\n";

            request_stream << "\r\n";
            request_stream.write( reinterpret_cast< const char* >( request.body.data( ) ), request.body.size( ) );

            tcp::resolver::query query( m_uri.get_authority( ), m_uri.get_scheme( ) );
            context->resolver->async_resolve( query, bind( &HttpSessionImpl::handle_resolve, this, _1, _2, context ) );

            return context;
        }

        void HttpSessionImpl::handle_read_body( const error_code& error, shared_ptr< HttpContextImpl >& context )
        {
            if ( not error )
            {
                asio::async_read( *context->socket,
                                  *context->response_buffer,
                                  asio::transfer_at_least( 1 ),
                                  bind( &HttpSessionImpl::handle_read_body, this, _1, context ) );
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

            asio::async_read_until( *context->socket,
                                    *context->response_buffer,
                                    "\r\n\r\n",
                                    bind( &HttpSessionImpl::handle_read_headers, this, _1, context ) );
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
                auto delimiter = header.find( ":" );

                if ( delimiter not_eq string::npos )
                {
                    auto name = header.substr( 0, delimiter );
                    auto value = header.substr( delimiter + 1 );

                    if ( value.front( ) == ' ' )
                    {
                        value.erase( value.begin( ) );
                    }

                    context->response.headers.insert( make_pair( name, value ) );

                    if ( String::lowercase( name ) == "set-cookie" )
                    {
                        delimiter = value.find( "=" );
                        name = value.substr( 0, delimiter );

                        m_cookies.insert( make_pair( name, value.substr( delimiter + 1 ) ) );
                    }
                }
                else
                {
                    context->response.headers.insert( make_pair( header, String::empty ) );
                }
            }

            asio::async_read( *context->socket,
                              *context->response_buffer,
                              asio::transfer_at_least( 1 ),
                              bind( &HttpSessionImpl::handle_read_body, this, _1, context ) );
        }

        void HttpSessionImpl::handle_write_request( const error_code& error, shared_ptr< HttpContextImpl >& context )
        {
            if ( error )
            {
                throw runtime_error( error.message( ) );
            }

            asio::async_read_until( *context->socket,
                                    *context->response_buffer,
                                    "\r\n",
                                    bind( &HttpSessionImpl::handle_read_status, this, _1, context ) );
        }

        void HttpSessionImpl::handle_connect( const error_code& error, tcp::resolver::iterator endpoint, shared_ptr< HttpContextImpl >& context )
        {
            if ( not error )
            {
                asio::async_write( *context->socket,
                                   *context->request_buffer,
                                   bind( &HttpSessionImpl::handle_write_request, this, _1, context ) );
            }
            else if ( endpoint not_eq tcp::resolver::iterator( ) )
            {
                context->socket->close( );
                context->socket->async_connect( *endpoint, bind( &HttpSessionImpl::handle_connect, this, _1, ++endpoint, context ) );
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

            context->socket->async_connect( *endpoint, bind( &HttpSessionImpl::handle_connect, this, _1, ++endpoint, context ) );
        }
    }
}
