#ifndef __OPENDRIVE_ROADLINK_H__
#define __OPENDRIVE_ROADLINK_H__

#include "Common/Common.h"

namespace OpenDRIVE
{
	
	//----------------------------------------------------------------------------------
	/**
	 * RoadLink class is used to store information about road's predecessors/successors
	 */
    struct RoadLink
	{

		/**
		 * Base properties of a successor/predecessor record
		 */
		QString element_type;
		QString element_id;
		QString contact_point;
	public:
		/**
		 * Constructor which intializes the base properties
		 */
        RoadLink(QString elementType, QString elementId, QString contactPoint)
        {
            this->element_type = elementType;
            this->element_id = elementId;
            this->contact_point = contactPoint;
        }

        RoadLink(){}

        bool read(const Common::DomElement& node)
        {
            contact_point = "NA";

            int checker = DOM_SUCCESS;
            checker += node.QueryStringAttribute("elementType", &element_type);
            checker += node.QueryStringAttribute("elementId", &element_id);
            if (element_type.compare("road") == 0)
                checker += node.QueryStringAttribute("contactPoint", &contact_point);

            if (checker != DOM_SUCCESS)
            {
                qDebug() << "Error parsing successor/predecessor attributes";
                return false;
            }
            return true;
        }

        void write(QDomDocument& doc, Common::DomElement& node, const QString& name) const
        {
            Common::DomElement nodeLink = doc.createElement(name);
            node.appendChild(nodeLink);

            nodeLink.setAttribute("elementType", this->element_type);
            nodeLink.setAttribute("elementId", this->element_id);
            nodeLink.setAttribute("contactPoint", this->contact_point);
        }

		bool IsCompatible(CONST RoadLink& other) CONST
		{
			return this->element_type == other.element_type &&
				this->element_id == other.element_id &&
				this->contact_point == other.contact_point;
		}


	};



}

#endif // __OPENDRIVE_ROADLINK_H__
