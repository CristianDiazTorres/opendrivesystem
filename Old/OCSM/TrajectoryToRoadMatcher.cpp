#include "OCSM/TrajectoryToRoadMatcher.h"

namespace OCSM
{

	bool TrajectoryToRoadMatcher::MatchingRoadForTrajectory(Common::ConstVehiclePosVec& trajectory, OpenDRIVE::OpenDRIVE& content)
	{
		for (int i = 0; i < trajectory.size(); i++)
		{
            if (!content.CheckPoint(trajectory[i]))
				return false;
		}

		return true;
	}

	Common::VehiclePosVec TrajectoryToRoadMatcher::GetReferenceLineOfMatchingRoad(Common::ConstVehiclePosVec& trajectory, OpenDRIVE::OpenDRIVE& content)
	{
		return content.GetPoints(trajectory);
	}

}
