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
/* Logs */
bool PGDatabaseConnector::clearLogs()
{
    QString queryString = " CALL sc_ods.\"clear_LogsOnly\"(); ";
    return execQuery(queryString).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::insertLog(const QString &tableName, const _NDebug::LogInfo& logInfo)
{
    QString queryString;
    queryString += " INSERT INTO sc_ods.\"" + tableName + "\"";
    queryString += " (\"appUser\", \"loggedDateTime\", \"threadId\", \"loggerId\", content, \"fullMessage\") VALUES ( ";
    queryString += STR_TO_SQL(DatabaseSettingsOnLocalSystem_getDefaultInstance.getAppUser());
    queryString += STR_TO_SQL_WITH_COMMA(logInfo.dateTime);
    queryString += STR_TO_SQL_WITH_COMMA(logInfo.threadId);
    queryString += STR_TO_SQL_WITH_COMMA(logInfo.loggerId);
    queryString += STR_TO_SQL_WITH_COMMA(logInfo.content);
    queryString += STR_TO_SQL_WITH_COMMA(logInfo.fullMessage);
    queryString += " ); ";

    return execQueryToAffectOneRow(queryString, _NDebug::LD_File);
}

bool PGDatabaseConnector::insertGlobalLog(const _NDebug::LogInfo& logInfo)
{
    return insertLog("_GlobalLogs", logInfo);
}

}
