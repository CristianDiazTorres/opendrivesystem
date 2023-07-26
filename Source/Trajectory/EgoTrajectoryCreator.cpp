#include "Trajectory/EgoTrajectoryCreator.h"
#include "Trajectory/KalmanFilter.h"
#include "Debugger/Main/Logger.h"
#include "GeoCoordinate/Main/VehiclePos.h"

namespace _NTrajectory
{

_NGC::VehiclePosVec EgoTrajectoryCreator::computeTrajectory(const _NGC::VehiclePosVec& content)
{
    DefaultLogger << "========== Computing trajectories ========== : " << content.size();

    if (content.isEmpty())
        return _NGC::VehiclePosVec();

    _NGC::VehiclePosVec result;

    const _NGC::VehiclePos& first = content[0];

    KalmanFilter filter;
    filter.intialize(first.timeSeconds, first.x(), first.y(), first.vx, first.vy, first.hdop);

    for (int i = 0; i < content.size(); i++)
    {
        const _NGC::VehiclePos& pos = content[i];
        const DoubleVec& predicted = filter.predict(pos.timeSeconds, pos.x(), pos.y(), pos.vx, pos.vy, pos.ax, pos.ay);

        result.resize(result.size() + 1);
        result.back().setFromPredictedPos(pos, XY(predicted[0], predicted[1]), predicted[2], predicted[3]);
        //DefaultLogger << pos.coord.lat << " "
        //    << pos.coord.lon << " "
        //    << pos.heading << " => "
        //    << result.back().coord.lat
        //    << result.back().coord.lon
        //    << result.back().heading;
    }

    DefaultLogger << "";

    return result;
}

}
