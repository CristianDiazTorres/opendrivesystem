#pragma once

#include "DB/Internal/Internal.h"
#include "SettingsOnLocalSystem/Main/SettingsOnLocalSystem.h"

namespace _NDB
{

class LocalFilesDatabaseSettings : public SettingsOnLocalSystem
{
    Q_OBJECT
    _NCM_DEFAULT_INSTANCE_INIT_DECLARE(LocalFilesDatabaseSettings, &, *)

public:
    LocalFilesDatabaseSettings();
    void init();

public:
    QString getLatestXODRRecordUpdatedTimeForXODRFile();
    void setLatestXODRRecordUpdatedTimeForXODRFile(const QString& dateTime);

    QString getLatestXODRRecordUpdatedTimeForJSONFile();
    void setLatestXODRRecordUpdatedTimeForJSONFile(const QString& dateTime);

    QString getLatestGeoJSONApplyingRecordUpdatedTime();
    void setLatestGeoJSONApplyingRecordUpdatedTime(const QString& dateTime);

};

#define LocalFilesDatabaseSettings_createDefaultInstance    _NDB::LocalFilesDatabaseSettings::createDefaultInstance()
#define LocalFilesDatabaseSettings_initDefaultInstance      _NDB::LocalFilesDatabaseSettings::initDefaultInstance()
#define LocalFilesDatabaseSettings_getDefaultInstance       _NDB::LocalFilesDatabaseSettings::getDefaultInstance()

}
