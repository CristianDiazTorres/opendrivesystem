#ifndef __OPENDRIVE_ROADTYPE_H__
#define __OPENDRIVE_ROADTYPE_H__

#include "Common/Common.h"

namespace OpenDRIVE
{
	//----------------------------------------------------------------------------------
	/**
	 * RoadType class is used to store information about a road type record
	 *
	 *
	 *
	 *
	 */
    struct RoadType
	{
		/**
		 * Base properties of a road type
		 */
		double s;
		QString type;
        QString country;

	public:
		/**
		 * Constructor which intializes the base properties
		 */
        RoadType(double s, QString type, QString country)
        {
            this->s = s;
            this->type = type;
            this->country = country;
        }

        RoadType(){}

        bool read(const Common::DomElement& node)
        {
            int checker = DOM_SUCCESS;
            checker += node.QueryDoubleAttribute("s", &s);
            checker += node.QueryStringAttribute("type", &type);
            checker += node.QueryStringAttribute("country", &country);
            if (checker != DOM_SUCCESS)
            {
                qDebug() << "Error parsing Road Type attributes";
                return false;
            }
            return true;
        }

        void write(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeRoadType = doc.createElement("type");
            node.appendChild(nodeRoadType);

            nodeRoadType.setDoubleAttribute("s", this->s);
            nodeRoadType.setAttribute("type", this->type);
            nodeRoadType.setAttribute("country", this->country);
        }

		bool IsCompatible(CONST RoadType& other) CONST
		{
			return this->s == other.s &&
				this->type == other.type;
		}
	};
}

#endif // __OPENDRIVE_ROADTYPE_H__
