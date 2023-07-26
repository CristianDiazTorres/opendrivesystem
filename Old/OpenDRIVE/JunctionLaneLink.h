#ifndef __OPENDRIVE_JUNCTIONLANELINK_H__
#define __OPENDRIVE_JUNCTIONLANELINK_H__

#include "Common/Common.h"

namespace OpenDRIVE
{
	/**
	 * Junction lane link class. Holds all the information for a lane link record
	 */
    struct JunctionLaneLink
	{

		/**
		 * Record parameters
		 */
		int from;
		int to;

	public:
		/**
		 * Constructor. Initializes the parameters
		 * @param from ID of the incoming lane
		 * @param to ID of the connecting lane
		 */
        JunctionLaneLink(int from, int to)
        {
            this->from = from; this->to = to;
        }

        JunctionLaneLink(){}

        bool read(const Common::DomElement& node)
        {
            int checker = DOM_SUCCESS;
            checker += node.QueryIntAttribute("from", &this->from);
            checker += node.QueryIntAttribute("to", &this->to);
            if (checker != DOM_SUCCESS)
            {
                qDebug() << "Error parsing Junction Lane Link attributes";
                return false;
            }
            return true;
        }

        void write(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeJunctionLaneLink = doc.createElement("laneLink");
            node.appendChild(nodeJunctionLaneLink);

            nodeJunctionLaneLink.setAttribute("from", this->from);
            nodeJunctionLaneLink.setAttribute("to", this->to);
        }

	};
}

#endif // __OPENDRIVE_JUNCTIONLANELINK_H__
