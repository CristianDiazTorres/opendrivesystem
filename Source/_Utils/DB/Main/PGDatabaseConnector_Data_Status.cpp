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
/* Data (& Status) */
bool PGDatabaseConnector::clearData()
{
    QString queryString = " CALL sc_ods.\"clear_DataOnly\"(); ";
    return execQuery(queryString).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::updateState(const QString& tableName, const QString& key, const QString& value)
{
    if (!isDBOpen())
        return false;

    QString queryString;
    queryString = " CALL sc_ods.\"update" + tableName + "\"( ";
    if (tableName != "_GlobalStatus")
        queryString += STR_TO_SQL(DatabaseSettingsOnLocalSystem_getDefaultInstance.getAppUser());
    queryString += STR_TO_SQL_WITH_COMMA(key);
    queryString += STR_TO_SQL_WITH_COMMA(value);
    queryString += " ); ";

    return execQuery(queryString, _NDebug::LD_File).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::getState(const QString& tableName, const QString& key, QString& value)
{
    if (!isDBOpen())
        return false;

    QString queryString;
    queryString = " SELECT \"stateValue\" FROM sc_ods.\"" + tableName + "\"";
    queryString += " WHERE ";
    if (tableName != "_GlobalStatus")
    {
        queryString += " \"appUser\" = ";
        queryString += STR_TO_SQL(DatabaseSettingsOnLocalSystem_getDefaultInstance.getAppUser());
        queryString += " AND ";
    }
    queryString += " \"stateKey\" = ";
    queryString += STR_TO_SQL(key);
    return getResult_R1C1(queryString, value);
}

}
