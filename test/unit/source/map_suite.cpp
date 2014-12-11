/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <map>
#include <string>
#include <utility>

//Project Includes
#include <corvusoft/framework/map>

//External Includes
#include <gtest/gtest.h>

//System Namespaces
using std::map;
using std::string;
using std::multimap;
using std::make_pair;

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

TEST( Map, find_key_ignoring_case_with_multimap_lowercase_string )
{
    multimap< string, string > values;
    values.insert( make_pair( "name", "value" ) );
    
    Map::iterator actual = Map::find_key_ignoring_case( "name", values );
    
    EXPECT_EQ( "name", actual->first );
    EXPECT_EQ( "value", actual->second );
}

TEST( Map, find_key_ignoring_case_with_multimap_uppercase_string )
{
    multimap< string, string > values;
    values.insert( make_pair( "name", "value" ) );
    
    Map::iterator actual = Map::find_key_ignoring_case( "NAME", values );
    
    EXPECT_EQ( "name", actual->first );
    EXPECT_EQ( "value", actual->second );
}

TEST( Map, find_key_ignoring_case_with_multimap_mixedcase_string )
{
    multimap< string, string > values;
    values.insert( make_pair( "name", "value" ) );
    
    Map::iterator actual = Map::find_key_ignoring_case( "NaMe", values );
    
    EXPECT_EQ( "name", actual->first );
    EXPECT_EQ( "value", actual->second );
}

TEST( Map, find_key_ignoring_case_with_multimap_empty_map )
{
    multimap< string, string > values;
    
    Map::iterator actual = Map::find_key_ignoring_case( "NaMe", values );
    
    EXPECT_EQ( values.end( ), actual );
}

TEST( Map, find_key_ignoring_case_with_multimap_unknown_entry )
{
    multimap< string, string > values;
    values.insert( make_pair( "name", "value" ) );
    
    Map::iterator actual = Map::find_key_ignoring_case( "forename", values );
    
    EXPECT_EQ( values.end( ), actual );
}

TEST( Map, find_key_ignoring_case_with_multimap_multiple_entries )
{
    multimap< string, string > values;
    values.insert( make_pair( "name", "1" ) );
    values.insert( make_pair( "name", "2" ) );
    
    Map::iterator actual = Map::find_key_ignoring_case( "name", values );
    
    EXPECT_EQ( values.begin( ), actual );
}
