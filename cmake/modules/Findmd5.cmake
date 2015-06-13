# Copyright (c) 2013, 2014, 2015 Corvusoft

find_path( md5_INCLUDE md5.h HINTS "${CMAKE_SOURCE_DIR}/dependency/md5/include" "/usr/include" "/usr/local/include" "/opt/local/include" )

if ( md5_INCLUDE )
    set( MD5_FOUND TRUE )

    if ( NOT md5_FIND_QUIETLY )
        message( STATUS "Found md5 source: ${md5_INCLUDE}" )
    endif ( )
else ( )
    if ( md5_FIND_REQUIRED )
        message( FATAL_ERROR "Failed to locate md5!" )
    endif ( )
endif ( )
