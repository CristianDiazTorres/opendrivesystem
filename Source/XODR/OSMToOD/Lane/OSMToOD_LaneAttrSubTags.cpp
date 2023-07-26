#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

void OSMToOpenDRIVE::convertLaneAttrSubTags(DatabaseConnector& database_connector,
                                       const _NOSM::Way& osmWay,
                                       int osmLaneIndex,
                                       _NOD::t_road& odRoad,
                                       _NOD::t_road_lanes_laneSection_lr_lane& odLane)
{
    convertLaneAccess(database_connector, osmWay, osmLaneIndex, odRoad, odLane);
    convertLaneHeight(database_connector, osmWay, osmLaneIndex, odRoad, odLane);
    convertLaneMaterial(database_connector, osmWay, osmLaneIndex, odRoad, odLane);
    convertLaneRule(database_connector, osmWay, osmLaneIndex, odRoad, odLane);
    convertLaneSpeed(database_connector, osmWay, osmLaneIndex, odRoad, odLane);
    convertLaneWidth(database_connector, osmWay, osmLaneIndex, odRoad, odLane);
    convertLaneRoadMark(database_connector, osmWay, osmLaneIndex, odRoad, odLane);
}

}
