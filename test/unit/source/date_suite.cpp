/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <string>
#include <chrono>
#include <stdexcept>

//Project Includes
#include <corvusoft/framework/date>

//External Includes
#define CATCH_CONFIG_MAIN
#include <catch.hpp>

//System Namespaces
using std::string;
using std::invalid_argument;
using std::chrono::system_clock;

//Project Namespaces
using framework::Date;

//External Namespaces

SCENARIO( "parse", "[date]" )
{
    GIVEN( "i want to parse a date string value" )
    {
        WHEN( "i invoke parse with 'Sat Jun 07 11:03:14 2014'" )
        {
            THEN( "i should see '1402138994' timestamp" )
            {
                REQUIRE( Date::parse( "Sat Jun 07 11:03:14 2014" ) == system_clock::from_time_t( 1402138994 ) );
                REQUIRE( Date::parse( "Thu, 01 Jan 1970 00:00:00 GMT" ) == system_clock::from_time_t( 0 ) );
                REQUIRE( Date::parse( "Thursday, 01-Jan-1970 00:00:00 GMT" ) == system_clock::from_time_t( 0 ) );
            }
        }
    }
}

SCENARIO( "empty parse", "[date]" )
{
    GIVEN( "i want to parse a date string value" )
    {
        WHEN( "i invoke parse with ''" )
        {
            THEN( "i should see an exception" )
            {
                REQUIRE_THROWS_AS( Date::parse( "" ), invalid_argument );
            }
        }
    }
}

SCENARIO( "invalid parse", "[date]" )
{
    GIVEN( "i want to parse a date string value" )
    {
        WHEN( "i invoke parse with '&%$FDS'" )
        {
            THEN( "i should see an exception" )
            {
                REQUIRE_THROWS_AS( Date::parse( "&%$FDS" ), invalid_argument );
            }
        }
    }
}

SCENARIO( "malformed parse", "[date]" )
{
    GIVEN( "i want to parse a date string value" )
    {
        WHEN( "i invoke parse with '29/02/1984'" )
        {
            THEN( "i should see an exception" )
            {
                REQUIRE_THROWS_AS( Date::parse( "29/02/1984" ), invalid_argument );
            }
        }
    }
}

SCENARIO( "format", "[date]" )
{
    GIVEN( "i want to format a timestamp" )
    {
        WHEN( "i invoke format with '1402138994'" )
        {
            THEN( "i should see 'Sat, 07 Jun 2014 11:03:14 GMT'" )
            {
                REQUIRE( Date::format( system_clock::from_time_t( 1402138994 ) ) == "Sat, 07 Jun 2014 11:03:14 GMT" );
            }
        }
    }
}

SCENARIO( "zero format", "[date]" )
{
    GIVEN( "i want to format a timestamp" )
    {
        WHEN( "i invoke format with '0'" )
        {
            THEN( "i should see 'Thu, 01 Jan 1970 00:00:00 GMT'" )
            {
                REQUIRE( Date::format( system_clock::from_time_t( 0 ) ) == "Thu, 01 Jan 1970 00:00:00 GMT" );
            }
        }
    }
}

SCENARIO( "negative format", "[date]" )
{
    GIVEN( "i want to format a timestamp" )
    {
        WHEN( "i invoke format with '-100'" )
        {
            THEN( "i should see 'Wed, 31 Dec 1969 23:58:20 GMT'" )
            {
                REQUIRE( Date::format( system_clock::from_time_t( -100 ) ) == "Wed, 31 Dec 1969 23:58:20 GMT" );
            }
        }
    }
}
