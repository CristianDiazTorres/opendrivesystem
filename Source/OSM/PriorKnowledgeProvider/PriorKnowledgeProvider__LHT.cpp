
#include "OSM/PriorKnowledgeProvider/PriorKnowledgeProvider__LHT.h"
#include "OSM/Way/Way.h"
#include "Debugger/Main/Logger.h"

namespace _NOSM
{

void PriorKnowledgeProvider__LHT::fillDrivingSide(Way& way)
{
    // Driving side
    // LHT or RHT
    way.osm[_SC_driving_side] = _SC_left;
}

void PriorKnowledgeProvider__LHT::fillLanesCountDirectional(Way &way)
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
        way.leftLaneCount = way.laneCount;
        way.rightLaneCount = way.bidirectionalLaneCount = 0;

    }
    else if (way.laneCount == 1)
    {
        way.leftLaneCount = way.rightLaneCount = 0;
        way.bidirectionalLaneCount = 1;
    }
    else
    {
        way.bidirectionalLaneCount = way.getMatchedLaneDirectionCount(_SC_both);

        if (way.rightLaneCount <= 0)
        {
            if (way.backwardLaneCount > 0)
            {
                way.rightLaneCount = way.backwardLaneCount;
            }
            else
            {
                int right = way.getMatchedLaneDirectionCount(_SC_backward, false);
                if (right > 0)
                {
                    way.rightLaneCount = right;
                }
                else
                {
                    if (way.forwardLaneCount > 0)
                    {
                        way.rightLaneCount = way.laneCount - way.forwardLaneCount - way.bidirectionalLaneCount;
                    }
                    else if (way.leftLaneCount > 0)
                    {
                        way.rightLaneCount = way.laneCount - way.leftLaneCount - way.bidirectionalLaneCount;
                    }
                    else
                    {
                        way.rightLaneCount = (way.laneCount - way.bidirectionalLaneCount) / 2;
                    }
                }
            }
        }

        way.leftLaneCount = way.laneCount - way.rightLaneCount - way.bidirectionalLaneCount;

        if (way.leftLaneCount < 0)
            way.leftLaneCount = 0;
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

void PriorKnowledgeProvider__LHT::fillAccessLanes(Way& way)
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

    DefaultLogger_File << "-------------Lanes Access-----------";

    DefaultLogger_File << "way.laneCount" << ":" << way.laneCount;

    if (way.osm.contains(_SC_access_lanes_forward_A))
        DefaultLogger_File << "_SC_access_lanes_forward_A" << ":" << way.osm[_SC_access_lanes_forward_A];

    QList<QString> lanesAccess = way.getSplit(_SC_access_lanes_forward_A);
    DefaultLogger_File << "lanesAccess.size()" << ":" << lanesAccess.size();

    if (way.osm.contains(_SC_access_lanes_backward_A))
        DefaultLogger_File << "_SC_access_lanes_backward_A" << ":" << way.osm[_SC_access_lanes_backward_A];

    QList<QString> backwardLanesAccess = way.getSplit(_SC_access_lanes_backward_A);
    DefaultLogger_File << "backwardLanesAccess.size()" << ":" << backwardLanesAccess.size();

    _NCM::append(lanesAccess, "", way.laneCount - backwardLanesAccess.size());
    DefaultLogger_File << "lanesAccess.size()" << ":" << lanesAccess.size();

    lanesAccess.append(backwardLanesAccess);
    DefaultLogger_File << "lanesAccess.size()" << ":" << lanesAccess.size();

    way.osm[_SC_access_lanes_A] = _NCM::getJoined(lanesAccess);
    DefaultLogger_File << "_SC_access_lanes_A" << ":" << way.osm[_SC_access_lanes_A];

    DefaultLogger_File << "way.laneCount" << ":" << way.laneCount;

    way.checkIfEqualToLaneCount(_SC_access_lanes_A);
}

}
