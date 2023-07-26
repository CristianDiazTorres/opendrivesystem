#include "DB/Main/PGDatabaseConnector.h"
#include "DB/Main/DatabaseSettingsOnLocalSystem.h"
#include <QSqlQuery>
#include <QSqlResult>
#include <QSqlError>
#include "Debugger/Main/Logger.h"
#include <QThread>
#include "Common/Main/StringContants.h"
#include <QDebug>
#include "GeoCoordinate/Main/VehiclePos.h"

namespace _NDB
{

/**********************************************************************/
/* Trajectory */
bool PGDatabaseConnector::insertTrajectoryLog(const _NDebug::LogInfo& logInfo)
{
    return insertLog("TrajLogs", logInfo);
}

bool PGDatabaseConnector::updateTrajectoryState(const QString& key, const QString& value)
{
    return updateState("TrajStatus", key, value);
}

bool PGDatabaseConnector::getTrajectoryState(const QString& key, QString& value)
{
    return getState("TrajStatus", key, value);
}

bool PGDatabaseConnector::updateTrajectoryState_LastProcessedGPSValidDataId(const QString& id)
{
    return updateTrajectoryState("lastProcedGPSValidDataIdForTraj", id);
}

bool PGDatabaseConnector::getTrajectoryState_LastProcessedGPSValidDataId(QString& id)
{
    return getTrajectoryState("lastProcedGPSValidDataIdForTraj", id);
}

bool PGDatabaseConnector::clearTrajectory()
{
    QString queryString = " CALL sc_ods.\"clearTraj\"(); ";
    return execQuery(queryString).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::clearTrajectoryAndDependencies()
{
    QString queryString = " CALL sc_ods.\"clearTrajAndDependencies\"(); ";
    return execQuery(queryString).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::insertTrajectoryData(const VehiclePos& pos)
{
    QString queryString;
    queryString += " CALL sc_ods.\"insertTrajData\" ( ";
    queryString += STR_TO_SQL(DatabaseSettingsOnLocalSystem_getDefaultInstance.getAppUser());
    queryString += NUM_TO_SQL_WITH_COMMA(pos.gpsFileId);
    queryString += NUM_TO_SQL_WITH_COMMA(pos.cellRow);
    queryString += NUM_TO_SQL_WITH_COMMA(pos.cellCol);
    queryString += DBL_TO_SQL_WITH_COMMA(pos.gpsTow);
    queryString += STR_TO_SQL_WITH_COMMA(pos.date);
    queryString += STR_TO_SQL_WITH_COMMA(pos.time);
    queryString += DBL_TO_SQL_WITH_COMMA(pos.lat);
    queryString += DBL_TO_SQL_WITH_COMMA(pos.lon);
    queryString += DBL_TO_SQL_WITH_COMMA(pos.sog);
    queryString += DBL_TO_SQL_WITH_COMMA(pos.roll);
    queryString += DBL_TO_SQL_WITH_COMMA(pos.pitch);
    queryString += DBL_TO_SQL_WITH_COMMA(pos.heading);
    queryString += DBL_TO_SQL_WITH_COMMA(pos.hdop);
    queryString += DBL_TO_SQL_WITH_COMMA(pos.ehpe);
    queryString += DBL_TO_SQL_WITH_COMMA(pos.evpe);
    queryString += " ); ";

    return execQuery(queryString, _NDebug::LD_File).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::getTrajectoryDataCountToProcessForXODR(qint64& countToProcess)
{
    QString queryString;
    queryString = " SELECT sc_ods.\"getTrajDataCntToProcForXODR\"(); ";

    return getResult_R1C1(queryString, countToProcess);
}

bool PGDatabaseConnector::getTrajectoryDataToProcessForXODR(QString& lastProcessedTrajectoryCellsId, QVector<VehiclePos>& trajectoryRecords)
{
    QString startId, endId;

    {
        QString queryString;
        queryString = " SELECT id, \"startId\", \"endId\" "
                        " FROM sc_ods.\"TrajSeqCellsData\" WHERE id > ";
        queryString += lastProcessedTrajectoryCellsId;
        queryString += " ORDER BY id LIMIT 1; ";

        QSqlQuery sqlQuery = execQuery(queryString);
        if (sqlQuery.lastError().type() != QSqlError::NoError)
            return false;

        if (!sqlQuery.first())
            return true;

        lastProcessedTrajectoryCellsId = sqlQuery.value(0).toString();
        startId = sqlQuery.value(1).toString();
        endId = sqlQuery.value(2).toString();
    }

    QString queryString;
    queryString = " SELECT id, \"gpsFileId\", \"GPS TOW [s]\", \"UTC Date\", \"UTC Time\" "
                    " , \"Lat [deg]\", \"Lon [deg]\", \"SOG [m/s]\", \"Roll [deg]\", \"Pitch [deg]\", \"Yaw [deg]\" "
                    " , \"HDOP\", \"EHPE [m]\", \"EVPE [m]\" "
                    " FROM sc_ods.\"TrajData\" WHERE id >= ";
    queryString += startId;
    queryString += " AND id <= ";
    queryString += endId;
    queryString += " ORDER BY id; ";

    QSqlQuery sqlQuery = execQuery(queryString);
    if (sqlQuery.lastError().type() != QSqlError::NoError)
        return false;

    if (!sqlQuery.first())
        return true;

    trajectoryRecords.reserve(1000);

    do
    {
        VehiclePos pos;
        pos.id = sqlQuery.value(0).value<qint64>();
        pos.gpsFileId = sqlQuery.value(1).value<qint64>();
        pos.gpsTow = sqlQuery.value(2).toDouble();
        pos.date = sqlQuery.value(3).toString();
        pos.time = sqlQuery.value(4).toString();
        pos.lat = sqlQuery.value(5).toDouble();
        pos.lon = sqlQuery.value(6).toDouble();
        pos.sog = sqlQuery.value(7).toDouble();
        pos.roll = sqlQuery.value(8).toDouble();
        pos.pitch = sqlQuery.value(9).toDouble();
        pos.heading = sqlQuery.value(10).toDouble();
        pos.hdop = sqlQuery.value(11).toDouble();
        pos.ehpe = sqlQuery.value(12).toDouble();
        pos.evpe = sqlQuery.value(13).toDouble();
        pos.updateDerivedProps();
        trajectoryRecords << pos;
    }
    while(sqlQuery.next());

    return true;
}

}
