/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes

//Project Includes
#include "corvusoft/framework/string.h"
#include "corvusoft/framework/detail/string_impl.h"

//External Includes

//System Namespaces
using std::string;
using std::vector;

//Project Namespaces
using framework::detail::StringImpl;

//External Namespaces

namespace framework
{
    const char* String::empty = StringImpl::empty;
    
    string String::to_string( const Bytes& value )
    {
        return StringImpl::to_string( value );
    }
    
    string String::lowercase( const string& value )
    {
        return StringImpl::lowercase( value );
    }
    
    string String::uppercase( const string& value )
    {
        return StringImpl::uppercase( value );
    }
    
    string String::format( const string format, ... )
    {
        va_list arguments;
        va_start( arguments, format );
        
        string formatted = StringImpl::format( format, arguments );
        
        va_end( arguments );
        
        return formatted;
    }
    
    vector< string > String::split( const string& value, const char delimiter )
    {
        return StringImpl::split( value, delimiter );
    }
    
    string String::trim( const string& value, const string& delimiter )
    {
        return StringImpl::trim( value, delimiter );
    }
    
    string String::trim_leading( const string& value, const string& delimiter )
    {
        return StringImpl::trim_leading( value, delimiter );
    }
    
    string String::trim_lagging( const string& value, const string& delimiter )
    {
        return StringImpl::trim_lagging( value, delimiter );
    }
    
    string String::remove( const string& needle, const string& haystack, bool case_insensitive )
    {
        return StringImpl::remove( needle, haystack, case_insensitive );
    }
    
    string String::replace( const string& needle, const string& substitute, const string& haystack, bool case_insensitive )
    {
        return StringImpl::replace( needle, substitute, haystack, case_insensitive );
    }
}
