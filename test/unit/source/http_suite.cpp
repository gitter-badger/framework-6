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
#include <gtest/gtest.h>

//System Namespaces
using std::map;
using std::vector;
using std::string;

//Project Namespaces
using framework::Http;

//External Namespaces

TEST( Http, request_defaults )
{
    Http::Request request;
    
    EXPECT_EQ( "", request.uri );
    EXPECT_EQ( 1.1, request.version );
    EXPECT_EQ( "GET", request.method );
    EXPECT_EQ( vector< uint8_t >( ), request.body );
    
    map< string, string > headers;
    EXPECT_EQ( headers, request.headers );
}

TEST( Http, response_defaults )
{
    Http::Response response;
    
    EXPECT_EQ( 1.1, response.version );
    EXPECT_EQ( 0, response.status_code );
    EXPECT_EQ( "", response.status_message );
    EXPECT_EQ( vector< uint8_t >( ), response.body );
    
    map< string, string > headers;
    EXPECT_EQ( headers, response.headers );
}
