/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <string>
#include <vector>

//Project Includes
#include <corvusoft/framework/string>
#include <corvusoft/framework/string_option>

//External Includes
#include <gtest/gtest.h>

//System Namespaces
using std::string;
using std::vector;

//Project Namespaces
using framework::String;
using framework::StringOption;

//External Namespaces

TEST( String, case_insensitive_remove_string )
{
    EXPECT_EQ( "corvusoft", String::remove( " Solutions", "corvusoft solutions", StringOption::CASE_INSENSITIVE ) );
}

TEST( String, case_insensitive_remove_string_with_missing_target )
{
    EXPECT_EQ( "corvusoft Solutions", String::remove( "ltd", "corvusoft Solutions", StringOption::CASE_INSENSITIVE ) );
}

TEST( String, case_insensitive_remove_string_with_empty_target )
{
    EXPECT_EQ( "Corvusoft Solutions", String::remove( "", "Corvusoft Solutions", StringOption::CASE_INSENSITIVE ) );
}

TEST( String, case_insensitive_remove_string_with_empty_value )
{
    EXPECT_EQ( "", String::remove( " Solutions", "", StringOption::CASE_INSENSITIVE ) );
}

TEST( String, case_insensitive_remove_string_with_empty_arguments )
{
    EXPECT_EQ( "", String::remove( "", "", StringOption::CASE_INSENSITIVE ) );
}

TEST( String, case_insensitive_replace_string )
{
    EXPECT_EQ( "Corvusoft Solutions", String::replace( "ltd", "Solutions", "Corvusoft Ltd", StringOption::CASE_INSENSITIVE ) );
}

TEST( String, case_insensitive_replace_string_with_missing_target )
{
    EXPECT_EQ( "Corvusoft Solutions", String::replace( "ltd", "Solutions", "Corvusoft Solutions", StringOption::CASE_INSENSITIVE ) );
}

TEST( String, case_insensitive_replace_string_with_empty_target )
{
    EXPECT_EQ( "Corvusoft ltd", String::replace( "", "Solutions", "Corvusoft ltd", StringOption::CASE_INSENSITIVE ) );
}

TEST( String, case_insensitive_replace_string_with_empty_substitute )
{
    EXPECT_EQ( "Corvusoft ", String::replace( "ltd", "", "Corvusoft ltd", StringOption::CASE_INSENSITIVE ) );
}

TEST( String, case_insensitive_replace_string_with_empty_value )
{
    EXPECT_EQ( "", String::replace( "ltd", "Solutions", "", StringOption::CASE_INSENSITIVE ) );
}

TEST( String, case_insensitive_replace_string_with_empty_target_and_substitute )
{
    EXPECT_EQ( "Corvusoft ltd", String::replace( "", "", "Corvusoft ltd", StringOption::CASE_INSENSITIVE ) );
}

TEST( String, case_insensitive_replace_string_with_empty_target_and_value )
{
    EXPECT_EQ( "", String::replace( "", "Solutions", "", StringOption::CASE_INSENSITIVE ) );
}

TEST( String, case_insensitive_replace_string_with_empty_substitute_and_value )
{
    EXPECT_EQ( "", String::replace( "ltd", "", "", StringOption::CASE_INSENSITIVE ) );
}

TEST( String, case_insensitive_replace_string_with_empty_arguments )
{
    EXPECT_EQ( "", String::replace( "", "", "", StringOption::CASE_INSENSITIVE ) );
}
