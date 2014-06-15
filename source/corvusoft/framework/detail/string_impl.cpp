/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <algorithm>

//Project Includes
#include "corvusoft/framework/detail/string_impl.h"

//External Includes

//System Namespaces
using std::string;
using std::vector;
using std::transform;

//Project Namespaces

//External Namespaces

namespace framework
{
    namespace detail
    {
        const char* StringImpl::empty = "";
        
        string StringImpl::to_string( const Bytes& value )
        {
            string result = empty;
            
            for ( const auto byte : value )
            {
                result.push_back( static_cast< char >( byte ) );
            }
            
            return result;
        }
        
        string StringImpl::lowercase( const string& value )
        {
            string result = empty;
            
            transform( value.begin( ), value.end( ), back_inserter( result ), ( int ( * )( int ) )tolower );
            
            return result;
        }
        
        string StringImpl::uppercase( const string& value )
        {
            string result = empty;
            
            transform( value.begin( ), value.end( ), back_inserter( result ), ( int ( * )( int ) )toupper );
            
            return result;
        }
        
        string StringImpl::format( const string format, va_list arguments )
        {
            string formatted = empty;
            string::size_type length = 1024;
            string::size_type required_length = StringImpl::format( formatted, length + 1, format, arguments );
            
            if ( required_length > length )
            {
                StringImpl::format( formatted, required_length + 1, format, arguments );
            }
            
            return formatted;
        }
        
        vector< string > StringImpl::split( const string& value, const char delimiter )
        {
            vector< string > tokens;
            
            string::size_type start = 0;
            string::size_type end = 0;
            
            while ( ( end = value.find( delimiter, start ) ) not_eq string::npos )
            {
                string text = value.substr( start, end - start );
                
                if ( not text.empty( ) )
                {
                    tokens.push_back( text );
                }
                
                start = end + 1;
            }
            
            string token = value.substr( start );
            
            if ( not token.empty( ) )
            {
                tokens.push_back( token );
            }
            
            return tokens;
        }
        
        string StringImpl::trim( const string& value, const string& delimiter )
        {
            string result = empty;
            
            result = StringImpl::trim_leading( value, delimiter );
            
            result = StringImpl::trim_lagging( result, delimiter );
            
            return result;
        }
        
        string StringImpl::trim_leading( const string& value, const string& delimiter )
        {
            string result = value;
            
            size_t position = result.find_first_not_of( delimiter );
            
            if ( string::npos not_eq position )
            {
                result = result.substr( position );
            }
            
            return result;
        }
        
        string StringImpl::trim_lagging( const string& value, const string& delimiter )
        {
            string result = value;
            
            size_t position = result.find_last_not_of( delimiter );
            
            if ( string::npos not_eq position )
            {
                result = result.substr( 0, position + 1 );
            }
            
            return result;
        }
        
        string StringImpl::remove( const string& needle, const string& haystack, bool case_insensitive )
        {
            return replace( needle, empty, haystack, case_insensitive );
        }
        
        string StringImpl::replace( const string& needle, const string& substitute, const string& haystack, bool case_insensitive )
        {
            string target = case_insensitive ? StringImpl::lowercase( needle ) : needle;
            string source = case_insensitive ? StringImpl::lowercase( haystack ) : haystack;
            
            string::size_type index = source.find( target );
            
            if ( index not_eq string::npos )
            {
                source.replace( index, target.length( ), substitute );
            }
            
            return source;
        }
        
        string::size_type StringImpl::format( string& output, const string::size_type length, const string format, va_list arguments )
        {
            char* formatted = new char[ length + 1 ];
            
            int required_length = vsnprintf( formatted, length + 1, format.data( ), arguments );
            
            if ( required_length == -1 )
            {
                required_length = 0;
            }
            
            output = formatted;
            
            delete[ ] formatted;
            
            return required_length;
        }
    }
}
