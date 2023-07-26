#include "UserSettingsOnPGDatabase.h"
#include <QDir>

namespace _NDB
{

UserSettingsOnPGDatabase* UserSettingsOnPGDatabase::defaultInstance = 0;

UserSettingsOnPGDatabase::UserSettingsOnPGDatabase()
    : SettingsOnPGDatabase("_UserSettings")
{
}

QString UserSettingsOnPGDatabase::getLocalFilesDatabasePath()
{
    QString path = getValue("LocalFilesDatabasePath");
    if (!QDir(path).exists())
        QDir().mkpath(path);
    return path;
}

void UserSettingsOnPGDatabase::setLocalFilesDatabasePath(const QString& path)
{
    setValue("LocalFilesDatabasePath", path);
}

QString UserSettingsOnPGDatabase::getLoggingMiliSleepTime()
{
    return getValue("LoggingMiliSleepTime", 100);
}

void UserSettingsOnPGDatabase::setLoggingMiliSleepTime(const QString& miliSleepTime)
{
    setValue("LoggingMiliSleepTime", miliSleepTime);
}

}
