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

target_link_libraries( fails_to_trim_whitespace_only_strings ${CMAKE_PROJECT_NAME} )

#
# Setup
#
enable_testing( )
add_test( fails_to_trim_whitespace_only_strings ${EXECUTABLE_OUTPUT_PATH}/fails_to_trim_whitespace_only_strings )
