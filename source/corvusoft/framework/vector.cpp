/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes

//Project Includes
#include "corvusoft/framework/vector.h"
#include "corvusoft/framework/detail/vector_impl.h"

//External Includes

//System Namespaces
using std::vector;
using std::string;

//Project Namespaces
using framework::detail::VectorImpl;

//External Namespaces

namespace framework
{
    Vector::iterator Vector::find_ignoring_case( const string& key, vector< string >& container )
    {
        return VectorImpl::find_ignoring_case( key, container );
    }
    
    Vector::const_iterator Vector::find_ignoring_case( const string& key, const vector< string >& container )
    {
        return VectorImpl::find_ignoring_case( key, container );
    }
    
    bool Vector::contains_value_ignoring_case( const string& key, const vector< string >& container )
    {
        return VectorImpl::contains_value_ignoring_case( key, container );
    }
}
