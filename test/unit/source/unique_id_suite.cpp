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

TEST_CASE( "constructor", "[unique_id]" )
{
    UniqueId unique_id( "c0f22109-d258-4458-a3f5-0d16b2f55487" );
        
    const time_point< system_clock > timestamp = unique_id.get_timestamp( );    
    REQUIRE( timestamp == system_clock::from_time_t( 1421766026 ) );

    const string id = unique_id.to_string( );
    REQUIRE( id == "c0f22109-d258-4458-a3f5-0d16b2f55487" );
}

TEST_CASE( "invalid constructor", "[unique_id]" )
{
    REQUIRE_THROWS_AS( UniqueId( "" ), invalid_argument );
    REQUIRE_THROWS_AS( UniqueId( "---_)(*&" ), invalid_argument );
}

TEST_CASE( "copy-constructor", "[unique_id]" )
{
    UniqueId unique_id( "c0f22109-d258-4458-a3f5-0d16b2f55487" );
    UniqueId copy( unique_id );

    const time_point< system_clock > timestamp = copy.get_timestamp( );        
    REQUIRE( timestamp == system_clock::from_time_t( 1421766026 ) );

    const string id = copy.to_string( );
    REQUIRE( id == "c0f22109-d258-4458-a3f5-0d16b2f55487" );
}

TEST_CASE( "destructor", "[unique_id]" )
{
    UniqueId* unique_id = new UniqueId( "c0f22109-d258-4458-a3f5-0d16b2f55487" );
    
    REQUIRE_NOTHROW( delete unique_id );
}

TEST_CASE( "assignment-operator", "[unique_id]" )
{
    UniqueId unique_id( "c0f22109-d258-4458-a3f5-0d16b2f55487" );
    UniqueId copy = unique_id;

    const string id = copy.to_string( );
    REQUIRE( id == "c0f22109-d258-4458-a3f5-0d16b2f55487" );

    const time_point< system_clock > timestamp = copy.get_timestamp( );
    REQUIRE( timestamp == system_clock::from_time_t( 1421766026 ) );
}

TEST_CASE( "less-than-operator", "[unique_id]" )
{
    UniqueId lhs = UniqueId::generate( );
    UniqueId rhs = UniqueId::generate( );
    
    REQUIRE( lhs < rhs );
}

TEST_CASE( "greater-than-operator", "[unique_id]" )
{
    UniqueId lhs = UniqueId::generate( );
    UniqueId rhs = UniqueId::generate( );

    REQUIRE( rhs > lhs );
}

TEST_CASE( "equality-operator", "[unique_id]" )
{
    UniqueId lhs( "c0f22109-d258-4458-a3f5-0d16b2f55487" );
    UniqueId rhs( "c0f22109-d258-4458-a3f5-0d16b2f55487" );
    
    REQUIRE( lhs == rhs );
}

TEST_CASE( "inequality-operator", "[unique_id]" )
{
    UniqueId lhs = UniqueId::generate( );
    UniqueId rhs = UniqueId::generate( );
    
    REQUIRE( lhs not_eq rhs );
}

TEST_CASE( "is_valid", "[unique_id]" )
{
    REQUIRE( UniqueId::is_valid( "c0f22109-d258-4458-a3f5-0d16b2f55487" ) == true );
}

TEST_CASE( "invalid is_valid", "[unique_id]" )
{
    REQUIRE( UniqueId::is_valid( "____" ) == false );
}

TEST_CASE( "empty is_valid", "[unique_id]" )
{
    REQUIRE( UniqueId::is_valid( "" ) == false );
}

TEST_CASE( "to_string", "[unique_id]" )
{
    UniqueId unique_id( "c0f22109-d258-4458-a3f5-0d16b2f55487" );
    REQUIRE( unique_id.to_string( ) == "c0f22109-d258-4458-a3f5-0d16b2f55487" );
}

TEST_CASE( "generate", "[unique_id]" )
{
    UniqueId unique_id = UniqueId::generate( );
    
    const string id = unique_id.to_string( );
    REQUIRE( id not_eq "" );

    const time_point< system_clock > timestamp = unique_id.get_timestamp( );
    REQUIRE( timestamp <= system_clock::now( ) );
}

TEST_CASE( "parse", "[unique_id]" )
{
    UniqueId unique_id = UniqueId::parse( "c0f22109-d258-4458-a3f5-0d16b2f55487" );

    const string value = unique_id.to_string( );       
    REQUIRE( value == "c0f22109-d258-4458-a3f5-0d16b2f55487" );
}

TEST_CASE( "invalid parse", "[unique_id]" )
{
    REQUIRE_THROWS_AS( UniqueId::parse( "---_)(*&" ), invalid_argument );
}

TEST_CASE( "empty parse", "[unique_id]" )
{
    REQUIRE_THROWS_AS( UniqueId::parse( "" ), invalid_argument );
}
