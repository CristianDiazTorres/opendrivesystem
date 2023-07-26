
#pragma once

#include "XODR/Internal/Internal.h"

namespace _NTrajectory
{

/*
 * 4.8 TrajectorySpliter Module
 * 4.8.1 I/O
 * 	Input: The TrajectorySpliter module shall be supplied with a QVector of (MeasurementContent).
 * 	Output: The TrajectorySpliter module shall output a QVector of vectorVehiclePose.
 * 4.8.2 System Level Requirements
 * 	TS-1: the TrajectorySpliter shall split a list of VehiclePose into a list of sublist of VehiclePose, so that each sublist only exist on a single SGA.
 * 4.8.3 Software Level Requirements
 * 	TS-1 ::Split() shall put the 1rst element of the input list in a new sublist of VehiclePose.
 * 	TS-2: Split() shall append each next item of the input list to the same sublist unless the next item is in a different SGA.
 * 	TS-3 :Split() shall create a new sublist when the next item is in a different SGA than the previous one.
 */

class TrajectorySpliter
{
public:
    /**
     * @return VehiclePosVecVec
     * @param trajectory
     */
    VehiclePosVecVec split(const VehiclePosVec& trajectory);
    void split(const VehiclePosVec& trajectory
               , const VehiclePosVec& measurementData
               , VehiclePosVecVec& trajectories
               , VehiclePosVecVec& splitedMeasurementData);

};

}

