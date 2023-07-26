#include "OSM/Way/Way.h"

namespace _NOSM
{

void Way::parseLaneCount2()
{
    // Adjust number of lanes
    if (laneCount <= 0)
    {
        int count = getSplit(_SC_width_lanes_A).size();
        if (count > 0)
        {
            laneCount = count;
        }
        else if (isOneway())
        {
            if (leftLaneCount > 0)
            {
                laneCount = leftLaneCount;
            }
            else if (rightLaneCount > 0)
            {
                laneCount = rightLaneCount;
            }
            else if (forwardLaneCount > 0)
            {
                laneCount = forwardLaneCount;
            }
            else if (backwardLaneCount > 0)
            {
                laneCount = backwardLaneCount;
            }
        }
        else if (forwardLaneCount + backwardLaneCount > 0)
        {
            // Ignore bidirectional lanes
            laneCount = forwardLaneCount + backwardLaneCount;
        }
        else if (leftLaneCount + rightLaneCount > 0)
        {
            // Ignore bidirectional lanes
            laneCount = leftLaneCount + rightLaneCount;
        }

        // Can try to other "...:lanes:..." attrs
        // TODO: ???!!!
    }
}

}
