/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <regex>
#include <string>

//Project Includes
#include <corvusoft/framework/regex>
#include <corvusoft/framework/regex_option>

//External Includes
#include <catch.hpp>

//System Namespaces
using std::regex;
using std::string;
using std::regex_error;

//Project Namespaces
using framework::Regex;
using framework::RegexOption;

//External Namespaces

TEST_CASE( "case insensitive string constructor", "[regex]" )
{
    const string value = "^[a-z]{9,9}$";
    Regex pattern( value, RegexOption::CASE_INSENSITIVE );
    
    REQUIRE( pattern.to_string( ) == value );
}

TEST_CASE( "case insensitive character pointer constructor", "[regex]" )
{
    const char* value = "^[a-z]{9,9}$";    
    Regex pattern( value, RegexOption::CASE_INSENSITIVE );
        
    REQUIRE( pattern.to_string( ) == value );
}
