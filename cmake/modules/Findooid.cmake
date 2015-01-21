# Copyright (c) 2013, 2014 Corvusoft

find_path( ooid_INCLUDE uuid.h HINTS "${CMAKE_SOURCE_DIR}/dependency/ooid/kashmir" "/usr/include" "/usr/local/include" "/opt/local/include" )

if ( ooid_INCLUDE )
    set( ooid_FOUND TRUE )

    if ( NOT ooid_FIND_QUIETLY )
        message( STATUS "Found ooid header: ${ooid_INCLUDE}" )
    endif ( )
else ( )
    if ( ooid_FIND_REQUIRED )
        message( FATAL_ERROR "Failed to locate ooid!" )
    endif ( )
endif ( )
