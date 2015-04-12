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
#include <corvusoft/framework/string>

//External Includes

//System Namespaces

//Project Namespaces

//External Namespaces

namespace framework
{
    struct HttpResponse
    {
        Bytes body;
        double version = 0;
        long status_code = 0;
        std::string protocol = String::empty;
        std::string status_message = String::empty;
        std::multimap< std::string, std::string > headers;
    };
}

#endif  /* _FRAMEWORK_HTTP_RESPONSE_H */
