/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <regex>
#include <algorithm>

//Project Includes
#include "corvusoft/framework/regex.h"
#include "corvusoft/framework/string_option.h"
#include "corvusoft/framework/detail/string_impl.h"

//External Includes

//System Namespaces
using std::map;
using std::regex;
using std::string;
using std::vector;
using std::smatch;
using std::multimap;
using std::transform;
using std::regex_constants::icase;

//Project Namespaces

//External Namespaces

namespace framework
{
    namespace detail
    {
        const char* StringImpl::empty = "";
        
        Bytes StringImpl::to_bytes( const string& value )
        {
            return Bytes( value.begin( ), value.end( ) );
        }
        
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
        
        string StringImpl::join( const vector< string >& values, const string& delimiter )
        {
            string result = empty;
            
            for ( auto& value : values )
            {
                result += value + delimiter;
            }
            
            return StringImpl::trim_lagging( result, delimiter );
        }
        
        string StringImpl::join( const map< string, string >& values, const string& pair_delimiter, const string& delimiter )
        {
            string result = empty;
            
            for ( auto value : values )
            {
                result += value.first + pair_delimiter + value.second + delimiter;
            }
            
            return StringImpl::trim_lagging( result, delimiter );
        }
        
        string StringImpl::join( const multimap< string, string >& values, const string& pair_delimiter, const string& delimiter )
        {
            string result = empty;
            
            for ( auto value : values )
            {
                result += value.first + pair_delimiter + value.second + delimiter;
            }
            
            return StringImpl::trim_lagging( result, delimiter );
        }
        
        string StringImpl::trim( const string& value, const string& delimiter )
        {
            string result = StringImpl::trim_leading( value, delimiter );

            return StringImpl::trim_lagging( result, delimiter );
        }
        
        string StringImpl::trim_leading( const string& value, const string& delimiter )
        {
            string result = empty;
            
            size_t position = value.find_first_not_of( delimiter );
            
            if ( string::npos not_eq position )
            {
                result = value.substr( position );
            }
            
            return result;
        }
        
        string StringImpl::trim_lagging( const string& value, const string& delimiter )
        {
            string result = empty;
            
            size_t position = value.find_last_not_of( delimiter );
            
            if ( string::npos not_eq position )
            {
                result = value.substr( 0, position + 1 );
            }
            
            return result;
        }
        
        string StringImpl::remove( const string& target, const string& value, const StringOption option )
        {
            return replace( target, empty, value, option );
        }
        
        string StringImpl::replace( const string& target, const string& substitute, const string& value, const StringOption option )
        {
            if ( target.empty( ) )
            {
                return value;
            }
            
            auto expression = Regex::escape( target );
            auto pattern = regex( expression );
            
            if ( option & StringOption::CASE_INSENSITIVE )
            {
                pattern.assign( expression, icase );
            }

            smatch match;
            string result = value;

            while ( regex_search( result, match, pattern ) )
            {
                result = regex_replace( result, pattern, substitute );
            }
            
            return result;
        }
    }
}
