#ifndef __OCSM_EXTERNALSOURCEPROVIDER_H__
#define __OCSM_EXTERNALSOURCEPROVIDER_H__

#include "OSMM/Road.h"

namespace OCSM
{
    class DatabaseConnector;

	/*
	 * 4.3 ExternalSourceProvider interfaces
	 * 4.3.1 I/O
	 * 	Input: Modules implementing ExternalSourceProvider shall be supplied with a QVector of GeoCoordinates.
	 * 	Output: Modules implementing ExternalSourceProvider shall output an ExternalRoadData.
	 */

	class ExternalSourceProvider
	{
	protected:
		OSMM::RoadVec m_saved_data;

	public:
		/**
		 * @return ExternalRoadData
		 * @param geocoordinates
		 */
        virtual OSMM::ConstRoadVec& RequestDataForPath(Common::ConstVehiclePosVec& poses, DatabaseConnector& database_connector) = 0;

		inline OSMM::ConstRoadVec& GetSavedData() CONST
		{
			return m_saved_data;
		}
	};

	typedef QVector<ExternalSourceProvider*>	ExternalSourceProviderVec;
	typedef CONST ExternalSourceProviderVec		ConstExternalSourceProviderVec;

}

#endif // __OCSM_EXTERNALSOURCEPROVIDER_H__
