
#include "OSM/PriorKnowledgeProvider/PriorKnowledgeProvider__RHT.h"
#include "OSM/Way/Way.h"
#include "Debugger/Main/Logger.h"

namespace _NOSM
{

void PriorKnowledgeProvider__RHT::fillDrivingSide(Way& way)
{
    // Driving side
    // RHT or RHT
    way.osm[_SC_driving_side] = _SC_right;
}

void PriorKnowledgeProvider__RHT::fillLanesCountDirectional(Way &way)
{
    Q_ASSERT(way.laneCount > 0);

    // Number of left lanes, bidirectional lanes, right lanes
    // Think only case of [left]|[bidirectional]|[right], ignore other cases.
    // one sample case : [forward]|[both]|[backward]

    int oldLeftLaneCount = way.leftLaneCount;
    int oldRightLaneCount = way.rightLaneCount;

    if (way.isOneway())
    {
        // Ignore some values
        way.rightLaneCount = way.laneCount;
        way.leftLaneCount = way.bidirectionalLaneCount = 0;
    }
    else if (way.laneCount == 1)
    {
        way.leftLaneCount = way.rightLaneCount = 0;
        way.bidirectionalLaneCount = 1;
    }
    else
    {
        way.bidirectionalLaneCount = way.getMatchedLaneDirectionCount(_SC_both);

        if (way.leftLaneCount <= 0)
        {
            if (way.backwardLaneCount > 0)
            {
                way.leftLaneCount = way.backwardLaneCount;
            }
            else
            {
                int left = way.getMatchedLaneDirectionCount(_SC_backward, true);
                if (left > 0)
                {
                    way.leftLaneCount = left;
                }
                else
                {
                    if (way.forwardLaneCount > 0)
                    {
                        way.leftLaneCount = way.laneCount - way.forwardLaneCount - way.bidirectionalLaneCount;
                    }
                    else if (way.rightLaneCount > 0)
                    {
                        way.leftLaneCount = way.laneCount - way.rightLaneCount - way.bidirectionalLaneCount;
                    }
                    else
                    {
                        way.leftLaneCount = (way.laneCount - way.bidirectionalLaneCount) / 2;
                    }
                }
            }
        }

        way.rightLaneCount = way.laneCount - way.leftLaneCount - way.bidirectionalLaneCount;

        if (way.rightLaneCount < 0)
            way.rightLaneCount = 0;
    }

    if (oldLeftLaneCount != way.leftLaneCount)
    {
        DefaultLogger_File << "Left lane count mismatch (old/new): " << oldLeftLaneCount << " / " << way.leftLaneCount;
    }

    if (oldRightLaneCount != way.rightLaneCount)
    {
        DefaultLogger_File << "Right lane count mismatch (old/new): " << oldRightLaneCount << " / " << way.rightLaneCount;
    }
}

void PriorKnowledgeProvider__RHT::fillAccessLanes(Way& way)
{
    if (way.osm[_SC_access] == _SC_no)
    {
        way.duplicateJoin(_SC_access_lanes_A, _SC_no, way.laneCount);
        way.checkIfEqualToLaneCount(_SC_access_lanes_A);
        return;
    }

    if (way.osm.contains(_SC_access_lanes_A))
    {
        way.appendJoin(_SC_access_lanes_A, "", way.laneCount);
        way.checkIfEqualToLaneCount(_SC_access_lanes_A);
        return;
    }

    QList<QString> lanesAccess = way.getSplit(_SC_access_lanes_backward_A);
    QList<QString> forwardLanesAccess = way.getSplit(_SC_access_lanes_forward_A);
    _NCM::append(lanesAccess, "", way.laneCount - forwardLanesAccess.size());
    lanesAccess.append(forwardLanesAccess);

    way.osm[_SC_access_lanes_A] = _NCM::getJoined(lanesAccess);
    way.checkIfEqualToLaneCount(_SC_access_lanes_A);
}

}
