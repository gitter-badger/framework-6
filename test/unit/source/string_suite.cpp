/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <string>
#include <vector>

//Project Includes
#include <corvusoft/framework/string>

//External Includes
#include <gtest/gtest.h>

//System Namespaces
using std::string;
using std::vector;

//Project Namespaces
using framework::String;

//External Namespaces

TEST( String, lowercase_upppercased_string )
{
    EXPECT_EQ( "corvusoft", String::lowercase( "CORVUSOFT" ) );
}

TEST( String, lowercase_lowercased_string )
{
    EXPECT_EQ( "corvusoft", String::lowercase( "corvusoft" ) );
}

TEST( String, lowercase_mixedcased_string )
{
    EXPECT_EQ( "corvusoft", String::lowercase( "CoRvUSoFt" ) );
}

TEST( String, lowercase_empty_string )
{
    EXPECT_EQ( "", String::lowercase( "" ) );
}

TEST( String, uppercase_upppercased_string )
{
    EXPECT_EQ( "CORVUSOFT", String::uppercase( "CORVUSOFT" ) );
}

TEST( String, uppercase_lowercased_string )
{
    EXPECT_EQ( "CORVUSOFT", String::uppercase( "corvusoft" ) );
}

TEST( String, uppercase_mixedcased_string )
{
    EXPECT_EQ( "CORVUSOFT", String::uppercase( "CoRvUSoFt" ) );
}

TEST( String, uppercase_empty_string )
{
    EXPECT_EQ( "", String::uppercase( "" ) );
}

TEST( String, format_string_with_no_specifiers )
{
    EXPECT_EQ( "Corvusoft", String::format( "Corvusoft" ) );
}

TEST( String, format_empty_string )
{
    EXPECT_EQ( "", String::format( "" ) );
}

TEST( String, split_string_with_delimiter )
{
    EXPECT_EQ( vector< string >( { "Corvusoft", "Solutions" } ), String::split( "Corvusoft Solutions", ' ' ) );
}

TEST( String, split_string_with_missing_delimiter )
{
    EXPECT_EQ( vector< string >( { "Corvusoft Solutions" } ), String::split( "Corvusoft Solutions", '+' ) );
}

TEST( String, split_empty_string_with_delimiter )
{
    EXPECT_EQ( vector< string >( ), String::split( "", ' ' ) );
}

TEST( String, trim_string )
{
    EXPECT_EQ( "Corvusoft Solutions", String::trim( "\n\r\t  Corvusoft Solutions\t\n\r " ) );
}

TEST( String, trim_empty_string )
{
    EXPECT_EQ( "", String::trim( "" ) );
}

TEST( String, trim_string_with_no_whitespace )
{
    EXPECT_EQ( "CorvusoftSolutions", String::trim( "CorvusoftSolutions" ) );
}

TEST( String, trim_leading_string )
{
    EXPECT_EQ( "Corvusoft Solutions\t\n\r ", String::trim_leading( "\n\r\t  Corvusoft Solutions\t\n\r " ) );
}

TEST( String, trim_leading_empty_string )
{
    EXPECT_EQ( "", String::trim_leading( "" ) );
}

TEST( String, trim_leading_string_with_no_whitespace )
{
    EXPECT_EQ( "CorvusoftSolutions", String::trim_leading( "CorvusoftSolutions" ) );
}

TEST( String, trim_lagging_string )
{
    EXPECT_EQ( "\n\r\t  Corvusoft Solutions", String::trim_lagging( "\n\r\t  Corvusoft Solutions\t\n\r " ) );
}

TEST( String, trim_lagging_empty_string )
{
    EXPECT_EQ( "", String::trim_lagging( "" ) );
}

TEST( String, trim_lagging_string_with_no_whitespace )
{
    EXPECT_EQ( "CorvusoftSolutions", String::trim_lagging( "CorvusoftSolutions" ) );
}

TEST( String, remove_string )
{
    EXPECT_EQ( "Corvusoft", String::remove( " Solutions", "Corvusoft Solutions" ) );
}

TEST( String, remove_string_with_missing_target )
{
    EXPECT_EQ( "Corvusoft Solutions", String::remove( "ltd", "Corvusoft Solutions" ) );
}

TEST( String, remove_string_with_empty_target )
{
    EXPECT_EQ( "Corvusoft Solutions", String::remove( "", "Corvusoft Solutions" ) );
}

TEST( String, remove_string_with_empty_value )
{
    EXPECT_EQ( "", String::remove( " Solutions", "" ) );
}

TEST( String, remove_string_with_empty_arguments )
{
    EXPECT_EQ( "", String::remove( "", "" ) );
}

TEST( String, replace_string )
{
    EXPECT_EQ( "Corvusoft Solutions", String::replace( "ltd", "Solutions", "Corvusoft ltd" ) );
}

TEST( String, replace_string_with_missing_target )
{
    EXPECT_EQ( "Corvusoft Solutions", String::replace( "ltd", "Solutions", "Corvusoft Solutions" ) );
}

TEST( String, replace_string_with_empty_target )
{
    EXPECT_EQ( "Corvusoft ltd", String::replace( "", "Solutions", "Corvusoft ltd" ) );
}

TEST( String, replace_string_with_empty_substitute )
{
    EXPECT_EQ( "Corvusoft ", String::replace( "ltd", "", "Corvusoft ltd" ) );
}

TEST( String, replace_string_with_empty_value )
{
    EXPECT_EQ( "", String::replace( "ltd", "Solutions", "" ) );
}

TEST( String, replace_string_with_empty_target_and_substitute )
{
    EXPECT_EQ( "Corvusoft ltd", String::replace( "", "", "Corvusoft ltd" ) );
}

TEST( String, replace_string_with_empty_target_and_value )
{
    EXPECT_EQ( "", String::replace( "", "Solutions", "" ) );
}

TEST( String, replace_string_with_empty_substitute_and_value )
{
    EXPECT_EQ( "", String::replace( "ltd", "", "" ) );
}

TEST( String, replace_string_with_empty_arguments )
{
    EXPECT_EQ( "", String::replace( "", "", "" ) );
}

TEST( String, string_empty )
{
    EXPECT_EQ( 0, strcmp( "", String::empty ) );
}
