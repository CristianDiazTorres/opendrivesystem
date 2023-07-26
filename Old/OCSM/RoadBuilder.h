
#ifndef __OCSM_ROADBUILDER_H__
#define __OCSM_ROADBUILDER_H__

#include "Common/VehiclePos.h"
#include "OpenDRIVE/core/OpenDRIVE.h"
#include "OCSM/MeasurementContent.h"
#include "OCSM/DatabaseConnector.h"
#include "OCSM/ExternalSourceProvider.h"

namespace OCSM
{

    /*
     * 4.11 RoadBuilder Module
     * 4.11.1 I/O
     * 	Input: The RoadBuilder module shall be supplied with a RLR, a QVector of (VehiclePose) and a MeasurementContent .
     * 	Output: The RoadBuilder module shall output an Content.
     * 4.11.2 System Level Requirements
     * 	RB-1: the RoadBuilder shall create an Content.
     * 	RB-2: the RoadBuilder shall populate the Content with road details based on measurements.
     * 	RB-3: the RoadBuilder shall use external sources to enrich the Content with road details.
     * 	RB-4: the RoadBuilder shall merge road details comming from measuremnts and external data in case those are conflicting.
     * 4.11.3 Software Level Requirements
     * 	For now this section is purposely left void for more flexibility of implementation. of implementation.
     */

    class RoadBuilder
    {
    public:

        /**
         * @return Content
         * @param rlr
         * @param trajectory
         * @param measurement_content
         */
        OpenDRIVE::OpenDRIVE Build(Common::ConstVehiclePosVec& rlr,
            Common::ConstVehiclePosVec& trajectory,
            ConstMeasurementContent& measurement_content,
            DatabaseConnector& database_connector,
            ConstExternalSourceProviderVec& external_source_providers);

        void makeHeader(DatabaseConnector& database_connector, const QString& name, OpenDRIVE::t_header& header);
        void convertRoadAttr(DatabaseConnector& database_connector, OSMM::ConstRoad& osmm_road, OpenDRIVE::t_road& od_road);
        void convertRoadType(DatabaseConnector& database_connector, OSMM::ConstRoad& osmm_road, OpenDRIVE::t_road& od_road);
        void convertGeometry(DatabaseConnector& database_connector, OSMM::ConstRoad& osmm_road, OpenDRIVE::t_road& od_road);
        void convertLane(DatabaseConnector& database_connector, OSMM::ConstRoad& osmm_road, OpenDRIVE::t_road& od_road);
        void convertWayNodes(DatabaseConnector& database_connector, OSMM::ConstRoad& osmm_road, OpenDRIVE::t_road& od_road);
    };

}

#endif // __OCSM_ROADBUILDER_H__
