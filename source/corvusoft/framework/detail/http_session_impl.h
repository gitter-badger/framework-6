/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

#ifndef _FRAMEWORK_DETAIL_HTTP_SESSION_IMPL_H
#define _FRAMEWORK_DETAIL_HTTP_SESSION_IMPL_H 1

//System Includes
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <memory>
#include <functional>

//Project Includes

//External Includes
#include <asio.hpp>

//System Namespaces

//Project Namespaces

//External Namespaces

namespace framework
{
    //Forward Declarations
    class Uri;
    struct HttpRequest;
    struct HttpResponse;
    struct HttpContextImpl;

    namespace detail
    {
        //Forward Declarations
        
        class HttpSessionImpl
        {
            public:
                //Friends
                
                //Definitions
                
                //Constructors
                HttpSessionImpl( const Uri& value );
                
                HttpSessionImpl( const HttpSessionImpl& original );
                
                virtual ~HttpSessionImpl( void );
                
                //Functionality
                HttpResponse perform( const std::string& method, const HttpRequest& value );

                void batch( std::queue< HttpRequest >& requests,
                            const std::function< bool ( const HttpRequest&, const HttpResponse& ) >& success_handler,
                            const std::function< bool ( const HttpRequest&, const HttpResponse& ) >& error_handler );

                void batch( const std::vector< HttpRequest >& requests,
                            const std::function< void ( const HttpRequest&, const HttpResponse& ) >& success_handler,
                            const std::function< void ( const HttpRequest&, const HttpResponse& ) >& error_handler );
                //Getters
                Uri get_uri( void ) const;

                std::string get_cookie( const std::string& name ) const;

                std::multimap< std::string, std::string > get_cookies( void ) const;

                std::multimap< std::string, std::string > get_cookies( const std::string& name ) const;

                std::string get_header( const std::string& name );

                std::multimap< std::string, std::string > get_headers( void ) const;
                
                std::multimap< std::string, std::string > get_headers( const std::string& name ) const;
                
                //Setters
                void set_cookie( const std::string& name, const std::string& value );

                void set_cookies( const std::multimap< std::string, std::string >& values );

                void set_header( const std::string& name, const std::string& value );

                void set_headers( const std::multimap< std::string, std::string >& values );

                //Operators
                HttpSessionImpl& operator =( const HttpSessionImpl& value );
                
                //Properties
                
            protected:
                //Friends
                
                //Definitions
                
                //Constructors
                
                //Functionality
                
                //Getters
                
                //Setters
                
                //Operators
                
                //Properties
                
            private:
                //Friends
                
                //Definitions
                
                //Constructors
                
                //Functionality
                std::map< std::string, std::string > parse_cookie( const std::string& definition );

                std::shared_ptr< HttpContextImpl > setup( const HttpRequest& request, asio::io_service& service );

                void handle_read_body( const asio::error_code& error, std::shared_ptr< HttpContextImpl >& context  );

                void handle_read_status( const asio::error_code& error, std::shared_ptr< HttpContextImpl >& context );

                void handle_read_headers( const asio::error_code& error, std::shared_ptr< HttpContextImpl >& context );

                void handle_write_request( const asio::error_code& error, std::shared_ptr< HttpContextImpl >& context );

                void handle_connect( const asio::error_code& error,
                                     asio::ip::tcp::resolver::iterator endpoint_iterator,
                                     std::shared_ptr< HttpContextImpl >& context );

                void handle_resolve( const asio::error_code& error,
                                     asio::ip::tcp::resolver::iterator endpoint_iterator,
                                     std::shared_ptr< HttpContextImpl >& context  );
                //Getters
                
                //Setters
                
                //Operators
                
                //Properties
                Uri m_uri;

                std::multimap< std::string, std::string > m_cookies;

                std::multimap< std::string, std::string > m_headers;
        };
    }
}

#endif  /* _FRAMEWORK_DETAIL_HTTP_SESSION_IMPL_H */
