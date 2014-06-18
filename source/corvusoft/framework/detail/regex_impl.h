/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

#ifndef _FRAMEWORK_DETAIL_REGEX_IMPL_H
#define _FRAMEWORK_DETAIL_REGEX_IMPL_H 1

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
        
        class RegexImpl
        {
            public:
                //Friends
                
                //Definitions
                
                //Constructor
                
                //Functionality
                static bool is_valid( const std::string& value );
            
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
                RegexImpl( void ) = delete;
            
                RegexImpl( const RegexImpl& original ) = delete;
            
                virtual ~RegexImpl( void ) = delete;
            
                //Functionality
            
                //Getters
            
                //Setters
            
                //Operators
                RegexImpl& operator =( const RegexImpl& value ) = delete;
            
                //Properties
        };
    }
}

#endif  /* _FRAMEWORK_DETAIL_REGEX_IMPL_H */
