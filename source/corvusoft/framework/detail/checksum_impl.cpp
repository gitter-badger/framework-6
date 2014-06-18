/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <regex>
#include <stdexcept>

//Project Includes
#include "corvusoft/framework/detail/checksum_impl.h"

//External Includes
#pragma GCC diagnostic ignored "-Wdeprecated-declarations" //See issue tracker #3
#include <gcrypt.h>
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

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
        ChecksumImpl::ChecksumImpl( void ) : m_checksum( "" )
        {
            //n/a
        }
        
        ChecksumImpl::ChecksumImpl( const ChecksumImpl& original ) : m_checksum( original.m_checksum )
        {
            //n/a
        }
        
        ChecksumImpl::~ChecksumImpl( void )
        {
            //n/a
        }
        
        string ChecksumImpl::to_string( void ) const
        {
            return m_checksum;
        }
        
        ChecksumImpl ChecksumImpl::generate( const Bytes& value )
        {
            int hash_size = gcry_md_get_algo_dlen( GCRY_MD_SHA256 );
            
            Byte* hash = new Byte[ hash_size ];
            
            gcry_md_hash_buffer( GCRY_MD_SHA256, hash, &value[0], value.size( ) );
            
            string data = "";
            
            for ( int index = 0; index < hash_size; index++ )
            {
                char hexidecimal[ 3 ] = { 0 };
                
                snprintf( hexidecimal, 3, "%02x", hash[ index ] );
                
                data.append( hexidecimal );
            }
            
            delete[ ] hash;
            
            ChecksumImpl pimpl;
            
            pimpl.m_checksum = data;
            
            return pimpl;
        }
        
        ChecksumImpl ChecksumImpl::generate( const string& value )
        {
            return generate( Bytes( value.begin( ), value.end( ) ) );
        }
        
        void ChecksumImpl::set_checksum( const string& value )
        {
            bool valid = regex_match( value, regex( "^[0-9a-fA-F]+$" ) );
            
            if ( not valid )
            {
                throw invalid_argument( "Checksum value supplied is not a valid hash: " + value );
            }
            
            m_checksum = value;
        }
        
        bool ChecksumImpl::operator <( const ChecksumImpl& rhs ) const
        {
            return ( m_checksum < rhs.m_checksum );
        }
        
        bool ChecksumImpl::operator >( const ChecksumImpl& rhs ) const
        {
            return not ( m_checksum < rhs.m_checksum );
        }
        
        bool ChecksumImpl::operator ==( const ChecksumImpl& rhs ) const
        {
            return ( m_checksum == rhs.m_checksum );
        }
        
        bool ChecksumImpl::operator !=( const ChecksumImpl& rhs ) const
        {
            return ( m_checksum not_eq rhs.m_checksum );
        }
        
        ChecksumImpl& ChecksumImpl::operator =( const ChecksumImpl& rhs )
        {
            set_checksum( rhs.m_checksum );
            
            return *this;
        }
    }
}
