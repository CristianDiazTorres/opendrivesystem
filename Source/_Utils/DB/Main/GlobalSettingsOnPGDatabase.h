#pragma once

#include "DB/Main/SettingsOnPGDatabase.h"
#include "Common/Main/DefaultInstance.h"

namespace _NDB
{

class GlobalSettingsOnPGDatabase : public SettingsOnPGDatabase
{
    _NCM_DEFAULT_INSTANCE_INIT_DECLARE(GlobalSettingsOnPGDatabase, &, *)

public:
    GlobalSettingsOnPGDatabase();

};

#define GlobalSettingsOnPGDatabase_createDefaultInstance    _NDB::GlobalSettingsOnPGDatabase::createDefaultInstance()
#define GlobalSettingsOnPGDatabase_initDefaultInstance      _NDB::GlobalSettingsOnPGDatabase::initDefaultInstance()
#define GlobalSettingsOnPGDatabase_getDefaultInstance       _NDB::GlobalSettingsOnPGDatabase::getDefaultInstance()

}
