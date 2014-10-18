# Copyright (c) 2013, 2014 Corvusoft

project( "unit test suite" )

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
add_executable( constant_find_key_ignoring_case_segmentation_fault_regression_test_suite ${SOURCE_DIR}/constant_find_key_ignoring_case_segmentation_fault_regression_test_suite.cpp )

target_link_libraries( constant_find_key_ignoring_case_segmentation_fault_regression_test_suite ${CMAKE_PROJECT_NAME} ${gtest_LIBRARY} ${gtest_MAIN_LIBRARY} )

#
# Setup
#
enable_testing( )
add_test( constant_find_key_ignoring_case_segmentation_fault_regression_test_suite ${EXECUTABLE_OUTPUT_PATH}/constant_find_key_ignoring_case_segmentation_fault_regression_test_suite )
