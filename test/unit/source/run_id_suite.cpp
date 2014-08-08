/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <string>
#include <chrono>
#include <stdexcept>

//Project Includes
#include <corvusoft/framework/run_id>

//External Includes
#include <gtest/gtest.h>

//System Namespaces
using std::string;
using std::invalid_argument;
using std::chrono::system_clock;

//Project Namespaces
using framework::RunId;

//External Namespaces

TEST( RunId, constructor )
{
    RunId run_id( "419D60B4-816A-447A-B902-A06DCCD61847-1407403744" );
    
    EXPECT_EQ( "419D60B4-816A-447A-B902-A06DCCD61847-1407403744", run_id.to_string( ) );
    EXPECT_THROW( RunId( "" ), invalid_argument );
    EXPECT_THROW( RunId( "---_)(*&" ), invalid_argument );
}

TEST( RunId, copy_constructor )
{
    RunId original( "419D60B4-816A-447A-B902-A06DCCD61847-1407403744" );
    RunId copy( original );
    
    EXPECT_EQ( "419D60B4-816A-447A-B902-A06DCCD61847-1407403744", copy.to_string( ) );
}

TEST( RunId, destructor )
{
    EXPECT_NO_THROW(
    {
        RunId* run_id = new RunId( "419D60B4-816A-447A-B902-A06DCCD61847-1407403744" );
        
        delete run_id;
    } );
}

TEST( RunId, is_valid )
{
    EXPECT_FALSE( RunId::is_valid( "" ) );
    EXPECT_FALSE( RunId::is_valid( "----" ) );
    EXPECT_TRUE( RunId::is_valid( "419D60B4-816A-447A-B902-A06DCCD61847-1407403744" ) );
}

TEST( RunId, to_string )
{
    RunId run_id( "419D60B4-816A-447A-B902-A06DCCD61847-1407403744" );
    
    EXPECT_EQ( "419D60B4-816A-447A-B902-A06DCCD61847-1407403744", run_id.to_string( ) );
}

TEST( RunId, generate )
{
    RunId run_id = RunId::generate( );
    
    EXPECT_NE( "", run_id.to_string( ) );
    EXPECT_TRUE( system_clock::now( ) >= run_id.get_timestamp( ) );
}

TEST( RunId, parse )
{
    RunId run_id = RunId::parse( "419D60B4-816A-447A-B902-A06DCCD61847-1407403744" );
    
    EXPECT_EQ( "419D60B4-816A-447A-B902-A06DCCD61847-1407403744", run_id.to_string( ) );
    
    EXPECT_THROW( RunId::parse( "" ), invalid_argument );
    EXPECT_THROW( RunId::parse( "*&^%$£" ), invalid_argument );
}

TEST( RunId, get_timestamp )
{
    RunId run_id = RunId::parse( "419D60B4-816A-447A-B902-A06DCCD61847-1407403744" );
    
    EXPECT_EQ( 1407403744, system_clock::to_time_t( run_id.get_timestamp( ) ) );
}

TEST( RunId, assignment_operator )
{
    RunId original( "419D60B4-816A-447A-B902-A06DCCD61847-1407403744" );
    RunId copy = original;
    
    EXPECT_EQ( "419D60B4-816A-447A-B902-A06DCCD61847-1407403744", copy.to_string( ) );
}

TEST( RunId, less_than_operator )
{
    RunId lhs( "419D60B4-816A-447A-B902-A06DCCD61847-1407403744" );
    RunId rhs( "419D60B4-816A-447A-B902-A06DCCD61847-1407496229" );
    
    EXPECT_TRUE( lhs < rhs );
}

TEST( RunId, greater_than_operator )
{
    RunId lhs( "419D60B4-816A-447A-B902-A06DCCD61847-1407496229" );
    RunId rhs( "419D60B4-816A-447A-B902-A06DCCD61847-1407403744" );
    
    EXPECT_TRUE( lhs > rhs );
}

TEST( RunId, equality_operator )
{
    RunId lhs( "419D60B4-816A-447A-B902-A06DCCD61847-1407403744" );
    RunId rhs( "419D60B4-816A-447A-B902-A06DCCD61847-1407403744" );
    
    EXPECT_TRUE( lhs == rhs );
}

TEST( RunId, inequality_operator )
{
    RunId lhs( "419D60B4-816A-447A-B902-A06DCCD61847-1407403744" );
    RunId rhs( "419D60B4-816A-447A-B902-A06DCCD61847-1407496229" );
    
    EXPECT_TRUE( lhs != rhs );
}
