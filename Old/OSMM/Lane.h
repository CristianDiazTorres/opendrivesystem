#ifndef __OSMM_LANE_H__
#define __OSMM_LANE_H__

#include "OSMM/DrivingDirection.h"
#include "OSMM/RoadMarking.h"
#include "OSMM/RoadMarkingColor.h"

namespace OSMM
{

	struct Lane
	{
		int id;
		int previous_id;
		int next_id;
		int maxspeed;
		double width;
		double lateral_offset;

		DrivingDirection driving_direction;
		RoadMarking left_marking;
		RoadMarking right_marking;
		RoadMarkingColor left_marking_color;
		RoadMarkingColor right_marking_color;

	public:
        inline QJsonObject ToQJsonObject() const
		{
			QJsonObject obj;

            obj["id"] = this->id;
            obj["previous_id"] = this->previous_id;
            obj["next_id"] = this->next_id;

			if (this->maxspeed != 0)
                obj["maxspeed"] = this->maxspeed;

			if (this->width > 0)
                obj["width"] = this->width;

            obj["lateral_offset"] = this->lateral_offset;

            obj["driving_direction"] = GetDrivingDirectionString(this->driving_direction);
            obj["left_marking"] = GetRoadMarkingString(this->left_marking);
            obj["right_marking"] = GetRoadMarkingString(this->right_marking);
            obj["left_marking_color"] = GetRoadMarkingColorString(this->left_marking_color);
            obj["right_marking_color"] = GetRoadMarkingColorString(this->right_marking_color);

            return obj;
		}

        inline operator QJsonObject() const
        {
            return ToQJsonObject();
        }
	};

	typedef CONST Lane		ConstLane;
	typedef QVector<Lane>	LaneVec;
	typedef CONST LaneVec	ConstLaneVec;

}

#endif // __OSMM_LANE_H__
