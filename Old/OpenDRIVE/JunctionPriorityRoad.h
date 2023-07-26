#ifndef __OPENDRIVE_JUNCTIONPRIORITYROAD_H__
#define __OPENDRIVE_JUNCTIONPRIORITYROAD_H__

#include "Common/Common.h"

namespace OpenDRIVE
{
	/**
	 * Junction priority class. Holds all the information for a priority record
	 *
	 */
    struct JunctionPriorityRoad
	{

		/**
		 * Record parameters
		 */
        QString high;
		QString low;
	public:

		/**
		 * Constructor. Initializes the parameters
		 * @param high ID of the connecting road with higher priority
		 * @param low ID of the connecting road with lower priority
		 */
        JunctionPriorityRoad(QString high, QString low)
        {
            this->high  = high;
            this->low = low;
        }

        JunctionPriorityRoad(){}

        bool read(const Common::DomElement& node)
        {
            int checker = DOM_SUCCESS;
            checker += node.QueryStringAttribute("high", &this->high);
            checker += node.QueryStringAttribute("low", &this->low);
            if (checker != DOM_SUCCESS)
            {
                qDebug() << "Error parsing Junction Priority attributes";
                return false;
            }
            return true;
        }

        void write(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeJunctionPriority = doc.createElement("priority");
            node.appendChild(nodeJunctionPriority);

            nodeJunctionPriority.setAttribute("high", this->high);
            nodeJunctionPriority.setAttribute("low", this->low);
        }

	};
}

#endif // __OPENDRIVE_JUNCTIONPRIORITYROAD_H__
