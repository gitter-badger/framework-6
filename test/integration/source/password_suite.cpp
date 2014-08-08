/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <string>

//Project Includes
#include <corvusoft/framework/password>
#include <corvusoft/framework/resident_string>

//External Includes
#include <gtest/gtest.h>

//System Namespaces
using std::string;

//Project Namespaces
using framework::Password;

//External Namespaces

TEST( Password, generate_with_a_salt )
{
    Password password = Password::generate( "corvusoft", "solutions" );
    
    EXPECT_EQ( "10$solutions$b8e7b06b7742d602fd7d215befaa4e2cb91cdfa17acd3d8f99c333b519d66c17", password.to_string( ) );
}

TEST( Password, generate_without_a_salt )
{
    Password acutal = Password::generate( "corvusoft" );
    
    EXPECT_TRUE( acutal == "corvusoft" );
}
