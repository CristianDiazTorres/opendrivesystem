#pragma once

#include "OSM/Internal/Internal.h"
#include "DB/Main/SettingsOnPGDatabase.h"
#include "Common/Main/DefaultInstance.h"

namespace _NOSM
{

class OSMWaySettingsOnPGDatabase : public SettingsOnPGDatabase
{
    _NCM_DEFAULT_INSTANCE_INIT_DECLARE(OSMWaySettingsOnPGDatabase, &, *)

public:
    OSMWaySettingsOnPGDatabase();

public:
    QString getJsonPath();
    void setJsonPath(const QString& path);

};

#define OSMWaySettingsOnPGDatabase_createDefaultInstance    _NOSM::OSMWaySettingsOnPGDatabase::createDefaultInstance()
#define OSMWaySettingsOnPGDatabase_initDefaultInstance      _NOSM::OSMWaySettingsOnPGDatabase::initDefaultInstance()
#define OSMWaySettingsOnPGDatabase_getDefaultInstance       _NOSM::OSMWaySettingsOnPGDatabase::getDefaultInstance()

}
