#ifndef __OPENDRIVE_ROADNEIGHBOR_H__
#define __OPENDRIVE_ROADNEIGHBOR_H__

#include "Common/Common.h"

namespace OpenDRIVE
{

	//----------------------------------------------------------------------------------
	/**
	 * RoadLink class is used to store information about road's neighbors
	 *
	 *
	 *
	 *
	 */
    struct RoadNeighbor
	{
		/**
		 * Base properties of a neighbor record
		 */
		QString side;
		QString element_id;
		QString direction;

	public:
		/**
		 * Constructor which intializes the base properties
		 */
        RoadNeighbor(QString side, QString elementId, QString direction)
        {
            this->side = side;
            this->element_id = elementId;
            this->direction = direction;
        }

        RoadNeighbor(){}

        bool read(const Common::DomElement& node)
        {
            int checker = DOM_SUCCESS;
            checker += node.QueryStringAttribute("side", &side);
            checker += node.QueryStringAttribute("elementId", &element_id);
            checker += node.QueryStringAttribute("direction", &direction);

            if (checker != DOM_SUCCESS)
            {
                qDebug() << "Error parsing Neighbor attributes";
                return false;
            }
            return true;
        }

        void write(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeLinkNeighbor = doc.createElement("neighbor");
            node.appendChild(nodeLinkNeighbor);

            nodeLinkNeighbor.setAttribute("side", this->side);
            nodeLinkNeighbor.setAttribute("elementId", this->element_id);
            nodeLinkNeighbor.setAttribute("direction", this->direction);
        }

		bool IsCompatible(CONST RoadNeighbor& other) CONST
		{
			return this->side == other.side &&
				this->element_id == other.element_id &&
				this->direction == other.direction;
		}

	};
}

#endif // __OPENDRIVE_ROADNEIGHBOR_H__
