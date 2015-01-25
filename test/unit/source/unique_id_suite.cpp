/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <string>
#include <chrono>
#include <stdexcept>

//Project Includes
#include <corvusoft/framework/unique_id>

//External Includes
#include <catch.hpp>

//System Namespaces
using std::string;
using std::invalid_argument;
using std::chrono::time_point;
using std::chrono::system_clock;

//Project Namespaces
using framework::UniqueId;

//External Namespaces

SCENARIO( "constructor", "[unique_id]" )
{
    GIVEN( "i want to instantiate a unique id from a string value" )
    {
        UniqueId unique_id( "c0f22109-d258-4458-a3f5-0d16b2f55487" );
        
        WHEN( "i construct the object with 'c0f22109-d258-4458-a3f5-0d16b2f55487'" )
        {
            const string id = unique_id.to_string( );
            const time_point< system_clock > timestamp = unique_id.get_timestamp( );
            
            THEN( "i should see 'c0f22109-d258-4458-a3f5-0d16b2f55487'" )
            {
                REQUIRE( timestamp == system_clock::from_time_t( 1421766026 ) );
                REQUIRE( id == "c0f22109-d258-4458-a3f5-0d16b2f55487" );
            }
        }
    }
}

SCENARIO( "invalid constructor", "[unique_id]" )
{
    GIVEN( "i want to instantiate a unique id from a string value" )
    {
        WHEN( "i construct the object with '---_)(*&'" )
        {
            THEN( "i should see an exception" )
            {
                REQUIRE_THROWS_AS( UniqueId( "" ), invalid_argument );
                REQUIRE_THROWS_AS( UniqueId( "---_)(*&" ), invalid_argument );
            }
        }
    }
}

SCENARIO( "copy-constructor", "[unique_id]" )
{
    GIVEN( "i want to copy an existing unique id" )
    {
        UniqueId unique_id( "c0f22109-d258-4458-a3f5-0d16b2f55487" );
        
        WHEN( "i instantiate the object with the copy-constructor" )
        {
            UniqueId copy( unique_id );
            const string id = copy.to_string( );
            const time_point< system_clock > timestamp = copy.get_timestamp( );
            
            THEN( "i should see the same properties" )
            {
                REQUIRE( timestamp == system_clock::from_time_t( 1421766026 ) );
                REQUIRE( id == "c0f22109-d258-4458-a3f5-0d16b2f55487" );
            }
        }
    }
}

SCENARIO( "destructor", "[unique_id]" )
{
    GIVEN( "i instantiate a new object" )
    {
        UniqueId* unique_id = new UniqueId( "c0f22109-d258-4458-a3f5-0d16b2f55487" );
        
        WHEN( "i deallocate the object" )
        {
            THEN( "i should not see any exceptions" )
            {
                REQUIRE_NOTHROW( delete unique_id );
            }
        }
    }
}

SCENARIO( "assignment-operator", "[unique_id]" )
{
    GIVEN( "i want to copy an existing unique id" )
    {
        UniqueId unique_id( "c0f22109-d258-4458-a3f5-0d16b2f55487" );
        
        WHEN( "i instantiate the object with the assignment-operator" )
        {
            UniqueId copy = unique_id;
            const string id = copy.to_string( );
            const time_point< system_clock > timestamp = copy.get_timestamp( );
            
            THEN( "i should see the same properties" )
            {
                REQUIRE( timestamp == system_clock::from_time_t( 1421766026 ) );
                REQUIRE( id == "c0f22109-d258-4458-a3f5-0d16b2f55487" );
            }
        }
    }
}

SCENARIO( "less-than-operator", "[unique_id]" )
{
    GIVEN( "i want to compare two objects" )
    {
        UniqueId lhs = UniqueId::generate( );
        UniqueId rhs = UniqueId::generate( );
        
        WHEN( "i perform a comparison with the less-than-operator" )
        {
            THEN( "i should see the lhs is less than the rhs" )
            {
                REQUIRE( lhs < rhs );
            }
        }
    }
}

SCENARIO( "greater-than-operator", "[unique_id]" )
{
    GIVEN( "i want to compare two objects" )
    {
        UniqueId lhs = UniqueId::generate( );
        UniqueId rhs = UniqueId::generate( );
        
        WHEN( "i perform a comparison with the greater-than-operator" )
        {
            THEN( "i should see the lhs is greater than the rhs" )
            {
                REQUIRE( rhs > lhs );
            }
        }
    }
}

SCENARIO( "equality-operator", "[unique_id]" )
{
    GIVEN( "i want to compare two objects" )
    {
        UniqueId lhs( "c0f22109-d258-4458-a3f5-0d16b2f55487" );
        UniqueId rhs( "c0f22109-d258-4458-a3f5-0d16b2f55487" );
        
        WHEN( "i perform a comparison with the equality-operator" )
        {
            THEN( "i should see the identical instances" )
            {
                REQUIRE( lhs == rhs );
            }
        }
    }
}

SCENARIO( "inequality-operator", "[unique_id]" )
{
    GIVEN( "i want to compare two objects" )
    {
        UniqueId lhs = UniqueId::generate( );
        UniqueId rhs = UniqueId::generate( );
        
        WHEN( "i perform a comparison with the inequality-operator" )
        {
            THEN( "i should see the identical instances" )
            {
                REQUIRE( lhs not_eq rhs );
            }
        }
    }
}

SCENARIO( "is_valid", "[unique_id]" )
{
    GIVEN( "i want to validate strings" )
    {
        WHEN( "i invoke is_valid with 'c0f22109-d258-4458-a3f5-0d16b2f55487' example data" )
        {
            THEN( "i should see success" )
            {
                REQUIRE( UniqueId::is_valid( "c0f22109-d258-4458-a3f5-0d16b2f55487" ) == true );
            }
        }
    }
}

SCENARIO( "invalid is_valid", "[unique_id]" )
{
    GIVEN( "i want to validate strings" )
    {
        WHEN( "i invoke is_valid with '____' example data" )
        {
            THEN( "i should see failure" )
            {
                REQUIRE( UniqueId::is_valid( "____" ) == false );
            }
        }
    }
}

SCENARIO( "empty is_valid", "[unique_id]" )
{
    GIVEN( "i want to validate strings" )
    {
        WHEN( "i invoke is_valid with '' example data" )
        {
            THEN( "i should see failure" )
            {
                REQUIRE( UniqueId::is_valid( "" ) == false );
            }
        }
    }
}

SCENARIO( "to_string", "[unique_id]" )
{
    GIVEN( "an object with example data" )
    {
        UniqueId unique_id( "c0f22109-d258-4458-a3f5-0d16b2f55487" );
        
        WHEN( "i invoke to_string" )
        {
            THEN( "i should a string representation" )
            {
                REQUIRE( unique_id.to_string( ) == "c0f22109-d258-4458-a3f5-0d16b2f55487" );
            }
        }
    }
}

SCENARIO( "generate", "[unique_id]" )
{
    GIVEN( "i want to generate a new unique id" )
    {
        UniqueId unique_id = UniqueId::generate( );
        
        WHEN( "i invoke generate" )
        {
            const string id = unique_id.to_string( );
            const time_point< system_clock > timestamp = unique_id.get_timestamp( );
            
            THEN( "i should a valid identifier" )
            {
                REQUIRE( id not_eq "" );
                REQUIRE( timestamp <= system_clock::now( ) );
            }
        }
    }
}

SCENARIO( "parse", "[unique_id]" )
{
    GIVEN( "i want to instantiate a unique id from a string value" )
    {
        UniqueId unique_id = UniqueId::parse( "c0f22109-d258-4458-a3f5-0d16b2f55487" );
        
        WHEN( "i invoke parse with 'c0f22109-d258-4458-a3f5-0d16b2f55487'" )
        {
            const string value = unique_id.to_string( );
            
            THEN( "i should see 'c0f22109-d258-4458-a3f5-0d16b2f55487'" )
            {
                REQUIRE( value == "c0f22109-d258-4458-a3f5-0d16b2f55487" );
            }
        }
    }
}

SCENARIO( "invalid parse", "[unique_id]" )
{
    GIVEN( "i want to instantiate a unique id from a string value" )
    {
        WHEN( "i invoke parse with '---_)(*&'" )
        {
            THEN( "i should see an exception" )
            {
                REQUIRE_THROWS_AS( UniqueId::parse( "---_)(*&" ), invalid_argument );
            }
        }
    }
}

SCENARIO( "empty parse", "[unique_id]" )
{
    GIVEN( "i want to instantiate a unique id from a string value" )
    {
        WHEN( "i invoke parse with ''" )
        {
            THEN( "i should see an exception" )
            {
                REQUIRE_THROWS_AS( UniqueId::parse( "" ), invalid_argument );
            }
        }
    }
}
