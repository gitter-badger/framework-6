/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

#ifndef _FRAMEWORK_DETAIL_HTTP_IMPL_H
#define _FRAMEWORK_DETAIL_HTTP_IMPL_H 1

//System Includes

//Project Includes
#include "corvusoft/framework/http.h"
#include "corvusoft/framework/byte.h"

//External Includes

//System Namespaces

//Project Namespaces

//External Namespaces

namespace framework
{
    //Forward Declarations
    
    namespace detail
    {
        //Forward Declarations
        
        class HttpImpl
        {
            public:
                //Friends
                
                //Definitions
                
                //Constructors
                
                //Functionality
                static Http::Response perform( const std::string& method, const Http::Request& request );
            
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
                HttpImpl( void ) = delete;
                
                HttpImpl( const HttpImpl& original ) = delete;
                
                virtual ~HttpImpl( void ) = delete;
                
                //Functionality
                static Http::Response perform( const Http::Request& request );
                
                //Getters
                
                //Setters
                
                //Operators
                HttpImpl& operator =( const HttpImpl& value ) = delete;
                
                //Properties
        };
    }
}

#endif  /* _FRAMEWORK_DETAIL_HTTP_IMPL_H */
