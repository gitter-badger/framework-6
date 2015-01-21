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
#define CATCH_CONFIG_MAIN
#include <catch.hpp>

//System Namespaces
using std::regex;
using std::string;
using std::regex_error;

//Project Namespaces
using framework::Regex;
using framework::RegexOption;

//External Namespaces

SCENARIO( "case insensitive string constructor", "[regex]" )
{
    GIVEN( "i want to instantiate a regex" )
    {
        const string value = "^[a-z]{9,9}$";
        
        Regex pattern( value, RegexOption::CASE_INSENSITIVE );
        
        WHEN( "i construct the object with '^[a-z]{9,9}$'" )
        {
            THEN( "i should see pattern '^[a-z]{9,9}$'" )
            {
                REQUIRE( pattern.to_string( ) == value );
            }
        }
    }
}

SCENARIO( "case insensitive character pointer constructor", "[regex]" )
{
    GIVEN( "i want to instantiate a regex" )
    {
        const char* value = "^[a-z]{9,9}$";
        
        Regex pattern( value, RegexOption::CASE_INSENSITIVE );
        
        WHEN( "i construct the object with '^[a-z]{9,9}$'" )
        {
            THEN( "i should see pattern '^[a-z]{9,9}$'" )
            {
                REQUIRE( pattern.to_string( ) == value );
            }
        }
    }
}
