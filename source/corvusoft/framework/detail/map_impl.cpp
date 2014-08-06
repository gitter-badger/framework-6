/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes

//Project Includes
#include "corvusoft/framework/string.h"
#include "corvusoft/framework/detail/map_impl.h"

//External Includes

//System Namespaces
using std::map;
using std::string;

//Project Namespaces

//External Namespaces

namespace framework
{
    namespace detail
    {
        MapImpl::iterator MapImpl::find_key_ignoring_case( const string& key, map< string, string >& container )
        {
            string identifier = String::lowercase( key );
            
            for ( auto value : container )
            {
                if ( identifier == String::lowercase( value.first ) )
                {
                    identifier = value.first;
                    break;
                }
            }
            
            return ( identifier not_eq String::empty ) ? container.find( identifier ) : container.end( );
        }
        
        MapImpl::const_iterator MapImpl::find_key_ignoring_case( const string& key, const map< string, string >& container )
        {
            string identifier = String::lowercase( key );
            
            for ( auto value : container )
            {
                if ( identifier == String::lowercase( value.first ) )
                {
                    identifier = value.first;
                    break;
                }
            }
            
            return ( identifier not_eq String::empty ) ? container.find( identifier ) : container.end( );
        }
    }
}
