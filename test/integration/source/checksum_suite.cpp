/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <string>

//Project Includes
#include <corvusoft/framework/byte>
#include <corvusoft/framework/checksum>

//External Includes
#include <catch.hpp>

//System Namespaces
using std::string;

//Project Namespaces
using framework::Bytes;
using framework::Checksum;

//External Namespaces

TEST_CASE( "generate", "[checksum]" )
{
    Bytes bytes = { 'b', 'y', 't', 'e', 's' };
        
    REQUIRE( Checksum::generate( bytes ).to_string( ) == "4b3a6218bb3e3a7303e8a171a60fcf92" );
}

TEST_CASE( "empty generate", "[checksum]" )
{
    Bytes bytes = { };
        
    REQUIRE( Checksum::generate( bytes ).to_string( ) == "d41d8cd98f00b204e9800998ecf8427e" );
}
