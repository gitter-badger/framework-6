/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes
#include <stdexcept>

//Project Includes
#include "corvusoft/framework/detail/threadpool_impl.h"

//External Includes

//System Namespaces
using std::mutex;
using std::thread;
using std::function;
using std::shared_ptr;
using std::unique_lock;
using std::invalid_argument;
using std::condition_variable;

//Project Namespaces

//External Namespaces

namespace framework
{
    namespace detail
    {
        ThreadPoolImpl::ThreadPoolImpl( void ) : m_is_active( false ),
            m_tasks_mutex( ),
            m_thread_limit( thread::hardware_concurrency( ) ),
            m_tasks_pending_cv( ),
            m_tasks( ),
            m_workers( )
        {
            //n/a
        }
        
        ThreadPoolImpl::~ThreadPoolImpl( void )
        {
            //n/a
        }
        
        void ThreadPoolImpl::stop( void )
        {
            m_is_active = false;
            
            m_tasks_pending_cv.notify_all( );
            
            join( );
            
            m_workers.clear( );
        }
        
        void ThreadPoolImpl::start( void )
        {
            m_is_active = true;
            
            for ( unsigned int count = 0; count < m_thread_limit; count++ )
            {
                m_workers.push_back( shared_ptr< thread >( new thread( &ThreadPoolImpl::idle_task, this ) ) );
            }
        }
        
        void ThreadPoolImpl::schedule( const function< void ( void ) >& task )
        {
            m_tasks_mutex.lock( );
            
            m_tasks.push_back( task );
            
            m_tasks_mutex.unlock( );
            
            m_tasks_pending_cv.notify_one( );
        }
        
        void ThreadPoolImpl::join( void )
        {
            for ( auto& worker : m_workers )
            {
                worker->join( );
            }
        }
        
        int ThreadPoolImpl::get_thread_limit( void ) const
        {
            return m_thread_limit;
        }
        
        void ThreadPoolImpl::set_thread_limit( const int value )
        {
            if ( value == 0 )
            {
                throw invalid_argument( "Thread limit must be greater than zero." );
            }
            
            m_thread_limit = value;
        }
        
        void ThreadPoolImpl::idle_task( void )
        {
            while ( m_is_active )
            {
                unique_lock< mutex > mtx( m_tasks_mutex );
                
                if ( m_tasks.empty( ) )
                {
                    m_tasks_pending_cv.wait( mtx );
                }
                
                if ( m_is_active and not m_tasks.empty( ) )
                {
                    function< void ( void ) > task = m_tasks.front( );
                    
                    m_tasks.pop_front( );
                    
                    mtx.unlock( );
                    
                    task( );
                }
            }
        }
    }
}
