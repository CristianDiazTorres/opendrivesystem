#include "DB/Main/PGDatabaseConnector.h"
#include "DB/Main/DatabaseSettingsOnLocalSystem.h"
#include <QSqlQuery>
#include <QSqlResult>
#include <QSqlError>
#include "Debugger/Main/Logger.h"
#include <QThread>
#include "Common/Main/StringContants.h"
#include <QDebug>
#include "GeoCoordinate/Main/Cell.h"

namespace _NDB
{

/**********************************************************************/
/* OSM Way */
bool PGDatabaseConnector::insertOSMWayLog(const _NDebug::LogInfo& logInfo)
{
    return insertLog("OSMWayLogs", logInfo);
}

bool PGDatabaseConnector::updateOSMWayState(const QString& key, const QString& value)
{
    return updateState("OSMWayStatus", key, value);
}

bool PGDatabaseConnector::getOSMWayState(const QString& key, QString& value)
{
    return getState("OSMWayStatus", key, value);
}

bool PGDatabaseConnector::updateOSMWayState_LastProcessedGPSCellsDataId(const QString& id)
{
    return updateOSMWayState("lastProcedGPSCellsDataIdForOSMWay", id);
}

bool PGDatabaseConnector::getOSMWayState_LastProcessedGPSCellsDataId(QString& id)
{
    return getOSMWayState("lastProcedGPSCellsDataIdForOSMWay", id);
}

bool PGDatabaseConnector::clearOSMWay()
{
    QString queryString = " CALL sc_ods.\"clearOSMWay\"(); ";
    return execQuery(queryString).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::clearOSMWayAndDependencies()
{
    QString queryString = " CALL sc_ods.\"clearOSMWayAndDependencies\"(); ";
    return execQuery(queryString).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::updateOSMWayDataAndHist(const QString &osmId, QString json, const QString &geom, QJsonObject tags)
{
    if (!isDBOpen())
        return false;

    QString queryString;
    queryString = " CALL sc_ods.\"updateOSMWayDataAndHist\"( ";
    queryString += STR_TO_SQL(osmId);
    queryString += STR_TO_SQL_WITH_COMMA(json);
    queryString += STR_TO_SQL_WITH_COMMA(geom);
    queryString += " , ARRAY[ ";
    queryString += JSON_TO_SQL(tags, _SC_access);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_access_lanes_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_access_lanes_backward_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_access_lanes_forward_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_addr_country_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_bidirectional);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_car_pooling_lanes_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_driving_direction_lanes_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_driving_side);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_driving_side_lanes_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_elevation);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_elevation_from_road);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_elevation_lanes_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_highway);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_junction);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_lanes);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_lanes_backward_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_lanes_bidirectional_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_lanes_direction_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_lanes_forward_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_lanes_left_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_lanes_right_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_lane_width_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_lanes_width_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_width_lanes_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_maxspeed);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_maxspeed_lanes_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_name);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_oneway);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_parking_condition_left_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_parking_condition_right_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_parking_lane_left_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_parking_lane_right_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_parking_lanes_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_parking_lanes_left_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_parking_lanes_right_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_parking_left_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_parking_right_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_road_marking);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_road_marking_center_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_central_line);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_central_reservation);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_centreline);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_divider);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_road_marking_center_color_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_centreline_color_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_road_marking_center_material_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_divider_material_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_road_marking_color_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_road_marking_colour_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_road_marking_curb_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_barrier);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_barrier_type_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_sloped_curb);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_road_marking_lanes_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_road_marking_lanes_color_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_road_marking_lanes_material_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_surface);
    queryString += " ] ";
    queryString += " ); ";

    return execQuery(queryString, _NDebug::LD_File).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::getOSMWayDataOnCell(Cell cell, StringVec& jsons)
{
    QRectF bound = cell.getCellBoundInDegrees();

    QString queryString;
    queryString = "SELECT json FROM sc_ods.\"OSMWayData\" WHERE ST_Intersects(geom4326, ST_SetSRID(POLYGON(BOX '((";
    queryString += _NCM::doubleToStringFullPrecision(bound.left());
    queryString += ",";
    queryString += _NCM::doubleToStringFullPrecision(bound.top());
    queryString += "),(";
    queryString += _NCM::doubleToStringFullPrecision(bound.right());
    queryString += ",";
    queryString += _NCM::doubleToStringFullPrecision(bound.bottom());
    queryString += "))')::GEOMETRY, 4326))";

    QSqlQuery sqlQuery = execQuery(queryString);
    if (sqlQuery.lastError().type() != QSqlError::NoError)
        return false;

    if (!sqlQuery.first())
        return true;

    jsons.reserve(100);

    do
    {
        jsons << sqlQuery.value(0).toString();
    }
    while(sqlQuery.next());

    return true;
}

}
