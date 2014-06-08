/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <regex>
#include <string>

//Project Includes
#include <corvusoft/framework/regex>

//External Includes
#include <gtest/gtest.h>

//System Namespaces
using std::regex;
using std::string;

//Project Namespaces
using framework::Regex;

//External Namespaces

TEST( Regex, valid_regex )
{
    EXPECT_EQ( true, Regex::is_valid( "[0-9]*" ) );
}

TEST( Regex, invalid_regex )
{
    EXPECT_EQ( false, Regex::is_valid( "$[0-9*" ) );
}
