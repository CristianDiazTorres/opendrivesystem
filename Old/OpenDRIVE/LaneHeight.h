#ifndef __OPENDRIVE_LANEHEIGHT_H__
#define __OPENDRIVE_LANEHEIGHT_H__

#include "Common/Common.h"

namespace OpenDRIVE
{
	/**
	* Lane height class. Contains all the data that describes lane access record
	*
	*/
    struct LaneHeight
	{
		/*
		* Parameters that describe the lane height
		*/
		double s_offset;
		double inner;
		double outer;

	public:
		/*
		* Constructors
		*/
        LaneHeight()
        {
            this->s_offset=0;
            this->inner=0;
            this->outer=0;
        }

        LaneHeight (double sOffset, double inner, double outer)
        {
            this->s_offset=sOffset;
            this->inner=inner;
            this->outer=outer;
        }

        bool read(const Common::DomElement& node)
        {
            int checker = DOM_SUCCESS;
            checker += node.QueryDoubleAttribute("sOffset", &this->s_offset);
            checker += node.QueryDoubleAttribute("inner", &this->inner);
            checker += node.QueryDoubleAttribute("outer", &this->outer);
            if (checker != DOM_SUCCESS)
            {
                qDebug() << "Error parsing Lane Weight attributes";
                return false;
            }
            return true;
        }

        void write(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeLaneHeight = doc.createElement("height");
            node.appendChild(nodeLaneHeight);

            nodeLaneHeight.setDoubleAttribute("sOffset", this->s_offset);
            nodeLaneHeight.setDoubleAttribute("inner", this->inner);
            nodeLaneHeight.setDoubleAttribute("outer", this->outer);
        }

		bool IsCompatible(CONST LaneHeight& other) CONST
		{
			return this->s_offset == other.s_offset &&
				this->inner == other.inner &&
				this->outer == other.outer;
		}

	};

	//----------------------------------------------------------------------------------

}

#endif // __OPENDRIVE_LANEHEIGHT_H__
