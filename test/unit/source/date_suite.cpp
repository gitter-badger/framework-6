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

TEST( Date, format )
{
    string actual = Date::format( system_clock::from_time_t( 1402138994 ) );
    
    EXPECT_EQ( "Sat Jun  7 07:03:14 2014", actual );
}
