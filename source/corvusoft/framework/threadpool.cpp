/*
 * Copyright (c) 2013, 2014 Corvusoft
 */

//System Includes

//Project Includes
#include "corvusoft/framework/threadpool.h"
#include "corvusoft/framework/detail/threadpool_impl.h"

//External Includes

//System Namespaces
using std::unique_ptr;

//Project Namespaces
using framework::detail::ThreadPoolImpl;

//External Namespaces

namespace framework
{
    ThreadPool::ThreadPool( void ) : m_pimpl( new ThreadPoolImpl )
    {
        //n/a
    }
    
    ThreadPool::ThreadPool( const int limit ) : m_pimpl( new ThreadPoolImpl )
    {
        m_pimpl->set_thread_limit( limit );
    }
    
    ThreadPool::~ThreadPool( void )
    {
        //n/a
    }
    
    void ThreadPool::stop( void )
    {
        m_pimpl->stop( );
    }
    
    void ThreadPool::start( void )
    {
        m_pimpl->start( );
    }
    
    void ThreadPool::schedule( const Task& task )
    {
        m_pimpl->schedule( task );
    }
    
    void ThreadPool::join( void )
    {
        m_pimpl->join( );
    }
}
