#include "DB/Main/PGDatabaseConnector.h"
#include "DB/Main/DatabaseSettingsOnLocalSystem.h"
#include <QSqlQuery>
#include <QSqlResult>
#include <QSqlError>
#include "Debugger/Main/Logger.h"
#include <QThread>
#include "Common/Main/StringContants.h"
#include <QDebug>
#include <QDateTime>
#include "Common/Main/DateTime.h"

namespace _NDB
{

/**********************************************************************/
/* GeoJSON Applying */

bool PGDatabaseConnector::insertGeoJSONApplyingLog(const _NDebug::LogInfo& logInfo)
{
    return insertLog("GeoJSONApplyingLogs", logInfo);
}

bool PGDatabaseConnector::updateGeoJSONApplyingState(const QString& key, const QString& value)
{
    return updateState("GeoJSONApplyingStatus", key, value);
}

bool PGDatabaseConnector::getGeoJSONApplyingState(const QString& key, QString& value)
{
    return getState("GeoJSONApplyingStatus", key, value);
}

bool PGDatabaseConnector::updateGeoJSONApplyingState_LastProcessedGeoJSONStagingNativeDataId(const QString& id)
{
    return updateGeoJSONApplyingState("lastProcedGeoJSONStagingNativeDataIdForApplying", id);
}

bool PGDatabaseConnector::getGeoJSONApplyingState_LastProcessedGeoJSONStagingNativeDataId(QString& id)
{
    return getGeoJSONApplyingState("lastProcedGeoJSONStagingNativeDataIdForApplying", id);
}

bool PGDatabaseConnector::clearGeoJSONApplying()
{
    QString queryString = " CALL sc_ods.\"clearGeoJSONApplying\"(); ";
    return execQuery(queryString).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::clearGeoJSONApplyingAndDependencies()
{
    QString queryString = " CALL sc_ods.\"clearGeoJSONApplyingAndDependencies\"(); ";
    return execQuery(queryString).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::insertGeoJSONApplyingData(qint64 nativeDataId
                                                    , QString filePath
                                                    , qint64 fileId
                                                    , QString tag
                                                    , QString json
                                                    , QString operation
                                                    , qint64 histIdBefore
                                                    , QString contentBefore
                                                    , qint64 histIdAfter
                                                    , QString contentAfter)
{
    if (!isDBOpen())
        return false;

    QString queryString;
    queryString = " CALL sc_ods.\"insertGeoJSONApplyingData\"( ";
    queryString += NUM_TO_SQL(nativeDataId);
    queryString += STR_TO_SQL_WITH_COMMA(filePath);
    queryString += NUM_TO_SQL_WITH_COMMA(fileId);
    queryString += STR_TO_SQL_WITH_COMMA(tag);
    queryString += STR_TO_SQL_WITH_COMMA(json);
    queryString += STR_TO_SQL_WITH_COMMA(operation);
    queryString += NUM_TO_SQL_WITH_COMMA(histIdBefore);
    queryString += STR_TO_SQL_WITH_COMMA(contentBefore);
    queryString += NUM_TO_SQL_WITH_COMMA(histIdAfter);
    queryString += STR_TO_SQL_WITH_COMMA(contentAfter);
    queryString += " ); ";

    return execQuery(queryString, _NDebug::LD_File).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::getGeoJSONApplyingRecordCount(qint64& countToProcess, const QString& latestGeoJSONApplyingRecordUpdatedTime)
{
    QString queryString;
    queryString += " SELECT COUNT(*) FROM sc_ods.\"GeoJSONApplyingData\" ";
    if (!latestGeoJSONApplyingRecordUpdatedTime.isEmpty())
    {
        queryString += " WHERE \"updatedDateTime\" > " + STR_TO_SQL(latestGeoJSONApplyingRecordUpdatedTime);
    }

    return getResult_R1C1(queryString, countToProcess);
}

bool PGDatabaseConnector::getGeoJSONApplyingRecord(const QString& prevGeoJSONApplyingRecordUpdatedTime
                              , QString& curGeoJSONApplyingRecordUpdatedTime
                              , qint64& id
                              , QString& geoJSONStagingFilePath
                              , QString& tag
                              , QString& json
                              , QString& operation
                              , QString& contentBefore
                              , QString& contentAfter)
{
    QString queryString;
    queryString += " SELECT CAST(\"updatedDateTime\" AS text), id, \"geoJSONStagingFilePath\", \"tag\", \"json\", \"operation\", to_json(\"contentBefore\"), to_json(\"contentAfter\") FROM sc_ods.\"GeoJSONApplyingData\" ";
    if (!prevGeoJSONApplyingRecordUpdatedTime.isEmpty())
    {
        queryString += " WHERE \"updatedDateTime\" > " + STR_TO_SQL(prevGeoJSONApplyingRecordUpdatedTime);
    }
    queryString += " ORDER BY \"updatedDateTime\" LIMIT 1 ";
    return getResult_R1C8(queryString, curGeoJSONApplyingRecordUpdatedTime, id, geoJSONStagingFilePath, tag, json, operation, contentBefore, contentAfter);
}

}
