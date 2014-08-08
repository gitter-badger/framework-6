/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <string>
#include <stdexcept>

//Project Includes
#include <corvusoft/framework/checksum>

//External Includes
#include <gtest/gtest.h>

//System Namespaces
using std::string;
using std::invalid_argument;

//Project Namespaces
using framework::Checksum;

//External Namespaces

TEST( Checksum, constructor )
{
    Checksum checksum( "ef0fae40052802a9b60938d8ffa710aec95be9f509c0126fb7444fd5264b3f8d" );
    
    EXPECT_EQ( "ef0fae40052802a9b60938d8ffa710aec95be9f509c0126fb7444fd5264b3f8d", checksum.to_string( ) );
    EXPECT_THROW( Checksum( "" ), invalid_argument );
    EXPECT_THROW( Checksum( "---_)(*&" ), invalid_argument );
}

TEST( Checksum, copy_constructor )
{
    Checksum original( "ef0fae40052802a9b60938d8ffa710aec95be9f509c0126fb7444fd5264b3f8d" );
    Checksum copy( original );
    
    EXPECT_EQ( "ef0fae40052802a9b60938d8ffa710aec95be9f509c0126fb7444fd5264b3f8d", copy.to_string( ) );
}

TEST( Checksum, destructor )
{
    EXPECT_NO_THROW(
    {
        Checksum* checksum = new Checksum( "ef0fae40052802a9b60938d8ffa710aec95be9f509c0126fb7444fd5264b3f8d" );
        
        delete checksum;
    } );
}

TEST( Checksum, is_valid )
{
    EXPECT_FALSE( Checksum::is_valid( "" ) );
    EXPECT_FALSE( Checksum::is_valid( "----" ) );
    EXPECT_TRUE( Checksum::is_valid( "ef0fae40052802a9b60938d8ffa710aec95be9f509c0126fb7444fd5264b3f8d" ) );
}

TEST( Checksum, to_string )
{
    Checksum checksum( "ef0fae40052802a9b60938d8ffa710aec95be9f509c0126fb7444fd5264b3f8d" );
    
    EXPECT_EQ( "ef0fae40052802a9b60938d8ffa710aec95be9f509c0126fb7444fd5264b3f8d", checksum.to_string( ) );
}

TEST( Checksum, generate_from_string )
{
    Checksum checksum = Checksum::generate( "corvusoft solutions" );
    
    EXPECT_EQ( "ef0fae40052802a9b60938d8ffa710aec95be9f509c0126fb7444fd5264b3f8d", checksum.to_string( ) );
    
    EXPECT_NO_THROW( Checksum::generate( "" ) );
    EXPECT_NO_THROW( Checksum::generate( "_)(*&^%" ) );
}

TEST( Checksum, parse )
{
    Checksum checksum = Checksum::parse( "ef0fae40052802a9b60938d8ffa710aec95be9f509c0126fb7444fd5264b3f8d" );
    
    EXPECT_EQ( "ef0fae40052802a9b60938d8ffa710aec95be9f509c0126fb7444fd5264b3f8d", checksum.to_string( ) );
    
    EXPECT_THROW( Checksum::parse( "" ), invalid_argument );
    EXPECT_THROW( Checksum::parse( "*&^%$£" ), invalid_argument );
}

TEST( Checksum, assignment_operator )
{
    Checksum original( "ef0fae40052802a9b60938d8ffa710aec95be9f509c0126fb7444fd5264b3f8d" );
    Checksum copy = original;
    
    EXPECT_EQ( "ef0fae40052802a9b60938d8ffa710aec95be9f509c0126fb7444fd5264b3f8d", copy.to_string( ) );
}

TEST( Checksum, less_than_operator )
{
    Checksum lhs( "a" );
    Checksum rhs( "ab" );
    
    EXPECT_TRUE( lhs < rhs );
}

TEST( Checksum, greater_than_operator )
{
    Checksum lhs( "ab" );
    Checksum rhs( "a" );
    
    EXPECT_TRUE( lhs > rhs );
}

TEST( Checksum, equality_operator )
{
    Checksum lhs( "a" );
    Checksum rhs( "a" );
    
    EXPECT_TRUE( lhs == rhs );
}

TEST( Checksum, inequality_operator )
{
    Checksum lhs( "a" );
    Checksum rhs( "ab" );
    
    EXPECT_TRUE( lhs != rhs );
}
