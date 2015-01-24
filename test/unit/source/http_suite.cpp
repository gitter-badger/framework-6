/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <map>
#include <string>
#include <vector>
#include <cstdint>

//Project Includes
#include <corvusoft/framework/http>

//External Includes
#define CATCH_CONFIG_MAIN
#include <catch.hpp>

//System Namespaces
using std::map;
using std::vector;
using std::string;

//Project Namespaces
using framework::Http;

//External Namespaces

SCENARIO( "request constructor", "[http]" )
{
    GIVEN( "i want to instantiate a HTTP request" )
    {
        WHEN( "i construct the structure" )
        {
            Http::Request request;
            
            THEN( "i should see default request values" )
            {
                REQUIRE( request.host == "" );
                REQUIRE( request.path == "" );
                REQUIRE( request.version == 1.1 );
                REQUIRE( request.method == "GET" );
                REQUIRE( request.body == vector< uint8_t >( ) );
                
                map< string, string > headers;
                REQUIRE( request.headers == headers );
            }
        }
    }
}

SCENARIO( "response constructor", "[http]" )
{
    GIVEN( "i want to instantiate a HTTP response" )
    {
        WHEN( "i construct the structure" )
        {
            Http::Response response;
            
            THEN( "i should see default request values" )
            {
                REQUIRE( response.version == 1.1 );
                REQUIRE( response.status_code == 0 );
                REQUIRE( response.status_message == "" );
                REQUIRE( response.body == vector< uint8_t >( ) );
                
                map< string, string > headers;
                REQUIRE( response.headers == headers );
            }
        }
    }
}
