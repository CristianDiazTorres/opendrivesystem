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
/* XODR */
bool PGDatabaseConnector::insertXODRLog(const _NDebug::LogInfo& logInfo)
{
    return insertLog("XODRLogs", logInfo);
}

bool PGDatabaseConnector::updateXODRState(const QString& key, const QString& value)
{
    return updateState("XODRStatus", key, value);
}

bool PGDatabaseConnector::getXODRState(const QString& key, QString& value)
{
    return getState("XODRStatus", key, value);
}

bool PGDatabaseConnector::updateXODRState_LastProcessedTrajectorySequentialCellsDataId(const QString& id)
{
    return updateXODRState("lastProcedTrajSeqCellsDataIdForXODR", id);
}

bool PGDatabaseConnector::getXODRState_LastProcessedTrajectorySequentialCellsDataId(QString& id)
{
    return getXODRState("lastProcedTrajSeqCellsDataIdForXODR", id);
}

bool PGDatabaseConnector::clearXODR()
{
    QString queryString = " CALL sc_ods.\"clearXODR\"(); ";
    return execQuery(queryString).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::updateXODRDataAndHist(int cellRow, int cellCol, QString json)
{
    if (!isDBOpen())
        return false;

    QString queryString;
    queryString = " CALL sc_ods.\"updateXODRDataAndHist\"( ";
    queryString += NUM_TO_SQL(cellRow);
    queryString += NUM_TO_SQL_WITH_COMMA(cellCol);
    queryString += STR_TO_SQL_WITH_COMMA(json);
    queryString += " ); ";

    return execQuery(queryString, _NDebug::LD_File).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::updateXODRContent(const Cell &cell, _NOD::OpenDRIVE &odContent)
{
    odContent.header.version = QString::number(odContent.header.version.toDouble() + 0.001);

    odContents.update(cell, odContent);

    QString json = odContent.writeToJson();

    return updateXODRDataAndHist(cell.cellRow, cell.cellCol, json);
}

bool PGDatabaseConnector::getXODRData(int cellRow, int cellCol, QString &json)
{
    QString queryString;
    queryString += " SELECT to_json(content) FROM sc_ods.\"XODRData\" WHERE ";
    queryString += " \"cellRow\" = ";
    queryString += NUM_TO_SQL(cellRow);
    queryString += " AND \"cellCol\" = ";
    queryString += NUM_TO_SQL(cellCol);
    queryString += " LIMIT 1";

    return getResult_R1C1(queryString, json);
}

_NOD::OpenDRIVE PGDatabaseConnector::getXODRContent(const Cell& cell)
{
    if (odContents.exists(cell))
        return odContents.getContent(cell);

    _NOD::OpenDRIVE odContent;
    QString json;

    if (getXODRData(cell.cellRow, cell.cellCol, json))
        odContent.readFromJson(json);

    if (json.isEmpty())
        odContent.init(cell);

    odContents.update(cell, odContent);
    return odContent;
}

bool PGDatabaseConnector::getXODRRecordCount(qint64& count, const QString& latestXODRRecordUpdatedTime)
{
    QString queryString;
    queryString += " SELECT COUNT(*) FROM sc_ods.\"XODRData\" ";
    if (!latestXODRRecordUpdatedTime.isEmpty())
    {
        queryString += " WHERE \"updatedDateTime\" > " + STR_TO_SQL(latestXODRRecordUpdatedTime);
    }

    return getResult_R1C1(queryString, count);
}

bool PGDatabaseConnector::getXODRCellInfo(const QString& prevXODRRecordUpdatedTime, QString& curXODRRecordUpdatedTime, int& cellRow, int& cellCol)
{
    QString queryString;
    queryString += " SELECT CAST(\"updatedDateTime\" AS text), \"cellRow\", \"cellCol\" FROM sc_ods.\"XODRData\" ";
    if (!prevXODRRecordUpdatedTime.isEmpty())
    {
        queryString += " WHERE \"updatedDateTime\" > " + STR_TO_SQL(prevXODRRecordUpdatedTime);
    }
    queryString += " ORDER BY \"updatedDateTime\" LIMIT 1 ";
    return getResult_R1C3(queryString, curXODRRecordUpdatedTime, cellRow, cellCol);
}

bool PGDatabaseConnector::getLatestXODRHistId(qint64& id, int cellRow, int cellCol)
{
    QString queryString;
    queryString += " SELECT sc_ods.\"getLatestXODRHistId\"( ";
    queryString += NUM_TO_SQL(cellRow);
    queryString += NUM_TO_SQL_WITH_COMMA(cellCol);
    queryString += " ) ";
    return getResult_R1C1(queryString, id);
}

}
