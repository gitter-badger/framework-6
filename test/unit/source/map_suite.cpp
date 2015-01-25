/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <map>
#include <string>
#include <utility>

//Project Includes
#include <corvusoft/framework/map>

//External Includes
#include <catch.hpp>

//System Namespaces
using std::map;
using std::string;
using std::multimap;
using std::make_pair;

//Project Namespaces
using framework::Map;

//External Namespaces

SCENARIO( "find_ignoring_case on lowercase map value", "[map]" )
{
    GIVEN( "i want to locate a map entry" )
    {
        WHEN( "i invoke find_ignoring_case with 'name' on '{ { name = value } }'" )
        {
            THEN( "i should see '{ name = value }'" )
            {
                map< string, string > values;
                values[ "name" ] = "value";
                
                Map::iterator actual = Map::find_ignoring_case( "name", values );
                
                REQUIRE( actual->first == "name" );
                REQUIRE( actual->second == "value" );
            }
        }
    }
}

SCENARIO( "find_ignoring_case on uppercase map value", "[map]" )
{
    GIVEN( "i want to locate a map entry" )
    {
        WHEN( "i invoke find_ignoring_case with 'NAME' on '{ { name = value } }'" )
        {
            THEN( "i should see '{ name = value }'" )
            {
                map< string, string > values;
                values[ "name" ] = "value";
                
                Map::iterator actual = Map::find_ignoring_case( "NAME", values );
                
                REQUIRE( actual->first == "name" );
                REQUIRE( actual->second == "value" );
            }
        }
    }
}

SCENARIO( "find_ignoring_case on mixedcase map value", "[map]" )
{
    GIVEN( "i want to locate a map entry" )
    {
        WHEN( "i invoke find_ignoring_case with 'NaMe' on '{ { name = value } }'" )
        {
            THEN( "i should see '{ name = value }'" )
            {
                map< string, string > values;
                values[ "name" ] = "value";
                
                Map::iterator actual = Map::find_ignoring_case( "NaMe", values );
                
                REQUIRE( actual->first == "name" );
                REQUIRE( actual->second == "value" );
            }
        }
    }
}

SCENARIO( "find_ignoring_case on empty map value", "[map]" )
{
    GIVEN( "i want to locate a map entry" )
    {
        WHEN( "i invoke find_ignoring_case with 'name' on ''" )
        {
            THEN( "i should see ''" )
            {
                map< string, string > values;
                
                Map::iterator actual = Map::find_ignoring_case( "name", values );
                
                REQUIRE( actual == values.end( ) );
            }
        }
    }
}

SCENARIO( "find_ignoring_case on unknown map entry", "[map]" )
{
    GIVEN( "i want to locate a map entry" )
    {
        WHEN( "i invoke find_ignoring_case with 'forename' on '{ { name = value } }'" )
        {
            THEN( "i should see '{ name = value }'" )
            {
                map< string, string > values;
                
                Map::iterator actual = Map::find_ignoring_case( "forename", values );
                
                REQUIRE( actual == values.end( ) );
            }
        }
    }
}

SCENARIO( "find_ignoring_case on lowercase multimap value", "[map]" )
{
    GIVEN( "i want to locate a multimap entry" )
    {
        WHEN( "i invoke find_ignoring_case with 'name' on '{ { name = value } }'" )
        {
            THEN( "i should see '{ name = value }'" )
            {
                multimap< string, string > values;
                values.insert( make_pair( "name", "value" ) );
                
                Map::iterator actual = Map::find_ignoring_case( "name", values );
                
                REQUIRE( actual->first == "name" );
                REQUIRE( actual->second == "value" );
            }
        }
    }
}

SCENARIO( "find_ignoring_case on uppercase multimap value", "[map]" )
{
    GIVEN( "i want to locate a multimap entry" )
    {
        WHEN( "i invoke find_ignoring_case with 'NAME' on '{ { name = value } }'" )
        {
            THEN( "i should see '{ name = value }'" )
            {
                multimap< string, string > values;
                values.insert( make_pair( "name", "value" ) );
                
                Map::iterator actual = Map::find_ignoring_case( "NAME", values );
                
                REQUIRE( actual->first == "name" );
                REQUIRE( actual->second == "value" );
            }
        }
    }
}

SCENARIO( "find_ignoring_case on mixedcase multimap value", "[map]" )
{
    GIVEN( "i want to locate a multimap entry" )
    {
        WHEN( "i invoke find_ignoring_case with 'NaMe' on '{ { name = value } }'" )
        {
            THEN( "i should see '{ name = value }'" )
            {
                multimap< string, string > values;
                values.insert( make_pair( "name", "value" ) );
                
                Map::iterator actual = Map::find_ignoring_case( "NaMe", values );
                
                REQUIRE( actual->first == "name" );
                REQUIRE( actual->second == "value" );
            }
        }
    }
}

SCENARIO( "find_ignoring_case on empty multimap value", "[map]" )
{
    GIVEN( "i want to locate a multimap entry" )
    {
        WHEN( "i invoke find_ignoring_case with 'name' on ''" )
        {
            THEN( "i should see ''" )
            {
                multimap< string, string > values;
                
                Map::iterator actual = Map::find_ignoring_case( "name", values );
                
                REQUIRE( actual == values.end( ) );
            }
        }
    }
}

SCENARIO( "find_ignoring_case on unknown multimap entry", "[map]" )
{
    GIVEN( "i want to locate a multimap entry" )
    {
        WHEN( "i invoke find_ignoring_case with 'forename' on '{ { name = value } }'" )
        {
            THEN( "i should see '{ name = value }'" )
            {
                multimap< string, string > values;
                values.insert( make_pair( "name", "value" ) );
                
                Map::iterator actual = Map::find_ignoring_case( "forename", values );
                
                REQUIRE( actual == values.end( ) );
            }
        }
    }
}

SCENARIO( "find_ignoring_case on multiple multimap entries", "[map]" )
{
    GIVEN( "i want to locate a multimap entry" )
    {
        WHEN( "i invoke find_ignoring_case with 'forename' on '{ { name = value } }'" )
        {
            THEN( "i should see '{ name = value }'" )
            {
                multimap< string, string > values;
                values.insert( make_pair( "name", "1" ) );
                values.insert( make_pair( "name", "2" ) );
                
                Map::iterator actual = Map::find_ignoring_case( "name", values );
                
                REQUIRE( actual == values.begin( ) );
                REQUIRE( actual->first == "name" );
                REQUIRE( actual->second == "1" );
            }
        }
    }
}
