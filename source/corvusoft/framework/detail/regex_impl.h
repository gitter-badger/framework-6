/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

#ifndef _FRAMEWORK_DETAIL_REGEX_IMPL_H
#define _FRAMEWORK_DETAIL_REGEX_IMPL_H 1

//System Includes
#include <regex>
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
                RegexImpl( const std::string& pattern );
                
                RegexImpl( const RegexImpl& original );
                
                virtual ~RegexImpl( void );
                
                //Functionality
                std::string to_string( void ) const;
                
                bool is_match( const std::string& value );
                
                static bool is_valid( const std::string& value );
                
                //Getters
                
                //Setters
                
                //Operators
                RegexImpl& operator =( const RegexImpl& value );
                
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
                
                //Functionality
                
                //Getters
                
                //Setters
                
                //Operators
                
                //Properties
                std::string m_pattern;
                
                std::regex m_expression;
        };
    }
}

#endif  /* _FRAMEWORK_DETAIL_REGEX_IMPL_H */
