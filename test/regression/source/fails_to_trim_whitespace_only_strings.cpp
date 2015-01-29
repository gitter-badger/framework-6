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

SCENARIO( "trim with only single whitespace character", "[string]" )
{
    GIVEN( "i want to trim a string value" )
    {
        WHEN( "i invoke trim with ' '" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::trim( " " ) == "" );
            }
        }
    }
}

SCENARIO( "trim with only multiple whitespace characters", "[string]" )
{
    GIVEN( "i want to trim a string value" )
    {
        WHEN( "i invoke trim with '    '" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::trim( "    " ) == "" );
            }
        }
    }
}

SCENARIO( "trim leading with only single whitespace character", "[string]" )
{
    GIVEN( "i want to trim a string value" )
    {
        WHEN( "i invoke trim_leading with ' '" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::trim_leading( " " ) == "" );
            }
        }
    }
}

SCENARIO( "trim leading with only multiple whitespace characters", "[string]" )
{
    GIVEN( "i want to trim a string value" )
    {
        WHEN( "i invoke trim_leading with '   '" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::trim_leading( "   " ) == "" );
            }
        }
    }
}

SCENARIO( "trim lagging with only single whitespace character", "[string]" )
{
    GIVEN( "i want to trim a string value" )
    {
        WHEN( "i invoke trim_lagging with ' '" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::trim_lagging( " " ) == "" );
            }
        }
    }
}

SCENARIO( "trim lagging with only multiple whitespace characters", "[string]" )
{
    GIVEN( "i want to trim a string value" )
    {
        WHEN( "i invoke trim_lagging with '   '" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::trim_lagging( "   " ) == "" );
            }
        }
    }
}
