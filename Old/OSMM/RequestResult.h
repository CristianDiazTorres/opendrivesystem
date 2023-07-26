#ifndef __OSMM_REQUESTRESULT_H__
#define __OSMM_REQUESTRESULT_H__

#include "OSMM/RequestStatus.h"
#include "OSMM/Road.h"

namespace OSMM
{

	struct OSMModuleRequestResult
	{
		RequestStatus request_status;
        RoadVec roads;

	public:
		OSMModuleRequestResult()
		{
		}

		OSMModuleRequestResult(RequestStatus request_status)
		{
			this->request_status = request_status;
		}
	};

}

#endif // __OSMM_REQUESTRESULT_H__
