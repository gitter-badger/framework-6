/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <regex>
#include <string>
#include <stdexcept>

//Project Includes
#include <corvusoft/framework/regex>

//External Includes
#define CATCH_CONFIG_MAIN
#include <catch.hpp>

//System Namespaces
using std::regex;
using std::string;
using std::regex_error;
using std::invalid_argument;

//Project Namespaces
using framework::Regex;

//External Namespaces

SCENARIO( "constructor", "[regex]" )
{
    GIVEN( "i want to instantiate a default regex" )
    {
        Regex pattern;
        
        WHEN( "i construct the default object" )
        {
            THEN( "i should see pattern ''" )
            {
                REQUIRE( pattern.to_string( ) == "" );
            }
        }
    }
}

SCENARIO( "string constructor", "[regex]" )
{
    GIVEN( "i want to instantiate a regex" )
    {
        const string value = ".*";
        
        Regex pattern( value );
        
        WHEN( "i construct the object with '.*'" )
        {
            THEN( "i should see pattern '.*'" )
            {
                REQUIRE( pattern.to_string( ) == value );
            }
        }
    }
}

SCENARIO( "character pointer constructor", "[regex]" )
{
    GIVEN( "i want to instantiate a regex" )
    {
        const char* value = ".*";
        
        Regex pattern( value );
        
        WHEN( "i construct the object with '.*'" )
        {
            THEN( "i should see pattern '.*'" )
            {
                REQUIRE( pattern.to_string( ) == value );
            }
        }
    }
}

SCENARIO( "invalid constructor", "[regex]" )
{
    GIVEN( "i want to instantiate a regex from a string value" )
    {
        WHEN( "i construct the object with '('" )
        {
            THEN( "i should see an exception" )
            {
                REQUIRE_THROWS_AS( Regex( "(" ), regex_error );
            }
        }
    }
}

SCENARIO( "empty constructor", "[regex]" )
{
    GIVEN( "i want to instantiate a regex from a string value" )
    {
        WHEN( "i construct the object with ''" )
        {
            Regex pattern( "" );
            
            THEN( "i should see an exception" )
            {
                REQUIRE( pattern.to_string( ) == "" );
            }
        }
    }
}

SCENARIO( "nullptr constructor", "[regex]" )
{
    GIVEN( "i want to instantiate a regex from a string value" )
    {
        WHEN( "i construct the object with ''" )
        {
            THEN( "i should see an exception" )
            {
                REQUIRE_THROWS_AS( Regex( nullptr ), invalid_argument );
            }
        }
    }
}

SCENARIO( "copy constructor", "[regex]" )
{
    GIVEN( "i want to copy an existing regex" )
    {
        Regex pattern( "*" );
        
        WHEN( "i instantiate the object with the copy-constructor" )
        {
            Regex copy( pattern );
            
            THEN( "i should see the same properties" )
            {
                REQUIRE( copy.to_string( ) == pattern.to_string( ) );
            }
        }
    }
}

SCENARIO( "destructor", "[regex]" )
{
    GIVEN( "i instantiate a new object" )
    {
        Regex* pattern = new Regex( "*" );
        
        WHEN( "i deallocate the object" )
        {
            THEN( "i should not see any exceptions" )
            {
                REQUIRE_NOTHROW( delete pattern );
            }
        }
    }
}

SCENARIO( "assignment-operator", "[regex]" )
{
    GIVEN( "i want to copy an existing regex" )
    {
        Regex pattern( "[0-9]*" );
        
        WHEN( "i instantiate the object with the assignment-operator" )
        {
            Regex copy = pattern;
            
            THEN( "i should see the same properties" )
            {
                REQUIRE( copy.to_string( ) == pattern.to_string( ) );
            }
        }
    }
}

SCENARIO( "less-than-operator", "[regex]" )
{
    GIVEN( "i want to compare two objects" )
    {
        Regex lhs( "*" );
        Regex rhs( "[0-9]*" );
        
        WHEN( "i perform a comparison with the less-than-operator" )
        {
            THEN( "i should see the lhs is less than the rhs" )
            {
                REQUIRE( lhs < rhs );
            }
        }
    }
}

SCENARIO( "greater-than-operator", "[regex]" )
{
    GIVEN( "i want to compare two objects" )
    {
        Regex lhs( "[0-9]*" );
        Regex rhs( "*" );
        
        WHEN( "i perform a comparison with the greater-than-operator" )
        {
            THEN( "i should see the lhs is greater than the rhs" )
            {
                REQUIRE( lhs > rhs );
            }
        }
    }
}

SCENARIO( "equality-operator", "[regex]" )
{
    GIVEN( "i want to compare two objects" )
    {
        Regex lhs( "*" );
        Regex rhs( "*" );
        
        WHEN( "i perform a comparison with the equality-operator" )
        {
            THEN( "i should see the identical instances" )
            {
                REQUIRE( lhs == rhs );
            }
        }
    }
}

SCENARIO( "inequality-operator", "[regex]" )
{
    GIVEN( "i want to compare two objects" )
    {
        Regex lhs( "*" );
        Regex rhs( "[0-9]*" );
        
        WHEN( "i perform a comparison with the inequality-operator" )
        {
            THEN( "i should see differing instances" )
            {
                REQUIRE( lhs not_eq rhs );
            }
        }
    }
}

SCENARIO( "is_valid", "[regex]" )
{
    GIVEN( "i want to validate strings" )
    {
        WHEN( "i invoke is_valid with '^[a-z]*$' example data" )
        {
            THEN( "i should see success" )
            {
                REQUIRE( Regex::is_valid( "^[a-z]*$" ) == true );
            }
        }
    }
}

SCENARIO( "invalid is_valid", "[regex]" )
{
    GIVEN( "i want to validate strings" )
    {
        WHEN( "i invoke is_valid with '(' example data" )
        {
            THEN( "i should see failure" )
            {
                REQUIRE( Regex::is_valid( "(" ) == false );
            }
        }
    }
}

SCENARIO( "empty is_valid", "[regex]" )
{
    GIVEN( "i want to validate strings" )
    {
        WHEN( "i invoke is_valid with '' example data" )
        {
            THEN( "i should see failure" )
            {
                REQUIRE( Regex::is_valid( "" ) == true );
            }
        }
    }
}

SCENARIO( "is_match", "[regex]" )
{
    GIVEN( "i want to match a string pattern of '^[a-z]*$'" )
    {
        WHEN( "i invoke is_match with 'corvusoft' example data" )
        {
            THEN( "i should see success" )
            {
                Regex pattern( "^[a-z]*$" );
                REQUIRE( pattern.is_match( "corvusoft" ) == true );
            }
        }
    }
}

SCENARIO( "empty is_match", "[regex]" )
{
    GIVEN( "i want to match a string pattern of ''" )
    {
        WHEN( "i invoke is_match with 'Corvusoft' example data" )
        {
            THEN( "i should see failure" )
            {
                Regex pattern( "" );
                REQUIRE( pattern.is_match( "Corvusoft" ) == false );
            }
        }
    }
}

SCENARIO( "static is_match", "[regex]" )
{
    GIVEN( "i want to match a string pattern of '^[a-z]*$'" )
    {
        WHEN( "i invoke is_match with 'corvusoft' example data" )
        {
            THEN( "i should see success" )
            {
                REQUIRE( Regex::is_match( "corvusoft", "^[a-z]*$" ) == true );
            }
        }
    }
}

SCENARIO( "static empty is_match", "[regex]" )
{
    GIVEN( "i want to match a string pattern of ''" )
    {
        WHEN( "i invoke is_match with 'Corvusoft' example data" )
        {
            THEN( "i should see failure" )
            {
                REQUIRE( Regex::is_match( "", "Corvusoft" ) == false );
            }
        }
    }
}

SCENARIO( "static invalid is_match", "[regex]" )
{
    GIVEN( "i want to match a string pattern of '('" )
    {
        WHEN( "i invoke is_match with 'Corvusoft' example data" )
        {
            THEN( "i should see an exception" )
            {
                REQUIRE( Regex::is_match( "(", "Corvusoft" ) == false );
            }
        }
    }
}

SCENARIO( "escape", "[regex]" )
{
    GIVEN( "i want to escape a string pattern" )
    {
        WHEN( "i invoke escape with 'a = 1 + 2' example data" )
        {
            THEN( "i should see 'a = 1 \\+ 2'" )
            {
                REQUIRE( Regex::escape( "a = 1 + 2" ) == "a = 1 \\+ 2" );
            }
        }
    }
}

SCENARIO( "empty escape", "[regex]" )
{
    GIVEN( "i want to escape a string pattern" )
    {
        WHEN( "i invoke escape with '' example data" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( Regex::escape( "" ) == "" );
            }
        }
    }
}

SCENARIO( "to_string", "[regex]" )
{
    GIVEN( "an object with example data" )
    {
        Regex pattern( ".*" );
        
        WHEN( "i invoke to_string" )
        {
            THEN( "i should a string representation" )
            {
                REQUIRE( pattern.to_string( ) == ".*" );
            }
        }
    }
}
