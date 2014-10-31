# Copyright (c) 2013, 2014 Corvusoft

find_path( gcrypt_INCLUDE gcrypt.h HINTS "${CMAKE_SOURCE_DIR}/dependency/gcrypt/src" "/usr/include" "/usr/local/include" "/opt/local/include" )
find_library( gcrypt_LIBRARY NAMES gcrypt HINTS "${CMAKE_SOURCE_DIR}/dependency/gcrypt/src/.libs" "/usr/lib" "/usr/local/lib" "/opt/local/lib" )

if ( gcrypt_INCLUDE AND gcrypt_LIBRARY )
    set( GCRYPT_FOUND TRUE )

    if ( NOT GCRYPT_FIND_QUIETLY )
        message( STATUS "Found gcrypt header: ${gcrypt_INCLUDE}" )
        message( STATUS "Found gcrypt library: ${gcrypt_LIBRARY}" )
    endif ( )
else ( )
    if ( GCRYPT_FIND_REQUIRED )
        message( FATAL_ERROR "Failed to locate gcrypt!" )
    endif ( )
endif ( )
