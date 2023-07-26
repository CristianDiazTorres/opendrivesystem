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
/* OSM Node */
bool PGDatabaseConnector::insertOSMNodeLog(const _NDebug::LogInfo& logInfo)
{
    return insertLog("OSMNodeLogs", logInfo);
}

bool PGDatabaseConnector::updateOSMNodeState(const QString& key, const QString& value)
{
    return updateState("OSMNodeStatus", key, value);
}

bool PGDatabaseConnector::getOSMNodeState(const QString& key, QString& value)
{
    return getState("OSMNodeStatus", key, value);
}

bool PGDatabaseConnector::updateOSMNodeState_LastProcessedGPSCellsDataId(const QString& id)
{
    return updateOSMNodeState("lastProcedGPSCellsDataIdForOSMNode", id);
}

bool PGDatabaseConnector::getOSMNodeState_LastProcessedGPSCellsDataId(QString& id)
{
    return getOSMNodeState("lastProcedGPSCellsDataIdForOSMNode", id);
}

bool PGDatabaseConnector::clearOSMNode()
{
    QString queryString = " CALL sc_ods.\"clearOSMNode\"(); ";
    return execQuery(queryString).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::clearOSMNodeAndDependencies()
{
    QString queryString = " CALL sc_ods.\"clearOSMNodeAndDependencies\"(); ";
    return execQuery(queryString).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::updateOSMNodeDataAndHist(const QString &osmId, QString json, const QString &geom, QJsonObject tags)
{
    if (!isDBOpen())
        return false;

    QString queryString;
    queryString = " CALL sc_ods.\"updateOSMNodeDataAndHist\"( ";
    queryString += STR_TO_SQL(osmId);
    queryString += STR_TO_SQL_WITH_COMMA(json);
    queryString += STR_TO_SQL_WITH_COMMA(geom);
    queryString += " , ARRAY[ ";
    queryString += JSON_TO_SQL(tags, _SC_abandoned);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_abandoned_amenity_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_abandoned_building_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_abandoned_car_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_abandoned_crossing_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_abandoned_highway_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_abandoned_highway_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_abandoned_natural_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_abandoned_natural_tree_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_abandoned_parking_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_abandoned_pole_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_abandoned_railway_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_abandoned_railway_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_abandoned_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_abandoned_tree_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_accomodation);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_addr_building_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_addr_housename_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_amenity);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_amenity_1);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_amenity_2);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_area);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_area_building_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_area_highway_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_area_traffic_calming_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_barrier);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_barrier_tree_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_barrier_type_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_bicycle);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_bicycle_parking_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_bicycle_parking_position_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_bicycle_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_blazed_natural_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_bollard);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_bollard_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_broken);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_broken_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_building);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_calming);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_camera_mount_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_construction);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_construction_amenity_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_construction_building_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_construction_crossing_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_construction_crossing_island_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_construction_demolished_highway_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_construction_demolished_highway_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_construction_highway_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_construction_highway_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_construction_highway_traffic_signal_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_construction_highway_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_construction_junction_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_construction_parking_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_construction_road_marking_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_construction_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_crane);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_crane_type_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_crossing);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_crossing_1);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_crossing_2);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_crossing_island_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_crossing_road_marking_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_crosswalk);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_cycleway);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_cycleway_left_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_cycleway_left_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_cycleway_left_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_cycleway_right_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_cycleway_right_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_cycleway_right_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_cycleway_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_cycleway_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_dead_natural_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_demolished);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_demolished_amenity_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_demolished_building_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_demolished_crossing_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_demolished_highway_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_demolished_highway_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_demolished_junction_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_demolished_natural_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_demolished_parking_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_demolished_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_destroyed);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_destroyed_building_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_destroyed_natural_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_destroyed_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_device);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_device_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_disabled);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_disabled_highway_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_disabled_highway_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_disabled_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_disused);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_disused_building_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_disused_crossing_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_disused_highway_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_disused_highway_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_disused_parking_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_disused_playground_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_disused_playground_roundabout_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_disused_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_disused_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_enforcement);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_fence);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_fence_pole_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_fence_type);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_fence_type_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_footway);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_forest);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_gantry);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_gantry_type_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_gone_natural_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_handrail);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_highway);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_highway_1);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_highway_1_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_highway_2);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_highway_2_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_highway_backward_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_highway_backward_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_highway_backwards_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_highway_backwards_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_highway_bicycle_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_highway_bicycle_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_highway_construction_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_highway_construction_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_highway_disused_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_highway_disused_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_highway_forward_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_highway_forward_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_highway_historic_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_highway_historic_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_highway_street_lamp_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_highway_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_historic);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_historic_1);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_historic_1_building_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_historic_building_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_historic_crossing_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_historic_highway_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_historic_highway_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_historical);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_historical_building_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_house);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_industrial);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_intersection);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_intersection_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_junction);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_junction_separate_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_junction_separate_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_junction_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_kerb_road_marking_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_lamp_type);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_lamp_type_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_landuse);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_level_crossing);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_light);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_light_type_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_lit);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_location);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_location_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_man_made);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_man_made_separate_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_man_made_separate_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_mini_roundabout);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_miniroundabout);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_motorcycle);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_motorcycle_parking_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_name);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_name_building_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_natura);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_natural);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_natural_1);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_natural_1_tree_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_natural_tree_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_obstacle);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_obstacle_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_old_amenity);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_old_amenity_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_old_natural);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_old_natural_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_park);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_parking);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_parking_1);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_parking_position);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_parking_slots);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_parking_space);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_parking_zone);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_plant);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_playground);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_playground_roundabout_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_pole);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_public_transport);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_railing);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_railway);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_razed);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_razed_amenity_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_razed_building_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_razed_crossing_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_razed_crossing_island_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_razed_highway_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_razed_highway_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_razed_natural_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_razed_natural_tree_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_razed_playground_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_razed_pole_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_razed_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_razed_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_razed_tree_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_ref);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_ref_pole_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_residential);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_road);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_road_mark);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_road_marking);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_road_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_roadmark);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_roundabout);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_ruined);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_ruined_building_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_ruins);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_ruins_building_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_ruins_car_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_ruins_tree_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_seamark);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_seamark_building_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_seasonal_winter_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_seasonal_winter_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_service_vehicle_parking_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_services);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_sidewalk);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_sidewalk_left_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_sidewalk_left_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_sidewalk_right_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_sidewalk_right_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_sidewalk_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_site);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_street_cabinet);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_street_cabinet_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_street_cabinet_traffic_signal_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_street_cabinet_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_street_furniture);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_street_lamp);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_street_light);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_streetlamp);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_streetlamp_ref_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_streetlight);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_structure);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_temporarily_gone_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_temporarily_gone_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_temporarily_removed);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_temporarily_removed_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_temporary);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_temporary_building_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_traffic_calming);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_traffic_control);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_traffic_control_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_traffic_island);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_traffic_lights);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_traffic_sign);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_traffic_sign_1);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_traffic_signal);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_traffic_signals);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_traffic_signals_1);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_training);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_transport);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_transport_traffic_signals_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_transportation);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_tree);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_trees);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_type);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_type_pole_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_use);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_user_defined);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_user_defined_other);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_vegetation);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_waterway);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_waterway_traffic_sign_A);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_zone);
    queryString += JSON_TO_SQL_WITH_COMMA(tags, _SC_zone_parking_A);
    queryString += " ] ";
    queryString += " ); ";

    return execQuery(queryString, _NDebug::LD_File).lastError().type() == QSqlError::NoError;
}

bool PGDatabaseConnector::getOSMNodeDataOnCell(Cell cell, StringVec& jsons)
{
    QRectF bound = cell.getCellBoundInDegrees();

    QString queryString;
    queryString = "SELECT json FROM sc_ods.\"OSMNodeData\" WHERE ST_Intersects(geom4326, ST_SetSRID(POLYGON(BOX '((";
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
