/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <iomanip>
#include <sstream>

//Project Includes
#include "corvusoft/framework/date.h"
#include "corvusoft/framework/detail/date_impl.h"

//External Includes

//System Namespaces
using std::string;
using std::chrono::time_point;
using std::chrono::system_clock;

//Project Namespaces
using framework::detail::DateImpl;

//External Namespaces

namespace framework
{
    string Date::format( const time_point< system_clock >& value )
    {
        return DateImpl::format( value );
    }
}
