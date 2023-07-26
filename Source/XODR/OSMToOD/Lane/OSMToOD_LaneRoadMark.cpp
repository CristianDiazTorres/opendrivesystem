#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

static _NOD::e_roadMarkType convertOSMRoadMarkTypeToODRoadMarkType(const QString& osmType)
{
    if (osmType.contains(_NOD::e_roadMarkType::SOLID_SOLID) ||
        osmType.contains(_SC_double_solid) ||
        osmType.contains(_SC_double_white) ||
        osmType.contains(_SC_solid_solid_B))
        return _NOD::e_roadMarkType::SOLID_SOLID;

    if (osmType.contains(_NOD::e_roadMarkType::SOLID_BROKEN))
        return _NOD::e_roadMarkType::SOLID_BROKEN;

    if (osmType.contains(_NOD::e_roadMarkType::BROKEN_SOLID))
        return _NOD::e_roadMarkType::BROKEN_SOLID;

    if (osmType.contains(_NOD::e_roadMarkType::BROKEN_BROKEN))
        return _NOD::e_roadMarkType::BROKEN_BROKEN;

    if (osmType.contains(_NOD::e_roadMarkType::BOTTS_DOTS))
        return _NOD::e_roadMarkType::BOTTS_DOTS;

    if (osmType.contains(_NOD::e_roadMarkType::GRASS))
        return _NOD::e_roadMarkType::GRASS;

    if (osmType.contains(_NOD::e_roadMarkType::CURB) ||
        osmType.contains(_SC_kerb))
        return _NOD::e_roadMarkType::CURB;

    if (osmType.contains(_NOD::e_roadMarkType::EDGE))
        return _NOD::e_roadMarkType::EDGE;

    if (osmType.contains(_NOD::e_roadMarkType::SOLID))
        return _NOD::e_roadMarkType::SOLID;

    if (osmType.contains(_NOD::e_roadMarkType::BROKEN) ||
        osmType.contains(_SC_dash))
        return _NOD::e_roadMarkType::BROKEN;

    if (osmType.isEmpty() || osmType == _SC_no || osmType == _SC_none)
        return _NOD::e_roadMarkType::NONE;

    return _NOD::e_roadMarkType::CUSTOM;
}

void OSMToOpenDRIVE::convertLaneRoadMark(DatabaseConnector& database_connector,
                                       const _NOSM::Way& osmWay,
                                       int osmLaneIndex,
                                       _NOD::t_road& odRoad,
                                       _NOD::t_road_lanes_laneSection_lr_lane& odLane)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(odRoad);

    QString type = osmWay.getSplit(_SC_road_marking_lanes_A).at(osmLaneIndex);
    QString color = osmWay.getSplit(_SC_road_marking_lanes_color_A).at(osmLaneIndex);
    QString material;
    if (osmWay.osm.contains(_SC_road_marking_lanes_material_A))
        material = osmWay.getSplit(_SC_road_marking_lanes_material_A).at(osmLaneIndex);

    _NOD::t_road_lanes_laneSection_lcr_lane_roadMark odRoadMark;
    odRoadMark.sOffset = 0;
    odRoadMark.type = convertOSMRoadMarkTypeToODRoadMarkType(type);
    odRoadMark.color = color;
    odRoadMark.material = material;
    odLane.roadMark_sequence << odRoadMark;
}

void OSMToOpenDRIVE::convertLaneRoadMark_Center(DatabaseConnector& database_connector,
                                       const _NOSM::Way& osmWay,
                                       _NOD::t_road& odRoad,
                                       _NOD::t_road_lanes_laneSection_lr_lane& odLane)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(odRoad);

    QString type = osmWay.osm[_SC_road_marking_center_A];
    QString color = osmWay.osm[_SC_road_marking_center_color_A];
    QString material;
    if (osmWay.osm.contains(_SC_road_marking_center_material_A))
        material = osmWay.osm[_SC_road_marking_center_material_A];

    _NOD::t_road_lanes_laneSection_lcr_lane_roadMark odRoadMark;
    odRoadMark.sOffset = 0;
    odRoadMark.type = convertOSMRoadMarkTypeToODRoadMarkType(type);
    odRoadMark.color = color;
    odRoadMark.material = material;
    odLane.roadMark_sequence << odRoadMark;
}

void OSMToOpenDRIVE::convertLaneRoadMark_Border(DatabaseConnector& database_connector,
                                       const _NOSM::Way& osmWay,
                                       _NOD::t_road& odRoad,
                                       _NOD::t_road_lanes_laneSection_lr_lane& odLane)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(odRoad);

    QString type;
    if (osmWay.osm.contains(_SC_road_marking_curb_A))
        type = osmWay.osm[_SC_road_marking_curb_A];

    if (type.isEmpty() || type == _SC_no || type == _SC_none)
        return;

    _NOD::t_road_lanes_laneSection_lcr_lane_roadMark odRoadMark;
    odRoadMark.sOffset = 0;
    odRoadMark.type = _NOD::e_roadMarkType::CURB;
    odLane.roadMark_sequence << odRoadMark;
}

}
