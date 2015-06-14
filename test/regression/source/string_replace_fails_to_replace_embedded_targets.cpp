/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 *
 * bug tracker issue #15
 */

//System Includes
#include <string>

//Project Includes
#include <corvusoft/framework/string>

//External Includes
#include <catch.hpp>

//System Namespaces
using std::string;

//Project Namespaces
using framework::String;

//External Namespaces

TEST_CASE( "deduplicate string value", "[string]" )
{
    const string value = "//path/to////resources/";

    REQUIRE( String::replace( "//", "/", value ) == "/path/to/resources/" );
}

TEST_CASE( "deduplicate string value with missing target", "[string]" )
{
    const string value = "/path/to/resources";

    REQUIRE( String::replace( "//", "/", value ) == "/path/to/resources" );
}
