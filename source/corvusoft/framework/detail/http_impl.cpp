/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <map>
#include <string>
#include <utility>
#include <iostream>
#include <stdexcept>

//Project Includes
#include "corvusoft/framework/map.h"
#include "corvusoft/framework/string.h"
#include "corvusoft/framework/detail/http_impl.h"

//External Includes
#include <asio.hpp>

//System Namespaces
using std::map;
using std::stod;
using std::vector;
using std::string;
using std::istream;
using std::ostream;
using std::getline;
using std::to_string;
using std::runtime_error;
using std::istreambuf_iterator;

//Project Namespaces

//External Namespaces
using asio::ip::tcp;
using asio::error_code;
using asio::system_error;

namespace framework
{
    namespace detail
    {
        Http::Response HttpImpl::perform( const string& method, const Http::Request& request )
        {
            Http::Request action = request;
            action.method = method;

            return perform( action );
        }

        Http::Response HttpImpl::perform( const Http::Request& request )
        {
            asio::io_service io_service;

            tcp::resolver resolver( io_service );
            tcp::resolver::query query( request.host, ::to_string( request.port ) );
            tcp::resolver::iterator endpoint_iterator = resolver.resolve( query );
            tcp::resolver::iterator end;

            tcp::socket socket( io_service );
            error_code error = asio::error::host_not_found;

            while ( error and endpoint_iterator not_eq end )
            {
                socket.close( );
                socket.connect( *endpoint_iterator++, error );
            }

            if ( error )
            {
                throw system_error(error);
            }

            asio::streambuf request_buffer;
            ostream request_stream( &request_buffer );

            request_stream << request.method << " " << request.path << " HTTP/1.1\r\n";
            request_stream << "Host: " << request.host << "\r\n";
            request_stream << "Connection: close\r\n";

            for ( auto header : request.headers )
            {
                request_stream << header.first << ": " << header.second << "\r\n";
            }

            request_stream << "\r\n";

            if ( not request.body.empty( ) )
            {
                request_stream << request.body.data( );
            }

            asio::write( socket, request_buffer );

            Http::Response response;
            asio::streambuf response_buffer;
            asio::read_until( socket, response_buffer, "\r\n" );
            istream response_stream( &response_buffer );

            string status;
            getline( response_stream, status );
            auto status_line = String::split( status, ' ' );

            string http_version = status_line[ 0 ].substr( status_line[ 0 ].find_first_of( '/' ) + 1 );
            response.version = stod( http_version );

            response.status_code = stod( status_line[ 1 ] );
            response.status_message = status_line[ 2 ].substr( 0, status_line[ 2 ].length( ) - 1 );

            asio::read_until( socket, response_buffer, "\r\n\r\n", error );

            string header;
            while ( getline( response_stream, header ) and header not_eq "\r" )
            {
                auto name_value = String::split( header, ':' );
                auto name = String::trim( name_value[ 0 ] );
                auto value = String::trim( name_value[ 1 ].substr( 0, name_value[ 1 ].find_last_of( '\r' ) ) );
                response.headers.insert( make_pair( name, value ) );
            }

            while ( not error )
            {
                auto body = Bytes( istreambuf_iterator< char >( &response_buffer ), istreambuf_iterator< char >( ) );
                response_buffer.consume( body.size( ) );
                response.body.insert( response.body.end( ), body.begin( ), body.end( ) );

                asio::read( socket, response_buffer, asio::transfer_all( ), error );
            }

            if ( error not_eq asio::error::eof )
            {
                throw runtime_error( "failed to read response." );
            }
            
            return response;
        }
    }
}
