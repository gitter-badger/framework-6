/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <string>
#include <chrono>

//Project Includes
#include <corvusoft/framework/date>

//External Includes
#include <gtest/gtest.h>

//System Namespaces
using std::string;
using std::invalid_argument;
using std::chrono::system_clock;

//Project Namespaces
using framework::Date;

//External Namespaces

TEST( Date, zero_format )
{
    string actual = Date::format( system_clock::from_time_t( 0 ) );
    
    EXPECT_EQ( "Thu, 01 Jan 1970 00:00:00 GMT", actual );
}

TEST( Date, positive_format )
{
    string actual = Date::format( system_clock::from_time_t( 1402138994 ) );
    
    EXPECT_EQ( "Sat, 07 Jun 2014 11:03:14 GMT", actual );
}

TEST( Date, negative_timestamp )
{
    string actual = Date::format( system_clock::from_time_t( -100 ) );
    
    EXPECT_EQ( "Wed, 31 Dec 1969 23:58:20 GMT", actual );
}

TEST( Date, empty_string_parse )
{
    EXPECT_THROW( Date::parse( "" ), invalid_argument );
}

TEST( Date, parse_valid_dates )
{
    auto datestamp = Date::parse( "Sat Jun 07 11:03:14 2014" );
    EXPECT_EQ( system_clock::from_time_t( 1402138994 ), datestamp );
    
    datestamp = Date::parse( "Thu, 01 Jan 1970 00:00:00 GMT" );
    EXPECT_EQ( system_clock::from_time_t( 0 ), datestamp );
    
    datestamp = Date::parse( "Thursday, 01-Jan-1970 00:00:00 GMT" );
    EXPECT_EQ( system_clock::from_time_t( 0 ), datestamp );
}

TEST( Date, parse_unknown_date )
{
    EXPECT_THROW( Date::parse( "29/02/1984" ), invalid_argument );
}
