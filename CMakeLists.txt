# Copyright (c) 2013, 2014, 2015 Corvusoft

project( "framework" )

cmake_minimum_required( VERSION 2.8.10 )

#
# Build Options
#
option( BUILD_TESTS "Build all test suites using CTest." OFF )

#
# Configuration
#
include( "${CMAKE_SOURCE_DIR}/cmake/build_configuration.cmake" )

#
# Dependencies
#
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DASIO_STANDALONE=YES" )
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules" )

find_package( md5 REQUIRED )
find_package( ooid REQUIRED )
find_package( asio REQUIRED )

include_directories( ${md5_INCLUDE} ${ooid_INCLUDE} ${asio_INCLUDE} )

#
# Build
#
include( "${CMAKE_SOURCE_DIR}/cmake/build_manifest.cmake" )

include_directories( ${INCLUDE_DIR} )

add_library( ${PROJECT_NAME} SHARED ${BUILD_MANIFEST} )

target_link_libraries( ${PROJECT_NAME} )

#
# Install
#
include( "${CMAKE_SOURCE_DIR}/cmake/build_artifacts.cmake" )

install( FILES ${INCLUDE_DIR}/${PROJECT_NAME} DESTINATION "include" )
install( FILES ${BUILD_ARTIFACTS} DESTINATION "include/corvusoft/${PROJECT_NAME}" )
install( FILES "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_SHARED_LIBRARY_PREFIX}${PROJECT_NAME}${CMAKE_SHARED_LIBRARY_SUFFIX}" DESTINATION "library" )

#
# Test
#
if ( BUILD_TESTS )
    find_package( catch REQUIRED )

    enable_testing( )
    add_subdirectory( "${CMAKE_SOURCE_DIR}/test/unit" "unit-tests" )
    add_subdirectory( "${CMAKE_SOURCE_DIR}/test/regression" "regression-tests" )
    add_subdirectory( "${CMAKE_SOURCE_DIR}/test/integration" "integration-tests" )
endif ( )
