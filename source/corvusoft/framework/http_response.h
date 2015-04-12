/*
 * Copyright (c) 2013, 2014, 2015 Corvusoft
 */

#ifndef _FRAMEWORK_HTTP_RESPONSE_H
#define _FRAMEWORK_HTTP_RESPONSE_H 1

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
    struct HttpResponse
    {
        Bytes body;
        double version;
        long status_code;
        std::string protocol;
        std::string status_message;
        std::multimap< std::string, std::string > headers;
    };
}

#endif  /* _FRAMEWORK_HTTP_RESPONSE_H */
