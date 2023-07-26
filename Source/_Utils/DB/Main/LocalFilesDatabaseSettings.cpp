#include "LocalFilesDatabaseSettings.h"
#include <QSettings>
#include "DB/Main/UserSettingsOnPGDatabase.h"

namespace _NDB
{

LocalFilesDatabaseSettings* LocalFilesDatabaseSettings::defaultInstance = 0;

LocalFilesDatabaseSettings::LocalFilesDatabaseSettings()
    : SettingsOnLocalSystem()
{
}

void LocalFilesDatabaseSettings::init()
{
    if (settings)
    {
        delete settings;
        settings = 0;
    }

    settings = new QSettings(UserSettingsOnPGDatabase_getDefaultInstance.getLocalFilesDatabasePath() + "/settings.ini", QSettings::IniFormat);
    settings->sync();
}

QString LocalFilesDatabaseSettings::getLatestXODRRecordUpdatedTimeForXODRFile()
{
    return getValue("LatestXODRRecordUpdatedTimeForXODRFile");
}

void LocalFilesDatabaseSettings::setLatestXODRRecordUpdatedTimeForXODRFile(const QString& dateTime)
{
    setValue("LatestXODRRecordUpdatedTimeForXODRFile", dateTime);
}

QString LocalFilesDatabaseSettings::getLatestXODRRecordUpdatedTimeForJSONFile()
{
    return getValue("LatestXODRRecordUpdatedTimeForJSONFile");
}

void LocalFilesDatabaseSettings::setLatestXODRRecordUpdatedTimeForJSONFile(const QString& dateTime)
{
    setValue("LatestXODRRecordUpdatedTimeForJSONFile", dateTime);
}

QString LocalFilesDatabaseSettings::getLatestGeoJSONApplyingRecordUpdatedTime()
{
    return getValue("LatestGeoJSONApplyingRecordUpdatedTime");
}

void LocalFilesDatabaseSettings::setLatestGeoJSONApplyingRecordUpdatedTime(const QString& dateTime)
{
    setValue("LatestGeoJSONApplyingRecordUpdatedTime", dateTime);
}

}
