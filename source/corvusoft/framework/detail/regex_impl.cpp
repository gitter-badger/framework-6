/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <regex>

//Project Includes
#include "corvusoft/framework/detail/regex_impl.h"

//External Includes

//System Namespaces
using std::regex;
using std::string;
using std::regex_error;

//Project Namespaces

//External Namespaces

namespace framework
{
    namespace detail
    {
        bool RegexImpl::is_valid( const string& value )
        {
            bool result = true;
            
            try
            {
                regex pattern( value );
            }
            catch ( regex_error const& re )
            {
                result = false;
            }
            
            return result;
        }
    }
}
