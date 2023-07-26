#pragma once

#include "OSM/Internal/Internal.h"
#include "DB/Main/SettingsOnPGDatabase.h"
#include "Common/Main/DefaultInstance.h"

namespace _NOSM
{

class OSMCountryAreaSettingsOnPGDatabase : public SettingsOnPGDatabase
{
    _NCM_DEFAULT_INSTANCE_INIT_DECLARE(OSMCountryAreaSettingsOnPGDatabase, &, *)

public:
    OSMCountryAreaSettingsOnPGDatabase();

public:
    bool haveToGetCountryAreaOnlyForAU();
    void setHaveToGetCountryAreaOnlyForAU(bool onlyForAU);
};

#define OSMCountryAreaSettingsOnPGDatabase_createDefaultInstance    _NOSM::OSMCountryAreaSettingsOnPGDatabase::createDefaultInstance()
#define OSMCountryAreaSettingsOnPGDatabase_initDefaultInstance      _NOSM::OSMCountryAreaSettingsOnPGDatabase::initDefaultInstance()
#define OSMCountryAreaSettingsOnPGDatabase_getDefaultInstance       _NOSM::OSMCountryAreaSettingsOnPGDatabase::getDefaultInstance()

}
