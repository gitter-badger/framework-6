/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

#ifndef _FRAMEWORK_RANGE_H
#define _FRAMEWORK_RANGE_H 1

//System Includes
#include <string>

//Project Includes

//External Includes

//System Namespaces

//Project Namespaces

//External Namespaces

namespace framework
{
    //Forward declarations
    
    template< typename Type, Type minimum, Type maximum >
    class Range
    {
        public:
            //Friends
            
            //Definitions
            typedef Type value_type;
            
            typedef value_type* pointer;
            
            typedef value_type const* const_pointer;
            
            typedef value_type& reference;
            
            typedef value_type const& const_reference;
            
            //Constructors
            Range( Type value ) : m_value( 0 )
            {
                if ( value >= minimum and value <= maximum )
                {
                    m_value = value;
                }
                else
                {
                    throw std::invalid_argument( "Supplied value is out with allowed range " + std::to_string( minimum ) + "-" + std::to_string( maximum ) );
                }
            }
            
            Range( const Range& original ) : m_value( original.m_value )
            {
                //n/a
            }
            
            virtual ~Range( void )
            {
                //n/a
            }
            
            //Functionality
            
            //Getters
            Type get_value( void ) const
            {
                return m_value;
            }
            
            Type get_minimum( void ) const
            {
                return minimum;
            }
            
            Type get_maximum( void ) const
            {
                return maximum;
            }
            
            //Setters
            
            //Operators
            Range& operator =( const Range& value )
            {
                m_value = value.m_value;
                
                return *this;
            }
            
            bool operator <( const Range& value ) const
            {
                return ( m_value < value.m_value );
            }
            
            bool operator >( const Range& value ) const
            {
                return ( m_value > value.m_value );
            }
            
            bool operator ==( const Range& value ) const
            {
                return ( m_value == value.m_value );
            }
            
            bool operator !=( const Range& value ) const
            {
                return ( m_value not_eq value.m_value );
            }
            
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
            Type m_value;
    };
}

#endif  /* _FRAMEWORK_RANGE_H */
