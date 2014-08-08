# Copyright (c) 2013, 2014 Corvusoft

project( "integration test suite" )

cmake_minimum_required( VERSION 2.8.10 )

#
# Configuration
#
set( SOURCE_DIR "source" )
set( EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/distribution/binary/test"  )

include_directories( ${gtest_INCLUDE} )

#
# Build
#
add_executable( regex_integration_test_suite ${SOURCE_DIR}/regex_suite.cpp )
add_executable( run_id_integration_test_suite ${SOURCE_DIR}/run_id_suite.cpp )
add_executable( checksum_integration_test_suite ${SOURCE_DIR}/checksum_suite.cpp )
add_executable( password_integration_test_suite ${SOURCE_DIR}/password_suite.cpp )
add_executable( string_integration_test_suite ${SOURCE_DIR}/string_suite.cpp )

target_link_libraries( run_id_integration_test_suite ${CMAKE_PROJECT_NAME} ${gtest_LIBRARY} ${gtest_MAIN_LIBRARY} )
target_link_libraries( regex_integration_test_suite ${CMAKE_PROJECT_NAME} ${gtest_LIBRARY} ${gtest_MAIN_LIBRARY} )
target_link_libraries( checksum_integration_test_suite ${CMAKE_PROJECT_NAME} ${gtest_LIBRARY} ${gtest_MAIN_LIBRARY} ) 
target_link_libraries( password_integration_test_suite ${CMAKE_PROJECT_NAME} ${gtest_LIBRARY} ${gtest_MAIN_LIBRARY} )
target_link_libraries( string_integration_test_suite ${CMAKE_PROJECT_NAME} ${gtest_LIBRARY} ${gtest_MAIN_LIBRARY} )

#
# Setup
#
enable_testing( )
add_test( run_id_integration_test_suite ${EXECUTABLE_OUTPUT_PATH}/run_id_integration_test_suite )
add_test( regex_integration_test_suite ${EXECUTABLE_OUTPUT_PATH}/regex_integration_test_suite )
add_test( checksum_integration_test_suite ${EXECUTABLE_OUTPUT_PATH}/checksum_integration_test_suite )
add_test( password_integration_test_suite ${EXECUTABLE_OUTPUT_PATH}/password_integration_test_suite )
add_test( string_integration_test_suite ${EXECUTABLE_OUTPUT_PATH}/string_integration_test_suite )
