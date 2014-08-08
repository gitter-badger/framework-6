/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <string>

//Project Includes
#include <corvusoft/framework/run_id>
#include <corvusoft/framework/unique_id>

//External Includes
#include <gtest/gtest.h>

//System Namespaces
using std::string;

//Project Namespaces
using framework::RunId;
using framework::UniqueId;

//External Namespaces

TEST( RunId, get_unique_id )
{
    RunId run_id = RunId::parse( "419D60B4-816A-447A-B902-A06DCCD61847-1407403744" );
    UniqueId unique_id( "419D60B4-816A-447A-B902-A06DCCD61847" );
    
    EXPECT_EQ( unique_id, run_id.get_unique_id( ) );
}
