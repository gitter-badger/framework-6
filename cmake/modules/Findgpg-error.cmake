# Copyright (c) 2013, 2014 Corvusoft

find_path( gpg-error_INCLUDE gpg-error.h HINTS "/usr/include" "/usr/local/include" "/opt/local/include" )
find_library( gpg-error_LIBRARY NAMES gpg-error HINTS "/usr/lib" "/usr/local/lib" "/opt/local/lib" )

if ( gpg-error_INCLUDE AND gpg-error_LIBRARY )
    set( GPG-ERROR_FOUND TRUE )

    if ( NOT GPG-ERROR_FIND_QUIETLY )
        message( STATUS "Found gpg-error header: ${gpg-error_INCLUDE}" )
        message( STATUS "Found gpg-error library: ${gpg-error_LIBRARY}" )
    endif ( )
else ( )
    if ( GPG-ERROR_FIND_REQUIRED )
        message( FATAL_ERROR "Failed to locate gpg-error!" )
    endif ( )
endif ( )
