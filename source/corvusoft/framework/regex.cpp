/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes

//Project Includes
#include "corvusoft/framework/regex.h"
#include "corvusoft/framework/detail/regex_impl.h"

//External Includes

//System Namespaces
using std::string;

//Project Namespaces
using framework::detail::RegexImpl;

//External Namespaces

namespace framework
{
    bool Regex::is_valid( const string& value )
    {
        return RegexImpl::is_valid( value );
    }
}
