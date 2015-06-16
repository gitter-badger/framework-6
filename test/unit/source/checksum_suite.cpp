/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <string>

//Project Includes
#include <corvusoft/framework/checksum>

//External Includes
#include <catch.hpp>

//System Namespaces
using std::string;
using std::invalid_argument;

//Project Namespaces
using framework::Checksum;

//External Namespaces

TEST_CASE( "constructor", "[checksum]" )
{
    Checksum checksum( "9abc3aa2b0e3ca6c4eb822830ec84e68" );
        
    const string value = checksum.to_string( );
    REQUIRE( value == "9abc3aa2b0e3ca6c4eb822830ec84e68" );
}

TEST_CASE( "invalid constructor", "[checksum]" )
{
    REQUIRE_THROWS_AS( Checksum( "---_)(*&" ), invalid_argument );
}

TEST_CASE( "empty constructor", "[checksum]" )
{
    REQUIRE_THROWS_AS( Checksum( "" ), invalid_argument );
}

TEST_CASE( "copy constructor", "[checksum]" )
{
    Checksum checksum( "9abc3aa2b0e3ca6c4eb822830ec84e68" );
    Checksum copy( checksum );
            
    REQUIRE( copy.to_string( ) == checksum.to_string( ) );
}

TEST_CASE( "destructor", "[checksum]" )
{
    Checksum* checksum = new Checksum( "9abc3aa2b0e3ca6c4eb822830ec84e68" );
        
    REQUIRE_NOTHROW( delete checksum );
}

TEST_CASE( "assignment-operator", "[checksum]" )
{
    Checksum checksum( "9abc3aa2b0e3ca6c4eb822830ec84e68" );
    Checksum copy = checksum;
            
    REQUIRE( copy.to_string( ) == checksum.to_string( ) );
}

TEST_CASE( "less-than-operator", "[checksum]" )
{
    Checksum lhs( "a" );
    Checksum rhs( "abc" );
        
    REQUIRE( lhs < rhs );
}

TEST_CASE( "greater-than-operator", "[checksum]" )
{
    Checksum lhs( "ab" );
    Checksum rhs( "a" );
        
    REQUIRE( lhs > rhs );
}

TEST_CASE( "equality-operator", "[checksum]" )
{
    Checksum lhs( "a" );
    Checksum rhs( "a" );
        
    REQUIRE( lhs == rhs );
}

TEST_CASE( "inequality-operator", "[checksum]" )
{
    Checksum lhs( "a" );
    Checksum rhs( "ab" );
        
    REQUIRE( lhs not_eq rhs );
}

TEST_CASE( "is_valid", "[checksum]" )
{
    REQUIRE( Checksum::is_valid( "9abc3aa2b0e3ca6c4eb822830ec84e68" ) == true );
}

TEST_CASE( "invalid is_valid", "[checksum]" )
{
    REQUIRE( Checksum::is_valid( "____" ) == false );
}

TEST_CASE( "empty is_valid", "[checksum]" )
{
    REQUIRE( Checksum::is_valid( "" ) == false );
}

TEST_CASE( "to_string", "[checksum]" )
{
    Checksum checksum( "9abc3aa2b0e3ca6c4eb822830ec84e68" );
        
    REQUIRE( checksum.to_string( ) == "9abc3aa2b0e3ca6c4eb822830ec84e68" );
}

TEST_CASE( "generate", "[checksum]" )
{
    Checksum checksum = Checksum::generate( "corvusoft solutions" );
        
    const string value = checksum.to_string( );
    REQUIRE( value == "9abc3aa2b0e3ca6c4eb822830ec84e68" );
}

TEST_CASE( "empty generate", "[checksum]" )
{
    Checksum checksum = Checksum::generate( "" );
        
    const string value = checksum.to_string( );
    REQUIRE( value == "d41d8cd98f00b204e9800998ecf8427e" );
}

TEST_CASE( "parse", "[checksum]" )
{
    Checksum checksum = Checksum::parse( "9abc3aa2b0e3ca6c4eb822830ec84e68" );
        
    const string value = checksum.to_string( );
    REQUIRE( value == "9abc3aa2b0e3ca6c4eb822830ec84e68" );
}

TEST_CASE( "invalid parse", "[checksum]" )
{
    REQUIRE_THROWS_AS( Checksum::parse( "---_)(*&" ), invalid_argument );
}

TEST_CASE( "empty parse", "[checksum]" )
{
    REQUIRE_THROWS_AS( Checksum::parse( "" ), invalid_argument );
}
