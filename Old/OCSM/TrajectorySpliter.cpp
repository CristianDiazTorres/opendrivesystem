#include "OCSM/TrajectorySpliter.h"

namespace OCSM
{

	Common::VehiclePosVecVec TrajectorySpliter::Split(Common::ConstVehiclePosVec& trajectory)
	{
		MyCout << "========== Splitting trajectories ==========" << MyEndl;

		if (trajectory.isEmpty())
		{
			MyCout << "Total trajectories: 0" << MyEndl;
			return Common::VehiclePosVecVec();
		}

		Common::VehiclePosVecVec result;
		result.push_back(Common::VehiclePosVec());
		result.back().push_back(trajectory[0]);

		for (int i = 1; i < trajectory.size(); i++)
		{
			Common::ConstVehiclePos& prev = result.back().back();
			Common::ConstVehiclePos& pos = trajectory[i];
			if (!prev.IsSameGrid(pos))
				result.resize(result.size() + 1);

			result.back().push_back(pos);
		}

		MyCout << "Total trajectories: " << result.size() << MyEndl;
		return result;
	}

}