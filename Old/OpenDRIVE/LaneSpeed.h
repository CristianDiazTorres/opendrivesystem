#ifndef __OPENDRIVE_LANESPEED_H__
#define __OPENDRIVE_LANESPEED_H__

#include "Common/Common.h"

namespace OpenDRIVE
{


	/**
	* Lane speed class. Contains all the data that describes lane speed record
	*
	*/
    struct LaneSpeed
	{

		/*
		* Parameters that describe the lane speed
		*/
		double s_offset;
		double max;
	public:
		/*
		* Constructor
		*/
        LaneSpeed(double sOffset, double max)
        {
            this->s_offset=sOffset;
            this->max=max;
        }

        LaneSpeed(){}

        bool read(const Common::DomElement& node)
        {
            int checker = DOM_SUCCESS;
            checker += node.QueryDoubleAttribute("sOffset", &this->s_offset);
            checker += node.QueryDoubleAttribute("max", &this->max);
            if (checker != DOM_SUCCESS)
            {
                qDebug() << "Error parsing Lane Weight attributes";
                return false;
            }

            return true;
        }

        void write(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeLaneSpeed = doc.createElement("speed");
            node.appendChild(nodeLaneSpeed);

            nodeLaneSpeed.setDoubleAttribute("sOffset", this->s_offset);
            nodeLaneSpeed.setDoubleAttribute("max", this->max);
        }

		bool IsCompatible(CONST LaneSpeed& other) CONST
		{
			return this->s_offset == other.s_offset &&
				this->max == other.max;
		}

	};

}

#endif // __OPENDRIVE_LANESPEED_H__
