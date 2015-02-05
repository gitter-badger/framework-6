/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <string>
#include <stdexcept>

//Project Includes
#include <corvusoft/framework/uri>

//External Includes
#include <catch.hpp>

//System Namespaces
using std::string;
using std::invalid_argument;

//Project Namespaces
using framework::Uri;

//External Namespaces

SCENARIO( "constructor", "[uri]" )
{
    GIVEN( "i want to instantiate a uri from a string value" )
    {
        Uri uri( "http://crowhurst.ben:ASDFFDSA1234@code.google.com:80/resources/index.html?q=bear&b=cubs#frag1" );
        
        WHEN( "i construct the object with 'http://username:password@127.1.1.1:80/resources/index.html?q=bear&b=cubs#frag1'" )
        {
            const string value = uri.to_string( );
            
            THEN( "i should see 'http://username:password@127.1.1.1:80/resources/index.html?q=bear&b=cubs#frag1'" )
            {
                REQUIRE( value == "http://crowhurst.ben:ASDFFDSA1234@code.google.com:80/resources/index.html?q=bear&b=cubs#frag1" );
                REQUIRE( uri.get_port( ) == 80 );
                REQUIRE( uri.get_path( ) == "/resources/index.html" );
                REQUIRE( uri.get_query( ) == "q=bear&b=cubs" );
                REQUIRE( uri.get_scheme( ) == "http" );
                REQUIRE( uri.get_fragment( ) == "frag1" );
                REQUIRE( uri.get_username( ) == "crowhurst.ben" );
                REQUIRE( uri.get_password( ) == "ASDFFDSA1234" );
                REQUIRE( uri.get_authority( ) == "code.google.com" );
            }
        }
    }
}

SCENARIO( "ipv4 constructor", "[uri]" )
{
    GIVEN( "i want to instantiate a uri from a string value" )
    {
        Uri uri( "http://username:password@127.1.1.1:80/resources/index.html?q=bear&b=cubs#frag1" );
        
        WHEN( "i construct the object with 'http://username:password@127.1.1.1:80/resources/index.html?q=bear&b=cubs#frag1'" )
        {
            const string value = uri.to_string( );
            
            THEN( "i should see 'http://username:password@127.1.1.1:80/resources/index.html?q=bear&b=cubs#frag1'" )
            {
                REQUIRE( value == "http://username:password@127.1.1.1:80/resources/index.html?q=bear&b=cubs#frag1" );
            }
        }
    }
}

SCENARIO( "ipv6 constructor", "[uri]" )
{
    GIVEN( "i want to instantiate a uri from a string value" )
    {
        Uri uri( "http://username:password@[2001:0db8:85a3:0000:0000:8a2e:0370:7334]:80/resources/index.html?q=bear&b=cubs#frag1" );
        
        WHEN( "i construct the object with 'http://username:password@[2001:0db8:85a3:0000:0000:8a2e:0370:7334]:80/resources/index.html?q=bear&b=cubs#frag1'" )
        {
            const string value = uri.to_string( );
            
            THEN( "i should see 'http://username:password@[2001:0db8:85a3:0000:0000:8a2e:0370:7334]:80/resources/index.html?q=bear&b=cubs#frag1'" )
            {
                REQUIRE( value == "http://username:password@[2001:0db8:85a3:0000:0000:8a2e:0370:7334]:80/resources/index.html?q=bear&b=cubs#frag1" );
            }
        }
    }
}

SCENARIO( "invalid constructor", "[uri]" )
{
    GIVEN( "i want to instantiate a uri from a string value" )
    {
        WHEN( "i construct the object with '---_)(*&'" )
        {
            THEN( "i should see an exception" )
            {
                REQUIRE_THROWS_AS( Uri( "---_)(*&" ), invalid_argument );
            }
        }
    }
}

SCENARIO( "empty constructor", "[uri]" )
{
    GIVEN( "i want to instantiate a uri from a string value" )
    {
        WHEN( "i construct the object with ''" )
        {
            THEN( "i should see an exception" )
            {
                REQUIRE_THROWS_AS( Uri( "" ), invalid_argument );
            }
        }
    }
}

SCENARIO( "copy constructor", "[uri]" )
{
    GIVEN( "i want to copy an existing uri" )
    {
        Uri uri( "ftp://code.google.com/p/application-on" );
        
        WHEN( "i instantiate the object with the copy-constructor" )
        {
            Uri copy( uri );
            
            THEN( "i should see the same properties" )
            {
                REQUIRE( copy.to_string( ) == uri.to_string( ) );
            }
        }
    }
}

SCENARIO( "destructor", "[uri]" )
{
    GIVEN( "i instantiate a new object" )
    {
        Uri* uri = new Uri( "ftp://code.google.com/p/application-on" );
        
        WHEN( "i deallocate the object" )
        {
            THEN( "i should not see any exceptions" )
            {
                REQUIRE_NOTHROW( delete uri );
            }
        }
    }
}

SCENARIO( "assignment-operator", "[uri]" )
{
    GIVEN( "i want to copy an existing uri" )
    {
        Uri uri( "http://code.google.com/p/application-on/source/detail?r=73aa44eefc85407545b11ff30abbcd980030aab1" );
        
        WHEN( "i instantiate the object with the assignment-operator" )
        {
            Uri copy = uri;
            
            THEN( "i should see the same properties" )
            {
                REQUIRE( copy.to_string( ) == uri.to_string( ) );
            }
        }
    }
}

SCENARIO( "less-than-operator", "[uri]" )
{
    GIVEN( "i want to compare two objects" )
    {
        Uri lhs( "http://restbed.corvusoft.co.uk" );
        Uri rhs( "http://restule.corvusoft.co.uk/index.html" );
        
        WHEN( "i perform a comparison with the less-than-operator" )
        {
            THEN( "i should see the lhs is less than the rhs" )
            {
                REQUIRE( lhs < rhs );
            }
        }
    }
}

SCENARIO( "greater-than-operator", "[uri]" )
{
    GIVEN( "i want to compare two objects" )
    {
        Uri lhs( "http://restbed.corvusoft.co.uk/index.html" );
        Uri rhs( "http://restbed.corvusoft.co.uk" );
        
        WHEN( "i perform a comparison with the greater-than-operator" )
        {
            THEN( "i should see the lhs is greater than the rhs" )
            {
                REQUIRE( lhs > rhs );
            }
        }
    }
}

SCENARIO( "equality-operator", "[uri]" )
{
    GIVEN( "i want to compare two objects" )
    {
        Uri lhs( "http://restq.corvusoft.co.uk" );
        Uri rhs( "http://restq.corvusoft.co.uk" );
        
        WHEN( "i perform a comparison with the equality-operator" )
        {
            THEN( "i should see the identical instances" )
            {
                REQUIRE( lhs == rhs );
            }
        }
    }
}

SCENARIO( "inequality-operator", "[uri]" )
{
    GIVEN( "i want to compare two objects" )
    {
        Uri lhs( "http://restbed.corvusoft.co.uk" );
        Uri rhs( "http://restule.corvusoft.co.uk" );
        
        WHEN( "i perform a comparison with the inequality-operator" )
        {
            THEN( "i should see differing instances" )
            {
                REQUIRE( lhs not_eq rhs );
            }
        }
    }
}

SCENARIO( "to_string", "[uri]" )
{
    GIVEN( "an object with example data" )
    {
        Uri uri( "https://source.corvusoft.co.uk" );
        
        WHEN( "i invoke to_string" )
        {
            THEN( "i should a string representation" )
            {
                REQUIRE( uri.to_string( ) == "https://source.corvusoft.co.uk" );
            }
        }
    }
}

SCENARIO( "to_native_path", "[uri]" )
{
    GIVEN( "an object with example data" )
    {
        string value = "/User/ben/Development/application-on/resource/en_GB.UTF-8";
        
        Uri uri( "file://" + value );
        
        WHEN( "i invoke to_string" )
        {
            THEN( "i should a string representation" )
            {
                REQUIRE( uri.to_native_path( ) == value );
            }
        }
    }
}

SCENARIO( "valid is_valid", "[uri]" )
{
    GIVEN( "i want to validate a string value" )
    {
        WHEN( "i construct the object with 'ws://restq.corvusoft.co.uk:443/queues" )
        {
            THEN( "i should see 'true'" )
            {
                REQUIRE( Uri::is_valid( "ws://restq.corvusoft.co.uk:443/queues" ) );
            }
        }
    }
}

SCENARIO( "invalid is_valid", "[uri]" )
{
    GIVEN( "i want to validate a string value" )
    {
        WHEN( "i construct the object with '---_)(*&'" )
        {
            THEN( "i should not see an exception but a 'false' value" )
            {
                REQUIRE( Uri::is_valid( "---_)(*&" ) == false );
            }
        }
    }
}

SCENARIO( "parse", "[uri]" )
{
    GIVEN( "i want to instantiate a uri from a string value" )
    {
        Uri uri = Uri::parse( "http://shard.corvusoft.co.uk" );
        
        WHEN( "i invoke parse with 'http://shard.corvusoft.co.uk'" )
        {
            const string value = uri.to_string( );
            
            THEN( "i should see 'http://shard.corvusoft.co.uk'" )
            {
                REQUIRE( value == "http://shard.corvusoft.co.uk" );
            }
        }
    }
}

SCENARIO( "invalid parse", "[uri]" )
{
    GIVEN( "i want to instantiate a uri from a string value" )
    {
        WHEN( "i invoke parse with '---_)(*&'" )
        {
            THEN( "i should see an exception" )
            {
                REQUIRE_THROWS_AS( Uri::parse( "---_)(*&" ), invalid_argument );
            }
        }
    }
}

SCENARIO( "empty parse", "[uri]" )
{
    GIVEN( "i want to instantiate a uri from a string value" )
    {
        WHEN( "i invoke parse with ''" )
        {
            THEN( "i should see an exception" )
            {
                REQUIRE_THROWS_AS( Uri::parse( "" ), invalid_argument );
            }
        }
    }
}

SCENARIO( "decode", "[uri]" )
{
    GIVEN( "i want to percent decode a string value" )
    {
        WHEN( "i invoke decode with 'file:///tmp/a%2Eb/tmp_20482932.txt'" )
        {
            THEN( "i should see 'file:///tmp/a.b/tmp_20482932.txt'" )
            {
                REQUIRE( Uri::decode( "file:///tmp/a%2Eb/tmp_20482932.txt" ) == "file:///tmp/a.b/tmp_20482932.txt" );
            }
        }
    }
}

SCENARIO( "decode_parameter", "[uri]" )
{
    GIVEN( "i want to percent decode a string value" )
    {
        WHEN( "i invoke decode_parameter with 'Corvusoft+Solutions'" )
        {
            THEN( "i should see 'Corvusoft Solutions'" )
            {
                REQUIRE( Uri::decode_parameter( "Corvusoft+Solutions" ) == "Corvusoft Solutions" );
            }
        }
    }
}

SCENARIO( "encode", "[uri]" )
{
    GIVEN( "i want to percent encode a string value" )
    {
        WHEN( "i invoke encode with 'a=b'" )
        {
            THEN( "i should see 'a%3Db'" )
            {
                REQUIRE( Uri::encode( "a=b" ) == "a%3Db" );
            }
        }
    }
}
