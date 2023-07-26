
#pragma once

#include "XODR/Main/OpenDRIVEBuilder.h"

namespace _NXODR
{

#define OSMToOpenDRIVE_CONTAINS_KEY(key) \
    containsKey(osmNode, key)

#define OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(key, value) \
    (osmNode.osm.contains(key) && osmNode.osm[key] == value)

#define OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(key, value) \
    (osmNode.osm.contains(key) && osmNode.osm[key].contains(value))

class OSMToOpenDRIVE : public OpenDRIVEBuilder
{
    static double MAX_NODE_ROAD_DISTANCE;

public:

    /**
     * @return Content
     * @param rlr
     * @param trajectory
     * @param measurement_content
     */
    QVector<_NOD::t_road> buildRoads(
            bool useBasicTables,
            const VehiclePosVec& trajectory,
            ConstMeasurementContent& measurement_content,
            DatabaseConnector& database_connector,
            ConstExternalSourceProviderVec& external_source_providers,
            QVector<_NOSM::Way>& allOSMWays);

    void updateOpenDRIVE(
            bool useBasicTables,
            const VehiclePosVec& trajectory,
            ConstMeasurementContent& measurement_content,
            DatabaseConnector& database_connector,
            ConstExternalSourceProviderVec& external_source_providers,
            QVector<_NOD::t_road> &odRoads,
            QVector<_NOSM::Way>& allOSMWays);

protected:
    void convertRoadAttrSubTags(DatabaseConnector& database_connector, const _NOSM::Way& osmWay, _NOD::t_road& odRoad);
    void convertRoadType(DatabaseConnector& database_connector, const _NOSM::Way& osmWay, _NOD::t_road& odRoad);
    void convertRoadTypeSpeed(DatabaseConnector& database_connector, const _NOSM::Way& osmWay, _NOD::t_road_type& od_road_type);
    void convertRoadElevationProfile(DatabaseConnector& database_connector, const _NOSM::Way& osmWay, _NOD::t_road& odRoad);

protected:
    void convertLane(DatabaseConnector& database_connector, const _NOSM::Way& osmWay, _NOD::t_road& odRoad);
    void convertLane_Oneway(DatabaseConnector& database_connector, const _NOSM::Way& osmWay, _NOD::t_road& odRoad);
    void convertLane_Bidirectional_OneLane(DatabaseConnector& database_connector, const _NOSM::Way& osmWay, _NOD::t_road& odRoad);
    void convertLane_Bidirectional_MultiLanes(DatabaseConnector& database_connector, const _NOSM::Way& osmWay, _NOD::t_road& odRoad);

protected:
    void convertLaneAttrSubTags(DatabaseConnector& database_connector,
                                           const _NOSM::Way& osmWay,
                                           int osmLaneIndex,
                                           _NOD::t_road& odRoad,
                                           _NOD::t_road_lanes_laneSection_lr_lane& odLane);
    void convertLaneAccess(DatabaseConnector& database_connector,
                                           const _NOSM::Way& osmWay,
                                           int osmLaneIndex,
                                           _NOD::t_road& odRoad,
                                           _NOD::t_road_lanes_laneSection_lr_lane& odLane);
    void convertLaneHeight(DatabaseConnector& database_connector,
                                           const _NOSM::Way& osmWay,
                                           int osmLaneIndex,
                                           _NOD::t_road& odRoad,
                                           _NOD::t_road_lanes_laneSection_lr_lane& odLane);
    void convertLaneMaterial(DatabaseConnector& database_connector,
                                           const _NOSM::Way& osmWay,
                                           int osmLaneIndex,
                                           _NOD::t_road& odRoad,
                                           _NOD::t_road_lanes_laneSection_lr_lane& odLane);
    void convertLaneRule(DatabaseConnector& database_connector,
                                           const _NOSM::Way& osmWay,
                                           int osmLaneIndex,
                                           _NOD::t_road& odRoad,
                                           _NOD::t_road_lanes_laneSection_lr_lane& odLane);
    void convertLaneSpeed(DatabaseConnector& database_connector,
                                           const _NOSM::Way& osmWay,
                                           int osmLaneIndex,
                                           _NOD::t_road& odRoad,
                                           _NOD::t_road_lanes_laneSection_lr_lane& odLane);
    void convertLaneWidth(DatabaseConnector& database_connector,
                                           const _NOSM::Way& osmWay,
                                           int osmLaneIndex,
                                           _NOD::t_road& odRoad,
                                           _NOD::t_road_lanes_laneSection_lr_lane& odLane);
    void convertLaneRoadMark(DatabaseConnector& database_connector,
                                           const _NOSM::Way& osmWay,
                                           int osmLaneIndex,
                                           _NOD::t_road& odRoad,
                                           _NOD::t_road_lanes_laneSection_lr_lane& odLane);
    void convertLaneRoadMark_Center(DatabaseConnector& database_connector,
                                           const _NOSM::Way& osmWay,
                                           _NOD::t_road& odRoad,
                                           _NOD::t_road_lanes_laneSection_lr_lane& odLane);
    void convertLaneRoadMark_Border(DatabaseConnector& database_connector,
                                           const _NOSM::Way& osmWay,
                                           _NOD::t_road& odRoad,
                                           _NOD::t_road_lanes_laneSection_lr_lane& odLane);

protected:
    void convertNodes(DatabaseConnector& database_connector, QVector<_NOSM::Node>& osmNodes, QVector<_NOD::t_road> &odRoads);
    void convertNode(DatabaseConnector& database_connector, _NOSM::Node& osmNode, QVector<_NOD::t_road> &odRoads);
    void convertNode(DatabaseConnector& database_connector, _NOSM::Node& osmNode, _NOD::t_road &odRoad);

    static inline bool containsKey(const _NOSM::Node& osmNode, const QString& key)
    {
        if (!osmNode.osm.contains(key))
            return false;

        const QString& value = osmNode.osm[key];
        return value != "" &&
            value != _SC_no &&
            value != _SC_false &&
            value != "-1";
    }

    bool convertNode_Signal(
            DatabaseConnector& database_connector,
            _NOSM::Node& osmNode,
            const QString& amenity,
            const QList<QString>& values,
            _NOD::t_road &odRoad);


#define OSMToOpenDRIVE_CONVERTNODE_PARAMS \
    DatabaseConnector& database_connector, \
    _NOSM::Node& osmNode, \
    const QString& amenity, \
    const QList<QString>& values, \
    _NOD::t_road &odRoad, \
    _NOD::t_road_objects_object& od_object

protected:
    bool convertNode_Object_BARRIER(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_BIKE(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_BUILDING(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_BUS(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_CAR(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_CROSSWALK(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_GANTRY(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_MOTORBIKE(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_OBSTACLE(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_PARKINGSPACE(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_PATCH(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_PEDESTRIAN(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_POLE(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_RAILING(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_ROADMARK(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_SOUNDBARRIER(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_STREETLAMP(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_TRAFFICISLAND(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_TRAILER(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_TRAIN(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_TRAM(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_TREE(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_VAN(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_VEGETATION(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
    bool convertNode_Object_WIND(OSMToOpenDRIVE_CONVERTNODE_PARAMS);
};

}

