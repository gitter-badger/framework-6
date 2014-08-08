/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <string>
#include <stdexcept>

//Project Includes
#include <corvusoft/framework/uri>

//External Includes
#include <gtest/gtest.h>

//System Namespaces
using std::string;
using std::invalid_argument;

//Project Namespaces
using framework::Uri;

//External Namespaces

TEST( Uri, constructor )
{
    string value = "http://code.google.com/p/application-on";
    
    Uri uri( value );
    
    EXPECT_STREQ( value.data( ), uri.to_string( ).data( ) );
    
    EXPECT_TRUE( 39u == uri.to_string( ).length( ) );
}

TEST( Uri, empty_constructor )
{
    EXPECT_THROW( Uri( "" ), invalid_argument );
}

TEST( Uri, copy_constructor )
{
    string value = "ftp://code.google.com/p/application-on";
    
    Uri original( value );
    
    Uri uri( original );
    
    EXPECT_TRUE( uri == original );
    
    EXPECT_STREQ( uri.to_string( ).data( ), original.to_string( ).data( ) );
}

TEST( Uri, destructor )
{
    EXPECT_NO_THROW(
    {
        Uri* uri = new Uri( "http://corvusoft.co.uk" );
        
        delete uri;
    } );
}

TEST( Uri, invalid_uri )
{
    EXPECT_THROW( Uri( "(*&^%$£@£$%^&" ), invalid_argument );
}

TEST( Uri, ipv4_uri )
{
    Uri uri( "http://username:password@127.1.1.1:80/resources/index.html?q=bear&b=cubs#frag1" );
    
    EXPECT_EQ( "http://username:password@127.1.1.1:80/resources/index.html?q=bear&b=cubs#frag1", uri.to_string( ) );
}

TEST( Uri, ipv6_uri )
{
    Uri uri( "http://username:password@[2001:0db8:85a3:0000:0000:8a2e:0370:7334]:80/resources/index.html?q=bear&b=cubs#frag1" );
    
    EXPECT_EQ( "http://username:password@[2001:0db8:85a3:0000:0000:8a2e:0370:7334]:80/resources/index.html?q=bear&b=cubs#frag1", uri.to_string( ) );
}

TEST( Uri, to_string )
{
    string value = "http://code.google.com/p/application-on";
    
    Uri uri( value );
    
    EXPECT_STREQ( value.data( ), uri.to_string( ).data( ) );
}

TEST( Uri, to_native_path )
{
    string value = "/User/ben/Development/application-on/resource/en_GB.UTF-8";
    
    Uri uri( "file://" + value );
    
    EXPECT_STREQ( value.data( ), uri.to_native_path( ).data( ) );
}

TEST( Uri, parse )
{
    string value = "file:///tmp/tmp_20482932.txt";
    
    Uri uri = Uri::parse( value );
    
    EXPECT_STREQ( value.data( ), uri.to_string( ).data( ) );
}

TEST( Uri, decode )
{
    string encoded = "file:///tmp/a%2Eb/tmp_20482932.txt";
    
    string decoded = Uri::decode( encoded );
    
    EXPECT_STREQ( decoded.data( ), "file:///tmp/a.b/tmp_20482932.txt" );
}

TEST( Uri, encode )
{
    string decoded = "file:///tmp/tmp_20482932.txt";
    
    string encoded = Uri::encode( decoded );
    
    EXPECT_STREQ( encoded.data( ), "file%3A%2F%2F%2Ftmp%2Ftmp_20482932.txt" );
}

TEST( Uri, get_port )
{
    string value = "http://code.google.com:8981/p/application-on/";
    
    Uri uri( value );
    
    EXPECT_TRUE( uri.get_port( ) == 8981 );
}

TEST( Uri, get_path )
{
    string value = "http://code.google.com:8981/p/application-on/";
    
    Uri uri( value );
    
    EXPECT_STREQ( uri.get_path( ).data( ), "/p/application-on/" );
}

TEST( Uri, get_query )
{
    string value = "http://code.google.com/p/application-on/source/detail?r=73aa44eefc85407545b11ff30abbcd980030aab1";
    
    Uri uri( value );
    
    EXPECT_STREQ( uri.get_query( ).data( ), "r=73aa44eefc85407545b11ff30abbcd980030aab1" );
}

TEST( Uri, get_scheme )
{
    string value = "http://code.google.com/p/application-on/source/detail?r=73aa44eefc85407545b11ff30abbcd980030aab1";
    
    Uri uri( value );
    
    EXPECT_STREQ( uri.get_scheme( ).data( ), "http" );
}

TEST( Uri, get_fragment )
{
    string value = "http://code.google.com/p/application-on/source/browse/source/appon/type/logger.h?spec=svn73aa44eefc85407545b11ff30abbcd980030aab1&r=73aa44eefc85407545b11ff30abbcd980030aab1#85";
    
    Uri uri( value );
    
    EXPECT_STREQ( uri.get_fragment( ).data( ), "85" );
}

TEST( Uri, get_username )
{
    string value = "https://crowhurst.ben@code.google.com/p/application-on";
    
    Uri uri( value );
    
    EXPECT_STREQ( uri.get_username( ).data( ), "crowhurst.ben" );
}

TEST( Uri, get_password )
{
    string value = "https://crowhurst.ben:ASDFFDSA1234@code.google.com/p/application-on";
    
    Uri uri( value );
    
    EXPECT_STREQ( uri.get_password( ).data( ), "ASDFFDSA1234" );
}

TEST( Uri, get_authority )
{
    string value = "https://crowhurst.ben:ASDFFDSA1234@code.google.com/p/application-on";
    
    Uri uri( value );
    
    EXPECT_STREQ( uri.get_authority( ).data( ), "code.google.com" );
}
