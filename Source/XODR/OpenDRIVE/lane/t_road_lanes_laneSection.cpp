#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes.h"

namespace _NOD
{

bool t_road_lanes_laneSection::calcOneway()
{
    if (!left_sequence.isEmpty() &&
        !left_sequence[0].lane_sequence.isEmpty() &&
        !right_sequence.isEmpty() &&
        !right_sequence[0].lane_sequence.isEmpty())
    {
        return (oneway = false);
    }

    if (!left_sequence.isEmpty())
    {
        for (const t_road_lanes_laneSection_left_lane& lane : left_sequence[0].lane_sequence)
        {
            if (lane.type == _NOD::e_laneType::BIDIRECTIONAL)
                return (oneway = false);
        }
    }

    if (!right_sequence.isEmpty())
    {
        for (const t_road_lanes_laneSection_right_lane& lane : right_sequence[0].lane_sequence)
        {
            if (lane.type == _NOD::e_laneType::BIDIRECTIONAL)
                return (oneway = false);
        }
    }

    return (oneway = true);
}

double t_road_lanes_laneSection::calcDistance(const a_s& other) const
{
    if (other.s < this->s)
        return this->s - other.s;
    double endS = ((t_road_lanes*)parent)->getLaneSectionEndS(this->s);
    if (other.s > endS)
        return other.s - endS;
    return 0;
}

}
