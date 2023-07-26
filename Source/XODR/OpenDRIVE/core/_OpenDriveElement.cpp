#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"
#include "XODR/OpenDRIVE/core/OpenDRIVE.h"
#include "DB/Main/PGDatabaseConnector.h"
#include "XODR/OpenDRIVE/road/t_road.h"

namespace _NOD
{

XY _OpenDriveElement::getJunctionPos(const OpenDRIVE& content, const t_junction& junction)
{
    Cell cell(content.getCell().cellRow, content.getCell().cellCol);

    QMap<_roadId, t_road> roads;

    for (const t_road& road : content.road_sequence)
        roads[road.id] = road;

    for (int i = 0; i < _NGC::DirectionCount; i ++)
    {
        Cell neighbour;
        neighbour.setFromLL(cell.getNeighbourCenter((CardinalDirection)i));
        OpenDRIVE neighbourContent = PGDatabaseConnector_getDefaultInstance.getXODRContent(neighbour);
        neighbourContent.setParent();
        for (const t_road& road : neighbourContent.road_sequence)
            roads[road.id] = road;
    }

    XY point(0, 0);
    int count = 0;

    for (const t_junction_connection& connection : junction.connection_sequence)
    {
        if (connection.connectingRoad != INTEGER_INVALID_VALUE && roads.contains(connection.connectingRoad))
        {
            point += roads[connection.connectingRoad].getPoint(connection.contactPoint);
            count ++;
        }

        for (const t_junction_predecessorSuccessor& predecessor : connection.predecessor_sequence)
        {
            if (predecessor.elementId != INTEGER_INVALID_VALUE && roads.contains(predecessor.elementId))
            {
                point += roads[predecessor.elementId].getPoint(predecessor.elementS);
                count ++;
            }
        }

        for (const t_junction_predecessorSuccessor& successor : connection.successor_sequence)
        {
            if (successor.elementId != INTEGER_INVALID_VALUE && roads.contains(successor.elementId))
            {
                point += roads[successor.elementId].getPoint(successor.elementS);
                count ++;
            }
        }
    }

    if (count == 0)
        return point;

    point.rx() /= count;
    point.ry() /= count;

    return point;
}

double a_s::calcDistance(const a_s& other) const
{
    return fabs(s - other.s);
}

double a_s::calcDistance(const a_s_t& other) const
{
    return fabs(s - other.s);
}

void a_s::updateST(const a_s_t& other)
{
    s = other.s;
}

double a_s_t::calcDistance(const a_s_t& other) const
{
    double ds = s - other.s;
    double dt = t - other.t;
    return sqrt(ds * ds + dt * dt);
}

void a_s_t::updateST(const a_s_t& other)
{
    s = other.s;
    t = other.t;
}

void a_s_t::calcAbsolutePos(t_road& road)
{
    road.calcXY(*this, *this);
}

void a_s_t::calcRelativePos(t_road& road)
{
    road.calcST(*this, *this);
}

}
