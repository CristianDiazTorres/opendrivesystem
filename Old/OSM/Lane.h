#ifndef __OSM_LANE_H__
#define __OSM_LANE_H__

#include "OSM/DrivingDirection.h"
#include "OSM/RoadMarking.h"
#include "OSM/RoadMarkingColor.h"

namespace _NOSM
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
    inline JsonObject ToQJsonObject() const
    {
        JsonObject obj;

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

    inline operator JsonObject() const
    {
        return ToQJsonObject();
    }
};

typedef const Lane		ConstLane;
typedef Vector<Lane>	LaneVec;
typedef const LaneVec	ConstLaneVec;

}

#endif // __OSM_LANE_H__
