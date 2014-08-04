/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes

//Project Includes
#include "corvusoft/framework/map.h"
#include "corvusoft/framework/string.h"
#include "corvusoft/framework/detail/http_impl.h"

//External Includes
#include <curl/curl.h>

//System Namespaces
using std::map;
using std::string;
using std::to_string;

//Project Namespaces

//External Namespaces

namespace framework
{
    namespace detail
    {
        Http::Response HttpImpl::get( const Http::Request& request )
        {
            auto rq = request;
            rq.method = "GET";
            
            return perform( request );
        }
        
        Http::Response HttpImpl::put( const Http::Request& request )
        {
            auto rq = request;
            rq.method = "PUT";
            
            return perform( request );
        }
        
        Http::Response HttpImpl::post( const Http::Request& request )
        {
            auto rq = request;
            rq.method = "POST";
            
            return perform( request );
        }
        
        Http::Response HttpImpl::destroy( const Http::Request& request )
        {
            auto rq = request;
            rq.method = "DELETE";
            
            return perform( request );
        }
        
        Http::Response HttpImpl::perform( const Http::Request& request )
        {
            Http::Response response;
            
            curl_global_init( CURL_GLOBAL_ALL );
            
            CURL* curl = curl_easy_init( );
            
            if ( curl )
            {
                curl_easy_setopt( curl, CURLOPT_VERBOSE, 0L );
                
                curl_easy_setopt( curl, CURLOPT_CUSTOMREQUEST, request.method.data( ) );
                
                curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, &write_body_callback );
                
                curl_easy_setopt( curl, CURLOPT_WRITEDATA, &response );
                
                curl_easy_setopt( curl, CURLOPT_HEADERFUNCTION, &write_headers_callback );
                
                curl_easy_setopt( curl, CURLOPT_WRITEHEADER, &response );
                
                curl_easy_setopt( curl, CURLOPT_URL, request.uri.data( ) );
                
                curl_easy_setopt( curl, CURLOPT_POSTFIELDS, &( request.body )[ 0 ] );
                
                curl_easy_setopt( curl, CURLOPT_HTTP_VERSION, request.version );
                
                struct curl_slist* headers = nullptr;
                
                if ( Map::find_key_ignoring_case( "Content-Length", request.headers ) == request.headers.end( ) )
                {
                    string value = "Content-Length: " + ::to_string( request.body.size( ) );
                    
                    headers = curl_slist_append( headers, value.data( ) );
                }
                
                for ( auto header : request.headers )
                {
                    string value = header.first + ": " + header.second;
                    
                    headers = curl_slist_append( headers, value.data( ) );
                }
                
                curl_easy_setopt( curl, CURLOPT_HTTPHEADER, headers );
                
                CURLcode result = curl_easy_perform( curl );
                
                if ( result not_eq CURLE_OK )
                {
                    fprintf( stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror( result ) );
                }
                
                curl_easy_cleanup( curl );
            }
            
            return response;
        }
        
        size_t HttpImpl::write_body_callback( void* data, size_t size, size_t nmemb, void* ptr )
        {
            Http::Response* response = static_cast< Http::Response* >( ptr );
            
            auto length = size * nmemb;
            
            response->body = Bytes( static_cast< Byte* >( data ), static_cast< Byte* >( data ) + length );
            
            return length;
        }
        
        size_t HttpImpl::write_headers_callback( void* data, size_t size, size_t nmemb, void* ptr )
        {
            //first line
            //"HTTP/1.1 200 OK"
            //response.status_code =
            //response.version = request.version;
            //response.status_message
            Http::Response* response = static_cast< Http::Response* >( ptr );
            
            auto length = size * nmemb;
            
            auto response_data = string( static_cast< char* >( data ), length );
            auto end_of_first_line = response_data.find( "\r\n" );
            
            auto header_data = response_data.substr( end_of_first_line );
            
            auto header = String::split( header_data, ':' );
            
            response->headers[ String::trim( header[ 0 ] ) ] = String::trim( header[ 1 ] );
            
            return length;
        }
    }
}
