/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

#ifndef _FRAMEWORK_THREADPOOL_H
#define _FRAMEWORK_THREADPOOL_H 1

//System Includes
#include <memory>
#include <functional>

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
        class ThreadPoolImpl;
    }
    
    class ThreadPool
    {
        public:
            //Friends
            
            //Definitions
            typedef std::function< void ( void ) > Task;
            
            //Constructors
            ThreadPool( void );
            
            ThreadPool( const int limit );
            
            virtual ~ThreadPool( void );
            
            //Functionality
            void stop( void );
            
            void start( void );
            
            void schedule( const Task& task );
            
            void join( void );
            
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
            ThreadPool( const ThreadPool& original ) = delete;
            
            //Functionality
            
            //Getters
            
            //Setters
            
            //Operators
            ThreadPool& operator =( const ThreadPool& value ) = delete;
            
            //Properties
            std::unique_ptr< detail::ThreadPoolImpl > m_pimpl;
    };
}

#endif  /* _FRAMEWORK_THREADPOOL_H */
