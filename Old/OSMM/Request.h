#ifndef __OSMM_REQUEST_H__
#define __OSMM_REQUEST_H__

#include "Common/VehiclePos.h"

namespace OCSM { class DatabaseConnector; }

namespace OSMM
{
	struct Request
	{
		Common::VehiclePosVec poses;
        OCSM::DatabaseConnector* database_connector;
	};

	typedef CONST Request		ConstRequest;

}

#endif // __OSMM_REQUEST_H__
