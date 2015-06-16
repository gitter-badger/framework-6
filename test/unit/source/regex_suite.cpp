/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <regex>
#include <string>
#include <stdexcept>

//Project Includes
#include <corvusoft/framework/regex>

//External Includes
#include <catch.hpp>

//System Namespaces
using std::regex;
using std::string;
using std::regex_error;
using std::invalid_argument;

//Project Namespaces
using framework::Regex;

//External Namespaces

TEST_CASE( "constructor", "[regex]" )
{
    Regex pattern;
      
    REQUIRE( pattern.to_string( ) == "" );
}

TEST_CASE( "string constructor", "[regex]" )
{
    const string value = ".*";
    Regex pattern( value );
    
    REQUIRE( pattern.to_string( ) == value );
}

TEST_CASE( "character pointer constructor", "[regex]" )
{
    const char* value = ".*";   
    Regex pattern( value );  

    REQUIRE( pattern.to_string( ) == value );
}

TEST_CASE( "invalid constructor", "[regex]" )
{
    REQUIRE_THROWS_AS( Regex( "(" ), regex_error );
}

TEST_CASE( "empty constructor", "[regex]" )
{
    Regex pattern( "" );
            
    REQUIRE( pattern.to_string( ) == "" );
}

TEST_CASE( "nullptr constructor", "[regex]" )
{
    REQUIRE_THROWS_AS( Regex( nullptr ), invalid_argument );
}

TEST_CASE( "copy constructor", "[regex]" )
{
    Regex pattern( "*" );
    Regex copy( pattern );
            
    REQUIRE( copy.to_string( ) == pattern.to_string( ) );
}

TEST_CASE( "destructor", "[regex]" )
{
    Regex* pattern = new Regex( "*" );
        
    REQUIRE_NOTHROW( delete pattern );
}

TEST_CASE( "assignment-operator", "[regex]" )
{
    Regex pattern( "[0-9]*" );
    Regex copy = pattern;
            
    REQUIRE( copy.to_string( ) == pattern.to_string( ) );
}

TEST_CASE( "less-than-operator", "[regex]" )
{
    Regex lhs( "*" );
    Regex rhs( "[0-9]*" );
        
    REQUIRE( lhs < rhs );
}

TEST_CASE( "greater-than-operator", "[regex]" )
{
    Regex lhs( "[0-9]*" );
    Regex rhs( "*" );
        
    REQUIRE( lhs > rhs );
}

TEST_CASE( "equality-operator", "[regex]" )
{
    Regex lhs( "*" );
    Regex rhs( "*" );
        
    REQUIRE( lhs == rhs );
}

TEST_CASE( "inequality-operator", "[regex]" )
{
    Regex lhs( "*" );
    Regex rhs( "[0-9]*" );
        
    REQUIRE( lhs not_eq rhs );
}

TEST_CASE( "is_valid", "[regex]" )
{
    REQUIRE( Regex::is_valid( "^[a-z]*$" ) == true );
}

TEST_CASE( "invalid is_valid", "[regex]" )
{
    REQUIRE( Regex::is_valid( "(" ) == false );
}

TEST_CASE( "empty is_valid", "[regex]" )
{
    REQUIRE( Regex::is_valid( "" ) == true );
}

TEST_CASE( "is_match", "[regex]" )
{
    Regex pattern( "^[a-z]*$" );

    REQUIRE( pattern.is_match( "corvusoft" ) == true );
}

TEST_CASE( "empty is_match", "[regex]" )
{
    Regex pattern( "" );

    REQUIRE( pattern.is_match( "Corvusoft" ) == false );
}

TEST_CASE( "static is_match", "[regex]" )
{
    REQUIRE( Regex::is_match( "corvusoft", "^[a-z]*$" ) == true );
}

TEST_CASE( "static empty is_match", "[regex]" )
{
    REQUIRE( Regex::is_match( "", "Corvusoft" ) == false );
}

TEST_CASE( "static invalid is_match", "[regex]" )
{
    REQUIRE( Regex::is_match( "(", "Corvusoft" ) == false );
}

TEST_CASE( "escape", "[regex]" )
{
    REQUIRE( Regex::escape( "a = 1 + 2" ) == "a = 1 \\+ 2" );
}

TEST_CASE( "empty escape", "[regex]" )
{
    REQUIRE( Regex::escape( "" ) == "" );
}

TEST_CASE( "to_string", "[regex]" )
{
    Regex pattern( ".*" );
        
    REQUIRE( pattern.to_string( ) == ".*" );
}
