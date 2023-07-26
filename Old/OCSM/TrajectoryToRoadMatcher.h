
#ifndef __OCSM_TRAJECTORYTOROADMATCHER_H__
#define __OCSM_TRAJECTORYTOROADMATCHER_H__

#include "Common/VehiclePos.h"
#include "OpenDRIVE/core/OpenDRIVE.h"

namespace OCSM
{

    /*
     * 4.9 TrajectoryToRoadMatcher Module
     * 4.9.1 I/O
     * 	Input: The TrajectoryToRoadMatcher module shall be supplied with a QVector of points(not MeasurementContent).
     * 	Output: The TrajectoryToRoadMatcher module shall output a boolean.
     * 	Output: The TrajectoryToRoadMatcher module shall output a RLR of the matching road.
     * 4.9.2 System Level Requirements
     * 	TRM-1: the TrajectoryToRoadMatcher shall tell if a list of VehiclePose matches an existing road.
     * 	TRM-2: the TrajectoryToRoadMatcher shall give the RLR of the matching road (if applicable).
     * 4.9.3 Software Level Requirements
     * 	TRM-1 :MatchingRoadForTrajectory shall return true if there exists a matching road within the Content.
     * 	TRM-2 :GetReferenceLineOfMatchingRoad() shall return a list of GeoCoordinates that correspond to the RLR of the matching road stored in the Content.
     * 	TRM-3 ::GetReferenceLineOfMatchingRoad() shall return an empty list of Geo Coordinates if no road matches the supplied trajectory.
     */

    class TrajectoryToRoadMatcher
    {
    public:
        /**
         * @return bool
         * @param trajectory
         */
        bool MatchingRoadForTrajectory(Common::ConstVehiclePosVec& trajectory, OpenDRIVE::OpenDRIVE& content);

        /**
         * @return Common::VehiclePosVec
         * @param trajectory
         */
        Common::VehiclePosVec GetReferenceLineOfMatchingRoad(Common::ConstVehiclePosVec& trajectory, OpenDRIVE::OpenDRIVE& content);

    };

}

#endif // __OCSM_TRAJECTORYTOROADMATCHER_H__
