/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <string>

//Project Includes
#include <corvusoft/framework/checksum>

//External Includes
#define CATCH_CONFIG_MAIN
#include <catch.hpp>

//System Namespaces
using std::string;
using std::invalid_argument;

//Project Namespaces
using framework::Checksum;

//External Namespaces

SCENARIO( "constructor", "[checksum]" )
{
    GIVEN( "i want to instantiate a checksum from a string value" )
    {
        Checksum checksum( "9abc3aa2b0e3ca6c4eb822830ec84e68" );
        
        WHEN( "i construct the object with '9abc3aa2b0e3ca6c4eb822830ec84e68'" )
        {
            const string value = checksum.to_string( );
            
            THEN( "i should see '9abc3aa2b0e3ca6c4eb822830ec84e68'" )
            {
                REQUIRE( value == "9abc3aa2b0e3ca6c4eb822830ec84e68" );
            }
        }
    }
}

SCENARIO( "invalid constructor", "[checksum]" )
{
    GIVEN( "i want to instantiate a checksum from a string value" )
    {
        WHEN( "i construct the object with '---_)(*&'" )
        {
            THEN( "i should see an exception" )
            {
                REQUIRE_THROWS_AS( Checksum( "---_)(*&" ), invalid_argument );
            }
        }
    }
}

SCENARIO( "empty constructor", "[checksum]" )
{
    GIVEN( "i want to instantiate a checksum from a string value" )
    {
        WHEN( "i construct the object with ''" )
        {
            THEN( "i should see an exception" )
            {
                REQUIRE_THROWS_AS( Checksum( "" ), invalid_argument );
            }
        }
    }
}

SCENARIO( "copy constructor", "[checksum]" )
{
    GIVEN( "i want to copy an existing checksum" )
    {
        Checksum checksum( "9abc3aa2b0e3ca6c4eb822830ec84e68" );
        
        WHEN( "i instantiate the object with the copy-constructor" )
        {
            Checksum copy( checksum );
            
            THEN( "i should see the same properties" )
            {
                REQUIRE( copy.to_string( ) == checksum.to_string( ) );
            }
        }
    }
}

SCENARIO( "destructor", "[checksum]" )
{
    GIVEN( "i instantiate a new object" )
    {
        Checksum* checksum = new Checksum( "9abc3aa2b0e3ca6c4eb822830ec84e68" );
        
        WHEN( "i deallocate the object" )
        {
            THEN( "i should not see any exceptions" )
            {
                REQUIRE_NOTHROW( delete checksum );
            }
        }
    }
}

SCENARIO( "assignment-operator", "[checksum]" )
{
    GIVEN( "i want to copy an existing checksum" )
    {
        Checksum checksum( "9abc3aa2b0e3ca6c4eb822830ec84e68" );
        
        WHEN( "i instantiate the object with the assignment-operator" )
        {
            Checksum copy = checksum;
            
            THEN( "i should see the same properties" )
            {
                REQUIRE( copy.to_string( ) == checksum.to_string( ) );
            }
        }
    }
}

SCENARIO( "less-than-operator", "[checksum]" )
{
    GIVEN( "i want to compare two objects" )
    {
        Checksum lhs( "a" );
        Checksum rhs( "abc" );
        
        WHEN( "i perform a comparison with the less-than-operator" )
        {
            THEN( "i should see the lhs is less than the rhs" )
            {
                REQUIRE( lhs < rhs );
            }
        }
    }
}

SCENARIO( "greater-than-operator", "[checksum]" )
{
    GIVEN( "i want to compare two objects" )
    {
        Checksum lhs( "ab" );
        Checksum rhs( "a" );
        
        WHEN( "i perform a comparison with the greater-than-operator" )
        {
            THEN( "i should see the lhs is greater than the rhs" )
            {
                REQUIRE( lhs > rhs );
            }
        }
    }
}

SCENARIO( "equality-operator", "[checksum]" )
{
    GIVEN( "i want to compare two objects" )
    {
        Checksum lhs( "a" );
        Checksum rhs( "a" );
        
        WHEN( "i perform a comparison with the equality-operator" )
        {
            THEN( "i should see the identical instances" )
            {
                REQUIRE( lhs == rhs );
            }
        }
    }
}

SCENARIO( "inequality-operator", "[checksum]" )
{
    GIVEN( "i want to compare two objects" )
    {
        Checksum lhs( "a" );
        Checksum rhs( "ab" );
        
        WHEN( "i perform a comparison with the inequality-operator" )
        {
            THEN( "i should see differing instances" )
            {
                REQUIRE( lhs not_eq rhs );
            }
        }
    }
}

SCENARIO( "is_valid", "[checksum]" )
{
    GIVEN( "i want to validate strings" )
    {
        WHEN( "i invoke is_valid with '9abc3aa2b0e3ca6c4eb822830ec84e68' example data" )
        {
            THEN( "i should see success" )
            {
                REQUIRE( Checksum::is_valid( "9abc3aa2b0e3ca6c4eb822830ec84e68" ) == true );
            }
        }
    }
}

SCENARIO( "invalid is_valid", "[checksum]" )
{
    GIVEN( "i want to validate strings" )
    {
        WHEN( "i invoke is_valid with '____' example data" )
        {
            THEN( "i should see failure" )
            {
                REQUIRE( Checksum::is_valid( "____" ) == false );
            }
        }
    }
}

SCENARIO( "empty is_valid", "[checksum]" )
{
    GIVEN( "i want to validate strings" )
    {
        WHEN( "i invoke is_valid with '' example data" )
        {
            THEN( "i should see failure" )
            {
                REQUIRE( Checksum::is_valid( "" ) == false );
            }
        }
    }
}

SCENARIO( "to_string", "[checksum]" )
{
    GIVEN( "an object with example data" )
    {
        Checksum checksum( "9abc3aa2b0e3ca6c4eb822830ec84e68" );
        
        WHEN( "i invoke to_string" )
        {
            THEN( "i should a string representation" )
            {
                REQUIRE( checksum.to_string( ) == "9abc3aa2b0e3ca6c4eb822830ec84e68" );
            }
        }
    }
}

SCENARIO( "generate", "[checksum]" )
{
    GIVEN( "i want to generate a new checksum" )
    {
        Checksum checksum = Checksum::generate( "corvusoft solutions" );
        
        WHEN( "i invoke generate with 'corvusoft solutions' example data" )
        {
            const string value = checksum.to_string( );
            
            THEN( "i should see '9abc3aa2b0e3ca6c4eb822830ec84e68'" )
            {
                REQUIRE( value == "9abc3aa2b0e3ca6c4eb822830ec84e68" );
            }
        }
    }
}

SCENARIO( "empty generate", "[checksum]" )
{
    GIVEN( "i want to generate a new checksum" )
    {
        Checksum checksum = Checksum::generate( "" );
        
        WHEN( "i invoke generate with '' example data" )
        {
            const string value = checksum.to_string( );
            
            THEN( "i should see 'd41d8cd98f00b204e9800998ecf8427e'" )
            {
                REQUIRE( value == "d41d8cd98f00b204e9800998ecf8427e" );
            }
        }
    }
}

SCENARIO( "parse", "[checksum]" )
{
    GIVEN( "i want to instantiate a checksum from a string value" )
    {
        Checksum checksum = Checksum::parse( "9abc3aa2b0e3ca6c4eb822830ec84e68" );
        
        WHEN( "i invoke parse with '9abc3aa2b0e3ca6c4eb822830ec84e68'" )
        {
            const string value = checksum.to_string( );
            
            THEN( "i should see '9abc3aa2b0e3ca6c4eb822830ec84e68'" )
            {
                REQUIRE( value == "9abc3aa2b0e3ca6c4eb822830ec84e68" );
            }
        }
    }
}

SCENARIO( "invalid parse", "[checksum]" )
{
    GIVEN( "i want to instantiate a checksum from a string value" )
    {
        WHEN( "i invoke parse with '---_)(*&'" )
        {
            THEN( "i should see an exception" )
            {
                REQUIRE_THROWS_AS( Checksum::parse( "---_)(*&" ), invalid_argument );
            }
        }
    }
}

SCENARIO( "empty parse", "[checksum]" )
{
    GIVEN( "i want to instantiate a checksum from a string value" )
    {
        WHEN( "i invoke parse with ''" )
        {
            THEN( "i should see an exception" )
            {
                REQUIRE_THROWS_AS( Checksum::parse( "" ), invalid_argument );
            }
        }
    }
}
