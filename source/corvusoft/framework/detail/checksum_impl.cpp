/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes
#include <regex>
#include <stdexcept>

//Project Includes
#include "corvusoft/framework/string.h"
#include "corvusoft/framework/hexidecimal.h"
#include "corvusoft/framework/detail/checksum_impl.h"

//External Includes
#include <md5.h>

//System Namespaces
using std::regex;
using std::string;
using std::regex_match;
using std::invalid_argument;

//Project Namespaces

//External Namespaces

namespace framework
{
    namespace detail
    {
        ChecksumImpl::ChecksumImpl( void ) : m_checksum( String::empty )
        {
            return;
        }
        
        ChecksumImpl::ChecksumImpl( const ChecksumImpl& original ) : m_checksum( original.m_checksum )
        {
            return;
        }
        
        ChecksumImpl::~ChecksumImpl( void )
        {
            return;
        }
        
        string ChecksumImpl::to_string( void ) const
        {
            return m_checksum;
        }
        
        bool ChecksumImpl::is_valid( const string& value )
        {
            return regex_match( value, regex( "^[0-9a-fA-F]+$" ) );
        }
        
        ChecksumImpl ChecksumImpl::generate( const Bytes& value )
        {
            md5_state_t state;
            md5_byte_t digest[ 16 ];
            md5_init( &state );
            md5_append( &state, ( const md5_byte_t* ) &value[ 0 ], value.size( ) );
            md5_finish( &state, digest );
            
            ChecksumImpl pimpl;
            pimpl.m_checksum = String::lowercase( Hexidecimal::encode( Bytes( digest, digest + 16 ) ) );
            
            return pimpl;
        }
        
        ChecksumImpl ChecksumImpl::generate( const string& value )
        {
            return generate( Bytes( value.begin( ), value.end( ) ) );
        }
        
        void ChecksumImpl::set_checksum( const string& value )
        {
            if ( not is_valid( value ) )
            {
                throw invalid_argument( "Checksum value supplied is not a valid hash: " + value );
            }
            
            m_checksum = value;
        }
        
        bool ChecksumImpl::operator <( const ChecksumImpl& value ) const
        {
            return m_checksum < value.m_checksum;
        }
        
        bool ChecksumImpl::operator >( const ChecksumImpl& value ) const
        {
            return not ( m_checksum < value.m_checksum );
        }
        
        bool ChecksumImpl::operator ==( const ChecksumImpl& value ) const
        {
            return m_checksum == value.m_checksum;
        }
        
        bool ChecksumImpl::operator !=( const ChecksumImpl& value ) const
        {
            return m_checksum not_eq value.m_checksum;
        }
        
        ChecksumImpl& ChecksumImpl::operator =( const ChecksumImpl& value )
        {
            set_checksum( value.m_checksum );
            
            return *this;
        }
    }
}
