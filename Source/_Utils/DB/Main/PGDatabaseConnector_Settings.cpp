#include "DB/Main/PGDatabaseConnector.h"
#include "DB/Main/DatabaseSettingsOnLocalSystem.h"
#include <QSqlQuery>
#include <QSqlResult>
#include <QSqlError>
#include "Debugger/Main/Logger.h"
#include <QThread>
#include "Common/Main/StringContants.h"
#include <QDebug>
#include "DB/Main/UserSettingsOnPGDatabase.h"

namespace _NDB
{

/**********************************************************************/
/* Settings */
bool PGDatabaseConnector::clearSettings()
{
    QString queryString = " CALL sc_ods.\"clear_SettingsOnly\"(); ";
    return execQuery(queryString).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::updateSetting(const QString& tableName, const QString& key, const QString& value)
{
    if (!isDBOpen())
        return false;

    QString queryString;
    queryString = " CALL sc_ods.\"update" + tableName + "\"( ";
    if (tableName != "_GlobalSettings")
        queryString += STR_TO_SQL(DatabaseSettingsOnLocalSystem_getDefaultInstance.getAppUser());
    queryString += STR_TO_SQL_WITH_COMMA(key);
    queryString += STR_TO_SQL_WITH_COMMA(value);
    queryString += " ); ";

    return execQuery(queryString).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::getSettings(const QString& tableName, StringVec& keys, StringVec& vals)
{
    if (!isDBOpen())
        return false;

    QString queryString;
    queryString = " SELECT \"settingKey\", \"settingValue\" FROM sc_ods.\"" + tableName + "\"";
    if (tableName != "_GlobalSettings")
    {
        queryString += " WHERE \"appUser\" = ";
        queryString += STR_TO_SQL(DatabaseSettingsOnLocalSystem_getDefaultInstance.getAppUser());
    }
    return getResult_C2(queryString, keys, vals);
}

int PGDatabaseConnector::getNewID(QString key)
{
    // ????????????!!!!!!!!!
    int id = UserSettingsOnPGDatabase_getDefaultInstance.getValue(key, 0).toInt() + 1;
    UserSettingsOnPGDatabase_getDefaultInstance.setValue(key, id);
    return id;
}

}
