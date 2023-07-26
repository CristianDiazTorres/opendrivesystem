
#include "OSM/PriorKnowledgeProvider/PriorKnowledgeProvider__Base.h"
#include "OSM/Way/Way.h"
#include "Debugger/Main/Logger.h"

namespace _NOSM
{

void PriorKnowledgeProvider__Base::fillWayAttrs(Way& way)
{
    fillDrivingSide(way);
    fillDirection(way);
    fillLanesCount(way);
    fillLanesCountDirectional(way);
    fillWidthLanes(way);
    fillElevationLanes(way);
    fillMaxspeedLanes(way);
    fillAccessLanes(way);
    fillRuleLanes(way);
    fillRoadMark(way);
}

void PriorKnowledgeProvider__Base::fillDirection(Way& way)
{
    // Need to check highway key
    // one way
    Q_UNUSED(way);
}

void PriorKnowledgeProvider__Base::fillLanesCount(Way& way)
{
    if (way.laneCount > 0)
        return;

    if (way.isOneway())
    {
        if (fillLanesCount_Oneway(way))
            return;
    }
    else
    {
        if (fillLanesCount_Bidirectional(way))
            return;
    }

    fillLanesCount_Other(way);
}

bool PriorKnowledgeProvider__Base::fillLanesCount_Oneway(Way& way)
{
    Q_ASSERT(way.laneCount <= 0);
    way.laneCount = 1;
    return true;
}

bool PriorKnowledgeProvider__Base::fillLanesCount_Bidirectional(Way& way)
{
    Q_ASSERT(way.laneCount <= 0);
    way.laneCount = 2;
    return true;
}

void PriorKnowledgeProvider__Base::fillLanesCount_Other(Way& way)
{
    Q_ASSERT(way.laneCount <= 0);
    way.laneCount = 2;
}

void PriorKnowledgeProvider__Base::fillWidthLanes(Way &way)
{
    if (way.osm.contains(_SC_width_lanes_A))
    {
        way.duplicateLastJoin(_SC_width_lanes_A, way.laneCount);
        way.checkIfEqualToLaneCount(_SC_width_lanes_A);
        return;
    }

    QString width;
    if (way.osm.contains(_SC_lane_width_A))
        width = way.osm[_SC_lane_width_A];
    else
        width = "3.5";

    way.duplicateJoin(_SC_width_lanes_A, width, way.laneCount);
    way.checkIfEqualToLaneCount(_SC_width_lanes_A);
}

void PriorKnowledgeProvider__Base::fillElevationLanes(Way &way)
{
    if (!way.osm.contains(_SC_elevation_from_road))
        return;

    way.duplicateJoin(_SC_elevation_lanes_A, way.osm[_SC_elevation_from_road], way.laneCount);
    way.checkIfEqualToLaneCount(_SC_elevation_lanes_A);
}

void PriorKnowledgeProvider__Base::fillMaxspeedLanes(Way& way)
{
    QString maxspeed = way.osm[_SC_maxspeed];
    if (maxspeed.toDouble() <= 0 && !way.osm.contains(_SC_maxspeed_lanes_A))
        return;

    DefaultLogger_File << way.osm[_SC_maxspeed_lanes_A];

    QList<QString> maxspeedList = way.getSplit(_SC_maxspeed_lanes_A);
    DefaultLogger_File << maxspeedList.size();

    _NCM::append(maxspeedList, "", way.laneCount);
    DefaultLogger_File << maxspeedList.size();

    QString maxspeedLanes;
    for (QString maxspeedLane : maxspeedList)
    {
        if (maxspeedLane.toDouble() > 0)
        {
            maxspeedLanes += maxspeedLane + "|";
            continue;
        }

        if (maxspeed.toDouble() > 0)
        {
            maxspeedLanes += maxspeed + "|";
            continue;
        }

        maxspeedLanes += "|";
    }

    _NCM::removeOneAtEnd(maxspeedLanes);
    DefaultLogger_File << maxspeedLanes;

    way.osm[_SC_maxspeed_lanes_A] = maxspeedLanes;
    way.checkIfEqualToLaneCount(_SC_maxspeed_lanes_A);
}

void PriorKnowledgeProvider__Base::fillRuleLanes(Way &way)
{
    // Car pool
    if (way.osm.contains(_SC_car_pooling_lanes_A))
        way.appendJoin(_SC_car_pooling_lanes_A, _SC_no, way.laneCount);

    // Parking & stopping
    QString left;
    if (way.osm[_SC_parking_condition_left_A].contains(_SC_no_stopping) ||
        way.osm[_SC_parking_lane_left_A].contains(_SC_no_stopping) ||
        way.osm[_SC_parking_lanes_left_A].contains(_SC_no_stopping) ||
        way.osm[_SC_parking_left_A].contains(_SC_no_stopping))
    {
        left = _SC_no_stopping;
    }
    else if (way.osm[_SC_parking_condition_left_A].contains(_SC_no_parking) ||
        way.osm[_SC_parking_condition_left_A].contains(_SC_disabled) ||
        way.osm[_SC_parking_condition_left_A].contains(_SC_no) ||
        way.osm[_SC_parking_lane_left_A].contains(_SC_no_parking) ||
        way.osm[_SC_parking_lane_left_A].contains(_SC_disabled) ||
        way.osm[_SC_parking_lane_left_A].contains(_SC_no) ||
        way.osm[_SC_parking_lanes_left_A].contains(_SC_no_parking) ||
        way.osm[_SC_parking_lanes_left_A].contains(_SC_disabled) ||
        way.osm[_SC_parking_lanes_left_A].contains(_SC_no) ||
        way.osm[_SC_parking_left_A].contains(_SC_no_parking) ||
        way.osm[_SC_parking_left_A].contains(_SC_disabled) ||
        way.osm[_SC_parking_left_A].contains(_SC_no))
    {
        left = _SC_no_parking;
    }

    QString right;
    if (way.osm[_SC_parking_condition_right_A].contains(_SC_no_stopping) ||
        way.osm[_SC_parking_lane_right_A].contains(_SC_no_stopping) ||
        way.osm[_SC_parking_lanes_right_A].contains(_SC_no_stopping) ||
        way.osm[_SC_parking_right_A].contains(_SC_no_stopping))
    {
        right = _SC_no_stopping;
    }
    else if (way.osm[_SC_parking_condition_right_A].contains(_SC_no_parking) ||
        way.osm[_SC_parking_condition_right_A].contains(_SC_disabled) ||
        way.osm[_SC_parking_condition_right_A].contains(_SC_no) ||
        way.osm[_SC_parking_lane_right_A].contains(_SC_no_parking) ||
        way.osm[_SC_parking_lane_right_A].contains(_SC_disabled) ||
        way.osm[_SC_parking_lane_right_A].contains(_SC_no) ||
        way.osm[_SC_parking_lanes_right_A].contains(_SC_no_parking) ||
        way.osm[_SC_parking_lanes_right_A].contains(_SC_disabled) ||
        way.osm[_SC_parking_lanes_right_A].contains(_SC_no) ||
        way.osm[_SC_parking_right_A].contains(_SC_no_parking) ||
        way.osm[_SC_parking_right_A].contains(_SC_disabled) ||
        way.osm[_SC_parking_right_A].contains(_SC_no))
    {
        right = _SC_no_parking;
    }

    QList<QString> parkingLanes;
    if (way.leftLaneCount > 0)
        parkingLanes << left;

    if (way.rightLaneCount > 0)
    {
        _NCM::append(parkingLanes, "", way.laneCount - 1);
        parkingLanes << right;
    }
    else
        _NCM::append(parkingLanes, "", way.laneCount);

    way.osm[_SC_parking_lanes_A] = _NCM::getJoined(parkingLanes);
    way.checkIfEqualToLaneCount(_SC_parking_lanes_A);
}

void PriorKnowledgeProvider__Base::fillRoadMark(Way& way)
{
    Q_UNUSED(way);

    // Center
    way.setIfNotContain(_SC_road_marking_center_A, _SC_solid_solid_A);
    way.setIfNotContain(_SC_road_marking_center_color_A, _SC_white);

    // Lanes
    way.setIfNotContain(_SC_road_marking, _SC_dashed);
    way.replaceIfEmptyAppendJoin(_SC_road_marking_lanes_A, way.osm[_SC_road_marking], way.laneCount);
    way.checkIfEqualToLaneCount(_SC_road_marking_lanes_A);

    way.setIfNotContain(_SC_road_marking_color_A, _SC_white);
    way.replaceIfEmptyAppendJoin(_SC_road_marking_lanes_color_A, way.osm[_SC_road_marking_color_A], way.laneCount);
    way.checkIfEqualToLaneCount(_SC_road_marking_lanes_color_A);
}

}
