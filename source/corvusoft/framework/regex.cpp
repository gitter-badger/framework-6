/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes

//Project Includes
#include "corvusoft/framework/regex.h"
#include "corvusoft/framework/string.h"
#include "corvusoft/framework/detail/regex_impl.h"

//External Includes

//System Namespaces
using std::string;
using std::unique_ptr;

//Project Namespaces
using framework::detail::RegexImpl;

//External Namespaces

namespace framework
{
    Regex::Regex( void ) : m_pimpl( new RegexImpl( String::empty ) )
    {
        return;
    }
    
    Regex::Regex( const char* pattern, const int options ) : m_pimpl( new RegexImpl( pattern, options ) )
    {
        return;
    }
    
    Regex::Regex( const string& pattern, const int options ) : m_pimpl( new RegexImpl( pattern.data( ), options ) )
    {
        return;
    }
    
    Regex::Regex( const Regex& original ) : m_pimpl( new RegexImpl( *original.m_pimpl ) )
    {
        return;
    }
    
    Regex::~Regex( void )
    {
        return;
    }
    
    string Regex::to_string( void ) const
    {
        return m_pimpl->to_string( );
    }
    
    bool Regex::is_match( const string& value )
    {
        return m_pimpl->is_match( value );
    }
    
    bool Regex::is_match( const string& value, const string& pattern, const int options )
    {
        return RegexImpl::is_match( value, pattern, options );
    }
    
    bool Regex::is_valid( const string& value )
    {
        return RegexImpl::is_valid( value );
    }
    
    string Regex::escape( const string& value )
    {
        return RegexImpl::escape( value );
    }
    
    Regex& Regex::operator =( const Regex& value )
    {
        *m_pimpl = *value.m_pimpl;
        
        return *this;
    }
    
    bool Regex::operator <( const Regex& value ) const
    {
        return *m_pimpl < *value.m_pimpl;
    }
    
    bool Regex::operator >( const Regex& value ) const
    {
        return *m_pimpl > *value.m_pimpl;
    }
    
    bool Regex::operator ==( const Regex& value ) const
    {
        return *m_pimpl == *value.m_pimpl;
    }
    
    bool Regex::operator !=( const Regex& value ) const
    {
        return *m_pimpl not_eq * value.m_pimpl;
    }
}
