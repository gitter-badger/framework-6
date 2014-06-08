/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <string>

//Project Includes
#include <corvusoft/framework/uri>

//External Includes
#include <gtest/gtest.h>

//System Namespaces
using std::string;

//Project Namespaces
using framework::Uri;

//External Namespaces

TEST( Uri, decode )
{
    string actual = Uri::decode( "%40%C2%A3%C2%A3Fgh5%24%24%26%26*kbljsprgifw%C2%A3%24%20%24" );
    
    EXPECT_EQ( "@££Fgh5$$&&*kbljsprgifw£$ $", actual );
}

TEST( Uri, decode_parameter )
{
    string actual = Uri::decode_parameter( "?name=Corvusoft+Solutions" );
    
    EXPECT_EQ( "?name=Corvusoft Solutions", actual );
}
