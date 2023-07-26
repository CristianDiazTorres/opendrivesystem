#include "XODR/OpenDRIVE/lane/t_road_lanes.h"
#include "XODR/OpenDRIVE/road/t_road.h"

namespace _NOD
{

double t_road_lanes::getLength() const
{
    return ((t_road*)parent)->length;
}

double t_road_lanes::getLaneSectionEndS(double s) const
{
    for (const t_road_lanes_laneSection& laneSection : laneSection_sequence)
    {
        if (s < laneSection.s)
            return laneSection.s;
    }
    return getLength();
}

}
