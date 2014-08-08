/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <regex>
#include <string>

//Project Includes
#include <corvusoft/framework/regex>
#include <corvusoft/framework/regex_option>

//External Includes
#include <gtest/gtest.h>

//System Namespaces
using std::regex;
using std::string;
using std::regex_error;

//Project Namespaces
using framework::Regex;
using framework::RegexOption;

//External Namespaces

TEST( Regex, string_constructor_ignore_case )
{
    string value = "^[a-z]{9,9}$";
    
    Regex pattern( value, RegexOption::CASE_INSENSITIVE );
    
    EXPECT_TRUE( pattern.is_match( "Corvusoft" ) );
}

TEST( Regex, character_constructor_ignore_case )
{
    const char* value = "^[a-z]{9,9}$";
    
    Regex pattern( value, RegexOption::CASE_INSENSITIVE );
    
    EXPECT_TRUE( pattern.is_match( "Corvusoft" ) );
}
