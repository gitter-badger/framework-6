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
    
    EXPECT_EQ( "388c5568fafc5325058396619a74cd28c3220a233a050d67bafe65dd313d0b23", Checksum::generate( bytes ).to_string( ) );
}
