#pragma once

#include "DB/Internal/Internal.h"
#include "SettingsOnLocalSystem/Main/SettingsOnLocalSystem.h"
#include "Common/Main/DefaultInstance.h"

namespace _NDB
{

class DatabaseSettingsOnLocalSystem : public SettingsOnLocalSystem
{
    _NCM_DEFAULT_INSTANCE_INIT_DECLARE(DatabaseSettingsOnLocalSystem, &, *)

public:
    DatabaseSettingsOnLocalSystem();

public:
    QString getHost();
    void setHost(const QString& host);
    QString getPort();
    void setPort(const QString& port);
    QString getDBName();
    void setDBName(const QString& dbName);
    QString getDBUser();
    void setDBUser(const QString& user);
    QString getPassword();
    void setPassword(const QString& password);
    QString getAppUser();
    void setAppUser(const QString& user);

    bool isPGSettingsValid();

};

#define DatabaseSettingsOnLocalSystem_createDefaultInstance     _NDB::DatabaseSettingsOnLocalSystem::createDefaultInstance()
#define DatabaseSettingsOnLocalSystem_initDefaultInstance       _NDB::DatabaseSettingsOnLocalSystem::initDefaultInstance()
#define DatabaseSettingsOnLocalSystem_getDefaultInstance        _NDB::DatabaseSettingsOnLocalSystem::getDefaultInstance()

}
