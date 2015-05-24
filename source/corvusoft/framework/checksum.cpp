/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes

//Project Includes
#include "corvusoft/framework/checksum.h"
#include "corvusoft/framework/detail/checksum_impl.h"

//External Includes

//System Namespaces
using std::string;
using std::unique_ptr;

//Project Namespaces
using framework::detail::ChecksumImpl;

//External Namespaces

namespace framework
{
    Checksum::Checksum( const string& hash ) : m_pimpl( new ChecksumImpl )
    {
        m_pimpl->set_checksum( hash );
    }
    
    Checksum::Checksum( const Checksum& original ) : m_pimpl( new ChecksumImpl( *original.m_pimpl ) )
    {
        return;
    }
    
    Checksum::~Checksum( void )
    {
        return;
    }
    
    string Checksum::to_string( void ) const
    {
        return m_pimpl->to_string( );
    }
    
    bool Checksum::is_valid( const string& value )
    {
        return ChecksumImpl::is_valid( value );
    }
    
    Checksum Checksum::generate( const Bytes& value )
    {
        Checksum checksum;
        *checksum.m_pimpl = ChecksumImpl::generate( value );

        return checksum;
    }
    
    Checksum Checksum::generate( const string& value )
    {
        Checksum checksum;
        *checksum.m_pimpl = ChecksumImpl::generate( value );

        return checksum;
    }
    
    Checksum Checksum::parse( const string& hash )
    {
        Checksum checksum;
        checksum.m_pimpl->set_checksum( hash );
        
        return checksum;
    }
    
    Checksum& Checksum::operator =( const Checksum& value )
    {
        *m_pimpl = *value.m_pimpl;
        
        return *this;
    }
    
    bool Checksum::operator <( const Checksum& value ) const
    {
        return *m_pimpl < *value.m_pimpl;
    }
    
    bool Checksum::operator >( const Checksum& value ) const
    {
        return *m_pimpl > *value.m_pimpl;
    }
    
    bool Checksum::operator ==( const Checksum& value ) const
    {
        return *m_pimpl == *value.m_pimpl;
    }
    
    bool Checksum::operator !=( const Checksum& value ) const
    {
        return *m_pimpl not_eq * value.m_pimpl;
    }
    
    Checksum::Checksum( void ) : m_pimpl( new ChecksumImpl )
    {
        return;
    }
}
