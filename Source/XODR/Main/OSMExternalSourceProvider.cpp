#include "OSM/OSM.h"
#include "XODR/Main/OSMExternalSourceProvider.h"

namespace _NXODR
{

void OSMExternalSourceProvider::getNearestRoadsForPath(bool useBasicTables
                                                       , const VehiclePosVec& poses
                                                       , _NOSM::WayVec& allOSMWays, _NOSM::WayVec& nearestWays)
{
    _NOSM::getNearestRoadsForPath(useBasicTables, poses, allOSMWays, nearestWays);
}

_NOSM::NodeVec OSMExternalSourceProvider::getNodes(bool useBasicTables, Cell cell)
{
    _NOSM::NodeVec nodes;
    _NOSM::getNodes(useBasicTables, cell, nodes);
    return nodes;
}

}
