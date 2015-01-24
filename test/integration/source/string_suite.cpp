/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <string>
#include <vector>

//Project Includes
#include <corvusoft/framework/bytes>
#include <corvusoft/framework/string>
#include <corvusoft/framework/string_option>

//External Includes
#define CATCH_CONFIG_MAIN
#include <catch.hpp>

//System Namespaces
using std::string;
using std::vector;

//Project Namespaces
using framework::Bytes;
using framework::String;
using framework::StringOption;

//External Namespaces

SCENARIO( "case insensitive remove", "[string]" )
{
    GIVEN( "i want to remove elements from a string value" )
    {
        WHEN( "i invoke remove 'Solutions' from 'Corvusoft SOLUTIONS'" )
        {
            THEN( "i should see 'Corvusoft '" )
            {
                REQUIRE( String::remove( "Solutions", "Corvusoft SOLUTIONS", StringOption::CASE_INSENSITIVE ) == "Corvusoft " );
            }
        }
    }
}

SCENARIO( "case insensitive remove with missing target", "[string]" )
{
    GIVEN( "i want to remove elements from a string value" )
    {
        WHEN( "i invoke remove 'ltd' from 'Corvusoft SOLUTIONS'" )
        {
            THEN( "i should see 'Corvusoft '" )
            {
                REQUIRE( String::remove( "ltd", "Corvusoft SOLUTIONS", StringOption::CASE_INSENSITIVE ) == "Corvusoft SOLUTIONS" );
            }
        }
    }
}

SCENARIO( "case insensitive remove with empty target", "[string]" )
{
    GIVEN( "i want to remove elements from a string value" )
    {
        WHEN( "i invoke remove '' from 'Corvusoft SOLUTIONS'" )
        {
            THEN( "i should see 'Corvusoft SOLUTIONS'" )
            {
                REQUIRE( String::remove( "", "Corvusoft SOLUTIONS", StringOption::CASE_INSENSITIVE ) == "Corvusoft SOLUTIONS" );
            }
        }
    }
}

SCENARIO( "case insensitive remove with empty value", "[string]" )
{
    GIVEN( "i want to remove elements from a string value" )
    {
        WHEN( "i invoke remove 'Solutions' from ''" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::remove( "Solutions", "", StringOption::CASE_INSENSITIVE ) == "" );
            }
        }
    }
}

SCENARIO( "case insensitive remove with empty arguments", "[string]" )
{
    GIVEN( "i want to remove elements from a string value" )
    {
        WHEN( "i invoke remove '' from ''" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::remove( "", "", StringOption::CASE_INSENSITIVE ) == "" );
            }
        }
    }
}

SCENARIO( "case insensitive replace", "[string]" )
{
    GIVEN( "i want to replace elements from a string value" )
    {
        WHEN( "i invoke replace 'ltd' with 'Solutions' from 'Corvusoft Ltd'" )
        {
            THEN( "i should see 'Corvusoft Solutions'" )
            {
                REQUIRE( String::replace( "ltd", "Solutions", "Corvusoft Ltd", StringOption::CASE_INSENSITIVE ) == "Corvusoft Solutions" );
            }
        }
    }
}

SCENARIO( "case insensitive replace with missing target", "[string]" )
{
    GIVEN( "i want to replace elements from a string value" )
    {
        WHEN( "i invoke replace 'Inc' with 'Solutions' from 'Corvusoft Ltd'" )
        {
            THEN( "i should see 'Corvusoft Ltd'" )
            {
                REQUIRE( String::replace( "", "Solutions", "Corvusoft Ltd", StringOption::CASE_INSENSITIVE ) == "Corvusoft Ltd" );
            }
        }
    }
}

SCENARIO( "case insensitive replace with empty target", "[string]" )
{
    GIVEN( "i want to replace elements from a string value" )
    {
        WHEN( "i invoke replace '' with 'Solutions' from 'Corvusoft Ltd'" )
        {
            THEN( "i should see 'Corvusoft Ltd'" )
            {
                REQUIRE( String::replace( "", "Solutions", "Corvusoft Ltd", StringOption::CASE_INSENSITIVE ) == "Corvusoft Ltd" );
            }
        }
    }
}

SCENARIO( "case insensitive replace with empty substitute", "[string]" )
{
    GIVEN( "i want to replace elements from a string value" )
    {
        WHEN( "i invoke replace 'Ltd' with '' from 'Corvusoft Ltd'" )
        {
            THEN( "i should see 'Corvusoft '" )
            {
                REQUIRE( String::replace( "Ltd", "", "Corvusoft Ltd", StringOption::CASE_INSENSITIVE ) == "Corvusoft " );
            }
        }
    }
}

SCENARIO( "case insensitive replace with empty value", "[string]" )
{
    GIVEN( "i want to replace elements from a string value" )
    {
        WHEN( "i invoke replace 'Ltd' with 'Solutions' from ''" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::replace( "Ltd", "Solutions", "", StringOption::CASE_INSENSITIVE ) == "" );
            }
        }
    }
}

SCENARIO( "case insensitive replace with empty target and substitute", "[string]" )
{
    GIVEN( "i want to replace elements from a string value" )
    {
        WHEN( "i invoke replace '' with '' from 'Corvusoft SOLUTIONS'" )
        {
            THEN( "i should see 'Corvusoft SOLUTIONS'" )
            {
                REQUIRE( String::replace( "", "", "Corvusoft SOLUTIONS", StringOption::CASE_INSENSITIVE ) == "Corvusoft SOLUTIONS" );
            }
        }
    }
}

SCENARIO( "case insensitive replace with empty target and value", "[string]" )
{
    GIVEN( "i want to replace elements from a string value" )
    {
        WHEN( "i invoke replace '' with 'SOLUTIONS' from ''" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::replace( "", "SOLUTIONS", "", StringOption::CASE_INSENSITIVE ) == "" );
            }
        }
    }
}

SCENARIO( "case insensitive replace with empty substitute and value", "[string]" )
{
    GIVEN( "i want to replace elements from a string value" )
    {
        WHEN( "i invoke replace 'Ltd' with '' from 'Corvusoft SOLUTIONS'" )
        {
            THEN( "i should see 'Corvusoft SOLUTIONS'" )
            {
                REQUIRE( String::replace( "Ltd", "", "Corvusoft SOLUTIONS", StringOption::CASE_INSENSITIVE ) == "Corvusoft SOLUTIONS" );
            }
        }
    }
}

SCENARIO( "case insensitive replace with empty arguments", "[string]" )
{
    GIVEN( "i want to replace elements from a string value" )
    {
        WHEN( "i invoke replace '' with '' from ''" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::replace( "", "", "", StringOption::CASE_INSENSITIVE ) == "" );
            }
        }
    }
}

SCENARIO( "to_string", "[string]" )
{
    GIVEN( "i want to convert bytes to a string value" )
    {
        WHEN( "i invoke to_string with '{ 'a', 'b' }'" )
        {
            THEN( "i should see 'ab'" )
            {
                REQUIRE( String::to_string( Bytes( { 'a', 'b' } ) ) == "ab" );
            }
        }
    }
}

SCENARIO( "empty to_string", "[string]" )
{
    GIVEN( "i want to convert bytes to a string value" )
    {
        WHEN( "i invoke to_string with ''" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::to_string( Bytes( { } ) ) == "" );
            }
        }
    }
}

SCENARIO( "to_bytes", "[string]" )
{
    GIVEN( "i want to convert bytes to a string value" )
    {
        WHEN( "i invoke to_string with 'ab'" )
        {
            THEN( "i should see '{ 'a', 'b' }'" )
            {
                REQUIRE( String::to_bytes( "ab" ) == Bytes( { 'a', 'b' } ) );
            }
        }
    }
}

SCENARIO( "empty to_bytes", "[string]" )
{
    GIVEN( "i want to convert bytes to a string value" )
    {
        WHEN( "i invoke to_string with ''" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::to_bytes( "" ) == Bytes( { } ) );
            }
        }
    }
}
