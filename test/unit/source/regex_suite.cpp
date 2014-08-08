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

TEST( Regex, constructor )
{
    Regex pattern;
    
    EXPECT_EQ( "", pattern.to_string( ) );
    
    EXPECT_THROW( Regex( "(" ), regex_error );
}

TEST( Regex, string_constructor )
{
    string value = ".*";
    
    Regex pattern( value );
    
    EXPECT_EQ( value, pattern.to_string( ) );
}

TEST( Regex, string_constructor_ignore_case )
{
    string value = "^[a-z]{9,9}$";
    
    Regex pattern( value, RegexOption::CASE_INSENSITIVE );
    
    EXPECT_TRUE( pattern.is_match( "Corvusoft" ) );
}

TEST( Regex, character_constructor )
{
    const char* value = ".*";
    
    Regex pattern( value );
    
    EXPECT_EQ( value, pattern.to_string( ) );
}

TEST( Regex, character_constructor_ignore_case )
{
    const char* value = "^[a-z]{9,9}$";
    
    Regex pattern( value, RegexOption::CASE_INSENSITIVE );
    
    EXPECT_TRUE( pattern.is_match( "Corvusoft" ) );
}

TEST( Regex, copy_constructor )
{
    Regex original( ".*" );
    Regex copy( original );
    
    EXPECT_EQ( ".*", copy.to_string( ) );
}

TEST( Regex, destructor )
{
    EXPECT_NO_THROW(
    {
        Regex* pattern = new Regex( );
        
        delete pattern;
    } );
}

TEST( Regex, to_string )
{
    Regex pattern( "^[a-z]*$" );
    
    EXPECT_EQ( "^[a-z]*$", pattern.to_string( ) );
}

TEST( Regex, is_match )
{
    Regex pattern( "^[a-zA-Z]{9,9}$" );
    
    EXPECT_TRUE( pattern.is_match( "Corvusoft" ) );
}

TEST( Regex, static_is_match )
{
    EXPECT_TRUE( Regex::is_match( "Corvusoft", "^[a-zA-Z]{9,9}$" ) );
}

TEST( Regex, static_is_valid )
{
    EXPECT_TRUE( Regex::is_valid( "^[a-zA-Z]{9,9}$" ) );
    EXPECT_FALSE( Regex::is_valid( "(" ) );
}

TEST( Regex, assignment_operator )
{
    Regex original( ".*" );
    Regex copy = original;
    
    EXPECT_EQ( ".*", copy.to_string( ) );
}

TEST( Regex, less_than_operator )
{
    Regex lhs( "a" );
    Regex rhs( "ab" );
    
    EXPECT_TRUE( lhs < rhs );
}

TEST( Regex, greater_than_operator )
{
    Regex lhs( "ab" );
    Regex rhs( "a" );
    
    EXPECT_TRUE( lhs > rhs );
}

TEST( Regex, equality_operator )
{
    Regex lhs( "a" );
    Regex rhs( "a" );
    
    EXPECT_TRUE( lhs == rhs );
}

TEST( Regex, inequality_operator )
{
    Regex lhs( "a" );
    Regex rhs( "ab" );
    
    EXPECT_TRUE( lhs != rhs );
}
