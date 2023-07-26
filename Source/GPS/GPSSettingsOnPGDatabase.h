#pragma once

#include "OSM/Internal/Internal.h"
#include "DB/Main/SettingsOnPGDatabase.h"
#include "Common/Main/DefaultInstance.h"

namespace _NOSM
{

class GPSSettingsOnPGDatabase : public SettingsOnPGDatabase
{
    _NCM_DEFAULT_INSTANCE_INIT_DECLARE(GPSSettingsOnPGDatabase, &, *)

public:
    GPSSettingsOnPGDatabase();

public:

};

#define GPSSettingsOnPGDatabase_createDefaultInstance    _NOSM::GPSSettingsOnPGDatabase::createDefaultInstance()
#define GPSSettingsOnPGDatabase_initDefaultInstance      _NOSM::GPSSettingsOnPGDatabase::initDefaultInstance()
#define GPSSettingsOnPGDatabase_getDefaultInstance       _NOSM::GPSSettingsOnPGDatabase::getDefaultInstance()

}
