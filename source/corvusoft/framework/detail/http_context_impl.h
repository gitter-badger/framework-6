/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

#ifndef _FRAMEWORK_HTTP_CONTEXT_IMPL_H
#define _FRAMEWORK_HTTP_CONTEXT_IMPL_H 1

//System Includes
#include <memory>
#include <functional>

//Project Includes
#include "corvusoft/framework/http_request.h"
#include "corvusoft/framework/http_response.h"

//External Includes
#include <asio.hpp>

//System Namespaces

//Project Namespaces

//External Namespaces

namespace framework
{
    namespace detail
    {
        struct HttpContextImpl
        {
            HttpRequest request;
            HttpResponse response;

            bool has_callbacks = false;

            std::shared_ptr< asio::streambuf > request_buffer;
            std::shared_ptr< asio::streambuf > response_buffer;

            std::shared_ptr< asio::ip::tcp::socket > socket;
            std::shared_ptr< asio::ip::tcp::resolver > resolver;

            std::function< void ( const HttpRequest&, const HttpResponse& ) > error_handler;
            std::function< void ( const HttpRequest&, const HttpResponse& ) > success_handler;

            virtual ~HttpContextImpl( void )
            {
                if ( has_callbacks )
                {
                    if ( response.status_code < 400 )
                    {
                        success_handler( request, response );
                    }
                    else
                    {
                        error_handler( request, response );
                    }
                }
            }
        };
    }
}

#endif  /* _FRAMEWORK_HTTP_CONTEXT_IMPL_H */
