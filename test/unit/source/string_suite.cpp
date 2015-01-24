/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <map>
#include <string>
#include <vector>

//Project Includes
#include <corvusoft/framework/string>

//External Includes
#define CATCH_CONFIG_MAIN
#include <catch.hpp>

//System Namespaces
using std::map;
using std::string;
using std::vector;

//Project Namespaces
using framework::String;

//External Namespaces

SCENARIO( "uppercase to lowercase", "[string]" )
{
    GIVEN( "i want to lowercase a string value" )
    {
        WHEN( "i invoke lowercase with 'CORVUSOFT'" )
        {
            THEN( "i should see 'corvusoft'" )
            {
                REQUIRE( String::lowercase( "CORVUSOFT" ) == "corvusoft" );
            }
        }
    }
}

SCENARIO( "lowercase to lowercase", "[string]" )
{
    GIVEN( "i want to lowercase a string value" )
    {
        WHEN( "i invoke lowercase with 'corvusoft'" )
        {
            THEN( "i should see 'corvusoft'" )
            {
                REQUIRE( String::lowercase( "corvusoft" ) == "corvusoft" );
            }
        }
    }
}

SCENARIO( "mixedcase to lowercase", "[string]" )
{
    GIVEN( "i want to lowercase a string value" )
    {
        WHEN( "i invoke lowercase with 'CoRvUSoFt'" )
        {
            THEN( "i should see 'corvusoft'" )
            {
                REQUIRE( String::lowercase( "CoRvUSoFt" ) == "corvusoft" );
            }
        }
    }
}

SCENARIO( "empty to lowercase", "[string]" )
{
    GIVEN( "i want to lowercase a string value" )
    {
        WHEN( "i invoke lowercase with ''" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::lowercase( "" ) == "" );
            }
        }
    }
}


SCENARIO( "uppercase to uppercase", "[string]" )
{
    GIVEN( "i want to uppercase a string value" )
    {
        WHEN( "i invoke uppercase with 'corvusoft'" )
        {
            THEN( "i should see 'CORVUSOFT'" )
            {
                REQUIRE( String::uppercase( "corvusoft" ) == "CORVUSOFT" );
            }
        }
    }
}

SCENARIO( "lowercase to uppercase", "[string]" )
{
    GIVEN( "i want to uppercase a string value" )
    {
        WHEN( "i invoke uppercase with 'corvusoft'" )
        {
            THEN( "i should see 'CORVUSOFT'" )
            {
                REQUIRE( String::uppercase( "corvusoft" ) == "CORVUSOFT" );
            }
        }
    }
}

SCENARIO( "mixedcase to uppercase", "[string]" )
{
    GIVEN( "i want to uppercase a string value" )
    {
        WHEN( "i invoke uppercase with 'CoRvUSoFt'" )
        {
            THEN( "i should see 'CORVUSOFT'" )
            {
                REQUIRE( String::uppercase( "CoRvUSoFt" ) == "CORVUSOFT" );
            }
        }
    }
}

SCENARIO( "empty to uppercase", "[string]" )
{
    GIVEN( "i want to uppercase a string value" )
    {
        WHEN( "i invoke uppercase with ''" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::uppercase( "" ) == "" );
            }
        }
    }
}

SCENARIO( "format", "[string]" )
{
    GIVEN( "i want to format a string value" )
    {
        WHEN( "i invoke format with 'Corvusoft %s', Solutions" )
        {
            THEN( "i should see 'Corvusoft Solutions'" )
            {
                REQUIRE( String::format( "Corvusoft %s", "Solutions" ) == "Corvusoft Solutions" );
            }
        }
    }
}

SCENARIO( "format with no specifiers", "[string]" )
{
    GIVEN( "i want to format a string value" )
    {
        WHEN( "i invoke format with 'Corvusoft'" )
        {
            THEN( "i should see 'Corvusoft'" )
            {
                REQUIRE( String::format( "Corvusoft" ) == "Corvusoft" );
            }
        }
    }
}

SCENARIO( "format with empty", "[string]" )
{
    GIVEN( "i want to format a string value" )
    {
        WHEN( "i invoke format with ''" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::format( "" ) == "" );
            }
        }
    }
}

SCENARIO( "split", "[string]" )
{
    GIVEN( "i want to split a string value on ' '" )
    {
        WHEN( "i invoke split with 'Corvusoft Solutions'" )
        {
            THEN( "i should see '[ Corvusoft, Solutions ]'" )
            {
                REQUIRE( String::split( "Corvusoft Solutions", ' ' ) == vector< string >( { "Corvusoft", "Solutions" } ) );
            }
        }
    }
}

SCENARIO( "split with missing delimiter", "[string]" )
{
    GIVEN( "i want to split a string value on '+'" )
    {
        WHEN( "i invoke split with 'Corvusoft Solutions'" )
        {
            THEN( "i should see '[ Corvusoft Solutions ]'" )
            {
                REQUIRE( String::split( "Corvusoft Solutions", '+' ) == vector< string >( { "Corvusoft Solutions" } ) );
            }
        }
    }
}

SCENARIO( "split with empty delimiter", "[string]" )
{
    GIVEN( "i want to split a string value on ''" )
    {
        WHEN( "i invoke split with 'Corvusoft Solutions'" )
        {
            THEN( "i should see '[ Corvusoft Solutions ]'" )
            {
                char expectation = 0;
                REQUIRE( String::split( "Corvusoft Solutions", expectation ) == vector< string >( { "Corvusoft Solutions" } ) );
            }
        }
    }
}

SCENARIO( "join vector to string", "[string]" )
{
    GIVEN( "i want to join a vector value on ', '" )
    {
        WHEN( "i invoke join with '[ Corvusoft, Solutions ]'" )
        {
            THEN( "i should see 'Corvusoft, Solutions'" )
            {
                REQUIRE( String::join( { "Corvusoft", "Solutions" }, ", " ) == "Corvusoft, Solutions" );
            }
        }
    }
}

SCENARIO( "join vector to string with missing delimiter", "[string]" )
{
    GIVEN( "i want to join a vector value on ''" )
    {
        WHEN( "i invoke join with '[ Corvusoft, Solutions ]'" )
        {
            THEN( "i should see 'CorvusoftSolutions'" )
            {
                REQUIRE( String::join( { "Corvusoft", "Solutions" }, "" ) == "CorvusoftSolutions" );
            }
        }
    }
}

SCENARIO( "join vector to string with empty array", "[string]" )
{
    GIVEN( "i want to join a vector value on '-'" )
    {
        WHEN( "i invoke join with '[ ]'" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::join( { }, "-" ) == "" );
            }
        }
    }
}

SCENARIO( "join map to string", "[string]" )
{
    GIVEN( "i want to join a map value on '=' and pairs on '&'" )
    {
        WHEN( "i invoke join with '{ fields = id,rev }, { sort = rev }'" )
        {
            THEN( "i should see 'fields=id,rev&sort=rev'" )
            {
                map< string, string > values = { { "fields", "id,rev" }, { "sort", "rev" } };
                REQUIRE( String::join( values, "=", "&" ) == "fields=id,rev&sort=rev" );
            }
        }
    }
}

SCENARIO( "join map to string with missing value & pair delimiters", "[string]" )
{
    GIVEN( "i want to join a map value on '' and pairs on ''" )
    {
        WHEN( "i invoke join with '{ fields = id,rev }, { sort = rev }'" )
        {
            THEN( "i should see 'fieldsid,revsortrev'" )
            {
                map< string, string > values = { { "fields", "id,rev" }, { "sort", "rev" } };
                REQUIRE( String::join( values, "", "" ) == "fieldsid,revsortrev" );
            }
        }
    }
}

SCENARIO( "join empty map to string", "[string]" )
{
    GIVEN( "i want to join a map value on '=' and pairs on '&'" )
    {
        WHEN( "i invoke join with ''" )
        {
            THEN( "i should see ''" )
            {
                map< string, string > values;
                REQUIRE( String::join( values, "=", "&" ) == "" );
            }
        }
    }
}

SCENARIO( "join map to string with missing value delimiter", "[string]" )
{
    GIVEN( "i want to join a map value on '' and pairs on '&'" )
    {
        WHEN( "i invoke join with '{ fields = id,rev }, { sort = rev }'" )
        {
            THEN( "i should see 'fieldsid,rev&sortrev'" )
            {
                map< string, string > values = { { "fields", "id,rev" }, { "sort", "rev" } };
                REQUIRE( String::join( values, "", "&" ) == "fieldsid,rev&sortrev" );
            }
        }
    }
}

SCENARIO( "join map to string with missing pair delimiter", "[string]" )
{
    GIVEN( "i want to join a map value on '=' and pairs on ''" )
    {
        WHEN( "i invoke join with '{ fields = id,rev }, { sort = rev }'" )
        {
            THEN( "i should see 'fields=id,revsort=rev'" )
            {
                map< string, string > values = { { "fields", "id,rev" }, { "sort", "rev" } };
                REQUIRE( String::join( values, "=", "" ) == "fields=id,revsort=rev" );
            }
        }
    }
}

SCENARIO( "trim", "[string]" )
{
    GIVEN( "i want to trim a string value" )
    {
        WHEN( "i invoke trim with '\\n\\r\\t  Corvusoft Solutions\\t\\n\\r '" )
        {
            THEN( "i should see 'Corvusoft Solutions'" )
            {
                REQUIRE( String::trim( "\n\r\t  Corvusoft Solutions\t\n\r " ) == "Corvusoft Solutions" );
            }
        }
    }
}

SCENARIO( "trim with empty", "[string]" )
{
    GIVEN( "i want to trim a string value" )
    {
        WHEN( "i invoke trim with ''" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::trim( "" ) == "" );
            }
        }
    }
}

SCENARIO( "trim with no whitespace", "[string]" )
{
    GIVEN( "i want to trim a string value" )
    {
        WHEN( "i invoke trim with 'CorvusoftSolutions'" )
        {
            THEN( "i should see 'CorvusoftSolutions'" )
            {
                REQUIRE( String::trim( "CorvusoftSolutions" ) == "CorvusoftSolutions" );
            }
        }
    }
}

SCENARIO( "trim leading", "[string]" )
{
    GIVEN( "i want to trim a string value" )
    {
        WHEN( "i invoke trim_leading with '\\n\\r\\t  Corvusoft Solutions\\t\\n\\r '" )
        {
            THEN( "i should see 'Corvusoft Solutions\\t\\n\\r '" )
            {
                REQUIRE( String::trim_leading( "\n\r\t  Corvusoft Solutions\t\n\r " ) == "Corvusoft Solutions\t\n\r " );
            }
        }
    }
}

SCENARIO( "trim leading with empty", "[string]" )
{
    GIVEN( "i want to trim a string value" )
    {
        WHEN( "i invoke trim_leading with ''" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::trim_leading( "" ) == "" );
            }
        }
    }
}

SCENARIO( "trim leading with no whitespace", "[string]" )
{
    GIVEN( "i want to trim a string value" )
    {
        WHEN( "i invoke trim_leading with 'CorvusoftSolutions'" )
        {
            THEN( "i should see 'CorvusoftSolutions'" )
            {
                REQUIRE( String::trim_leading( "CorvusoftSolutions" ) == "CorvusoftSolutions" );
            }
        }
    }
}

SCENARIO( "trim lagging", "[string]" )
{
    GIVEN( "i want to trim a string value" )
    {
        WHEN( "i invoke trim_lagging with '\\n\\r\\t  Corvusoft Solutions\\t\\n\\r '" )
        {
            THEN( "i should see '\\n\\r\\t  Corvusoft Solutions'" )
            {
                REQUIRE( String::trim_lagging( "\n\r\t  Corvusoft Solutions\t\n\r " ) == "\n\r\t  Corvusoft Solutions" );
            }
        }
    }
}

SCENARIO( "trim lagging with empty", "[string]" )
{
    GIVEN( "i want to trim a string value" )
    {
        WHEN( "i invoke trim_lagging with ''" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::trim_lagging( "" ) == "" );
            }
        }
    }
}

SCENARIO( "trim lagging with no whitespace", "[string]" )
{
    GIVEN( "i want to trim a string value" )
    {
        WHEN( "i invoke trim_lagging with 'CorvusoftSolutions'" )
        {
            THEN( "i should see 'CorvusoftSolutions'" )
            {
                REQUIRE( String::trim_lagging( "CorvusoftSolutions" ) == "CorvusoftSolutions" );
            }
        }
    }
}

SCENARIO( "remove", "[string]" )
{
    GIVEN( "i want to remove elements from a string value" )
    {
        WHEN( "i invoke remove 'Solutions' from 'Corvusoft Solutions'" )
        {
            THEN( "i should see 'Corvusoft '" )
            {
                REQUIRE( String::remove( "Solutions", "Corvusoft Solutions" ) == "Corvusoft " );
            }
        }
    }
}

SCENARIO( "remove multiple", "[string]" )
{
    GIVEN( "i want to remove elements from a string value" )
    {
        WHEN( "i invoke remove 'dot' from 'dot dash dot dash dash'" )
        {
            THEN( "i should see ' dash  dash dash'" )
            {
                REQUIRE( String::remove( "dot", "dot dash dot dash dash" ) == " dash  dash dash" );
            }
        }
    }
}

SCENARIO( "remove with missing target", "[string]" )
{
    GIVEN( "i want to remove elements from a string value" )
    {
        WHEN( "i invoke remove 'ltd' from 'Corvusoft Solutions'" )
        {
            THEN( "i should see 'Corvusoft Solutions'" )
            {
                REQUIRE( String::remove( "ltd", "Corvusoft Solutions" ) == "Corvusoft Solutions" );
            }
        }
    }
}

SCENARIO( "remove with empty target", "[string]" )
{
    GIVEN( "i want to remove elements from a string value" )
    {
        WHEN( "i invoke remove '' from 'Corvusoft Solutions'" )
        {
            THEN( "i should see 'Corvusoft Solutions'" )
            {
                REQUIRE( String::remove( "", "Corvusoft Solutions" ) == "Corvusoft Solutions" );
            }
        }
    }
}

SCENARIO( "remove with empty value", "[string]" )
{
    GIVEN( "i want to remove elements from a string value" )
    {
        WHEN( "i invoke remove ' Solutions' from ''" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::remove( " Solutions", "" ) == "" );
            }
        }
    }
}

SCENARIO( "remove with empty arguments", "[string]" )
{
    GIVEN( "i want to remove elements from a string value" )
    {
        WHEN( "i invoke remove '' from ''" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::remove( "", "" ) == "" );
            }
        }
    }
}

SCENARIO( "replace", "[string]" )
{
    GIVEN( "i want to replace elements from a string value" )
    {
        WHEN( "i invoke replace 'Solutions' with 'ltd' from 'Corvusoft ltd'" )
        {
            THEN( "i should see 'Corvusoft Solutions'" )
            {
                REQUIRE( String::replace( "ltd", "Solutions", "Corvusoft ltd" ) == "Corvusoft Solutions" );
            }
        }
    }
}

SCENARIO( "replace multiple", "[string]" )
{
    GIVEN( "i want to replace elements from a string value" )
    {
        WHEN( "i invoke replace 'dot' with 'ping' from 'dot dash dot dash dash'" )
        {
            THEN( "i should see 'ping dash ping dash dash'" )
            {
                REQUIRE( String::replace( "dot", "ping", "dot dash dot dash dash" ) == "ping dash ping dash dash" );
            }
        }
    }
}

SCENARIO( "replace with missing target", "[string]" )
{
    GIVEN( "i want to replace elements from a string value" )
    {
        WHEN( "i invoke replace 'ltd' with 'Solutions' from 'Corvusoft Solutions'" )
        {
            THEN( "i should see 'Corvusoft Solutions'" )
            {
                REQUIRE( String::replace( "ltd", "Solutions", "Corvusoft Solutions" ) == "Corvusoft Solutions" );
            }
        }
    }
}

SCENARIO( "replace with empty target", "[string]" )
{
    GIVEN( "i want to replace elements from a string value" )
    {
        WHEN( "i invoke replace '' with 'Solutions' from 'Corvusoft ltd'" )
        {
            THEN( "i should see 'Corvusoft ltd'" )
            {
                REQUIRE( String::replace( "", "Solutions", "Corvusoft ltd" ) == "Corvusoft ltd" );
            }
        }
    }
}

SCENARIO( "replace with empty substitute", "[string]" )
{
    GIVEN( "i want to replace elements from a string value" )
    {
        WHEN( "i invoke replace 'ltd' with '' from 'Corvusoft ltd'" )
        {
            THEN( "i should see 'Corvusoft '" )
            {
                REQUIRE( String::replace( "ltd", "", "Corvusoft ltd" ) == "Corvusoft " );
            }
        }
    }
}

SCENARIO( "replace with empty value", "[string]" )
{
    GIVEN( "i want to replace elements from a string value" )
    {
        WHEN( "i invoke replace 'ltd' with 'Solutions' from ''" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::replace( "ltd", "Solutions", "" ) == "" );
            }
        }
    }
}

SCENARIO( "replace with empty target and substitute", "[string]" )
{
    GIVEN( "i want to replace elements from a string value" )
    {
        WHEN( "i invoke replace '' with '' from 'Corvusoft ltd'" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::replace( "", "", "Corvusoft ltd" ) == "Corvusoft ltd" );
            }
        }
    }
}

SCENARIO( "replace with empty target and value", "[string]" )
{
    GIVEN( "i want to replace elements from a string value" )
    {
        WHEN( "i invoke replace '' with 'Solutions' from ''" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::replace( "", "Solutions", "" ) == "" );
            }
        }
    }
}

SCENARIO( "replace with empty substitue and value", "[string]" )
{
    GIVEN( "i want to replace elements from a string value" )
    {
        WHEN( "i invoke replace 'ltd' with '' from ''" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::replace( "ltd", "", "" ) == "" );
            }
        }
    }
}

SCENARIO( "replace with empty arguments", "[string]" )
{
    GIVEN( "i want to replace elements from a string value" )
    {
        WHEN( "i invoke replace '' with '' from ''" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( String::replace( "", "", "" ) == "" );
            }
        }
    }
}

SCENARIO( "empty", "[string]" )
{
    GIVEN( "i want an empty string value" )
    {
        WHEN( "i assign String::empty to a string" )
        {
            THEN( "i should see ''" )
            {
                REQUIRE( strlen( "" ) == 0 );
                REQUIRE( strcmp( "", String::empty ) == 0 );
            }
        }
    }
}
