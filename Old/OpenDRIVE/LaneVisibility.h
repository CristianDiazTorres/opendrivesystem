#ifndef __OPENDRIVE_LANEVISIBILITY_H__
#define __OPENDRIVE_LANEVISIBILITY_H__

#include "Common/Common.h"

namespace OpenDRIVE
{
	/**
	* Lane visibility class. Contains all the data that describes lane visibility record
	*
	*
	*
	*
	*
	*/
    struct LaneVisibility
	{

		/*
		* Parameters that describe the lane visibility
		*/
		double s_offset;
		double forward;
		double back;
		double left;
		double right;
	public:
		/*
		* Constructor
		*/
        LaneVisibility(double sOffset, double forward, double back, double left, double right)
        {	this->s_offset=sOffset; this->forward=forward; this->back=back; this->left=left; this->right=right;	}

        LaneVisibility(){}

        bool read(const Common::DomElement& node)
        {
            int checker = DOM_SUCCESS;
            checker += node.QueryDoubleAttribute("sOffset", &this->s_offset);
            checker += node.QueryDoubleAttribute("forward", &this->forward);
            checker += node.QueryDoubleAttribute("back", &this->back);
            checker += node.QueryDoubleAttribute("left", &this->left);
            checker += node.QueryDoubleAttribute("right", &this->right);
            if (checker != DOM_SUCCESS)
            {
                qDebug() << "Error parsing Lane Weight attributes";
                return false;
            }
            return true;
        }

        void write(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeLaneVisibility = doc.createElement("visibility");
            node.appendChild(nodeLaneVisibility);

            nodeLaneVisibility.setDoubleAttribute("sOffset", this->s_offset);
            nodeLaneVisibility.setDoubleAttribute("forward", forward);
            nodeLaneVisibility.setDoubleAttribute("back", back);
            nodeLaneVisibility.setDoubleAttribute("left", left);
            nodeLaneVisibility.setDoubleAttribute("right", right);
        }

		bool IsCompatible(CONST LaneVisibility& other) CONST
		{
			return this->s_offset == other.s_offset &&
				this->forward == other.forward &&
				this->back == other.back &&
				this->left == other.left &&
				this->right == other.right;
		}

	};


}

#endif // __OPENDRIVE_LANEVISIBILITY_H__
