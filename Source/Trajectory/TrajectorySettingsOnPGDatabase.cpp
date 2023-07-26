#include "TrajectorySettingsOnPGDatabase.h"

namespace _NTrajectory
{

TrajectorySettingsOnPGDatabase* TrajectorySettingsOnPGDatabase::defaultInstance = 0;

TrajectorySettingsOnPGDatabase::TrajectorySettingsOnPGDatabase()
    : SettingsOnPGDatabase("TrajSettings")
{

}

}
