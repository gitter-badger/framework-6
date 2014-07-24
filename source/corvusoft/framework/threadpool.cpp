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
    
    ThreadPool::ThreadPool( const ThreadPool& original ) : m_pimpl( new ThreadPoolImpl( *original.m_pimpl ) )
    {
        //n/a
    }
    
    ThreadPool::ThreadPool( const ThreadPoolImpl& implementation ) : m_pimpl( new ThreadPoolImpl( implementation ) )
    {
        //n/a
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
    
    ThreadPool& ThreadPool::operator =( const ThreadPool& value )
    {
        *this->m_pimpl = *value.m_pimpl;
        
        return *this;
    }
}
