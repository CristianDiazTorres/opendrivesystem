#include "GeoJSONApplyingTestThread.h"
#include "DB/Main/PGDatabaseConnector.h"
#include "DB/Main/UserSettingsOnPGDatabase.h"
#include "DB/Main/LocalFilesDatabaseSettings.h"
#include "Debugger/Main/Logger.h"
#include <QFileInfo>
#include "Common/Main/File.h"
#include <QDir>

namespace _NGeoJSON
{

GeoJSONApplyingTestThread* GeoJSONApplyingTestThread::defaultInstance = 0;

void GeoJSONApplyingTestThread::setParams()
{

}

bool GeoJSONApplyingTestThread::onPreLoop()
{
    setProgress(0);

    if (hasToStop())
        return false;

    QString latestGeoJSONApplyingRecordUpdatedTime = LocalFilesDatabaseSettings_getDefaultInstance.getLatestGeoJSONApplyingRecordUpdatedTime();
    qint64 countToProcess = 0;
    if (!PGDatabaseConnector_getDefaultInstance.getGeoJSONApplyingRecordCount(countToProcess, latestGeoJSONApplyingRecordUpdatedTime))
    {
        DefaultLogger << "Error while getting geojson applying record count";
        return false;
    }

    QString testPath = UserSettingsOnPGDatabase_getDefaultInstance.getLocalFilesDatabasePath() + "/GeoJSON_Test/";

    for (int i = 0; i < countToProcess; i ++)
    {
        qint64 id;
        QString geoJSONStagingFilePath, tag, json, operation, contentBeforeStr, contentAfterStr;
        if (!PGDatabaseConnector_getDefaultInstance.getGeoJSONApplyingRecord(latestGeoJSONApplyingRecordUpdatedTime
                                                                 , latestGeoJSONApplyingRecordUpdatedTime
                                                                 , id
                                                                 , geoJSONStagingFilePath
                                                                 , tag
                                                                 , json
                                                                 , operation
                                                                 , contentBeforeStr
                                                                 , contentAfterStr))
        {
            DefaultLogger << "Error while getting geojson applying info";
            return false;
        }

        //qDebug() << "============" << latestGeoJSONApplyingRecordUpdatedTime;

        /***********************************************************************/

        _NOD::OpenDRIVE contentBefore, contentAfter;
        contentBefore.readFromJson(contentBeforeStr);
        contentAfter.readFromJson(contentAfterStr);

        QString filePrefixPath = testPath + QString::number(id) + "--" + contentAfter.header.name;

        //_NCM::writeToFile(filePrefixPath + "--contentBefore_db_record.json", QString(contentBeforeStr).replace(",\"", "\n,\""));
        //_NCM::writeToFile(filePrefixPath + "--contentBefore_QJson.json", QJsonDocument::fromJson(contentBeforeStr.toUtf8()).toJson());
        //contentBefore.writeToJson(filePrefixPath + "--contentBefore_our_json_io_module.json");
        contentBefore.write(filePrefixPath + "--contentBefore.xodr");

        //_NCM::writeToFile(filePrefixPath + "--contentAfter_db_record.json", QString(contentAfterStr).replace(",\"", "\n,\""));
        //_NCM::writeToFile(filePrefixPath + "--contentAfter_QJson.json", QJsonDocument::fromJson(contentAfterStr.toUtf8()).toJson());
        //contentAfter.writeToJson(filePrefixPath + "--contentAfter_our_json_io_module.json");
        contentAfter.write(filePrefixPath + "--contentAfter.xodr");

        QString description = "id=" + QString::number(id);
        description += "\ngeoJSONStagingFilePath=" + geoJSONStagingFilePath;
        description += "\ntag=" + tag;
        description += "\noperation=" + operation;
        _NCM::writeToFile(filePrefixPath + "--description.txt", description);

        _NCM::writeToFile(filePrefixPath + ".geojson", json);

        /***********************************************************************/

        setProgress((i + 1) * 100 / countToProcess);

        LocalFilesDatabaseSettings_getDefaultInstance.setLatestGeoJSONApplyingRecordUpdatedTime(latestGeoJSONApplyingRecordUpdatedTime);

        if (hasToStop())
            return false;
    }

    DefaultLogger << "Finished !!!";

    setProgress(100);

    return false;
}

}
