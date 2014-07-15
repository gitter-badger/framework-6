/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes

//Project Includes
#include "corvusoft/framework/detail/regex_impl.h"

//External Includes

//System Namespaces
using std::regex;
using std::string;
using std::regex_match;
using std::regex_error;

//Project Namespaces

//External Namespaces

namespace framework
{
    namespace detail
    {
        RegexImpl::RegexImpl( const string& pattern ) : m_pattern( pattern ),
            m_expression( regex( pattern ) )
        {
            //n/a
        }
        
        RegexImpl::RegexImpl( const RegexImpl& original ) : m_pattern( original.m_pattern ),
            m_expression( original.m_expression )
        {
            //n/a
        }
        
        RegexImpl::~RegexImpl( void )
        {
            //n/a
        }
        
        string RegexImpl::to_string( void ) const
        {
            return m_pattern;
        }
        
        bool RegexImpl::is_match( const string& value )
        {
            return regex_match( value, m_expression );
        }
        
        bool RegexImpl::is_valid( const string& value )
        {
            bool result = true;
            
            try
            {
                regex pattern( value );
            }
            catch ( regex_error const& re )
            {
                result = false;
            }
            
            return result;
        }
        
        RegexImpl& RegexImpl::operator =( const RegexImpl& value )
        {
            m_pattern = value.m_pattern;
            
            m_expression = value.m_expression;
            
            return *this;
        }
    }
}
