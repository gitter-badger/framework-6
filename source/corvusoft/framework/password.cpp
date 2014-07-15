/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes

//Project Includes
#include "corvusoft/framework/password.h"
#include "corvusoft/framework/detail/password_impl.h"

//External Includes

//System Namespaces
using std::string;
using std::unique_ptr;

//Project Namespaces
using framework::detail::PasswordImpl;

//External Namespaces

namespace framework
{
    Password::Password( const string& hash ) : m_pimpl( new PasswordImpl )
    {
        m_pimpl->set_password( hash );
    }
    
    Password::Password( const Password& original ) : m_pimpl( new PasswordImpl( *original.m_pimpl ) )
    {
        //n/a
    }
    
    Password::~Password( void )
    {
        //n/a
    }
    
    string Password::to_string( void ) const
    {
        return m_pimpl->to_string( );
    }
    
    Password Password::parse( const string& hash )
    {
        Password password;
        
        password.m_pimpl->set_password( hash );
        
        return password;
    }
    
    Password Password::generate( const ResidentString& cleartext )
    {
        Password password;
        
        *password.m_pimpl = PasswordImpl::generate( cleartext );
        
        return password;
    }
    
    Password Password::generate( const ResidentString& cleartext, const string& salt )
    {
        Password password;
        
        *password.m_pimpl = PasswordImpl::generate( cleartext, salt );
        
        return password;
    }
    
    Password Password::generate( const ResidentString& cleartext, const string& salt, const HashAlgorithm algorithm )
    {
        Password password;
        
        *password.m_pimpl = PasswordImpl::generate( cleartext, salt, algorithm );
        
        return password;
    }
    
    bool Password::operator ==( const Password& value ) const
    {
        return ( *m_pimpl == *value.m_pimpl );
    }
    
    bool Password::operator !=( const Password& value ) const
    {
        return ( *m_pimpl not_eq * value.m_pimpl );
    }
    
    bool Password::operator ==( const ResidentString& cleartext ) const
    {
        return ( *m_pimpl == cleartext );
    }
    
    bool Password::operator !=( const ResidentString& cleartext ) const
    {
        return ( *m_pimpl not_eq cleartext );
    }
    
    Password::Password( void ) : m_pimpl( new PasswordImpl )
    {
        //n/a
    }
    
    Password& Password::operator =( const Password& value )
    {
        *m_pimpl = *value.m_pimpl;
        
        return *this;
    }
    
    bool Password::operator <( const Password& value ) const
    {
        return ( *m_pimpl < *value.m_pimpl );
    }
    
    bool Password::operator >( const Password& value ) const
    {
        return ( *m_pimpl > *value.m_pimpl );
    }
}
