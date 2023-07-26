#pragma once

#include "DB/Main/SettingsOnPGDatabase.h"
#include "Common/Main/DefaultInstance.h"

namespace _NDB
{

class UserSettingsOnPGDatabase : public SettingsOnPGDatabase
{
    Q_OBJECT
    _NCM_DEFAULT_INSTANCE_INIT_DECLARE(UserSettingsOnPGDatabase, &, *)

public:
    UserSettingsOnPGDatabase();

public:
    QString getLocalFilesDatabasePath();
    void setLocalFilesDatabasePath(const QString& path);

    QString getLoggingMiliSleepTime();
    void setLoggingMiliSleepTime(const QString& miliSleepTime);

};

#define UserSettingsOnPGDatabase_createDefaultInstance      _NDB::UserSettingsOnPGDatabase::createDefaultInstance()
#define UserSettingsOnPGDatabase_initDefaultInstance        _NDB::UserSettingsOnPGDatabase::initDefaultInstance()
#define UserSettingsOnPGDatabase_getDefaultInstance         _NDB::UserSettingsOnPGDatabase::getDefaultInstance()

}
