#ifndef _ROUTERS_HPP_
#define _ROUTERS_HPP_

#include "hv/HttpService.h"

namespace route
{
    void RegisterResources(hv::HttpService& router);
}

#endif