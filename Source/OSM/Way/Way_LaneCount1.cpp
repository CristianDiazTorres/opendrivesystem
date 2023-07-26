#include "OSM/Way/Way.h"

namespace _NOSM
{

void Way::parseLaneCount1()
{
    laneCount = osm[_SC_lanes].toInt();
    leftLaneCount = osm[_SC_lanes_left_A].toInt();
    forwardLaneCount = osm[_SC_lanes_forward_A].toInt();
    bidirectionalLaneCount = osm[_SC_lanes_bidirectional_A].toInt();
    rightLaneCount = osm[_SC_lanes_right_A].toInt();
    backwardLaneCount = osm[_SC_lanes_backward_A].toInt();
}

}
