/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes

//Project Includes
#include "corvusoft/framework/uri.h"
#include "corvusoft/framework/detail/uri_impl.h"

//External Includes

//System Namespaces
using std::string;

//Project Namespaces
using framework::detail::UriImpl;

//External Namespaces

namespace framework
{
    string Uri::decode( const string& value )
    {
        return UriImpl::decode( value );
    }
    
    string Uri::decode_parameter( const string& value )
    {
        return UriImpl::decode_parameter( value );
    }
}
