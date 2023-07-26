#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

void OSMToOpenDRIVE::convertLane(DatabaseConnector& database_connector, const _NOSM::Way& osmWay, _NOD::t_road& odRoad)
{
    Q_UNUSED(database_connector);

    odRoad.lanes.laneSection_sequence.resize(1);

    if (osmWay.isOneway()) // yes, true, 1, -1, reverse, reversible, alternating
        convertLane_Oneway(database_connector, osmWay, odRoad);
    else if (osmWay.laneCount == 1)
        convertLane_Bidirectional_OneLane(database_connector, osmWay, odRoad);
    else
        convertLane_Bidirectional_MultiLanes(database_connector, osmWay, odRoad);
}

}
