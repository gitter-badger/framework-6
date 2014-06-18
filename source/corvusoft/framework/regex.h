/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

#ifndef _FRAMEWORK_REGEX_H
#define _FRAMEWORK_REGEX_H 1

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
    
    class Regex
    {
        public:
            //Friends
            
            //Definitions
            
            //Constructors
            
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
            Regex( void ) = delete;
        
            Regex( const Regex& original ) = delete;
        
            virtual ~Regex( void ) = delete;
        
            //Functionality
        
            //Getters
        
            //Setters
        
            //Operators
            Regex& operator =( const Regex& value ) = delete;
        
            //Properties
    };
}

#endif  /* _FRAMEWORK_REGEX_H */
