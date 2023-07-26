#include "DatabaseSettingsOnLocalSystem.h"

namespace _NDB
{

DatabaseSettingsOnLocalSystem* DatabaseSettingsOnLocalSystem::defaultInstance = 0;

DatabaseSettingsOnLocalSystem::DatabaseSettingsOnLocalSystem()
    : SettingsOnLocalSystem("Database")
{
}

QString DatabaseSettingsOnLocalSystem::getHost()
{
    return getValue("Host");
}

void DatabaseSettingsOnLocalSystem::setHost(const QString& host)
{
    setValue("Host", host);
}

QString DatabaseSettingsOnLocalSystem::getPort()
{
    return getValue("Port");
}

void DatabaseSettingsOnLocalSystem::setPort(const QString& port)
{
    setValue("Port", port);
}

QString DatabaseSettingsOnLocalSystem::getDBName()
{
    return getValue("DBName");
}

void DatabaseSettingsOnLocalSystem::setDBName(const QString& dbName)
{
    setValue("DBName", dbName);
}

QString DatabaseSettingsOnLocalSystem::getDBUser()
{
    return getValue("DBUser");
}

void DatabaseSettingsOnLocalSystem::setDBUser(const QString& user)
{
    setValue("DBUser", user);
}

QString DatabaseSettingsOnLocalSystem::getPassword()
{
    return getValue("Password");
}

void DatabaseSettingsOnLocalSystem::setPassword(const QString& password)
{
    setValue("Password", password);
}

QString DatabaseSettingsOnLocalSystem::getAppUser()
{
    return getValue("AppUser");
}

void DatabaseSettingsOnLocalSystem::setAppUser(const QString& user)
{
    setValue("AppUser", user);
}

bool DatabaseSettingsOnLocalSystem::isPGSettingsValid()
{
    return !getHost().isEmpty()
        && !getPort().isEmpty()
        && !getDBName().isEmpty()
        && !getDBUser().isEmpty()
        && !getAppUser().isEmpty();
}

}
