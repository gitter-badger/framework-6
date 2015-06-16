/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <string>
#include <vector>

//Project Includes
#include <corvusoft/framework/byte>
#include <corvusoft/framework/string>
#include <corvusoft/framework/string_option>

//External Includes
#include <catch.hpp>

//System Namespaces
using std::string;
using std::vector;

//Project Namespaces
using framework::Bytes;
using framework::String;
using framework::StringOption;

//External Namespaces

TEST_CASE( "case insensitive remove", "[string]" )
{
    REQUIRE( String::remove( "Solutions", "Corvusoft SOLUTIONS", StringOption::CASE_INSENSITIVE ) == "Corvusoft " );
}

TEST_CASE( "case insensitive remove with missing target", "[string]" )
{
    REQUIRE( String::remove( "ltd", "Corvusoft SOLUTIONS", StringOption::CASE_INSENSITIVE ) == "Corvusoft SOLUTIONS" );
}

TEST_CASE( "case insensitive remove with empty target", "[string]" )
{
    REQUIRE( String::remove( "", "Corvusoft SOLUTIONS", StringOption::CASE_INSENSITIVE ) == "Corvusoft SOLUTIONS" );
}

TEST_CASE( "case insensitive remove with empty value", "[string]" )
{
    REQUIRE( String::remove( "Solutions", "", StringOption::CASE_INSENSITIVE ) == "" );
}

TEST_CASE( "case insensitive remove with empty arguments", "[string]" )
{
    REQUIRE( String::remove( "", "", StringOption::CASE_INSENSITIVE ) == "" );
}

TEST_CASE( "case insensitive replace", "[string]" )
{
    REQUIRE( String::replace( "ltd", "Solutions", "Corvusoft Ltd", StringOption::CASE_INSENSITIVE ) == "Corvusoft Solutions" );
}

TEST_CASE( "case insensitive replace with missing target", "[string]" )
{
    REQUIRE( String::replace( "", "Solutions", "Corvusoft Ltd", StringOption::CASE_INSENSITIVE ) == "Corvusoft Ltd" );
}

TEST_CASE( "case insensitive replace with empty target", "[string]" )
{
    REQUIRE( String::replace( "", "Solutions", "Corvusoft Ltd", StringOption::CASE_INSENSITIVE ) == "Corvusoft Ltd" );
}

TEST_CASE( "case insensitive replace with empty substitute", "[string]" )
{
    REQUIRE( String::replace( "Ltd", "", "Corvusoft Ltd", StringOption::CASE_INSENSITIVE ) == "Corvusoft " );
}

TEST_CASE( "case insensitive replace with empty value", "[string]" )
{
    REQUIRE( String::replace( "Ltd", "Solutions", "", StringOption::CASE_INSENSITIVE ) == "" );
}

TEST_CASE( "case insensitive replace with empty target and substitute", "[string]" )
{
    REQUIRE( String::replace( "", "", "Corvusoft SOLUTIONS", StringOption::CASE_INSENSITIVE ) == "Corvusoft SOLUTIONS" );
}

TEST_CASE( "case insensitive replace with empty target and value", "[string]" )
{
    REQUIRE( String::replace( "", "SOLUTIONS", "", StringOption::CASE_INSENSITIVE ) == "" );
}

TEST_CASE( "case insensitive replace with empty substitute and value", "[string]" )
{
    REQUIRE( String::replace( "Ltd", "", "Corvusoft SOLUTIONS", StringOption::CASE_INSENSITIVE ) == "Corvusoft SOLUTIONS" );
}

TEST_CASE( "case insensitive replace with empty arguments", "[string]" )
{
    REQUIRE( String::replace( "", "", "", StringOption::CASE_INSENSITIVE ) == "" );
}

TEST_CASE( "to_string", "[string]" )
{
    REQUIRE( String::to_string( Bytes( { 'a', 'b' } ) ) == "ab" );
}

TEST_CASE( "empty to_string", "[string]" )
{
    REQUIRE( String::to_string( Bytes( { } ) ) == "" );
}

TEST_CASE( "to_bytes", "[string]" )
{
    REQUIRE( String::to_bytes( "ab" ) == Bytes( { 'a', 'b' } ) );
}

TEST_CASE( "empty to_bytes", "[string]" )
{
    REQUIRE( String::to_bytes( "" ) == Bytes( { } ) );
}
