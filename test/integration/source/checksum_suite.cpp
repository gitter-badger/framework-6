/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <string>

//Project Includes
#include <corvusoft/framework/bytes>
#include <corvusoft/framework/checksum>

//External Includes
#include <gtest/gtest.h>

//System Namespaces
using std::string;

//Project Namespaces
using framework::Bytes;
using framework::Checksum;

//External Namespaces

TEST( Checksum, generate_from_bytes )
{
    Bytes bytes = { 'b', 'y', 't', 'e', 's', '\0' };
    
    EXPECT_EQ( "73ca55dbfe8bb55d6351bf415671fc4b", Checksum::generate( bytes ).to_string( ) );
}
