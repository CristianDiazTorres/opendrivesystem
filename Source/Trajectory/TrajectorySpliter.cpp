#include "TrajectorySpliter.h"
#include "Math/Main/ClipperLL.h"
#include "Debugger/Main/Logger.h"
#include "GeoCoordinate/Main/VehiclePos.h"

namespace _NTrajectory
{
typedef _NMath::ClipperLL< qreal, QRectF, double, LL, LL >	Clipper2;


void TrajectorySpliter::split(const VehiclePosVec& trajectory
           , const VehiclePosVec& measurementData
           , VehiclePosVecVec& trajectories
           , VehiclePosVecVec& splitedMeasurementData)
{
    DefaultLogger << "========== Splitting trajectories ==========";

    if (trajectory.isEmpty())
    {
        DefaultLogger << "Total trajectories: 0";
        return;
    }

    trajectories.push_back(VehiclePosVec());
    trajectories.back().push_back(trajectory[0]);

    splitedMeasurementData.push_back(VehiclePosVec());
    splitedMeasurementData.back().push_back(measurementData[0]);

    for (int i = 1; i < trajectory.size(); i++)
    {
        const VehiclePos& prev = trajectories.back().back();
        const VehiclePos& pos = trajectory[i];
        //DefaultLogger << i << ":";
        if (!prev.isOnSameCell(pos))
        {
            //DefaultLogger << "Not same";
            LLVec points;
            points << prev;
            points << pos;

            {
                QRectF prevBound = prev.getCellBoundInDegrees();
                LLVec intersected;
                Clipper2::getClippedLines(prevBound, points, intersected);
                //DefaultLogger << "Inter : " << intersected.size();
                if (!intersected.isEmpty() && intersected.last() != prev)
                {
                    VehiclePos interPos;
                    interPos.setFrom2Poses_Prev(prev, pos, intersected.last());
                    trajectories.back().push_back(interPos);
                }
            }

            trajectories.resize(trajectories.size() + 1);

            {
                QRectF curBound = pos.getCellBoundInDegrees();
                LLVec intersected;
                Clipper2::getClippedLines(curBound, points, intersected);
                //DefaultLogger << "Inter : " << intersected.size();
                if (!intersected.isEmpty() && intersected.first() != pos)
                {
                    VehiclePos interPos;
                    interPos.setFrom2Poses_Next(prev, pos, intersected.last());
                    trajectories.back().push_back(interPos);
                }
            }

            splitedMeasurementData.back().push_back(measurementData[i]);
            splitedMeasurementData.resize(splitedMeasurementData.size() + 1);
            //splitedMeasurementData.back().push_back(measurementData[i - 1]);
        }

        trajectories.back().push_back(pos);

        splitedMeasurementData.back().push_back(measurementData[i]);

        //DefaultLogger << trajectories.size() << ":" << trajectories.back().size();
    }

    DefaultLogger << "Total trajectories: " << trajectories.size();
}

}
