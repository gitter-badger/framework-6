/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <map>
#include <string>
#include <vector>
#include <cstdint>

//Project Includes
#include <corvusoft/framework/http>
#include <corvusoft/framework/byte>

//External Includes
#include <catch.hpp>

//System Namespaces
using std::string;
using std::multimap;

//Project Namespaces
using framework::Http;
using framework::Bytes;

//External Namespaces

TEST_CASE( "request constructor", "[http]" )
{
    Http::Request request;

    REQUIRE( request.host == "" );
    REQUIRE( request.path == "/" );
    REQUIRE( request.port == 80 );
    REQUIRE( request.version == 1.1 );
    REQUIRE( request.method == "GET" );
    REQUIRE( request.body == Bytes( ) );

    multimap< string, string > headers;
    REQUIRE( request.headers == headers );
}

TEST_CASE( "response constructor", "[http]" )
{
    Http::Response response;
            
    REQUIRE( response.version == 1.1 );
    REQUIRE( response.status_code == 0 );
    REQUIRE( response.status_message == "" );
    REQUIRE( response.body == Bytes( ) );
    
    multimap< string, string > headers;
    REQUIRE( response.headers == headers );
}
