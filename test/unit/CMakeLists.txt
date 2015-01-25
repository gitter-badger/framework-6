# Copyright (c) 2013, 2014, 2015 Corvusoft

project( "unit test suite" )

cmake_minimum_required( VERSION 2.8.10 )

#
# Configuration
#
set( SOURCE_DIR "source" )
set( EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/distribution/binary/test"  )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCATCH_CONFIG_MAIN" )

include_directories( ${catch_INCLUDE} )

#
# Build
#
add_executable( uri_unit_test_suite ${SOURCE_DIR}/uri_suite.cpp )
add_executable( map_unit_test_suite ${SOURCE_DIR}/map_suite.cpp )
add_executable( http_unit_test_suite ${SOURCE_DIR}/http_suite.cpp )
add_executable( date_unit_test_suite ${SOURCE_DIR}/date_suite.cpp )
add_executable( regex_unit_test_suite ${SOURCE_DIR}/regex_suite.cpp )
add_executable( string_unit_test_suite ${SOURCE_DIR}/string_suite.cpp )
add_executable( istream_unit_test_suite ${SOURCE_DIR}/istream_suite.cpp )
add_executable( checksum_unit_test_suite ${SOURCE_DIR}/checksum_suite.cpp )
add_executable( unique_id_unit_test_suite ${SOURCE_DIR}/unique_id_suite.cpp )

target_link_libraries( uri_unit_test_suite ${CMAKE_PROJECT_NAME} )
target_link_libraries( map_unit_test_suite ${CMAKE_PROJECT_NAME} )
target_link_libraries( http_unit_test_suite ${CMAKE_PROJECT_NAME} )
target_link_libraries( date_unit_test_suite ${CMAKE_PROJECT_NAME} )
target_link_libraries( regex_unit_test_suite ${CMAKE_PROJECT_NAME} )
target_link_libraries( string_unit_test_suite ${CMAKE_PROJECT_NAME} )
target_link_libraries( istream_unit_test_suite ${CMAKE_PROJECT_NAME} )
target_link_libraries( checksum_unit_test_suite ${CMAKE_PROJECT_NAME} ) 
target_link_libraries( unique_id_unit_test_suite ${CMAKE_PROJECT_NAME} )

#
# Setup
#
enable_testing( )
add_test( uri_unit_test_suite ${EXECUTABLE_OUTPUT_PATH}/uri_unit_test_suite )
add_test( map_unit_test_suite ${EXECUTABLE_OUTPUT_PATH}/map_unit_test_suite )
add_test( http_unit_test_suite ${EXECUTABLE_OUTPUT_PATH}/date_unit_test_suite )
add_test( date_unit_test_suite ${EXECUTABLE_OUTPUT_PATH}/date_unit_test_suite )
add_test( regex_unit_test_suite ${EXECUTABLE_OUTPUT_PATH}/regex_unit_test_suite )
add_test( string_unit_test_suite ${EXECUTABLE_OUTPUT_PATH}/string_unit_test_suite )
add_test( istream_unit_test_suite ${EXECUTABLE_OUTPUT_PATH}/istream_unit_test_suite )
add_test( checksum_unit_test_suite ${EXECUTABLE_OUTPUT_PATH}/checksum_unit_test_suite )
add_test( unique_id_unit_test_suite ${EXECUTABLE_OUTPUT_PATH}/unique_id_unit_test_suite )
