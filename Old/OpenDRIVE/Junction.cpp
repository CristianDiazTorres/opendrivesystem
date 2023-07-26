#include "OpenDRIVE/Junction.h"

namespace OpenDRIVE
{

	/**
	* Junction class. Holds all the junction information
	*
	*
	*
	*
	*/

	/**
	* Constructor. Sets basic junction parameters
	* @param name Name of the junction
	* @param id Unique ID of the junction
	*/
	Junction::Junction(QString name, QString id)
	{
		this->name = name;
		this->id = id;
	}

    bool Junction::read(const Common::DomElement& node)
    {
        int checker = DOM_SUCCESS;
        checker += node.QueryStringAttribute("name", &this->name);
        checker += node.QueryStringAttribute("id", &this->id);
        if (checker != DOM_SUCCESS)
        {
            qDebug() << "Error parsing Junction attributes";
            return false;
        }

        //Read connection parameters and add them to the lane if available
        Common::DomElement subNode = node.firstChildElement("connection");

        while (!subNode.isNull())
        {
            JunctionConnection junctionConnection;
            if (junctionConnection.read(subNode))
                this->junction_connections << junctionConnection;
            subNode = subNode.nextSiblingElement("connection");
        }

        //Read connection parameters and add them to the lane if available
        subNode = node.firstChildElement("priority");

        while (!subNode.isNull())
        {
            JunctionPriorityRoad junctionPriorityRoad;
            if (junctionPriorityRoad.read(subNode))
                this->junction_priority_roads << junctionPriorityRoad;
            subNode = subNode.nextSiblingElement("priority");
        }

        //Read connection parameters and add them to the lane if available
        subNode = node.firstChildElement("controller");

        while (!subNode.isNull())
        {
            JunctionController junctionController;
            if (junctionController.read(subNode))
                this->junction_contollers << junctionController;
            subNode = subNode.nextSiblingElement("controller");
        }

        return true;
    }

    void Junction::write(QDomDocument& doc, Common::DomElement& node) const
    {
        Common::DomElement nodeJunction = doc.createElement("junction");
        node.appendChild(nodeJunction);

        nodeJunction.setAttribute("name", name);
        nodeJunction.setAttribute("id", id);

        for (const JunctionConnection junction_connection : this->junction_connections)
            junction_connection.write(doc, nodeJunction);

        for (const JunctionPriorityRoad junction_priority_road : this->junction_priority_roads)
            junction_priority_road.write(doc, nodeJunction);

        for (const JunctionController& junction_controller : this->junction_contollers)
            junction_controller.write(doc, nodeJunction);
    }

	bool Junction::IsCompatible(CONST Junction& other) CONST
	{
		if (this->name != other.name)
			return false;

		if (this->junction_connections.size() != other.junction_connections.size())
			return false;

		if (this->junction_priority_roads.size() != other.junction_priority_roads.size())
			return false;

		if (this->junction_contollers.size() != other.junction_contollers.size())
			return false;

		return true;
	}

}
