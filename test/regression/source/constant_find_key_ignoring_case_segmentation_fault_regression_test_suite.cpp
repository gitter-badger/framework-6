/*
 * Copyright (c) 2013, 2014 Corvusoft
 *
 * bug tracker issue #6
 */

//System Includes
#include <map>
#include <string>

//Project Includes
#include <corvusoft/framework/map>

//External Includes
#include <gtest/gtest.h>

//System Namespaces
using std::map;
using std::string;

//Project Namespaces
using framework::Map;

//External Namespaces

TEST( Map, constant_find_key_ignoring_case_segmentation_fault_regression_test_suite )
{
    const map< string, string > values = { { "name", "value" } };
    
    auto actual = Map::find_key_ignoring_case( "name", values );
    
    EXPECT_EQ( "name", actual->first );
    EXPECT_EQ( "value", actual->second );
}
