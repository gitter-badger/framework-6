/*
 * Copyright (c) 2013, 2014 Corvusoft
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

TEST( Map, find_key_ignoring_case )
{
    map< string, string > values;
    values[ "name" ] = "value";
    
    Map::iterator actual = Map::find_key_ignoring_case( "NAMe", values );
    
    EXPECT_EQ( "name", actual->first );
    EXPECT_EQ( "value", actual->second );
}
