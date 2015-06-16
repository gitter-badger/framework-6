/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <string>
#include <chrono>
#include <stdexcept>

//Project Includes
#include <corvusoft/framework/date>

//External Includes
#include <catch.hpp>

//System Namespaces
using std::string;
using std::invalid_argument;
using std::chrono::system_clock;

//Project Namespaces
using framework::Date;

//External Namespaces

TEST_CASE( "parse", "[date]" )
{
    REQUIRE( Date::parse( "Sat Jun 07 11:03:14 2014" ) == system_clock::from_time_t( 1402138994 ) );
    REQUIRE( Date::parse( "Thu, 01 Jan 1970 00:00:00 GMT" ) == system_clock::from_time_t( 0 ) );
    REQUIRE( Date::parse( "Thursday, 01-Jan-1970 00:00:00 GMT" ) == system_clock::from_time_t( 0 ) );
}

TEST_CASE( "empty parse", "[date]" )
{
    REQUIRE_THROWS_AS( Date::parse( "" ), invalid_argument );
}

TEST_CASE( "invalid parse", "[date]" )
{
    REQUIRE_THROWS_AS( Date::parse( "&%$FDS" ), invalid_argument );
}

TEST_CASE( "malformed parse", "[date]" )
{
    REQUIRE_THROWS_AS( Date::parse( "29/02/1984" ), invalid_argument );
}

TEST_CASE( "format", "[date]" )
{
    REQUIRE( Date::format( system_clock::from_time_t( 1402138994 ) ) == "Sat, 07 Jun 2014 11:03:14 GMT" );
}

TEST_CASE( "zero format", "[date]" )
{
    REQUIRE( Date::format( system_clock::from_time_t( 0 ) ) == "Thu, 01 Jan 1970 00:00:00 GMT" );
}

TEST_CASE( "negative format", "[date]" )
{
    REQUIRE( Date::format( system_clock::from_time_t( -100 ) ) == "Wed, 31 Dec 1969 23:58:20 GMT" );
}
