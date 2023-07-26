#pragma once

#include "OSM/Internal/Internal.h"
#include "Common/Main/StringContants.h"

namespace _NOSM
{

enum RequestStatus
{
    SUCCESS,
    FAILED,
    NOTFOUND
};

static inline QString getRequestStatusString(RequestStatus request_status)
{
    static QString request_statuses[] =
    {
        _SC_SUCCESS,
        _SC_FAILED,
        _SC_NOTFOUND
    };

    return request_statuses[(int)request_status];
}

}

