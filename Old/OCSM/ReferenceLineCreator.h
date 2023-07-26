
#ifndef __OCSM_REFERENCELINECREATOR_H__
#define __OCSM_REFERENCELINECREATOR_H__

#include "Common/VehiclePos.h"
#include "OCSM/MeasurementContent.h"
#include "OCSM/ExternalSourceProvider.h"

namespace OCSM
{

    /*
     * 4.10 ReferenceLineCreator Module
     * 4.10.1 I/O
     * 	Input: The ReferenceLineCreator module shall be supplied with a QVector of VehiclePose and a MeasurementContent.
     * 	Output: The ReferenceLineCreator module shall output a QVector of GeoCoordinates.
     * 4.10.2 System Level Requirements
     * 	RLC-1: the ReferenceLineCreator shall output a list of GeoCoordinates corresponding to the RLR based on supplied trajectory.
     * 	RLC-2: the ReferenceLineCreator shall use measurement data and external source provider (if required) to obtain the RLR.
     * 4.10.3 Software Level Requirements
     * 	RLC-1: Create() shall obtain the distance to the RLR for each VehiclePosition by analyzing measurement data.
     * 	RLC-2: Create() shall derive distance to the RLR using external source when it is not possible to do so from measurements.
    **/

    class ReferenceLineCreator
    {
    public:
        /**
         * @return Common::VehiclePosVec
         * @param trajectory
         * @param measurement_content
         */
        Common::VehiclePosVec Create(Common::ConstVehiclePosVec& trajectory,
            ConstMeasurementContent& content,
            ConstExternalSourceProviderVec& external_source_providers);

    };

}

#endif // __OCSM_REFERENCELINECREATOR_H__

