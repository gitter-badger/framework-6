/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <string>
#include <stdexcept>

//Project Includes
#include <corvusoft/framework/password>

//External Includes
#include <gtest/gtest.h>

//System Namespaces
using std::string;
using std::invalid_argument;

//Project Namespaces
using framework::Password;

//External Namespaces

TEST( Password, constructor )
{
    Password password( "10$3jtRLRDwXEVta81t$46edeb2ed96ae8672efec6550b57f7fbe8afaf66c5002cec97ebf78403ab8e26" );
    
    //= Password::generate( "48963Rar" );
    
    EXPECT_EQ( "10$3jtRLRDwXEVta81t$46edeb2ed96ae8672efec6550b57f7fbe8afaf66c5002cec97ebf78403ab8e26", password.to_string( ) );
    EXPECT_THROW( Password( "" ), invalid_argument );
    EXPECT_THROW( Password( "$" ), invalid_argument );
}

TEST( Password, copy_constructor )
{
    Password original( "10$3jtRLRDwXEVta81t$46edeb2ed96ae8672efec6550b57f7fbe8afaf66c5002cec97ebf78403ab8e26" );
    Password copy( original );
    
    EXPECT_EQ( "10$3jtRLRDwXEVta81t$46edeb2ed96ae8672efec6550b57f7fbe8afaf66c5002cec97ebf78403ab8e26", copy.to_string( ) );
}

TEST( Password, destructor )
{
    EXPECT_NO_THROW(
    {
        Password* password = new Password( "10$3jtRLRDwXEVta81t$46edeb2ed96ae8672efec6550b57f7fbe8afaf66c5002cec97ebf78403ab8e26" );
        
        delete password;
    } );
}

TEST( Password, to_string )
{
    Password password( "10$3jtRLRDwXEVta81t$46edeb2ed96ae8672efec6550b57f7fbe8afaf66c5002cec97ebf78403ab8e26" );
    
    EXPECT_EQ( "10$3jtRLRDwXEVta81t$46edeb2ed96ae8672efec6550b57f7fbe8afaf66c5002cec97ebf78403ab8e26", password.to_string( ) );
}

TEST( Password, parse )
{
    Password password = Password::parse( "10$3jtRLRDwXEVta81t$46edeb2ed96ae8672efec6550b57f7fbe8afaf66c5002cec97ebf78403ab8e26" );
    
    EXPECT_EQ( "10$3jtRLRDwXEVta81t$46edeb2ed96ae8672efec6550b57f7fbe8afaf66c5002cec97ebf78403ab8e26", password.to_string( ) );
    
    EXPECT_THROW( Password::parse( "" ), invalid_argument );
    EXPECT_THROW( Password::parse( "*&^%$£" ), invalid_argument );
}

TEST( Password, equality_operator )
{
    Password lhs( "10$LgwFWKr66L5P5en4$4521427eb64bef61e2c6be5f3c14aee47ea57aa71740996907840637812346bd" );
    Password rhs( "10$LgwFWKr66L5P5en4$4521427eb64bef61e2c6be5f3c14aee47ea57aa71740996907840637812346bd" );
    
    EXPECT_TRUE( lhs == rhs );
}

TEST( Password, inequality_operator )
{
    Password lhs( "10$LgwFWKr66L5P5en4$4521427eb64bef61e2c6be5f3c14aee47ea57aa71740996907840637812346bd" );
    Password rhs( "10$LgwFWKr66L5P5en4$8ded4e2a12da23a80d156b1e18d2b8e1f935ac1eef0e4143d9a2b1fa834a681d" );
    
    EXPECT_TRUE( lhs != rhs );
}
