#include "OpenDRIVE/JunctionConnection.h"

namespace OpenDRIVE
{
	/**
	* Junction connection class. Holds all the information for a connection record
	*
	*/

	/**
	* Constructor. Sets basic junction connection parameters
	* @param id ID within the junction
	* @param incomingRoad ID of the incoming road
	* @param connectingRoad ID of the connecting path
	* @param contactPoint Contact point on the connecting road (start / end)
	*/
	JunctionConnection::JunctionConnection(QString id, QString incomingRoad, QString connectingRoad, QString contactPoint)
	{
		this->id = id;
		this->incoming_road = incomingRoad;
		this->connecting_road = connectingRoad;
		this->contact_point = contactPoint;
	}

    bool JunctionConnection::read(const Common::DomElement& node)
    {
        int checker = DOM_SUCCESS;
        checker += node.QueryStringAttribute("id", &this->id);
        checker += node.QueryStringAttribute("incomingRoad", &this->incoming_road);
        checker += node.QueryStringAttribute("connectingRoad", &this->connecting_road);
        checker += node.QueryStringAttribute("contactPoint", &this->contact_point);
        if (checker != DOM_SUCCESS)
        {
            qDebug() << "Error parsing Junction Connection attributes";
            return false;
        }

        Common::DomElement subNode = node.firstChildElement("laneLink");

        while (!subNode.isNull())
        {
            JunctionLaneLink junctionLaneLink;
            if (junctionLaneLink.read(subNode))
                this->junction_lane_links << junctionLaneLink;
            subNode = subNode.nextSiblingElement("laneLink");
        }

        return true;
    }

    void JunctionConnection::write(QDomDocument& doc, Common::DomElement& node) const
    {
        Common::DomElement nodeJunctionConnection = doc.createElement("connection");
        node.appendChild(nodeJunctionConnection);

        nodeJunctionConnection.setAttribute("id", this->id);
        nodeJunctionConnection.setAttribute("incomingRoad", this->incoming_road);
        nodeJunctionConnection.setAttribute("connectingRoad", this->connecting_road);
        nodeJunctionConnection.setAttribute("contactPoint", this->contact_point);

        for (const JunctionLaneLink& junction_lane_link : this->junction_lane_links)
            junction_lane_link.write(doc, nodeJunctionConnection);
    }
}
