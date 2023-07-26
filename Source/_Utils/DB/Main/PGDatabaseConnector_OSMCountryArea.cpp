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
/* OSM Country Area */
bool PGDatabaseConnector::insertOSMCountryAreaLog(const _NDebug::LogInfo& logInfo)
{
    return insertLog("OSMCntryAreaLogs", logInfo);
}

bool PGDatabaseConnector::clearOSMCountryArea()
{
    QString queryString = " CALL sc_ods.\"clearOSMCntryArea\"(); ";
    return execQuery(queryString).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::clearOSMCountryAreaAndDependencies()
{
    QString queryString = " CALL sc_ods.\"clearOSMCntryAreaAndDependencies\"(); ";
    return execQuery(queryString).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::updateOSMCountryAreaDataAndHist(const StringVec &countries
                                                , const StringVec &jsons
                                                , const StringVec &areas)
{
    if (!isDBOpen())
        return false;

    for (int i = 0; i < countries.size(); i ++)
    {
        QString queryString;
        queryString = " CALL sc_ods.\"updateOSMCntryAreaDataAndHist\"( ";
        queryString += STR_TO_SQL(countries[i]);
        queryString += STR_TO_SQL_WITH_COMMA(jsons[i]);
        queryString += STR_TO_SQL_WITH_COMMA(areas[i]);
        queryString += " ); ";

        if (execQuery(queryString).lastError().type() != QSqlError::NoError)
            return false;
    }

    return true;
}

bool PGDatabaseConnector::getOSMCountryAreaData_NameAsISO3166_1(double lat, double lon, QString& name)
{
    QString queryString;
    queryString += "SELECT iso3166_1 "
                   "FROM sc_ods.\"OSMCntryAreaData\" "
                   "ORDER BY ST_Distance(geom4326,  ST_SetSRID(ST_Point("
                   + _NCM::doubleToStringFullPrecision(lon)
                   + ","
                   + _NCM::doubleToStringFullPrecision(lat)
                   + "), 4326)) LIMIT 1";
    return getResult_R1C1(queryString, name, _NDebug::LD_File);
}

}
