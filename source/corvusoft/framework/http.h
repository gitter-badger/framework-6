/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

#ifndef _FRAMEWORK_HTTP_H
#define _FRAMEWORK_HTTP_H 1

//System Includes
#include <map>
#include <string>
#include <cstdint>

//Project Includes
#include <corvusoft/framework/bytes>

//External Includes

//System Namespaces

//Project Namespaces

//External Namespaces

namespace framework
{
    //Forward Delcarations
    
    class Http
    {
        public:
            //Friends
            
            //Definitions
            struct Request
            {
                Bytes body;
                uint16_t port = 80;
                double version = 1.1;
                std::string host = "";
                std::string path = "/";
                std::string method = "GET";
                std::multimap< std::string, std::string > headers;
            };
            
            struct Response
            {
                Bytes body;
                double version = 1.1;
                long status_code = 0;
                std::string status_message = "";
                std::multimap< std::string, std::string > headers;
            };
            
            //Constructors
            
            //Functionality
            static Response get( const Request& request );
            
            static Response put( const Request& request );
            
            static Response post( const Request& request );
            
            static Response destroy( const Request& request );
            
            //Getters
            
            //Setters
            
            //Operators
            
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
            Http( void ) = delete;
            
            Http( const Http& original ) = delete;
            
            virtual ~Http( void ) = delete;
            
            //Functionality
            
            //Getters
            
            //Setters
            
            //Operators
            Http& operator =( const Http& value ) = delete;
            
            //Properties
    };
}

#endif  /* _FRAMEWORK_HTTP_H */
