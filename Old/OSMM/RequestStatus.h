#ifndef __OSMM_REQUESTSTATUS_H__
#define __OSMM_REQUESTSTATUS_H__

#include "Common/Common.h"

namespace OSMM
{

	enum RequestStatus
	{
		SUCCESS,
		FAILED,
		NOTFOUND
	};

	static inline QString GetRequestStatusString(RequestStatus request_status)
	{
		static QString request_statuses[] =
		{
			"SUCCESS",
			"FAILED",
			"NOTFOUND"
		};

		return request_statuses[(int)request_status];
	}

}

#endif // __OSMM_REQUESTSTATUS_H__
