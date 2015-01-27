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
        return HttpImpl::get( request );
    }
    
    Http::Response Http::put( const Http::Request& request )
    {
        return HttpImpl::put( request );
    }
    
    Http::Response Http::post( const Http::Request& request )
    {
        return HttpImpl::post( request );
    }
    
    Http::Response Http::destroy( const Http::Request& request )
    {
        return HttpImpl::destroy( request );
    }

    Http::Response Http::trace( const Http::Request& request )
    {
        return HttpImpl::trace( request );
    }

    Http::Response Http::connect( const Http::Request& request )
    {
        return HttpImpl::connect( request );
    }

    Http::Response Http::options( const Http::Request& request )
    {
        return HttpImpl::options( request );
    }
}
