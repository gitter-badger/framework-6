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
    Bytes bytes = { 'b', 'y', 't', 'e', 's' };
    
    EXPECT_EQ( "4b3a6218bb3e3a7303e8a171a60fcf92", Checksum::generate( bytes ).to_string( ) );
}

TEST( Checksum, generate_from_empty_bytes )
{
    Bytes bytes;
    
    EXPECT_EQ( "d41d8cd98f00b204e9800998ecf8427e", Checksum::generate( bytes ).to_string( ) );
}
