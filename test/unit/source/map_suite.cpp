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

TEST( Map, find_key_ignoring_case_with_lowercase_string )
{
    map< string, string > values;
    values[ "name" ] = "value";
    
    Map::iterator actual = Map::find_key_ignoring_case( "name", values );
    
    EXPECT_EQ( "name", actual->first );
    EXPECT_EQ( "value", actual->second );
}

TEST( Map, find_key_ignoring_case_with_uppercase_string )
{
    map< string, string > values;
    values[ "name" ] = "value";
    
    Map::iterator actual = Map::find_key_ignoring_case( "NAME", values );
    
    EXPECT_EQ( "name", actual->first );
    EXPECT_EQ( "value", actual->second );
}

TEST( Map, find_key_ignoring_case_with_mixedcase_string )
{
    map< string, string > values;
    values[ "name" ] = "value";
    
    Map::iterator actual = Map::find_key_ignoring_case( "NaMe", values );
    
    EXPECT_EQ( "name", actual->first );
    EXPECT_EQ( "value", actual->second );
}

TEST( Map, find_key_ignoring_case_with_empty_map )
{
    map< string, string > values;
    
    Map::iterator actual = Map::find_key_ignoring_case( "NaMe", values );
    
    EXPECT_EQ( values.end( ), actual );
}

TEST( Map, find_key_ignoring_case_with_unknown_entry )
{
    map< string, string > values;
    values[ "name" ] = "value";
    
    Map::iterator actual = Map::find_key_ignoring_case( "forename", values );
    
    EXPECT_EQ( values.end( ), actual );
}
