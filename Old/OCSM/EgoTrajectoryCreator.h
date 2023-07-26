
#ifndef __OCSM_EGOTRAJECTORYCREATOR_H__
#define __OCSM_EGOTRAJECTORYCREATOR_H__

#include "Common/VehiclePos.h"
#include "OCSM/MeasurementContent.h"

namespace OCSM
{

    /*
     * 4.7 EgoTrajectoryCreator Module
     * 4.7.1 I/O
     * 	Input: The EgoTrajectoryCreator module shall be supplied with a (NOT: QVector of) MeasurementContent.
     * 	Output: The EgoTrajectoryCreator module shall output a QVector of VehiclePose.
     * 4.7.2 System Level Requirements
     * 	ETC-1: the EgoTrajectoryCreator shall extract the trajectory of the ego vehicle from the list of measurements.
     * 4.7.3 Software Level Requirements
     * 	ETC-1 :: ComputeTrajectory() shall return a QVector of VehiclePose that contains as much object as there are valid keys (time-stamp) in the MeasurementContent.
     * 	ETC-2 :: ComputeTrajectory() shall compute the VehiclePose by reconstruction of inertial navigation data and fuse it with GPS position measurements (e.g. using technique like Kalman Filters for instance).
     * 	ETC-3 :: ComputeTrajectory() shall make the assumption, that for any Vehicle Pose but the last, the pitch of the vehicle must point toward the next VehiclePose unless more reliable assumptions (using e.g. external data sources) can be made.
     * 	ETC-4 :: ComputeTrajectory() shall set the pitch of the last VehiclePose to be the same as the pitch of the previous point, unless more reliable assumptions (using e.g. external data sources) can be made.
    */

    class EgoTrajectoryCreator
    {
    public:
        /**
         * @return Common::VehiclePosVec
         * @param measurements
         */
        Common::VehiclePosVec ComputeTrajectory(ConstMeasurementContent& content);
    };

}

#endif // __OCSM_EGOTRAJECTORYCREATOR_H__

