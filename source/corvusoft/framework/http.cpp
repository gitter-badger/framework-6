/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes

//Project Includes
#include "corvusoft/framework/http.h"
#include "corvusoft/framework/detail/http_impl.h"

//External Includes

//System Namespaces
using std::map;
using std::string;

//Project Namespaces
using framework::detail::HttpImpl;

//External Namespaces

namespace framework
{
    Http::Response Http::get( const Http::Request& request )
    {
        return HttpImpl::perform( "GET", request );
    }
    
    Http::Response Http::put( const Http::Request& request )
    {
        return HttpImpl::perform( "PUT", request );
    }

    Http::Response Http::trace( const Http::Request& request )
    {
        return HttpImpl::perform( "TRACE", request );
    }

    Http::Response Http::post( const Http::Request& request )
    {
        return HttpImpl::perform( "POST", request );
    }

    Http::Response Http::head( const Http::Request& request )
    {
        return HttpImpl::perform( "HEAD", request );
    }

    Http::Response Http::patch( const Http::Request& request )
    {
        return HttpImpl::perform( "PATCH", request );
    }

    Http::Response Http::destroy( const Http::Request& request )
    {
        return HttpImpl::perform( "DELETE", request );
    }

    Http::Response Http::connect( const Http::Request& request )
    {
        return HttpImpl::perform( "CONNECT", request );
    }

    Http::Response Http::options( const Http::Request& request )
    {
        return HttpImpl::perform( "OPTIONS", request );
    }
}
