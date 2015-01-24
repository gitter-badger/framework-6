/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

#ifndef _FRAMEWORK_DETAIL_UNIQUE_ID_IMPL_H
#define _FRAMEWORK_DETAIL_UNIQUE_ID_IMPL_H 1

//System Includes
#include <chrono>
#include <string>
#include <memory>

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
        
        class UniqueIdImpl
        {
            public:
                //Friends
                
                //Definitions
                
                //Constructors
                UniqueIdImpl( void );
                
                UniqueIdImpl( const UniqueIdImpl& original );
                
                virtual ~UniqueIdImpl( void );
                
                //Functionality
                std::string to_string( void ) const;
                
                static UniqueIdImpl generate( void );
                
                static bool is_valid( const std::string& value );
                
                //Getters
                std::chrono::time_point< std::chrono::system_clock > get_timestamp( void ) const;
                
                //Setters
                void set_id( const std::string& value );
                
                //Operators
                bool operator <( const UniqueIdImpl& value ) const;
                
                bool operator >( const UniqueIdImpl& value ) const;
                
                bool operator ==( const UniqueIdImpl& value ) const;
                
                bool operator !=( const UniqueIdImpl& value ) const;
                
                UniqueIdImpl& operator =( const UniqueIdImpl& value );
                
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
                std::string m_unique_id;
        };
    }
}

#endif  /* _FRAMEWORK_DETAIL_UNIQUE_ID_IMPL_H */
