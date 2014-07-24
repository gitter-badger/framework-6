/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

#ifndef _FRAMEWORK_DETAIL_THREADPOOL_IMPL_H
#define _FRAMEWORK_DETAIL_THREADPOOL_IMPL_H 1

//System Includes
#include <list>
#include <mutex>
#include <memory>
#include <thread>
#include <functional>
#include <condition_variable>

//Project Includes

//External Includes

//System Namespaces

//Project Namespaces

//External Namespaces

namespace framework
{
    //Forward Declaration
    
    namespace detail
    {
        //Forward Declaration
        
        class ThreadPoolImpl
        {
            public:
                //Friends
                
                //Definitions
                
                //Constructors
                ThreadPoolImpl( void );
                
                virtual ~ThreadPoolImpl( void );
                
                //Functionality
                void stop( void );
                
                void start( void );
                
                void schedule( const std::function< void ( void ) >& task );
                
                void join( void );
                
                //Getters
                int get_thread_limit( void ) const;
                
                //Setters
                void set_thread_limit( const int value );
                
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
                ThreadPoolImpl( const ThreadPoolImpl& original ) = delete;
                
                //Functionality
                void idle_task( void );
                
                //Getters
                
                //Setters
                
                //Operators
                ThreadPoolImpl& operator =( const ThreadPoolImpl& value ) = delete;
                
                //Properties
                bool m_is_active;
                
                std::mutex m_tasks_mutex;
                
                unsigned int m_thread_limit;
                
                std::condition_variable m_tasks_pending_cv;
                
                std::list< std::function< void ( void ) > > m_tasks;
                
                std::list< std::shared_ptr< std::thread > >  m_workers;
        };
    }
}

#endif  /* _FRAMEWORK_DETAIL_THREADPOOL_IMPL_H */
