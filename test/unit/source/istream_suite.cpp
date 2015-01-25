/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <sstream>

//Project Includes
#include <corvusoft/framework/istream>

//External Includes
#include <catch.hpp>

//System Namespaces
using std::istringstream;

//Project Namespaces
using framework::IStream;

//External Namespaces

SCENARIO( "reverse_peek", "[istream]" )
{
    GIVEN( "i want to peek at the previously read character" )
    {
        WHEN( "i call get and then reverse peek on a 'Corvusoft' stream" )
        {
            istringstream stream( "Corvusoft" );
            stream.get( );
            
            THEN( "i should see 'C'" )
            {
                REQUIRE( IStream::reverse_peek( stream ) == 'C' );
            }
        }
    }
}

SCENARIO( "empty reverse_peek", "[istream]" )
{
    GIVEN( "i want to peek at the previously read character" )
    {
        WHEN( "i call get and then reverse peek on a '' stream" )
        {
            istringstream stream( "" );
            stream.get( );
            
            THEN( "i should see ''" )
            {
                REQUIRE( IStream::reverse_peek( stream ) == 0 );
            }
        }
    }
}
