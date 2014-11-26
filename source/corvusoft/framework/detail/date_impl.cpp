/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <ctime>
#include <iomanip>
#include <sstream>
#include <stdexcept>

//Project Includes
#include "corvusoft/framework/string.h"
#include "corvusoft/framework/detail/date_impl.h"

//External Includes

//System Namespaces
using std::tm;
using std::time_t;
using std::string;
using std::mktime;
using std::get_time;
using std::put_time;
using std::ostringstream;
using std::istringstream;
using std::invalid_argument;
using std::chrono::time_point;
using std::chrono::system_clock;

//Project Namespaces

//External Namespaces

namespace framework
{
    namespace detail
    {
        time_point< system_clock > DateImpl::parse( const string& value )
        {
            const static string formats[ 4 ] =
            {
                "%a %b %d %H:%M:%S %Y",
                "%A, %d-%b-%y %H:%M:%S %Z",
                "%a, %d %b %Y %H:%M:%S %Z"
            };
            
            tm datestamp = { };
            istringstream stream( value );
            
            for ( auto format : formats )
            {
                stream >> get_time( &datestamp, format.data( ) );
                
                if ( not stream.fail( ) )
                {
                    break;
                }
            }
            
            if ( stream.fail( ) )
            {
                throw invalid_argument( String::empty );
            }
            
            time_t timestamp = mktime( &datestamp );
            
            return system_clock::from_time_t( timestamp );
        }
        
        string DateImpl::format( const time_point< system_clock >& value )
        {
            time_t timestamp = system_clock::to_time_t( value );
            
            tm time = { };
            gmtime_r( &timestamp, &time );
            
            ostringstream date;
            date << put_time( &time, "%a, %d %b %Y %H:%M:%S GMT" );
            
            return date.str( );
        }
    }
}
