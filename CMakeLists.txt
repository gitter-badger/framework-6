# Copyright (c) 2013, 2014 Corvusoft

project( "framework" )

cmake_minimum_required( VERSION 2.8.10 )

#
# Build Options
#
option( BUILD_TESTS "Build all test suites using CTest." OFF )

#
# Dependencies
#
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules" )

find_package( md5 REQUIRED )
find_package( ooid REQUIRED )
find_package( asio REQUIRED )

include_directories( ${md5_INCLUDE} ${ooid_INCLUDE} ${asio_INCLUDE} )

#
# Configuration
#
set( INCLUDE_DIR "${CMAKE_SOURCE_DIR}/source" )
set( SOURCE_DIR "${INCLUDE_DIR}/corvusoft/${PROJECT_NAME}" )
set( CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/distribution" )
set( LIBRARY_OUTPUT_PATH "${CMAKE_INSTALL_PREFIX}/library" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DASIO_STANDALONE=YES" )

if ( ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" )
    if ( ${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 4.9 )
        message( FATAL_ERROR "\nGCC version < 4.9\nYour systems default compiler is GCC. This project makes use of c++11 features present only in versions of gcc >= 4.9. You can use a different compiler by re-running cmake with the command switch \"-D CMAKE_CXX_COMPILER=<compiler>\" " )
    endif ( )
elseif ( ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang" )
    if ( ${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 3.3 )
        message( FATAL_ERROR "\nClang version < 3.3\nYour systems default compiler is clang. This project makes use of c++11 features present only in versions of clang >= 3.3. You can use a different compiler by re-running cmake with the command switch \"-D CMAKE_CXX_COMPILER=<compiler>\" " )
    else ( )
        set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++" )
    endif ( )
else ( )
    message( FATAL_ERROR "Compiler not supported")
endif ( )

if ( CMAKE_BUILD_TYPE MATCHES Debug )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -O0 -Wall -Wextra -Weffc++ -pedantic" )
else ( )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Weffc++ -pedantic" )
endif ( )

#
# Build
#
include( "${CMAKE_SOURCE_DIR}/cmake/build_manifest.cmake" )

include_directories( ${INCLUDE_DIR} )

add_library( ${PROJECT_NAME} SHARED ${MANIFEST} )

target_link_libraries( ${PROJECT_NAME} ${curl_LIBRARY} )

#
# Install
#
file( MAKE_DIRECTORY "${CMAKE_INSTALL_PREFIX}/library" )
file( MAKE_DIRECTORY "${CMAKE_INSTALL_PREFIX}/include/corvusoft" )

include( "${CMAKE_SOURCE_DIR}/cmake/build_artifacts.cmake" )

install( FILES ${INCLUDE_DIR}/${PROJECT_NAME} DESTINATION "include/" )
install( FILES ${PROJECT_ARTIFACTS} DESTINATION "include/corvusoft/${PROJECT_NAME}" )

#
# Test
#
if ( BUILD_TESTS )
    find_package( catch REQUIRED )

    enable_testing( )
    add_subdirectory( "${CMAKE_SOURCE_DIR}/test/unit" "unit-tests" )
    add_subdirectory( "${CMAKE_SOURCE_DIR}/test/integration" "integration-tests" )
endif ( )
