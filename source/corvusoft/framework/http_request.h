/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

#ifndef _FRAMEWORK_HTTP_REQUEST_H
#define _FRAMEWORK_HTTP_REQUEST_H 1

//System Includes
#include <map>
#include <string>

//Project Includes
#include <corvusoft/framework/bytes>

//External Includes

//System Namespaces

//Project Namespaces

//External Namespaces

namespace framework
{
    struct HttpRequest
    {
        Bytes body;
        double version;
        std::string path;
        std::string method;
        std::multimap< std::string, std::string > headers;
    };
}

#endif  /* _FRAMEWORK_HTTP_REQUEST_H */
