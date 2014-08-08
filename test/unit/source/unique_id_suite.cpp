/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <string>
#include <stdexcept>

//Project Includes
#include <corvusoft/framework/unique_id>

//External Includes
#include <gtest/gtest.h>

//System Namespaces
using std::string;
using std::invalid_argument;

//Project Namespaces
using framework::UniqueId;

//External Namespaces

TEST( UniqueId, constructor )
{
    UniqueId unique_id( "419D60B4-816A-447A-B902-A06DCCD61847" );
    
    EXPECT_EQ( "419D60B4-816A-447A-B902-A06DCCD61847", unique_id.to_string( ) );
    EXPECT_THROW( UniqueId( "" ), invalid_argument );
    EXPECT_THROW( UniqueId( "---_)(*&" ), invalid_argument );
}

TEST( UniqueId, copy_constructor )
{
    UniqueId original( "419D60B4-816A-447A-B902-A06DCCD61847" );
    UniqueId copy( original );
    
    EXPECT_EQ( "419D60B4-816A-447A-B902-A06DCCD61847", copy.to_string( ) );
}

TEST( UniqueId, destructor )
{
    EXPECT_NO_THROW(
    {
        UniqueId* unique_id = new UniqueId( "419D60B4-816A-447A-B902-A06DCCD61847" );
        
        delete unique_id;
    } );
}

TEST( UniqueId, is_valid )
{
    EXPECT_FALSE( UniqueId::is_valid( "" ) );
    EXPECT_FALSE( UniqueId::is_valid( "----" ) );
    EXPECT_TRUE( UniqueId::is_valid( "419D60B4-816A-447A-B902-A06DCCD61847" ) );
}

TEST( UniqueId, to_string )
{
    UniqueId unique_id( "419D60B4-816A-447A-B902-A06DCCD61847" );
    
    EXPECT_EQ( "419D60B4-816A-447A-B902-A06DCCD61847", unique_id.to_string( ) );
}

TEST( UniqueId, generate )
{
    UniqueId unique_id = UniqueId::generate( );
    
    EXPECT_NE( "", unique_id.to_string( ) );
}

TEST( UniqueId, parse )
{
    UniqueId unique_id = UniqueId::parse( "419D60B4-816A-447A-B902-A06DCCD61847" );
    
    EXPECT_EQ( "419D60B4-816A-447A-B902-A06DCCD61847", unique_id.to_string( ) );
    
    EXPECT_THROW( UniqueId::parse( "" ), invalid_argument );
    EXPECT_THROW( UniqueId::parse( "*&^%$£" ), invalid_argument );
}

TEST( UniqueId, assignment_operator )
{
    UniqueId original( "419D60B4-816A-447A-B902-A06DCCD61847" );
    UniqueId copy = original;
    
    EXPECT_EQ( "419D60B4-816A-447A-B902-A06DCCD61847", copy.to_string( ) );
}

TEST( UniqueId, less_than_operator )
{
    UniqueId lhs( "419D60B4-816A-447A-B902-A06DCCD61847" );
    UniqueId rhs( "450A6A76-EDBB-48F6-B1E1-F6930E05605E" );
    
    EXPECT_TRUE( lhs < rhs );
}

TEST( UniqueId, greater_than_operator )
{
    UniqueId lhs( "450A6A76-EDBB-48F6-B1E1-F6930E05605E" );
    UniqueId rhs( "419D60B4-816A-447A-B902-A06DCCD61847" );
    
    EXPECT_TRUE( lhs > rhs );
}

TEST( UniqueId, equality_operator )
{
    UniqueId lhs( "419D60B4-816A-447A-B902-A06DCCD61847" );
    UniqueId rhs( "419D60B4-816A-447A-B902-A06DCCD61847" );
    
    EXPECT_TRUE( lhs == rhs );
}

TEST( UniqueId, inequality_operator )
{
    UniqueId lhs( "419D60B4-816A-447A-B902-A06DCCD61847" );
    UniqueId rhs( "450A6A76-EDBB-48F6-B1E1-F6930E05605E" );
    
    EXPECT_TRUE( lhs != rhs );
}
