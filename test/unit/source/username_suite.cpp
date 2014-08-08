/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <string>
#include <stdexcept>

//Project Includes
#include <corvusoft/framework/username>

//External Includes
#include <gtest/gtest.h>

//System Namespaces
using std::string;
using std::invalid_argument;

//Project Namespaces
using framework::Username;

//External Namespaces

TEST( Username, constructor )
{
    Username username( "bencrow" );
    
    EXPECT_EQ( "bencrow", username.to_string( ) );
    EXPECT_THROW( Username( "" ), invalid_argument );
    EXPECT_THROW( Username( "$%£#" ), invalid_argument );
}

TEST( Username, copy_constructor )
{
    Username original( "bencrow" );
    Username copy( original );
    
    EXPECT_EQ( "bencrow", copy.to_string( ) );
}

TEST( Username, destructor )
{
    EXPECT_NO_THROW(
    {
        Username* username = new Username( "bencrow" );
        
        delete username;
    } );
}

TEST( Username, is_valid )
{
    EXPECT_FALSE( Username::is_valid( "" ) );
    EXPECT_FALSE( Username::is_valid( "----" ) );
    EXPECT_TRUE( Username::is_valid( "bencrow" ) );
}

TEST( Username, to_string )
{
    Username username( "bencrow" );
    
    EXPECT_EQ( "bencrow", username.to_string( ) );
}

TEST( Username, parse )
{
    Username username = Username::parse( "bencrow" );
    
    EXPECT_EQ( "bencrow", username.to_string( ) );
    
    EXPECT_THROW( Username::parse( "" ), invalid_argument );
    EXPECT_THROW( Username::parse( "*&^%$£" ), invalid_argument );
}

TEST( Username, assignment_operator )
{
    Username original( "bencrow" );
    Username copy = original;
    
    EXPECT_EQ( "bencrow", copy.to_string( ) );
}

TEST( Username, less_than_operator )
{
    Username lhs( "bencrow" );
    Username rhs( "craiglilley" );
    
    EXPECT_TRUE( lhs < rhs );
}

TEST( Username, greater_than_operator )
{
    Username lhs( "craiglilley" );
    Username rhs( "bencrow" );
    
    EXPECT_TRUE( lhs > rhs );
}

TEST( Username, equality_operator )
{
    Username lhs( "bencrow" );
    Username rhs( "bencrow" );
    
    EXPECT_TRUE( lhs == rhs );
}

TEST( Username, inequality_operator )
{
    Username lhs( "bencrow" );
    Username rhs( "craiglilley" );
    
    EXPECT_TRUE( lhs != rhs );
}
