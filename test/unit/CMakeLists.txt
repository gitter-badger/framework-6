# Copyright (c) 2013, 2014 Corvusoft

project( "Unit Test Suite" )

cmake_minimum_required( VERSION 2.8.10 )

#
# Configuration
#
set( SOURCE_DIR "source" )
set( CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/distribution" )
set( EXECUTABLE_OUTPUT_PATH "${CMAKE_INSTALL_PREFIX}/binary/test"  )

include_directories( ${gtest_INCLUDE} )

#
# Build
#
add_executable( uri_unit_test_suite ${SOURCE_DIR}/uri_suite.cpp )
add_executable( map_unit_test_suite ${SOURCE_DIR}/map_suite.cpp )
add_executable( date_unit_test_suite ${SOURCE_DIR}/date_suite.cpp )
add_executable( regex_unit_test_suite ${SOURCE_DIR}/regex_suite.cpp )
add_executable( istream_unit_test_suite ${SOURCE_DIR}/istream_suite.cpp )

target_link_libraries( uri_unit_test_suite ${CMAKE_PROJECT_NAME} ${gtest_LIBRARY} ${gtest_MAIN_LIBRARY} )
target_link_libraries( map_unit_test_suite ${CMAKE_PROJECT_NAME} ${gtest_LIBRARY} ${gtest_MAIN_LIBRARY} )
target_link_libraries( date_unit_test_suite ${CMAKE_PROJECT_NAME} ${gtest_LIBRARY} ${gtest_MAIN_LIBRARY} )
target_link_libraries( regex_unit_test_suite ${CMAKE_PROJECT_NAME} ${gtest_LIBRARY} ${gtest_MAIN_LIBRARY} )
target_link_libraries( istream_unit_test_suite ${CMAKE_PROJECT_NAME} ${gtest_LIBRARY} ${gtest_MAIN_LIBRARY} )

#
# Setup
#
enable_testing( )
add_test( uri_unit_test_suite ${EXECUTABLE_OUTPUT_PATH}/uri_unit_test_suite )
add_test( map_unit_test_suite ${EXECUTABLE_OUTPUT_PATH}/map_unit_test_suite )
add_test( date_unit_test_suite ${EXECUTABLE_OUTPUT_PATH}/date_unit_test_suite )
add_test( regex_unit_test_suite ${EXECUTABLE_OUTPUT_PATH}/regex_unit_test_suite )
add_test( istream_unit_test_suite ${EXECUTABLE_OUTPUT_PATH}/istream_unit_test_suite )
