#include "XODR/Main/OpenDRIVEBuilder.h"
#include "Debugger/Main/Logger.h"
#include "DB/Main/PGDatabaseConnector.h"

namespace _NXODR
{

bool isSimilarForJunction(const XY& p1, const XY& p2)
{
    return p1.calcDistance(p2) <= 2;
}

_NOD::_junctionId findNearExistingJunctions(QMap<_NOD::_roadId, _NOD::t_road>& odTempRoads, _NOD::t_road& odTempRoad)
{
    static QVector<_NOD::e_contactPoint> contactPoints;
    if (contactPoints.isEmpty())
        contactPoints << _NOD::e_contactPoint::START << _NOD::e_contactPoint::END;

    // We are going to make junction-areas
    // Find only real junctions
    for (int linkType = _NOD::Incoming; linkType < _NOD::LinkTypeCount; linkType ++)
    {
        _NOD::_e_road_link_type oppositeLinkType = (_NOD::_e_road_link_type)(_NOD::Outgoing - linkType);
        for (_NOD::e_contactPoint& contactPointOnThis : contactPoints)
        {
            for (_NOD::_t_road_link_info& odRoadLinkInfo2 :
                 odTempRoad.linkedRoadsInfoPerLTPerCP[contactPointOnThis][(_NOD::_e_road_link_type)linkType])
            {
                _NOD::t_road& odTempRoad2 = odTempRoads[odRoadLinkInfo2.linkedRoadId];
                if (odTempRoad2.junction > 0)
                    return odTempRoad2.junction;

                for (_NOD::_t_road_link_info& odRoadLinkInfo3 :
                     odTempRoad2.linkedRoadsInfoPerLTPerCP[odRoadLinkInfo2.contactPointOnLinkedRoad][oppositeLinkType])
                {
                    _NOD::t_road& odTempRoad3 = odTempRoads[odRoadLinkInfo3.linkedRoadId];
                    if (odTempRoad3.junction > 0)
                        return odTempRoad3.junction;
                }
            }
        }
    }

    return -1;
}

void mergeJunctions(QMap<_NOD::_roadId, _NOD::t_road>& odTempRoads, _NOD::t_road& odTempRoad, int tempRealJunctionIndex)
{
    static QVector<_NOD::e_contactPoint> contactPoints;
    if (contactPoints.isEmpty())
        contactPoints << _NOD::e_contactPoint::START << _NOD::e_contactPoint::END;

    odTempRoad.tempRealJunctionIndex = tempRealJunctionIndex;

    // We are going to make junction-areas
    // Find only real junctions
    for (int linkType = _NOD::Incoming; linkType < _NOD::LinkTypeCount; linkType ++)
    {
        _NOD::_e_road_link_type oppositeLinkType = (_NOD::_e_road_link_type)(_NOD::Outgoing - linkType);
        for (_NOD::e_contactPoint& contactPointOnThis : contactPoints)
        {
            for (_NOD::_t_road_link_info& odRoadLinkInfo2 :
                 odTempRoad.linkedRoadsInfoPerLTPerCP[contactPointOnThis][(_NOD::_e_road_link_type)linkType])
            {
                _NOD::t_road& odTempRoad2 = odTempRoads[odRoadLinkInfo2.linkedRoadId];
                if (odTempRoad2.junction == 0)
                {
                    Q_ASSERT(odTempRoad2.tempRealJunctionIndex == -1 || odTempRoad2.tempRealJunctionIndex == tempRealJunctionIndex);
                    if (odTempRoad2.tempRealJunctionIndex == -1)
                        mergeJunctions(odTempRoads, odTempRoad2, tempRealJunctionIndex);

                    continue;
                }

                for (_NOD::_t_road_link_info& odRoadLinkInfo3 :
                     odTempRoad2.linkedRoadsInfoPerLTPerCP[odRoadLinkInfo2.contactPointOnLinkedRoad][oppositeLinkType])
                {
                    _NOD::t_road& odTempRoad3 = odTempRoads[odRoadLinkInfo3.linkedRoadId];
                    if (odTempRoad3.junction == 0)
                    {
                        Q_ASSERT(odTempRoad3.tempRealJunctionIndex == -1 || odTempRoad3.tempRealJunctionIndex == tempRealJunctionIndex);
                        if (odTempRoad3.tempRealJunctionIndex == -1)
                            mergeJunctions(odTempRoads, odTempRoad3, tempRealJunctionIndex);
                    }
                }
            }
        }
    }
}

void getPredecessorSuccessorLanes(_NOD::t_road& odTempRoad,
                                  bool leftSide,
                                  QVector<_NOD::_t_road_lanes_laneSection_lcr_lane>& predecessorSuccessorLanes)
{
    // TODO: ???!!! lane order may be important

    DefaultLogger << "getPredecessorSuccessorLanes";

    if (leftSide)
    {
        if (!odTempRoad.lanes.laneSection_sequence[0].left_sequence.isEmpty())
        {
            DefaultLogger << " Left : " << odTempRoad.lanes.laneSection_sequence[0].left_sequence[0].lane_sequence.size();
            _NCM::appendForce(predecessorSuccessorLanes, odTempRoad.lanes.laneSection_sequence[0].left_sequence[0].lane_sequence);
        }

        if (!odTempRoad.lanes.laneSection_sequence[0].right_sequence.isEmpty())
        {
            for (_NOD::t_road_lanes_laneSection_right_lane& lane : odTempRoad.lanes.laneSection_sequence[0].right_sequence[0].lane_sequence)
            {
                if (lane.type == _NOD::e_laneType::BIDIRECTIONAL)
                    predecessorSuccessorLanes << lane;
            }
        }
    }
    else // if (!leftSide)
    {
        if (!odTempRoad.lanes.laneSection_sequence[0].right_sequence.isEmpty())
        {
            DefaultLogger << " Right : " << odTempRoad.lanes.laneSection_sequence[0].right_sequence[0].lane_sequence.size();
            _NCM::appendForce(predecessorSuccessorLanes, odTempRoad.lanes.laneSection_sequence[0].right_sequence[0].lane_sequence);
        }

        if (!odTempRoad.lanes.laneSection_sequence[0].left_sequence.isEmpty())
        {
            for (_NOD::t_road_lanes_laneSection_left_lane& lane : odTempRoad.lanes.laneSection_sequence[0].left_sequence[0].lane_sequence)
            {
                if (lane.type == _NOD::e_laneType::BIDIRECTIONAL)
                    predecessorSuccessorLanes << lane;
            }
        }
    }

    DefaultLogger << predecessorSuccessorLanes.size();
    Q_ASSERT(!predecessorSuccessorLanes.isEmpty());
}

void getPredecessorLanes(QMap<_NOD::_roadId, _NOD::t_road>& odTempRoads,
                         _NOD::_t_road_link_info& odRoadLinkInfo,
                         QVector<_NOD::_t_road_lanes_laneSection_lcr_lane>& predecessorLanes)
{
    Q_ASSERT(odRoadLinkInfo.linkType == _NOD::Incoming);

    _NOD::t_road& odTempRoad = odTempRoads[odRoadLinkInfo.linkedRoadId];
    bool leftSide = odTempRoad.rule == _NOD::e_trafficRule::LHT;
    if (odRoadLinkInfo.contactPointOnLinkedRoad == _NOD::e_contactPoint::START)
        leftSide = !leftSide;

    getPredecessorSuccessorLanes(odTempRoad, leftSide, predecessorLanes);
}

void getSuccessorLanes(QMap<_NOD::_roadId, _NOD::t_road>& odTempRoads,
                       _NOD::_t_road_link_info& odRoadLinkInfo,
                       QVector<_NOD::_t_road_lanes_laneSection_lcr_lane>& successorLanes)
{
    Q_ASSERT(odRoadLinkInfo.linkType == _NOD::Incoming);

    _NOD::t_road& odTempRoad = odTempRoads[odRoadLinkInfo.thisId];
    bool leftSide = odTempRoad.rule == _NOD::e_trafficRule::LHT;
    if (odRoadLinkInfo.contactPointOnThis == _NOD::e_contactPoint::END)
        leftSide = !leftSide;

    getPredecessorSuccessorLanes(odTempRoad, leftSide, successorLanes);
}

void addLaneLinks(_NOD::t_junction_connection& odJunctionConnection,
                  QVector<_NOD::_t_road_lanes_laneSection_lcr_lane>& predecessorLanes,
                  QVector<_NOD::_t_road_lanes_laneSection_lcr_lane>& successorLanes)
{
    Q_ASSERT(!predecessorLanes.isEmpty());
    Q_ASSERT(!successorLanes.isEmpty());

    int maxCount = qMax(predecessorLanes.size(), successorLanes.size());
    for (int i = 0; i < maxCount; i ++)
    {
        _NOD::_t_road_lanes_laneSection_lcr_lane& predecessorLane = predecessorLanes[qMin(i, predecessorLanes.size() - 1)];
        _NOD::_t_road_lanes_laneSection_lcr_lane& successorLane = successorLanes[qMin(i, successorLanes.size() - 1)];

        _NOD::t_junction_connection_laneLink odLaneLink;
        odLaneLink.from = predecessorLane.id;
        odLaneLink.to = successorLane.id;
        odJunctionConnection.laneLink_sequence << odLaneLink;
    }
}

void addLaneLinks(_NOD::t_junction_connection& odJunctionConnection,
                  QMap<_NOD::_roadId, _NOD::t_road>& odTempRoads,
                  _NOD::_t_road_link_info& odRoadLinkInfo)
{
    Q_ASSERT(odRoadLinkInfo.linkType == _NOD::Incoming);

    QVector<_NOD::_t_road_lanes_laneSection_lcr_lane> predecessorLanes, successorLanes;
    getPredecessorLanes(odTempRoads, odRoadLinkInfo, predecessorLanes);
    getSuccessorLanes(odTempRoads, odRoadLinkInfo, successorLanes);
    addLaneLinks(odJunctionConnection, predecessorLanes, successorLanes);
}

void addRealJunctionConnection(DatabaseConnector& databaseConnector,
                               _NOD::t_junction& odJunction,
                               QMap<_NOD::_roadId, _NOD::t_road>& odTempRoads,
                               _NOD::_t_road_link_info& odRoadLinkInfo)
{
    Q_ASSERT(odRoadLinkInfo.linkType == _NOD::Incoming);

    // real junction
    _NOD::t_junction_connection odJunctionConnection;
    odJunctionConnection.id = databaseConnector.getNewID();
    odJunctionConnection.type = _NOD::e_junction_type::DEFAULT;
    odJunctionConnection.incomingRoad = odRoadLinkInfo.linkedRoadId;
    odJunctionConnection.connectingRoad = odRoadLinkInfo.thisId;
    odJunctionConnection.contactPoint = odRoadLinkInfo.contactPointOnThis;

    addLaneLinks(odJunctionConnection, odTempRoads, odRoadLinkInfo);

    odJunction.connection_sequence << odJunctionConnection;
}

void addRoadLink(_NOD::t_road& odRoad, _NOD::_t_road_link_info& odRoadLinkInfo)
{
    // TODO: ???!!! need to re-check
    if (odRoadLinkInfo.linkType == _NOD::Incoming)
    {
        if (odRoadLinkInfo.contactPointOnThis == _NOD::e_contactPoint::END)
            return;
    }
    else
    {
        if (odRoadLinkInfo.contactPointOnThis == _NOD::e_contactPoint::START)
            return;
    }

    if (odRoad.link_sequence.isEmpty())
    {
        odRoad.link_sequence.resize(1);
    }
    else
    {
        // TODO: ???!!! need to re-check
        if (odRoadLinkInfo.linkType == _NOD::Incoming)
        {
            if (!odRoad.link_sequence[0].predecessor_sequence.isEmpty())
                return;
        }
        else
        {
            if (!odRoad.link_sequence[0].successor_sequence.isEmpty())
                return;
        }
    }

    _NOD::t_road_link_predecessorSuccessor predecessorSuccessor;
    predecessorSuccessor.elementId = odRoadLinkInfo.linkedRoadId;
    predecessorSuccessor.contactPoint = odRoadLinkInfo.contactPointOnLinkedRoad;
    predecessorSuccessor.elementType = _NOD::e_road_link_elementType::ROAD;

    if (odRoadLinkInfo.linkType == _NOD::Incoming)
        odRoad.link_sequence[0].predecessor_sequence << predecessorSuccessor;
    else
        odRoad.link_sequence[0].successor_sequence << predecessorSuccessor;
}

void addJunctionPredecessor(_NOD::t_junction_connection& odJunctionConnection,
                            QMap<_NOD::_roadId, _NOD::t_road>& odTempRoads,
                            _NOD::_t_road_link_info& odRoadLinkInfo)
{
    Q_ASSERT(odRoadLinkInfo.linkType == _NOD::Incoming);

    _NOD:: t_junction_predecessorSuccessor predecessor;
    predecessor.elementId = odRoadLinkInfo.linkedRoadId;

    if (odRoadLinkInfo.contactPointOnLinkedRoad == _NOD::e_contactPoint::START)
    {
        predecessor.elementS = 0;
        predecessor.elementDir = _NOD::e_elementDir::MINUS;
    }
    else
    {
        predecessor.elementS = odTempRoads[predecessor.elementId].planView.geometry_sequence.last().s;
        predecessor.elementDir = _NOD::e_elementDir::PLUS;
    }

    odJunctionConnection.predecessor_sequence << predecessor;
}

void addJunctionSuccessor(_NOD::t_junction_connection& odJunctionConnection,
                          QMap<_NOD::_roadId, _NOD::t_road>& odTempRoads,
                          _NOD::_t_road_link_info& odRoadLinkInfo)
{
    Q_ASSERT(odRoadLinkInfo.linkType == _NOD::Incoming);

    _NOD:: t_junction_predecessorSuccessor successor;
    successor.elementId = odRoadLinkInfo.thisId;

    if (odRoadLinkInfo.contactPointOnThis == _NOD::e_contactPoint::START)
    {
        successor.elementS = 0;
        successor.elementDir = _NOD::e_elementDir::PLUS;
    }
    else
    {
        successor.elementS = odTempRoads[successor.elementId].planView.geometry_sequence.last().s;
        successor.elementDir = _NOD::e_elementDir::MINUS;
    }

    odJunctionConnection.successor_sequence << successor;
}

void addVirtualJunctionConnection(DatabaseConnector& databaseConnector,
                                  _NOD::t_junction& odJunction,
                                  QMap<_NOD::_roadId, _NOD::t_road>& odTempRoads,
                                  _NOD::_t_road_link_info& odRoadLinkInfo)
{
    Q_ASSERT(odRoadLinkInfo.linkType == _NOD::Incoming);

    DefaultLogger << "addVirtualJunctionConnection" << odRoadLinkInfo.linkedRoadId << "=>" << odRoadLinkInfo.thisId;
    DefaultLogger << "OSM id" << odTempRoads[odRoadLinkInfo.linkedRoadId].referenceId <<
             "=>" << odTempRoads[odRoadLinkInfo.thisId].referenceId;

    // real junction
    _NOD::t_junction_connection odJunctionConnection;
    odJunctionConnection.id = databaseConnector.getNewID();
    odJunctionConnection.type = _NOD::e_junction_type::VIRTUAL;

    addJunctionPredecessor(odJunctionConnection, odTempRoads, odRoadLinkInfo);
    addJunctionSuccessor(odJunctionConnection, odTempRoads, odRoadLinkInfo);
    addLaneLinks(odJunctionConnection, odTempRoads, odRoadLinkInfo);

    odJunction.connection_sequence << odJunctionConnection;
}

void OpenDRIVEBuilder::updateNeighbor(DatabaseConnector& databaseConnector,
                                      const VehiclePos& pos,
                                      CardinalDirection direction)
{
    DefaultLogger << "Now updating neighbour junctions/roadlinks : " << _NGC::toString(direction);

    // Center
    LLCoordSysXYCell center;
    center.setNeighbourCellCenterFrom(pos, direction);

    updateJunctionLink(databaseConnector, center);
}

void OpenDRIVEBuilder::updateJunctionLink(DatabaseConnector &databaseConnector, const LLCoordSysXYCell &pos)
{
    DefaultLogger << "Now updating junctions/roadlinks : " << pos.getName();

    // Center content
    //_NOD::OpenDRIVE centerODC = databaseConnector.get(pos);
    _NOD::OpenDRIVE centerODC = PGDatabaseConnector_getDefaultInstance.getXODRContent(pos);
    centerODC.setParent();
    if (centerODC.road_sequence.isEmpty())
    {
        DefaultLogger << "Empty content 0000000000000";
        return;
    }

    // Remove old junctions and road links from center content
    centerODC.removeJunctions();
    centerODC.removeRoadLinks();

    // Roads map for center content and neighbour contents
    // We will work using this map
    QMap<_NOD::_roadId, _NOD::t_road> odTempRoads;

    // Add roads from center content to roads map
    for (_NOD::t_road& odRoad : centerODC.road_sequence)
    {
        odRoad.calcStartEndOneway();
        odTempRoads[odRoad.id] = odRoad;
    }

    // Process neighbour contents
    for (int i = 0; i < _NGC::DirectionCount; i ++)
    {
        // Neighbour center
        LLCoordSysXYCell neighbourCenter;
        neighbourCenter.setNeighbourCellCenterFrom(pos, (CardinalDirection)i);

        DefaultLogger << "Loading neighbour's neighbour: " << _NGC::toString((CardinalDirection)i);

        // Load neighbour content
        //_NOD::OpenDRIVE neighbourODC = databaseConnector.get(neighbourCenter);
        _NOD::OpenDRIVE neighbourODC = PGDatabaseConnector_getDefaultInstance.getXODRContent(neighbourCenter);
        neighbourODC.setParent();

        // Add roads from neighbour content to roads map
        for (_NOD::t_road& odRoad : neighbourODC.road_sequence)
        {
            odRoad.calcStartEndOneway();
            odTempRoads[odRoad.id] = odRoad;
        }
    }

    // Process every 2 roads pair in roads map
    QMap<_NOD::_roadId, _NOD::t_road>::Iterator iter1, iter2;

    // First loop
    for (iter1 = odTempRoads.begin(); iter1 != odTempRoads.end(); iter1 ++)
    {
        _NOD::_roadId roadId1 = iter1.key();
        _NOD::t_road& odTempRoad1 = iter1.value();

        // Second loop
        for (iter2 = odTempRoads.begin(); iter2 != odTempRoads.end(); iter2 ++)
        {
            if (iter2 == iter1)
                continue;

            _NOD::_roadId roadId2 = iter2.key();
            _NOD::t_road& odTempRoad2 = iter2.value();

            // We check only road1=>road2
            // Compare road1 and road2

            // Check connection for (r1 start, r1 end) => (r2 start, r2 end)
            if (isSimilarForJunction(odTempRoad1.end, odTempRoad2.start))
            {
                odTempRoad1.addOutgoingLink(_NOD::e_contactPoint::END, roadId2, _NOD::e_contactPoint::START);
                odTempRoad2.addIncomingLink(_NOD::e_contactPoint::START, roadId1, _NOD::e_contactPoint::END);
            }

            // Check connection for (r1 end, r1 start) => (r2 end, r2 start)
            if (!odTempRoad1.oneway && !odTempRoad2.oneway &&
                isSimilarForJunction(odTempRoad1.start, odTempRoad2.end))
            {
                odTempRoad1.addOutgoingLink(_NOD::e_contactPoint::START, roadId2, _NOD::e_contactPoint::END);
                odTempRoad2.addIncomingLink(_NOD::e_contactPoint::END, roadId1, _NOD::e_contactPoint::START);
            }

            // (r1 end, r1 start) => (r2 start, r2 end)
            if (!odTempRoad1.oneway &&
                isSimilarForJunction(odTempRoad1.start, odTempRoad2.start))
            {
                odTempRoad1.addOutgoingLink(_NOD::e_contactPoint::START, roadId2, _NOD::e_contactPoint::START);
                odTempRoad2.addIncomingLink(_NOD::e_contactPoint::START, roadId1, _NOD::e_contactPoint::START);
            }

            // (r1 start, r1 end) => (r2 end, r2 start)
            if (!odTempRoad2.oneway &&
                isSimilarForJunction(odTempRoad1.end, odTempRoad2.end))
            {
                odTempRoad1.addOutgoingLink(_NOD::e_contactPoint::END, roadId2, _NOD::e_contactPoint::END);
                odTempRoad2.addIncomingLink(_NOD::e_contactPoint::END, roadId1, _NOD::e_contactPoint::END);
            }
        }
    }

    // Merge real junction
    for (_NOD::t_road& odRoad : centerODC.road_sequence)
    {
        _NOD::t_road& odTempRoad = odTempRoads[odRoad.id];
        if (odTempRoad.junction == 0)
        {
            _NOD::_junctionId nearJunctionId = findNearExistingJunctions(odTempRoads, odTempRoad);
            if (nearJunctionId > 0)
                odRoad.junction = odTempRoad.junction = nearJunctionId;
        }
    }

    int realJunctionCount = 0;
    for (_NOD::t_road& odRoad : centerODC.road_sequence)
    {
        _NOD::t_road& odTempRoad = odTempRoads[odRoad.id];
        if (odTempRoad.junction == 0 && odTempRoad.tempRealJunctionIndex == -1)
            mergeJunctions(odTempRoads, odTempRoad, realJunctionCount ++);
    }

    // Add real junction
    centerODC.junction_sequence.resize(realJunctionCount);
    for (int i = 0; i < realJunctionCount; i ++)
    {
        centerODC.junction_sequence[i].id = databaseConnector.getNewID();
        centerODC.junction_sequence[i].type = _NOD::e_junction_type::DEFAULT;
    }

    // Center content's bound
    // We will ignore junction candidates outside of this bound
    QRectF bound = pos.getCellBoundInDegrees();

    for (_NOD::t_road& odRoad : centerODC.road_sequence)
    {
        _NOD::t_road& odTempRoad = odTempRoads[odRoad.id];

        if (odTempRoad.junction == 0)
        {
            _NOD::t_junction& odJunction = centerODC.junction_sequence[odTempRoad.tempRealJunctionIndex];
            odRoad.junction = odJunction.id;

            if (!odRoad.junctionType.isEmpty())
                odJunction.name = odRoad.junctionType;

            for (_NOD::_t_road_link_info& odRoadLinkInfo : odTempRoad.incomingRoadsInfo)
            {
                if (odRoad.referenceId == odTempRoads[odRoadLinkInfo.linkedRoadId].referenceId)
                    addRoadLink(odRoad, odRoadLinkInfo);
                else
                    addRealJunctionConnection(databaseConnector, odJunction, odTempRoads, odRoadLinkInfo);
            }

            for (_NOD::_t_road_link_info& odRoadLinkInfo : odTempRoad.outgoingRoadsInfo)
                if (odRoad.referenceId == odTempRoads[odRoadLinkInfo.linkedRoadId].referenceId)
                    addRoadLink(odRoad, odRoadLinkInfo);
        }
        else
        {
            static QVector<_NOD::e_contactPoint> contactPoints;
            if (contactPoints.isEmpty())
                contactPoints << _NOD::e_contactPoint::START << _NOD::e_contactPoint::END;

            for (_NOD::e_contactPoint contactPointOnThis : contactPoints)
            {
                if (odTempRoad.linkedRoadsPerCP[contactPointOnThis].size() == 1)
                {
                    for (int linkType = _NOD::Incoming; linkType < _NOD::LinkTypeCount; linkType ++)
                        for (_NOD::_t_road_link_info& odRoadLinkInfo : odTempRoad.linkedRoadsInfoPerLTPerCP[contactPointOnThis][(_NOD::_e_road_link_type)linkType])
                            addRoadLink(odRoad, odRoadLinkInfo);
                }
                else if (!odTempRoad.linkedRoadsInfoPerLTPerCP[contactPointOnThis][_NOD::Incoming].isEmpty())
                {
                    // Roads count at contact point
                    int count = odTempRoad.linkedRoadsInfoPerLTPerCP[contactPointOnThis][_NOD::Incoming].size() + 1;

                    // Calculate averaged contact XY
                    XY contactXY = contactPointOnThis == _NOD::e_contactPoint::START ? odTempRoad.start : odTempRoad.end;

                    for (_NOD::_t_road_link_info& odRoadLinkInfo : odTempRoad.linkedRoadsInfoPerLTPerCP[contactPointOnThis][_NOD::Incoming])
                    {
                        _NOD::t_road& odTempRoad2 = odTempRoads[odRoadLinkInfo.linkedRoadId];
                        contactXY += odRoadLinkInfo.contactPointOnLinkedRoad == _NOD::e_contactPoint::START ? odTempRoad2.start : odTempRoad2.end;
                    }

                    contactXY /= count;
                    LLCoordSysXYCell contactPos;
                    contactPos.setFromXY(contactXY, pos);

                    // Check if outside of bound
                    if (contactPos.lon < bound.left() || contactPos.lon >= bound.right() ||
                        contactPos.lat < bound.top() || contactPos.lat >= bound.bottom())
                        continue;

                    _NOD::t_junction odJunction;
                    odJunction.id = databaseConnector.getNewID();
                    odJunction.type = _NOD::e_junction_type::VIRTUAL;

                    for (_NOD::_t_road_link_info& odRoadLinkInfo : odTempRoad.linkedRoadsInfoPerLTPerCP[contactPointOnThis][_NOD::Incoming])
                        addVirtualJunctionConnection(databaseConnector, odJunction, odTempRoads, odRoadLinkInfo);

                    centerODC.junction_sequence << odJunction;
                }
            }
        }
    }

    //databaseConnector.updateCacheOnly(centerODC);
    PGDatabaseConnector_getDefaultInstance.updateXODRContent(pos, centerODC);
}

}
