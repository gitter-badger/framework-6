/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

#ifndef _FRAMEWORK_DETAIL_HTTP_SESSION_H
#define _FRAMEWORK_DETAIL_HTTP_SESSION_H 1

//System Includes
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <memory>
#include <functional>

//Project Includes
#include <corvusoft/framework/bytes>

//External Includes

//System Namespaces

//Project Namespaces

//External Namespaces

namespace framework
{
    //Forward Declarations
    class Uri;
    struct HttpRequest;
    struct HttpResponse;

    namespace detail
    {
        class HttpSessionImpl;
    }
    
    class HttpSession
    {
        public:
            //Friends
            
            //Definitions

            //Constructors
            HttpSession( const Uri& value );

            HttpSession( const HttpSession& original );

            virtual ~HttpSession( void );
            
            //Functionality
            HttpResponse get( const HttpRequest& value );

            HttpResponse put( const HttpRequest& value );

            HttpResponse post( const HttpRequest& value );

            HttpResponse trace( const HttpRequest& value );

            HttpResponse destroy( const HttpRequest& value );

            HttpResponse options( const HttpRequest& value );

            HttpResponse connect( const HttpRequest& value );

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
            HttpSession& operator =( const HttpSession& value );
            
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
            
            //Getters
            
            //Setters
            
            //Operators
            
            //Properties
            const std::unique_ptr< detail::HttpSessionImpl > m_pimpl;
    };
}

#endif  /* _FRAMEWORK_DETAIL_HTTP_SESSION_H */
