/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

#ifndef _FRAMEWORK_DETAIL_URI_IMPL_H
#define _FRAMEWORK_DETAIL_URI_IMPL_H 1

//System Includes
#include <string>

//Project Includes

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
        
        class UriImpl
        {
            public:
                //Friends
                
                //Definitions
                
                //Constructor
                
                //Functionality
                static std::string decode( const std::string& value );
            
                static std::string decode_parameter( const std::string& value );
            
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
                UriImpl( void ) = delete;
                
                UriImpl( const UriImpl& original ) = delete;
                
                virtual ~UriImpl( void ) = delete;
                
                //Functionality
                
                //Getters
                
                //Setters
                
                //Operators
                UriImpl& operator =( const UriImpl& value ) = delete;
            
                //Properties
        };
    }
}

#endif  /* _FRAMEWORK_DETAIL_URI_IMPL_H */
