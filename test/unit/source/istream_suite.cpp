/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <sstream>

//Project Includes
#include <corvusoft/framework/istream>

//External Includes
#include <gtest/gtest.h>

//System Namespaces
using std::istringstream;

//Project Namespaces
using framework::IStream;

//External Namespaces

TEST( IStream, valid_string )
{
    istringstream stream( "Corvusoft" );
    stream.get( );
    
    char actual = IStream::reverse_peek( stream );
    
    EXPECT_EQ( 'C', actual );
}

TEST( IStream, empty_string )
{
    istringstream stream( "" );
    stream.get( );
    
    char actual = IStream::reverse_peek( stream );
    char expected = 0;
    
    EXPECT_EQ( expected, actual );
}
