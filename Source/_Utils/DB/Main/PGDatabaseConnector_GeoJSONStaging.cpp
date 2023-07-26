#include "DB/Main/PGDatabaseConnector.h"
#include "DB/Main/DatabaseSettingsOnLocalSystem.h"
#include <QSqlQuery>
#include <QSqlResult>
#include <QSqlError>
#include "Debugger/Main/Logger.h"
#include <QThread>
#include "Common/Main/StringContants.h"
#include <QDebug>

namespace _NDB
{

/**********************************************************************/
/* GeoJSON Staging */

bool PGDatabaseConnector::insertGeoJSONStagingLog(const _NDebug::LogInfo& logInfo)
{
    return insertLog("GeoJSONStagingLogs", logInfo);
}

bool PGDatabaseConnector::updateGeoJSONStagingState(const QString& key, const QString& value)
{
    return updateState("GeoJSONStagingStatus", key, value);
}

bool PGDatabaseConnector::getGeoJSONStagingState(const QString& key, QString& value)
{
    return getState("GeoJSONStagingStatus", key, value);
}

bool PGDatabaseConnector::clearGeoJSONStaging()
{
    QString queryString = " CALL sc_ods.\"clearGeoJSONStaging\"(); ";
    return execQuery(queryString).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::clearGeoJSONStagingAndDependencies()
{
    QString queryString = " CALL sc_ods.\"clearGeoJSONStagingAndDependencies\"(); ";
    return execQuery(queryString).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::insertGeoJSONStagingFileData(const QString& geoJSONStagingFilePath, qint64& tableId)
{
    QString queryString;
    queryString += " INSERT INTO sc_ods.\"GeoJSONStagingFileData\" (\"geoJSONStagingFilePath\") VALUES ( ";
    queryString += STR_TO_SQL(geoJSONStagingFilePath);
    queryString += " ) RETURNING id; ";
    return getResult_R1C1(queryString, tableId);
}

bool PGDatabaseConnector::insertGeoJSONStagingNativeData(QString geoJSONStagingFilePath, qint64 geoJSONStagingFileId, QString geom, QString tag, QString json)
{
    QString queryString;
    queryString += " INSERT INTO sc_ods.\"GeoJSONStagingNativeData\" ( \"geoJSONStagingFilePath\", \"geoJSONStagingFileId\" "
                   " , \"geom4326\", \"tag\", \"json\" ) VALUES ( ";
    queryString += STR_TO_SQL(geoJSONStagingFilePath);
    queryString += NUM_TO_SQL_WITH_COMMA(geoJSONStagingFileId);
    queryString += " , ST_GeomFromText(" + STR_TO_SQL(geom) + ", 4326) ";
    queryString += STR_TO_SQL_WITH_COMMA(tag);
    queryString += STR_TO_SQL_WITH_COMMA(json);
    queryString += " ); ";

    return execQuery(queryString, _NDebug::LD_File).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::getGeoJSONStagingNativeDataCountToProcessForApplying(qint64& countToProcess)
{
    QString queryString;
    queryString = " SELECT sc_ods.\"getGeoJSONStagingNativeDataCntToProcForApplying\"(); ";

    return getResult_R1C1(queryString, countToProcess);
}

bool PGDatabaseConnector::getGeoJSONStagingNativeData(const QString& lastProcessedGeoJSONStagingNativeDataId
                                                      , QVector<qint64>& ids
                                                      , StringVec& filePaths
                                                      , QVector<qint64>& fileIds
                                                      , StringVec& jsons)
{
    QString queryString;
    queryString = " SELECT id, \"geoJSONStagingFilePath\", \"geoJSONStagingFileId\", \"json\""
                    " FROM sc_ods.\"GeoJSONStagingNativeData\" WHERE id > ";
    queryString += lastProcessedGeoJSONStagingNativeDataId;
    queryString += " ORDER BY id ";
    queryString += " LIMIT 100; ";

    QSqlQuery sqlQuery = execQuery(queryString);
    if (sqlQuery.lastError().type() != QSqlError::NoError)
        return false;

    if (!sqlQuery.first())
        return true;

    ids.reserve(100);
    filePaths.reserve(100);
    fileIds.reserve(100);
    jsons.reserve(100);

    do
    {
        ids << sqlQuery.value(0).value<qint64>();
        filePaths << sqlQuery.value(1).toString();
        fileIds << sqlQuery.value(2).value<qint64>();
        jsons << sqlQuery.value(3).toString();
    }
    while(sqlQuery.next());

    return true;
}

}
