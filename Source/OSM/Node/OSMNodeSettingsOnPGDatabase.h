#pragma once

#include "OSM/Internal/Internal.h"
#include "DB/Main/SettingsOnPGDatabase.h"
#include "Common/Main/DefaultInstance.h"

namespace _NOSM
{

class OSMNodeSettingsOnPGDatabase : public SettingsOnPGDatabase
{
    _NCM_DEFAULT_INSTANCE_INIT_DECLARE(OSMNodeSettingsOnPGDatabase, &, *)

public:
    OSMNodeSettingsOnPGDatabase();

public:
    QString getJsonPath();
    void setJsonPath(const QString& path);

};

#define OSMNodeSettingsOnPGDatabase_createDefaultInstance    _NOSM::OSMNodeSettingsOnPGDatabase::createDefaultInstance()
#define OSMNodeSettingsOnPGDatabase_initDefaultInstance      _NOSM::OSMNodeSettingsOnPGDatabase::initDefaultInstance()
#define OSMNodeSettingsOnPGDatabase_getDefaultInstance       _NOSM::OSMNodeSettingsOnPGDatabase::getDefaultInstance()

}
