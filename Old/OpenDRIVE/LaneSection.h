#ifndef __OPENDRIVE_LANESECTION_H__
#define __OPENDRIVE_LANESECTION_H__

#include "OpenDRIVE/Lane.h"

namespace OpenDRIVE
{
    struct LaneSectionSample;

	/**
	* Lane section class. Holds all the lane section information
	*
	*/
    struct LaneSection
	{

		/**
		* Record parameters
		*/
		double s;
		QVector<Lane> lanes;

	public:
		/**
		* Constructor. Sets basic lane section parameters
		* @param s s-offset of the lane section
		*/
		LaneSection(double s);
        LaneSection(){}

        bool read(const Common::DomElement& node)
        {
            int checker = DOM_SUCCESS;
            checker += node.QueryDoubleAttribute("s", &this->s);

            if (checker != DOM_SUCCESS)
            {
                qDebug() << "Error parsing Lane Section attributes";
                return false;
            }

            Common::DomElement subNode = node.firstChildElement("left");
            if (!subNode.isNull())
            {
                subNode = subNode.firstChildElement("lane");
                while (!subNode.isNull())
                {
                    Lane lane;
                    if (lane.read(subNode, 1))
                        this->lanes << lane;
                    subNode = subNode.nextSiblingElement("lane");
                }

            }

            subNode = node.firstChildElement("center");
            if (!subNode.isNull())
            {
                subNode = subNode.firstChildElement("lane");
                while (!subNode.isNull())
                {
                    Lane lane;
                    if (lane.read(subNode, 0))
                        this->lanes << lane;
                    subNode = subNode.nextSiblingElement("lane");
                }
            }

            subNode = node.firstChildElement("right");
            if (!subNode.isNull())
            {
                subNode = subNode.firstChildElement("lane");
                while (!subNode.isNull())
                {
                    Lane lane;
                    if (lane.read(subNode, -1))
                        this->lanes << lane;
                    subNode = subNode.nextSiblingElement("lane");
                }
            }

            return true;
        }

        void write(QDomDocument& doc, Common::DomElement& node) const
        {
            Common::DomElement nodeLaneSection = doc.createElement("laneSection");
            node.appendChild(nodeLaneSection);

            nodeLaneSection.setDoubleAttribute("s", this->s);

            //Fill in lane section
            Common::DomElement nodeLanesLeft;
            if (this->GetLeftLaneCount() > 0)
            {
                nodeLanesLeft = doc.createElement("left");
                nodeLaneSection.appendChild(nodeLanesLeft);
            }

            Common::DomElement nodeLanesCenter = doc.createElement("center");
            nodeLaneSection.appendChild(nodeLanesCenter);

            Common::DomElement nodeLanesRight;
            if (this->GetRightLaneCount() > 0)
            {
                nodeLanesRight = doc.createElement("right");
                nodeLaneSection.appendChild(nodeLanesRight);
            }

            for (const Lane& lane : this->lanes)
            {
                if (lane.side == 1)
                {
                    lane.write(doc, nodeLanesLeft);
                }
                else if (lane.side == 0)
                {
                    lane.write(doc, nodeLanesCenter);
                }
                else if (lane.side == -1)
                {
                    lane.write(doc, nodeLanesRight);
                }
            }
        }

		bool IsCompatible(CONST LaneSection& other) CONST;

		/**
		* Get the lane section s-offset
		*/

		/**
		* Get the lane section final s-offset which is the s-offset of the last record of the lane section
		*/
        double GetS2();

		/**
		* Check if the tested s-offset is inside the lane section interval
		* @param A double s-offset value that has to be checked
		* @return Return true if the s-offset value belongs to current lane section, false otherwise
		*/
		bool CheckInterval(double s_check);

		/**
		* Return the lane-0 index in the lanes QVector
		* @return An int value with the index
		*/
		int GetZeroLaneIndex();

		/**
		* Return the number of left lanes
		* @return An int value with the number of left lanes
		*/
        int GetLeftLaneCount() const;

		/**
		* Return the number of central lanes
		* @return An int value with the number of central lanes
		*/
		int GetCenterLaneCount();

		/**
		* Return the number of right lanes
		* @return An int value with the number of right lanes
		*/
        int GetRightLaneCount() const;

	};

}

#endif // __OPENDRIVE_LANESECTION_H__
