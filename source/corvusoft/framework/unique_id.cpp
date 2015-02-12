/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes

//Project Includes
#include "corvusoft/framework/unique_id.h"
#include "corvusoft/framework/detail/unique_id_impl.h"

//External Includes

//System Namespaces
using std::string;
using std::unique_ptr;
using std::chrono::time_point;
using std::chrono::system_clock;

//Project Namespaces
using framework::detail::UniqueIdImpl;

//External Namespaces

namespace framework
{
    UniqueId::UniqueId( const string& value ) : m_pimpl( new UniqueIdImpl )
    {
        m_pimpl->set_id( value );
    }
    
    UniqueId::UniqueId( const UniqueId& original ) : m_pimpl( new UniqueIdImpl( *original.m_pimpl ) )
    {
        return;
    }
    
    UniqueId::UniqueId( const UniqueIdImpl& implementation ) : m_pimpl( new UniqueIdImpl( implementation ) )
    {
        return;
    }
    
    UniqueId::~UniqueId( void )
    {
        return;
    }
    
    string UniqueId::to_string( void ) const
    {
        return m_pimpl->to_string( );
    }
    
    UniqueId UniqueId::generate( void )
    {
        return UniqueIdImpl::generate( );
    }
    
    UniqueId UniqueId::parse( const string& value )
    {
        UniqueId id;
        id.m_pimpl->set_id( value );
        return id;
    }
    
    bool UniqueId::is_valid( const string& value )
    {
        return UniqueIdImpl::is_valid( value );
    }
    
    time_point< system_clock > UniqueId::get_timestamp( void ) const
    {
        return m_pimpl->get_timestamp( );
    }
    
    UniqueId& UniqueId::operator =( const UniqueId& value )
    {
        *m_pimpl = *value.m_pimpl;
        
        return *this;
    }
    
    bool UniqueId::operator <( const UniqueId& value ) const
    {
        return *m_pimpl < *value.m_pimpl;
    }
    
    bool UniqueId::operator >( const UniqueId& value ) const
    {
        return *m_pimpl > *value.m_pimpl;
    }
    
    bool UniqueId::operator ==( const UniqueId& value ) const
    {
        return *m_pimpl == *value.m_pimpl;
    }
    
    bool UniqueId::operator !=( const UniqueId& value ) const
    {
        return *m_pimpl not_eq * value.m_pimpl;
    }
    
    UniqueId::UniqueId( void ) : m_pimpl( new UniqueIdImpl )
    {
        return;
    }
}
