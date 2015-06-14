# Copyright (c) 2013, 2014, 2015 Corvusoft

project( "regression test suite" )

cmake_minimum_required( VERSION 2.8.10 )

#
# Configuration
#
set( SOURCE_DIR "source" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCATCH_CONFIG_MAIN" )

include_directories( ${catch_INCLUDE} )

#
# Build
#
add_executable( fails_to_trim_whitespace_only_strings ${SOURCE_DIR}/fails_to_trim_whitespace_only_strings.cpp )
add_executable( string_replace_fails_to_replace_embedded_targets ${SOURCE_DIR}/string_replace_fails_to_replace_embedded_targets.cpp )

target_link_libraries( fails_to_trim_whitespace_only_strings ${CMAKE_PROJECT_NAME} )
target_link_libraries( string_replace_fails_to_replace_embedded_targets ${CMAKE_PROJECT_NAME} )

#
# Setup
#
enable_testing( )
add_test( fails_to_trim_whitespace_only_strings ${EXECUTABLE_OUTPUT_PATH}/fails_to_trim_whitespace_only_strings )
add_test( string_replace_fails_to_replace_embedded_targets ${EXECUTABLE_OUTPUT_PATH}/string_replace_fails_to_replace_embedded_targets )
