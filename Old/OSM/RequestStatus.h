#ifndef __OSM_REQUESTSTATUS_H__
#define __OSM_REQUESTSTATUS_H__

#include "OSM/Internal.h"

namespace _NOSM
{

enum RequestStatus
{
    SUCCESS,
    FAILED,
    NOTFOUND
};

static inline String GetRequestStatusString(RequestStatus request_status)
{
    static String request_statuses[] =
    {
        "SUCCESS",
        "FAILED",
        "NOTFOUND"
    };

    return request_statuses[(int)request_status];
}

}

#endif // __OSM_REQUESTSTATUS_H__
