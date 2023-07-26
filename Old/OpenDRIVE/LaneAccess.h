#ifndef __OPENDRIVE_LANEACCESS_H__
#define __OPENDRIVE_LANEACCESS_H__

#include "Common/Common.h"

namespace OpenDRIVE
{

	/**
	* Lane access class. Contains all the data that describes lane access record
	*
	*/
    struct LaneAccess
	{
		/*
		* Parameters that describe the lane access
		*/
		double s_offset;
		QString restriction;
	public:
		/*
		* Constructor
		*/
        LaneAccess(double sOffset, QString restriction)
        {
            this->s_offset=sOffset;
            this->restriction = restriction;
        }

        LaneAccess(){}

        bool read(const Common::DomElement& node)
        {
            int checker = DOM_SUCCESS;
            checker += node.QueryDoubleAttribute("sOffset", &this->s_offset);
            checker += node.QueryStringAttribute("restriction", &this->restriction);
            if (checker != DOM_SUCCESS)
            {
                qDebug() << "Error parsing Lane Weight attributes";
                return false;
            }
            return true;
        }

        void write(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeLaneAccess = doc.createElement("access");
            node.appendChild(nodeLaneAccess);

            nodeLaneAccess.setDoubleAttribute("sOffset", this->s_offset);
            nodeLaneAccess.setAttribute("restriction", this->restriction);
        }

		bool IsCompatible(CONST LaneAccess& other) CONST
		{
			return this->s_offset == other.s_offset &&
				this->restriction == other.restriction;
		}
	};

}

#endif // __OPENDRIVE_LANEACCESS_H__
