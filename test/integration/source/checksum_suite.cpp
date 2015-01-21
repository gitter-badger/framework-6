/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <string>

//Project Includes
#include <corvusoft/framework/bytes>
#include <corvusoft/framework/checksum>

//External Includes
#define CATCH_CONFIG_MAIN
#include <catch.hpp>

//System Namespaces
using std::string;

//Project Namespaces
using framework::Bytes;
using framework::Checksum;

//External Namespaces

SCENARIO( "generate", "[checksum]" )
{
    GIVEN( "i want to instantiate a checksum from a byte value" )
    {
        Bytes bytes = { 'b', 'y', 't', 'e', 's' };
        
        WHEN( "i construct the object with '{ 'b', 'y', 't', 'e', 's' }'" )
        {
            THEN( "i should see '4b3a6218bb3e3a7303e8a171a60fcf92'" )
            {
                REQUIRE( Checksum::generate( bytes ).to_string( ) == "4b3a6218bb3e3a7303e8a171a60fcf92" );
            }
        }
    }
}

SCENARIO( "empty generate", "[checksum]" )
{
    GIVEN( "i want to instantiate a checksum from a byte value" )
    {
        Bytes bytes = { };
        
        WHEN( "i construct the object with ''" )
        {
            THEN( "i should see 'd41d8cd98f00b204e9800998ecf8427e'" )
            {
                REQUIRE( Checksum::generate( bytes ).to_string( ) == "d41d8cd98f00b204e9800998ecf8427e" );
            }
        }
    }
}
