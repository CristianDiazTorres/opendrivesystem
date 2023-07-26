#pragma once

#include "OSMM/LaneSection.h"

namespace OSMM
{

	// https://wiki.openstreetmap.org/wiki/Highways
    struct Road
	{
		// request position
		Common::VehiclePos pos;
        double length;

		//====================================================
		QString name;
		QString country;
		QString highway;
		int width;
		int maxspeed;
		int maxheight;
		int maxwidth;
		int maxweight;
		int lane_count;
		QString oneway;
		QString junction;

		//====================================================
		QString lit;
		QString smoothness;
		QString surface;
		QString source;
		QString source_maxspeed;

		//====================================================
		QString access;
		QString bicycle;
		QString foot;
		QString footway;

		//====================================================
		Common::LatLon center_coord;
		LaneSectionVec lane_sections;

	public:
        Road()
		{
			width = 0;
			maxspeed = 0;
			maxheight = 0;
			maxwidth = 0;
			maxweight = 0;
			lane_count = 0;
		}

        inline QJsonObject ToQJsonObject() const
		{
			QJsonObject obj;

            obj["pos"] = pos.ToQJsonObject();

            obj["length"] = this->length;

			//====================================================
			if (!this->name.isEmpty())
                obj["name"] = this->name;

			if (!this->country.isEmpty())
                obj["country"] = this->country;

			if (!this->highway.isEmpty())
                obj["highway"] = this->highway;

			if (this->width != 0)
                obj["width"] = this->width;

			if (this->maxspeed != 0)
                obj["maxspeed"] = this->maxspeed;

			if (this->maxheight != 0)
                obj["maxheight"] = this->maxheight;

			if (this->maxwidth != 0)
                obj["maxwidth"] = this->maxwidth;

			if (this->maxweight != 0)
                obj["maxweight"] = this->maxweight;

			if (this->lane_count != 0)
                obj["lane_count"] = this->lane_count;

			if (!this->oneway.isEmpty())
                obj["oneway"] = this->oneway;

			if (!this->junction.isEmpty())
                obj["junction"] = this->junction;

			//====================================================
			if (!this->lit.isEmpty())
                obj["lit"] = this->lit;

			if (!this->smoothness.isEmpty())
                obj["smoothness"] = this->smoothness;

			if (!this->surface.isEmpty())
                obj["surface"] = this->surface;

			if (!this->source.isEmpty())
                obj["source"] = this->source;

			if (!this->source_maxspeed.isEmpty())
                obj["source:maxspeed"] = this->source_maxspeed;

			//====================================================
			if (!this->access.isEmpty())
                obj["access"] = this->access;

			if (!this->bicycle.isEmpty())
                obj["bicycle"] = this->bicycle;

			if (!this->foot.isEmpty())
                obj["foot"] = this->foot;

			if (!this->footway.isEmpty())
                obj["footway"] = this->footway;

			//====================================================
			obj["center_coord"] = this->center_coord.ToQJsonArray();

            obj["lane_sections"] = Common::ToQJsonArrayOfObject(this->lane_sections);

            return obj;
		}

        inline operator QJsonObject() const
        {
            return ToQJsonObject();
        }

        inline void CalculateLength()
        {
            this->length = 0;
            for (ConstLaneSection& lane_section: this->lane_sections)
                for (Common::ConstVehiclePos& pos : lane_section.chord_coords)
                    this->length += pos.length;
        }
	};

    typedef CONST Road          ConstRoad;
    typedef QVector<Road>       RoadVec;
    typedef CONST RoadVec       ConstRoadVec;

}
