#include "OCSM/OSMMExternalSourceProvider.h"
#include "OSMM/OSMM.h"

namespace OCSM
{

    OSMM::ConstRoadVec& OSMMExternalSourceProvider::RequestDataForPath(Common::ConstVehiclePosVec& poses, DatabaseConnector& database_connector)
	{
		OSMM::Request request;
		request.poses = poses;
        request.database_connector = &database_connector;

		OSMM::OSMModuleRequestResult result = OSMM::RequestDataForPath2(request);
        this->m_saved_data = result.roads;
		return this->m_saved_data;
	}

}
