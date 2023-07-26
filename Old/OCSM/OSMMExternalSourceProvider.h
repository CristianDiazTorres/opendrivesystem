#ifndef __OCSM_OSMMEXTERNALSOURCEPROVIDER_H__
#define __OCSM_OSMMEXTERNALSOURCEPROVIDER_H__

#include "OCSM/ExternalSourceProvider.h"

namespace OCSM
{
	/*
	 * 4.3 ExternalSourceProvider interfaces
	 * 4.3.1 I/O
	 * 	Input: Modules implementing ExternalSourceProvider shall be supplied with a QVector of GeoCoordinates.
	 * 	Output: Modules implementing ExternalSourceProvider shall output an ExternalRoadData.
	 */

	class OSMMExternalSourceProvider : public ExternalSourceProvider
	{
	public:
		/**
		 * @return ExternalRoadData
		 * @param geocoordinates
		 */
        OSMM::ConstRoadVec& RequestDataForPath(Common::ConstVehiclePosVec& poses, DatabaseConnector& database_connector);
	};

}

#endif // __OCSM_OSMMEXTERNALSOURCEPROVIDER_H__
