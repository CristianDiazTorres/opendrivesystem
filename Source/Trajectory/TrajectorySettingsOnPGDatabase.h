#pragma once

#include "OSM/Internal/Internal.h"
#include "DB/Main/SettingsOnPGDatabase.h"
#include "Common/Main/DefaultInstance.h"

namespace _NTrajectory
{

class TrajectorySettingsOnPGDatabase : public SettingsOnPGDatabase
{
    _NCM_DEFAULT_INSTANCE_INIT_DECLARE(TrajectorySettingsOnPGDatabase, &, *)

public:
    TrajectorySettingsOnPGDatabase();

public:

};

#define TrajectorySettingsOnPGDatabase_createDefaultInstance    _NTrajectory::TrajectorySettingsOnPGDatabase::createDefaultInstance()
#define TrajectorySettingsOnPGDatabase_initDefaultInstance      _NTrajectory::TrajectorySettingsOnPGDatabase::initDefaultInstance()
#define TrajectorySettingsOnPGDatabase_getDefaultInstance       _NTrajectory::TrajectorySettingsOnPGDatabase::getDefaultInstance()

}
