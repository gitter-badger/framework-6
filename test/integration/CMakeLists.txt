# Copyright (c) 2013, 2014, 2015 Corvusoft

project( "integration test suite" )

cmake_minimum_required( VERSION 2.8.10 )

#
# Configuration
#
set( SOURCE_DIR "source" )
set( EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/distribution/binary/test"  )

include_directories( ${catch_INCLUDE} )

#
# Build
#
add_executable( http_unit_test_suite ${SOURCE_DIR}/http_suite.cpp )
add_executable( regex_integration_test_suite ${SOURCE_DIR}/regex_suite.cpp )
add_executable( string_integration_test_suite ${SOURCE_DIR}/string_suite.cpp )
add_executable( checksum_integration_test_suite ${SOURCE_DIR}/checksum_suite.cpp )

target_link_libraries( http_unit_test_suite ${CMAKE_PROJECT_NAME} )
target_link_libraries( regex_integration_test_suite ${CMAKE_PROJECT_NAME} )
target_link_libraries( string_integration_test_suite ${CMAKE_PROJECT_NAME} )
target_link_libraries( checksum_integration_test_suite ${CMAKE_PROJECT_NAME} )

#
# Setup
#
enable_testing( )
add_test( http_unit_test_suite ${EXECUTABLE_OUTPUT_PATH}/http_unit_test_suite )
add_test( regex_integration_test_suite ${EXECUTABLE_OUTPUT_PATH}/regex_integration_test_suite )
add_test( string_integration_test_suite ${EXECUTABLE_OUTPUT_PATH}/string_integration_test_suite )
add_test( checksum_integration_test_suite ${EXECUTABLE_OUTPUT_PATH}/checksum_integration_test_suite )
