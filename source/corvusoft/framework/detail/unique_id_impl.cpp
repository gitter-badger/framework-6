/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <regex>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <stdexcept>

//Project Includes
#include "corvusoft/framework/string.h"
#include "corvusoft/framework/detail/unique_id_impl.h"

//External Includes
#include <uuid.h>
#include <devrand.h>

//System Namespaces
using std::hex;
using std::regex;
using std::string;
using std::strtol;
using std::stringstream;
using std::chrono::seconds;
using std::invalid_argument;
using std::chrono::time_point;
using std::chrono::system_clock;
using std::chrono::microseconds;
using std::chrono::duration_cast;

//Project Namespaces

//External Namespaces

namespace framework
{
    namespace detail
    {
        UniqueIdImpl::UniqueIdImpl( void ) : m_unique_id( String::empty )
        {
            //n/a
        }
        
        UniqueIdImpl::UniqueIdImpl( const UniqueIdImpl& original ) : m_unique_id( original.m_unique_id )
        {
            //n/a
        }
        
        UniqueIdImpl::~UniqueIdImpl( void )
        {
            //n/a
        }
        
        string UniqueIdImpl::to_string( void ) const
        {
            return m_unique_id;
        }
        
        UniqueIdImpl UniqueIdImpl::generate( void )
        {
            stringstream stream;
            stream << hex << duration_cast< microseconds >( system_clock::now( ).time_since_epoch( ) ).count( );
            string timestamp = stream.str( );
            timestamp.insert( 1, "-" );
            
            kashmir::uuid_t id;
            kashmir::system::DevRand devrandom;
            devrandom >> id;
            
            std::stringstream buffer;
            buffer << id;
            string uuid = buffer.str( );
            
            UniqueIdImpl pimpl;
            pimpl.m_unique_id = uuid.replace( uuid.length( ) - timestamp.length( ), timestamp.length( ), timestamp );
            return pimpl;
        }
        
        bool UniqueIdImpl::is_valid( const string& value )
        {
            return regex_match( value, regex( "^[0-9a-zA-Z]{8,}\\-[0-9a-zA-Z]{4,}\\-[0-9a-zA-Z]{4,}\\-[0-9a-zA-Z]{4,}\\-[0-9a-zA-Z]{12,}$" ) );
        }
        
        time_point< system_clock > UniqueIdImpl::get_timestamp( void ) const
        {
            string timestamp = m_unique_id.substr( m_unique_id.length( ) - 14, m_unique_id.length( ) );
            timestamp = String::remove( "-", timestamp );
            
            return system_clock::from_time_t( duration_cast< seconds >( microseconds( strtol( timestamp.data( ), nullptr, 16 ) ) ).count( ) );
        }
        
        void UniqueIdImpl::set_id( const string& value )
        {
            if ( not is_valid( value ) )
            {
                throw invalid_argument( "Argument is not a valid unique id: " + value );
            }
            
            m_unique_id = value;
        }
        
        bool UniqueIdImpl::operator <( const UniqueIdImpl& value ) const
        {
            string lhs_timestamp = m_unique_id.substr( m_unique_id.length( ) - 14, m_unique_id.length( ) );
            lhs_timestamp = String::remove( "-", lhs_timestamp );
            
            string rhs_timestamp = value.m_unique_id.substr( m_unique_id.length( ) - 14, value.m_unique_id.length( ) );
            rhs_timestamp = String::remove( "-", rhs_timestamp );
            
            return strtol( lhs_timestamp.data( ), nullptr, 16 ) < strtol( rhs_timestamp.data( ), nullptr, 16 );
        }
        
        bool UniqueIdImpl::operator >( const UniqueIdImpl& value ) const
        {
            return not ( *this < value );
        }
        
        bool UniqueIdImpl::operator ==( const UniqueIdImpl& value ) const
        {
            return m_unique_id == value.m_unique_id;
        }
        
        bool UniqueIdImpl::operator !=( const UniqueIdImpl& value ) const
        {
            return m_unique_id not_eq value.m_unique_id;
        }
        
        UniqueIdImpl& UniqueIdImpl::operator =( const UniqueIdImpl& value )
        {
            set_id( value.m_unique_id );
            
            return *this;
        }
    }
}
