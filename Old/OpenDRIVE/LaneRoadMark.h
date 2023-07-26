#ifndef __OPENDRIVE_LANEROADMARK_H__
#define __OPENDRIVE_LANEROADMARK_H__

#include "Common/Common.h"

namespace OpenDRIVE
{


	/**
	* Road mark class. Holds all the data that describes a road mark
	*
	*/
    struct LaneRoadMark
	{


		/*
		* Parameters of the road mark
		*/
		double s_offset;
		QString type;
		QString weight;
		QString color;
		double width;
		QString lane_change;

	public:
		/*
		* Constructors
		*/
        LaneRoadMark()
        {
            this->s_offset=0;
            this->type="none";
            this->weight="standard";
            this->color="standard";
            this->width=0.75;
            this->lane_change="both";
        }

        LaneRoadMark(double sOffset, QString type, QString weight, QString color, double width, QString laneChange)
        {
            this->s_offset=sOffset;
            this->type=type;
            this->weight=weight;
            this->color=color;
            this->width=width;
            this->lane_change=laneChange;
        }

        LaneRoadMark(double sOffset, QString type, QString weight, QString color, double width)
        {
            this->s_offset=sOffset;
            this->type=type;
            this->weight=weight;
            this->color=color;
            this->width=width;
            this->lane_change="both";
        }

        bool read(const Common::DomElement& node)
        {
            int checker = DOM_SUCCESS;
            checker += node.QueryDoubleAttribute("sOffset", &this->s_offset);
            checker += node.QueryStringAttribute("type", &this->type);
            checker += node.QueryStringAttribute("weight", &this->weight);
            checker += node.QueryStringAttribute("color", &this->color);
            if (checker != DOM_SUCCESS)
            {
                qDebug() << "Error parsing Lane Weight attributes";
                return false;
            }

            checker = node.QueryDoubleAttribute("width", &width);
            if (checker != DOM_SUCCESS)
            {
                width = 0;
            }

            checker = node.QueryStringAttribute("laneChange", &this->lane_change);
            if (checker != DOM_SUCCESS)
            {
                this->lane_change = "both";
            }

            return true;
        }

        void write(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeLaneRoadMark = doc.createElement("roadMark");
            node.appendChild(nodeLaneRoadMark);

            nodeLaneRoadMark.setDoubleAttribute("sOffset", this->s_offset);
            nodeLaneRoadMark.setAttribute("type", this->type);
            nodeLaneRoadMark.setAttribute("weight", this->weight);
            nodeLaneRoadMark.setAttribute("color", this->color);
            nodeLaneRoadMark.setDoubleAttribute("width", this->width);
            nodeLaneRoadMark.setAttribute("laneChange", this->lane_change);
        }

		bool IsCompatible(CONST LaneRoadMark& other) CONST
		{
			return this->s_offset == other.s_offset &&
				this->type == other.type &&
				this->weight == other.weight &&
				this->color == other.color &&
				this->width == other.width &&
				this->lane_change == other.lane_change;
		}

	};
}

#endif // __OPENDRIVE_LANEROADMARK_H__
