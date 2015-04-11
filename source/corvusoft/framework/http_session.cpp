/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

//System Includes

//Project Includes
#include "corvusoft/framework/uri.h"
#include "corvusoft/framework/http_session.h"
#include "corvusoft/framework/http_request.h"
#include "corvusoft/framework/http_response.h"
#include "corvusoft/framework/detail/http_session_impl.h"

//External Includes

//System Namespaces
using std::queue;
using std::string;
using std::vector;
using std::multimap;
using std::function;
using std::unique_ptr;

//Project Namespaces
using framework::detail::HttpSessionImpl;

//External Namespaces

namespace framework
{
    HttpSession::HttpSession( const Uri& value ) : m_pimpl( new HttpSessionImpl( value ) )
    {
        return;
    }
    
    HttpSession::HttpSession( const HttpSession& original ) : m_pimpl( new HttpSessionImpl( *original.m_pimpl ) )
    {
        return;
    }

    HttpSession::HttpSession( const HttpSessionImpl& implementation ) : m_pimpl( new HttpSessionImpl( implementation ) )
    {
        return;
    }
    
    HttpSession::~HttpSession( void )
    {
        return;
    }

    HttpResponse HttpSession::get( const HttpRequest& value )
    {
        return m_pimpl->perform( "GET", value );
    }

    HttpResponse HttpSession::put( const HttpRequest& value )
    {
        return m_pimpl->perform( "PUT", value );
    }

    HttpResponse HttpSession::post( const HttpRequest& value )
    {
        return m_pimpl->perform( "POST", value );
    }

    HttpResponse HttpSession::trace( const HttpRequest& value )
    {
        return m_pimpl->perform( "TRACE", value );
    }

    HttpResponse HttpSession::destroy( const HttpRequest& value )
    {
        return m_pimpl->perform( "DELETE", value );
    }

    HttpResponse HttpSession::options( const HttpRequest& value )
    {
        return m_pimpl->perform( "OPTIONS", value );
    }

    HttpResponse HttpSession::connect( const HttpRequest& value )
    {
        return m_pimpl->perform( "CONNECT", value );
    }

    void HttpSession::batch( queue< HttpRequest >& requests,
                             const function< bool ( const HttpRequest&, const HttpResponse& ) >& success_handler,
                             const function< bool ( const HttpRequest&, const HttpResponse& ) >& error_handler )
    {
        m_pimpl->batch( requests, success_handler, error_handler );
    }

    void HttpSession::batch( const vector< HttpRequest >& requests,
                             const function< void ( const HttpRequest&, const HttpResponse& ) >& success_handler,
                             const function< void ( const HttpRequest&, const HttpResponse& ) >& error_handler )
    {
        m_pimpl->batch( requests, success_handler, error_handler );
    }

    Uri HttpSession::get_uri( void ) const
    {
        return m_pimpl->get_uri( );
    }

    string HttpSession::get_cookie( const string& name ) const
    {
        return m_pimpl->get_cookie( name );
    }

    multimap< string, string > HttpSession::get_cookies( void ) const
    {
        return m_pimpl->get_cookies( );
    }

    multimap< string, string > HttpSession::get_cookies( const string& name ) const
    {
        return m_pimpl->get_cookies( name );
    }

    string HttpSession::get_header( const string& name )
    {
        return m_pimpl->get_header( name );
    }

    multimap< string, string > HttpSession::get_headers( void ) const
    {
        return m_pimpl->get_headers( );
    }

    multimap< string, string > HttpSession::get_headers( const string& name ) const
    {
        return m_pimpl->get_headers( name );
    }

    void HttpSession::set_cookie( const string& name, const string& value )
    {
        m_pimpl->set_cookie( name, value );
    }

    void HttpSession::set_cookies( const multimap< string, string >& values )
    {
        m_pimpl->set_cookies( values );
    }

    void HttpSession::set_header( const string& name, const string& value )
    {
        m_pimpl->set_header( name, value );
    }

    void HttpSession::set_headers( const multimap< string, string >& values )
    {
        m_pimpl->set_headers( values );
    }

    HttpSession& HttpSession::operator =( const HttpSession& )
    {
        return *this;
    }
}
