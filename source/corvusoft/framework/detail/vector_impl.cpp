/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <algorithm>

//Project Includes
#include "corvusoft/framework/string.h"
#include "corvusoft/framework/detail/vector_impl.h"

//External Includes

//System Namespaces
using std::vector;
using std::string;
using std::find_if;

//Project Namespaces

//External Namespaces

namespace framework
{
    namespace detail
    {
        VectorImpl::iterator VectorImpl::find_ignoring_case( const string& key, vector< string >& container )
        {
            auto identifier = String::lowercase( key );
            
            return find_if( container.begin( ), container.end( ), [ &identifier ]( const string & value )
            {
                return ( identifier == String::lowercase( value ) );
            } );
        }
        
        VectorImpl::const_iterator VectorImpl::find_ignoring_case( const string& key, const vector< string >& container )
        {
            vector< string > items = container;
            
            auto iterator = find_ignoring_case( key, items );
            
            return static_cast< VectorImpl::const_iterator >( iterator );
        }
        
        bool VectorImpl::contains_value_ignoring_case( const string& key, const vector< string >& container )
        {
            return ( find_ignoring_case( key, container ) not_eq container.end( ) );
        }
    }
}
