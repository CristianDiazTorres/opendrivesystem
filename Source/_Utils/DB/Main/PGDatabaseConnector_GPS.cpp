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
/* GPS */
bool PGDatabaseConnector::insertGPSLog(const _NDebug::LogInfo& logInfo)
{
    return insertLog("GPSLogs", logInfo);
}

bool PGDatabaseConnector::updateGPSState(const QString& key, const QString& value)
{
    return updateState("GPSStatus", key, value);
}

bool PGDatabaseConnector::getGPSState(const QString& key, QString& value)
{
    return getState("GPSStatus", key, value);
}

bool PGDatabaseConnector::clearGPS()
{
    QString queryString = " CALL sc_ods.\"clearGPS\"(); ";
    return execQuery(queryString).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::clearGPSAndDependencies()
{
    QString queryString = " CALL sc_ods.\"clearGPSAndDependencies\"(); ";
    return execQuery(queryString).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::insertGPSFileData(const QString& gpsFilePath, qint64& tableId)
{
    QString queryString;
    queryString += " INSERT INTO sc_ods.\"GPSFileData\" (\"gpsFilePath\") VALUES ( ";
    queryString += STR_TO_SQL(gpsFilePath);
    queryString += " ) RETURNING id; ";
    return getResult_R1C1(queryString, tableId);
}

bool PGDatabaseConnector::insertGPSNativeData(QString gpsFilePath, qint64 gpsFileId, const _NGPS::NativeGPSData& gpsData)
{
    QString queryString;
    queryString += " INSERT INTO sc_ods.\"GPSNativeData\" ( \"gpsFilePath\", \"gpsFileId\", \"GPS Week\", \"GPS TOW [s]\" "
                   " , \"Pos Mode\", \"INS Mode\", \"Hdg Mode\", \"SVs Tracked\", \"SVs Used\", \"UTC Date\", \"UTC Time\" "
                   " , \"Lat [deg]\", \"Lon [deg]\", \"Alt Ellips [m]\", \"SOG [m/s]\", \"COG [deg]\", \"Hdg [deg]\", \"Vert Vel [m/s]\" "
                   " , \"Roll [deg]\", \"Pitch [deg]\", \"Yaw [deg]\", \"PDOP\", \"HDOP\", \"EHPE [m]\", \"EVPE [m]\", \"Baseline 2D [m]\", \"Baseline 3D [m]\" "
                   " , \"Corr. Age [s]\", \"Delta TOW [ms]\", \"2D Delta Pos [m]\", \"3D Delta Pos [m]\" ) VALUES ( ";
    queryString += STR_TO_SQL(gpsFilePath);
    queryString += NUM_TO_SQL_WITH_COMMA(gpsFileId);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_GPS_Week_A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_GPS_TOW__s__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Pos_Mode_A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_INS_Mode_A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Hdg_Mode_A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_SVs_Tracked_A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_SVs_Used_A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_UTC_Date_A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_UTC_Time_A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Lat__deg__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Lon__deg__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Alt_Ellips__m__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_SOG__m_s__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_COG__deg__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Hdg__deg__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Vert_Vel__m_s__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Roll__deg__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Pitch__deg__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Yaw__deg__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_PDOP]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_HDOP]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_EHPE__m__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_EVPE__m__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Baseline_2D__m__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Baseline_3D__m__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Corr__Age__s__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Delta_TOW__ms__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_2D_Delta_Pos__m__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_3D_Delta_Pos__m__A]);
    queryString += " ); ";

    return execQuery(queryString, _NDebug::LD_File).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::insertGPSValidData(QString gpsFilePath, qint64 gpsFileId, const _NGPS::NativeGPSData& gpsData)
{
    Cell cell;
    cell.setFromLL(LL(gpsData[_SC_Lat__deg__A].toDouble(), gpsData[_SC_Lon__deg__A].toDouble()));

    QString queryString;
    queryString += " CALL sc_ods.\"insertGPSValidData\" ( ";
    queryString += STR_TO_SQL(DatabaseSettingsOnLocalSystem_getDefaultInstance.getAppUser());
    queryString += STR_TO_SQL_WITH_COMMA(gpsFilePath);
    queryString += NUM_TO_SQL_WITH_COMMA(gpsFileId);
    queryString += NUM_TO_SQL_WITH_COMMA(cell.cellRow);
    queryString += NUM_TO_SQL_WITH_COMMA(cell.cellCol);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_GPS_Week_A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_GPS_TOW__s__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Pos_Mode_A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_INS_Mode_A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Hdg_Mode_A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_SVs_Tracked_A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_SVs_Used_A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_UTC_Date_A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_UTC_Time_A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Lat__deg__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Lon__deg__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Alt_Ellips__m__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_SOG__m_s__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_COG__deg__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Hdg__deg__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Vert_Vel__m_s__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Roll__deg__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Pitch__deg__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Yaw__deg__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_PDOP]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_HDOP]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_EHPE__m__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_EVPE__m__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Baseline_2D__m__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Baseline_3D__m__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Corr__Age__s__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_Delta_TOW__ms__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_2D_Delta_Pos__m__A]);
    queryString += STR_TO_SQL_WITH_COMMA(gpsData[_SC_3D_Delta_Pos__m__A]);
    queryString += " ); ";

    return execQuery(queryString, _NDebug::LD_File).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::getGPSValidDataCountToProcessForTrajectory(qint64& countToProcess)
{
    QString queryString;
    queryString = " SELECT sc_ods.\"getGPSValidDataCntToProcForTraj\"(); ";

    return getResult_R1C1(queryString, countToProcess);
}

bool PGDatabaseConnector::getGPSValidDataToProcessForTrajectory(const QString& lastProcessedGPSId, QVector<VehiclePos>& gpsRecords)
{
    QString queryString;
    queryString = " SELECT id, \"gpsFileId\", \"GPS TOW [s]\", \"UTC Date\", \"UTC Time\" "
                    " , \"Lat [deg]\", \"Lon [deg]\", \"SOG [m/s]\", \"Roll [deg]\", \"Pitch [deg]\", \"Yaw [deg]\" "
                    " , \"HDOP\", \"EHPE [m]\", \"EVPE [m]\" "
                    " FROM sc_ods.\"GPSValidData\" WHERE id > ";
    queryString += lastProcessedGPSId;
    queryString += " ORDER BY id ";
    queryString += " LIMIT 100; ";

    QSqlQuery sqlQuery = execQuery(queryString);
    if (sqlQuery.lastError().type() != QSqlError::NoError)
        return false;

    if (!sqlQuery.first())
        return true;

    gpsRecords.reserve(100);

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
        gpsRecords << pos;
    }
    while(sqlQuery.next());

    return true;
}

bool PGDatabaseConnector::getGPSCellsDataCountToProcessForOSMWay(qint64& countToProcess)
{
    QString queryString;
    queryString = " SELECT sc_ods.\"getGPSCellsDataCntToProcForOSMWay\"(); ";

    return getResult_R1C1(queryString, countToProcess);
}

bool PGDatabaseConnector::getGPSCellsDataToProcessForOSMWay(const QString& lastProcessedCellsId, QVector<qint64>& cellsIds, QVector<Cell>& cells)
{
    QString queryString;
    queryString = " SELECT id, \"cellRow\", \"cellCol\" "
                    " FROM sc_ods.\"GPSCellsData\" WHERE id > ";
    queryString += lastProcessedCellsId;
    queryString += " ORDER BY id ";
    queryString += " LIMIT 100; ";

    QSqlQuery sqlQuery = execQuery(queryString);
    if (sqlQuery.lastError().type() != QSqlError::NoError)
        return false;

    if (!sqlQuery.first())
        return true;

    cellsIds.reserve(100);
    cells.reserve(100);

    do
    {
        cellsIds << sqlQuery.value(0).value<qint64>();
        cells << Cell(sqlQuery.value(1).value<qint64>(), sqlQuery.value(2).value<qint64>());
    }
    while(sqlQuery.next());

    return true;
}

bool PGDatabaseConnector::getGPSCellsDataCountToProcessForOSMNode(qint64& countToProcess)
{
    QString queryString;
    queryString = " SELECT sc_ods.\"getGPSCellsDataCntToProcForOSMNode\"(); ";

    return getResult_R1C1(queryString, countToProcess);
}

bool PGDatabaseConnector::getGPSCellsDataToProcessForOSMNode(const QString& lastProcessedCellsId, QVector<qint64>& cellsIds, QVector<Cell>& cells)
{
    QString queryString;
    queryString = " SELECT id, \"cellRow\", \"cellCol\" "
                    " FROM sc_ods.\"GPSCellsData\" WHERE id > ";
    queryString += lastProcessedCellsId;
    queryString += " ORDER BY id ";
    queryString += " LIMIT 100; ";

    QSqlQuery sqlQuery = execQuery(queryString);
    if (sqlQuery.lastError().type() != QSqlError::NoError)
        return false;

    if (!sqlQuery.first())
        return true;

    cellsIds.reserve(100);
    cells.reserve(100);

    do
    {
        cellsIds << sqlQuery.value(0).value<qint64>();
        cells << Cell(sqlQuery.value(1).value<qint64>(), sqlQuery.value(2).value<qint64>());
    }
    while(sqlQuery.next());

    return true;
}

}
