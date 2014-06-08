/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <cstdio>
#include <cstdlib>

//Project Includes
#include "corvusoft/framework/string.h"
#include "corvusoft/framework/detail/uri_impl.h"

//External Includes

//System Namespaces
using std::strtol;
using std::string;
using std::snprintf;

//Project Namespaces

//External Namespaces

namespace framework
{
    namespace detail
    {
        string UriImpl::decode( const string& value )
        {
            const int BASE16 = 16;
            
            string result = String::empty;
            
            for ( string::size_type index = 0; index not_eq value.length( ); index++ )
            {
                if ( value[ index ] == '%' )
                {
                    char hexidecimal[ 3 ] = { 0 };
                    
                    hexidecimal[ 0 ] = value[ ++index ];
                    
                    hexidecimal[ 1 ] = value[ ++index ];
                    
                    char byte = static_cast< char >( strtol( hexidecimal, nullptr, BASE16 ) );
                    
                    result.push_back( byte );
                }
                else
                {
                    result.push_back( value[ index ] );
                }
            }
            
            return result;
        }
        
        string UriImpl::decode_parameter( const string& value )
        {
            string source = String::replace( "+", " ", value );
            
            return UriImpl::decode( source );
        }
    }
}
