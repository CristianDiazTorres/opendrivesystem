#ifndef __OPENDRIVE_LANE_H__
#define __OPENDRIVE_LANE_H__

#include "OpenDRIVE/LaneWidth.h"
#include "OpenDRIVE/LaneRoadMark.h"
#include "OpenDRIVE/LaneMaterial.h"
#include "OpenDRIVE/LaneVisibility.h"
#include "OpenDRIVE/LaneSpeed.h"
#include "OpenDRIVE/LaneAccess.h"
#include "OpenDRIVE/LaneHeight.h"

namespace OpenDRIVE
{
	/**
	* Lane class. Holds all the record data that describes a lane
	*
	*/
    struct Lane
	{

		/**
		*	Record parameters
		*/
        int side; //0 = center, -1 = right, 1=left
		int id;
		QString type;
		bool level; //true or false(default)

		//links
		bool predecessor_exists;
		int predecessor;
		bool successor_exists;
		int successor;

		//Width
		QVector <LaneWidth> lane_widths;
		//Road Mark
		QVector <LaneRoadMark> lane_road_marks;
		//Lane Material
		QVector <LaneMaterial> lane_materials;
		//Lane Visibility
		QVector <LaneVisibility> lane_visibilities;
		//Lane Speed
		QVector <LaneSpeed> lane_speeds;
		//Lane Access
		QVector<LaneAccess> lane_accesses;
		//Lane Height
		QVector<LaneHeight> lane_heights;

	public:
		/**
		*	Constructor
		*/
		Lane(int side, int id, QString type, bool level);
        Lane(){}

        bool read(const Common::DomElement& node, int side)
        {
            this->side = side;

            int checker = DOM_SUCCESS;
            checker += node.QueryIntAttribute("id", &this->id);
            checker += node.QueryStringAttribute("type", &this->type);
            checker += node.QueryBoolAttribute("level", &this->level);
            if (checker != DOM_SUCCESS)
            {
                qDebug() << "Error parsing Lane attributes";
                return false;
            }

            //Read Link parameters and add them to the lane if available
            Common::DomElement subNode = node.firstChildElement("link");
            Common::DomElement subSubNode;
            if (!subNode.isNull())
                subSubNode = subNode.firstChildElement("predecessor");
            if (!subSubNode.isNull())
            {
                checker = subSubNode.QueryIntAttribute("id", &predecessor);
            }
            if (!subNode.isNull())
                subSubNode = subNode.firstChildElement("successor");
            if (!subSubNode.isNull())
            {
                checker = subSubNode.QueryIntAttribute("id", &successor);
            }

            //Proceed to the Road width
            subNode = node.firstChildElement("width");
            while (!subNode.isNull())
            {
                LaneWidth laneWidth;
                if (laneWidth.read(subNode))
                    this->lane_widths << laneWidth;
                subNode = subNode.nextSiblingElement("width");
            }

            //Proceed to the Road Mark
            subNode = node.firstChildElement("roadMark");
            while (!subNode.isNull())
            {
                LaneRoadMark laneRoadMark;
                if (laneRoadMark.read(subNode))
                    this->lane_road_marks << laneRoadMark;
                subNode = subNode.nextSiblingElement("roadMark");
            }

            //Proceed to the Lane Material
            subNode = node.firstChildElement("material");
            while (!subNode.isNull())
            {
                LaneMaterial laneMaterial;
                if (laneMaterial.read(subNode))
                    this->lane_materials << laneMaterial;
                subNode = subNode.nextSiblingElement("material");
            }

            //Proceed to the Lane Visibility
            subNode = node.firstChildElement("visibility");
            while (!subNode.isNull())
            {
                LaneVisibility laneVisibility;
                if (laneVisibility.read(subNode))
                    this->lane_visibilities << laneVisibility;
                subNode = subNode.nextSiblingElement("visibility");
            }

            //Proceed to the Lane speed
            subNode = node.firstChildElement("speed");
            while (!subNode.isNull())
            {
                LaneSpeed laneSpeed;
                if (laneSpeed.read(subNode))
                    this->lane_speeds << laneSpeed;
                subNode = subNode.nextSiblingElement("speed");
            }

            //Proceed to the Lane access
            subNode = node.firstChildElement("access");
            while (!subNode.isNull())
            {
                LaneAccess laneAccess;
                if (laneAccess.read(subNode))
                    this->lane_accesses << laneAccess;
                subNode = subNode.nextSiblingElement("access");
            }

            //Proceed to the Lane height
            subNode = node.firstChildElement("height");
            while (!subNode.isNull())
            {
                LaneHeight laneHeight;
                if (laneHeight.read(subNode))
                    this->lane_heights << laneHeight;
                subNode = subNode.nextSiblingElement("height");
            }

            return true;
        }

        void write(QDomDocument& doc, Common::DomElement& node) const
        {
            //Write Lane attributes
            Common::DomElement nodeLane = doc.createElement("lane");
            node.appendChild(nodeLane);

            //Attributes
            nodeLane.setAttribute("id", this->id);
            nodeLane.setAttribute("type", this->type);
            nodeLane.setBoolAttribute("level", this->level);

            //Links
            Common::DomElement nodeLaneLink = doc.createElement("link");
            nodeLane.appendChild(nodeLaneLink);

            if (this->predecessor_exists)
            {
                Common::DomElement nodeLaneLinkPredecessor = doc.createElement("predecessor");
                nodeLaneLink.appendChild(nodeLaneLinkPredecessor);

                nodeLaneLinkPredecessor.setAttribute("id", this->predecessor);
            }
            if (this->successor_exists)
            {
                Common::DomElement nodeLaneLinkSuccessor = doc.createElement("successor");
                nodeLaneLink.appendChild(nodeLaneLinkSuccessor);

                nodeLaneLinkSuccessor.setAttribute("id", this->successor);
            }

            //Lane Width
            for (const LaneWidth& laneWidth : this->lane_widths)
                laneWidth.write(doc, nodeLane);

            //Lane Road Mark
            for (const LaneRoadMark& laneRoadMark : this->lane_road_marks)
                laneRoadMark.write(doc, nodeLane);

            //Lane Material
            for (const LaneMaterial& laneMaterial : this->lane_materials)
                laneMaterial.write(doc, nodeLane);

            //Lane Visibility
            for (const LaneVisibility& laneVisibility : this->lane_visibilities)
                laneVisibility.write(doc, nodeLane);

            //Lane speed
            for (const LaneSpeed& laneSpeed : this->lane_speeds)
                laneSpeed.write(doc, nodeLane);

            //Lane access
            for (const LaneAccess& laneAccess : this->lane_accesses)
                laneAccess.write(doc, nodeLane);

            //Lane height
            for (const LaneHeight& laneHeight : this->lane_heights)
                laneHeight.write(doc, nodeLane);
        }


		/**
		*	Operator less, Used to sort the lanes
		*/
		bool operator<(Lane rhs)const { return (this->id < rhs.id); }

		bool IsCompatible(CONST Lane& other) CONST
		{
			return this->side == other.side &&
				this->type == other.type &&
				this->level == other.level &&
				this->lane_widths.size() == other.lane_widths.size() &&
				this->lane_road_marks.size() == other.lane_road_marks.size() &&
				this->lane_materials.size() == other.lane_materials.size() &&
				this->lane_visibilities.size() == other.lane_visibilities.size() &&
				this->lane_speeds.size() == other.lane_speeds.size() &&
				this->lane_accesses.size() == other.lane_accesses.size() &&
				this->lane_heights.size() == other.lane_heights.size();
		}

		/**
		*	Check the intervals and return the index of the records that applies to the provided s-offset
		*/
		int CheckWidthInterval(double s_check);
		int CheckRoadMarkInterval(double s_check);
		int CheckMaterialInterval(double s_check);
		int CheckVisibilityInterval(double s_check);
		int CheckSpeedInterval(double s_check);
		int CheckAccessInterval(double s_check);
		int CheckHeightInterval(double s_check);


		/**
		*	Evaluate the record and return the width value
		*/
		double GetWidthValue(double s_check);

		/**
		*	Evaluate the record and return the height object
		*/
		LaneHeight GetHeightValue(double s_check);

		/**
		*	Evaluate the road marks records and return the road mark object corresponding to the provided s-offset
		*/
		LaneRoadMark GetRoadMarkValue(double s_check);

	};
}

#endif // __OPENDRIVE_LANE_H__
