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
using std::chrono::system_clock;

//Project Namespaces
using framework::Date;

//External Namespaces

TEST( Date, zero_format )
{
    string actual = Date::format( system_clock::from_time_t( 0 ) );
    
    EXPECT_EQ( "Thu Jan  1 00:00:00 1970", actual );
}

TEST( Date, positive_format )
{
    string actual = Date::format( system_clock::from_time_t( 1402138994 ) );
    
    EXPECT_EQ( "Sat Jun  7 11:03:14 2014", actual );
}

TEST( Date, negative_timestamp )
{
    string actual = Date::format( system_clock::from_time_t( -100 ) );
    
    EXPECT_EQ( "Wed Dec 31 23:58:20 1969", actual );
}
