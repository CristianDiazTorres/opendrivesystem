#include "OCSM/EgoTrajectoryCreator.h"
#include "OCSM/KalmanFilterForGPS.h"

namespace OCSM
{

	Common::VehiclePosVec EgoTrajectoryCreator::ComputeTrajectory(ConstMeasurementContent& content)
	{
		MyCout << "========== Computing trajectories ==========" << MyEndl;

		if (content.isEmpty())
			return Common::VehiclePosVec();

		Common::VehiclePosVec result;

		Common::ConstVehiclePos& first = content[0];

		KalmanFilterForGPS filter;
		filter.Intialize(first.time_seconds, first.x, first.y, first.vx, first.vy, first.hdop);

		for (int i = 0; i < content.size(); i++)
		{
			Common::ConstVehiclePos& pos = content[i];
			ConstDoubleVec& predicted = filter.Predict(pos.time_seconds, pos.x, pos.y, pos.vx, pos.vy, pos.ax, pos.ay);

			result.resize(result.size() + 1);
			result.back().SetFromPredictedPos(pos, predicted[0], predicted[1], predicted[2], predicted[3]);
            MyCout << QString::number(pos.coord.lat, 'f', 10) << " "
                << QString::number(pos.coord.lon, 'f', 10) << " "
                << QString::number(pos.heading, 'f', 10) << " => "
                << QString::number(result.back().coord.lat, 'f', 10) << " "
                << QString::number(result.back().coord.lon, 'f', 10) << " "
                << QString::number(result.back().heading, 'f', 10);
		}

        MyCout << "";

		return result;
	}

}
