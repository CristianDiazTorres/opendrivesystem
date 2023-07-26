#pragma once

#include "OSM/Internal.h"
#include "Common/Json.h"
#include "Math/Math.h"
#include "OSM/Lane.h"
#include "OSM/Node/Node.h"

#include "OSM/Way/WayAbutters.h"
#include "OSM/Way/WayAccess.h"
#include "OSM/Way/WayBridge.h"
#include "OSM/Way/WayBusway.h"
#include "OSM/Way/WayBus_Bay.h"
#include "OSM/Way/WayConveying.h"
#include "OSM/Way/WayCovered.h"
#include "OSM/Way/WayCrossing.h"
#include "OSM/Way/WayCrossing_Ref.h"
#include "OSM/Way/WayCycleway.h"
#include "OSM/Way/WayEmbedded_Rails.h"
#include "OSM/Way/WayFootway.h"
#include "OSM/Way/WayFord.h"
#include "OSM/Way/WayHighway.h"
#include "OSM/Way/WayIndoor.h"
#include "OSM/Way/WayJunction.h"
#include "OSM/Way/WayKerb.h"
#include "OSM/Way/WayLit.h"
#include "OSM/Way/WayMaterial.h"
#include "OSM/Way/WayOneway.h"
#include "OSM/Way/WayOvertaking.h"
#include "OSM/Way/WayParking_Condition.h"
#include "OSM/Way/WayParking_Lane.h"
#include "OSM/Way/WayPriority_Road.h"
#include "OSM/Way/WayRamp.h"
#include "OSM/Way/WayRamp_Luggage.h"
#include "OSM/Way/WayRoute.h"
#include "OSM/Way/WaySac_Scale.h"
#include "OSM/Way/WayService.h"
#include "OSM/Way/WaySidewalk.h"
#include "OSM/Way/WaySmoothness.h"
#include "OSM/Way/WaySurface.h"
#include "OSM/Way/WayTactile_Paving.h"
#include "OSM/Way/WayTracktype.h"
#include "OSM/Way/WayTraffic_Calming.h"
#include "OSM/Way/WayTrail_Visibility.h"
#include "OSM/Way/WayTunnel.h"
#include "OSM/Way/WayTurn.h"
#include "OSM/Way/WayWheelchair.h"

/*

https://wiki.openstreetmap.org/wiki/Highways

*/

namespace _NOSM
{

// TODO: ???? : must added NONE_EMPTY for every enum

// ":lanes" ..|..|..

// ":vehicles"
// ":bus"
// ":taxi"
// ":bicycle"
// ":motorcycle"
// ":foot"

// ":psv"
// ":hgv"
// ":hov"

// ":both"
// ":right"
// ":left"
// ":center"
// ":forward"
// ":backward"

// ":access"
// ":surface"
// ":smoothness"
// ":width"
// ":residents"
// ":category"
// ":conditional"
// ":disabled"
// ":both_ways"
// ":ref"
// ":floor"
// ":levels"
// ":N3"
// ":wheelchair"
// ":description"

#undef _OSM_MEMBERSAA
#define _OSM_MEMBERSAA(usingType, lineEnd) \
    ZZXXQQ(usingType, WayAbutters, abutters, "abutters") \
    ZZXXQQ(usingType, WayAccess, access, "access") \
    ZZXXQQ(usingType, WayAccess, bicycle, "bicycle") \
    ZZXXQQ(usingType, Yes, bicycle_road, "bicycle_road") \
    ZZXXQQ(usingType, WayBridge, bridge, "bridge") \
    ZZXXQQ(usingType, YesNoDesignated, bus, "bus") \
    ZZXXQQ(usingType, WayBus_Bay, bus_bay, "bus_bay") \
    ZZXXQQ(usingType, WayBusway, busway, "busway") \
    ZZXXQQ(usingType, WayConveying, conveying, "conveying") \
    ZZXXQQ(usingType, WayCovered, covered, "covered") \
    ZZXXQQ(usingType, WayCrossing, crossing, "crossing") \
    ZZXXQQ(usingType, WayCrossing_Ref, crossing_ref, "crossing_ref") \
    ZZXXQQ(usingType, WayCycleway, cycleway, "cycleway") \
    ZZXXQQ(usingType, String, destination, "destination") \
    ZZXXQQ(usingType, WayEmbedded_Rails, embedded_rails, "embedded_rails") \
    ZZXXQQ(usingType, YesNo, expressway, "expressway") \
    ZZXXQQ(usingType, YesNo, fee, "fee") \
    ZZXXQQ(usingType, WayAccess, foot, "foot") \
    ZZXXQQ(usingType, WayFootway, footway, "footway") \
    ZZXXQQ(usingType, WayFord, ford, "ford") \
    ZZXXQQ(usingType, WayAccess, goods, "goods") \
    ZZXXQQ(usingType, YesNo, handrail, "handrail") \
    ZZXXQQ(usingType, WayHighway, highway, "highway") \
    ZZXXQQ(usingType, Yes, ice_road, "ice_road") \
    ZZXXQQ(usingType, WayIndoor, indoor, "indoor") \
    ZZXXQQ(usingType, Yes, informal, "informal") \
    ZZXXQQ(usingType, WayJunction, junction, "junction") \
    ZZXXQQ(usingType, WayKerb, kerb, "kerb") \
    ZZXXQQ(usingType, int, lanes, "lanes") \
    ZZXXQQ(usingType, YesNo, lane_markings, "lane_markings") \
    ZZXXQQ(usingType, int, level, "level") \
    ZZXXQQ(usingType, WayLit, lit, "lit") \
    ZZXXQQ(usingType, String, loc_name, "loc_name") \
    ZZXXQQ(usingType, WayMaterial, material, "material") \
    ZZXXQQ(usingType, String, maxspeed, "maxspeed") \
    ZZXXQQ(usingType, String, maxweight, "maxweight") \
    ZZXXQQ(usingType, String, minspeed, "minspeed") \
    ZZXXQQ(usingType, String, mofa, "mofa") \
    ZZXXQQ(usingType, YesNo, motorroad, "motorroad") \
    ZZXXQQ(usingType, String, mtb_description, "mtb:description") \
    ZZXXQQ(usingType, int, mtb_scale, "mtb:scale") \
    ZZXXQQ(usingType, int, mtb_scale_imba, "mtb:scale:imba") \
    ZZXXQQ(usingType, int, mtb_scale_uphill, "mtb:scale:uphill") \
    ZZXXQQ(usingType, String, name, "name") \
    ZZXXQQ(usingType, WayOneway, oneway, "oneway") \
    ZZXXQQ(usingType, YesNo, oneway_bicycle, "oneway:bicycle") \
    ZZXXQQ(usingType, String, opening_hours, "opening_hours") \
    ZZXXQQ(usingType, String, operator_, "operator") \
    ZZXXQQ(usingType, WayOvertaking, overtaking, "overtaking") \
    ZZXXQQ(usingType, WayParking_Condition, parking_condition, "parking:condition") \
    ZZXXQQ(usingType, WayParking_Lane, parking_lane, "parking:lane") \
    ZZXXQQ(usingType, YesNo, passing_places, "passing_places") \
    ZZXXQQ(usingType, WayPriority_road, priority_road, "priority_road") \
    ZZXXQQ(usingType, String, proposed, "proposed") \
    ZZXXQQ(usingType, YesNoDesignated, psv, "psv") \
    ZZXXQQ(usingType, WayRamp, ramp, "ramp") \
    ZZXXQQ(usingType, YesNo, ramp_bicycle, "ramp:bicycle") \
    ZZXXQQ(usingType, WayRamp_Luggage, ramp_luggage, "ramp:luggage") \
    ZZXXQQ(usingType, YesNo, ramp_stroller, "ramp:stroller") \
    ZZXXQQ(usingType, YesNo, ramp_wheelchair, "ramp:wheelchair") \
    ZZXXQQ(usingType, String, ref, "ref") \
    ZZXXQQ(usingType, WayRoute, route, "route") \
    ZZXXQQ(usingType, String, route_ref, "route_ref") \
    ZZXXQQ(usingType, WaySac_Scale, sac_scale, "sac_scale") \
    ZZXXQQ(usingType, YesNo, segregated, "segregated") \
    ZZXXQQ(usingType, WayService, service, "service") \
    ZZXXQQ(usingType, YesNo, shelter, "shelter") \
    ZZXXQQ(usingType, WaySidewalk, sidewalk, "sidewalk") \
    ZZXXQQ(usingType, WaySmoothness, smoothness, "smoothness") \
    ZZXXQQ(usingType, String, start_date, "start_date") \
    ZZXXQQ(usingType, int, step_count, "step_count") \
    ZZXXQQ(usingType, WaySurface, surface, "surface") \
    ZZXXQQ(usingType, String, symbol, "symbol") \
    ZZXXQQ(usingType, WayTactile_Paving, tactile_paving, "tactile_paving") \
    ZZXXQQ(usingType, YesNo, tactile_writing, "tactile_writing") \
    ZZXXQQ(usingType, YesNo, toll, "toll") \
    ZZXXQQ(usingType, WayTracktype, tracktype, "tracktype") \
    ZZXXQQ(usingType, WayTraffic_Calming, traffic_calming, "traffic_calming") \
    ZZXXQQ(usingType, WayTrail_Visibility, trail_visibility, "trail_visibility") \
    ZZXXQQ(usingType, WayTunnel, tunnel, "tunnel") \
    ZZXXQQ(usingType, WayTurn, turn, "turn") \
    ZZXXQQ(usingType, WayWheelchair, wheelchair, "wheelchair") \
    ZZXXQQ(usingType, String, width, "width") \
    ZZXXQQ(usingType, Yes, winter_road, "winter_road") \
    EMPTY_COMMAND

struct Way
{



    //====================================================
    String name;
    String country;
    String highway;
    int width;
    int maxspeed;
    int maxheight;
    int maxwidth;
    int maxweight;
    int lane_count;
    String oneway;
    String junction;

    //====================================================
    String lit;
    String smoothness;
    String surface;
    String source;
    String source_maxspeed;

    //====================================================
    String access;
    String bicycle;
    String foot;
    String footway;

    //====================================================
    LL center_coord;

    LaneVec lanes;

    VehiclePosVec chord_coords;
    VehiclePosVec gps_coords;
    VehiclePosVec updated_coords;

    double chord_length;
    double gps_length;
    double updated_length;

public:
    Way()
    {
        width = 0;
        maxspeed = 0;
        maxheight = 0;
        maxwidth = 0;
        maxweight = 0;
        lane_count = 0;
    }

    inline JsonObject ToQJsonObject() const
    {
        JsonObject obj;

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

        obj["lanes"] = _NCM::ToJsonArrayOfObject(this->lanes);

        obj["chord_coords"] = _NCM::ToJsonArrayOfArray(this->chord_coords);
        obj["gps_coords"] = _NCM::ToJsonArrayOfArray(this->gps_coords);
        obj["updated_coords"] = _NCM::ToJsonArrayOfArray(this->updated_coords);

        return obj;
    }

    inline operator JsonObject() const
    {
        return ToQJsonObject();
    }

    inline void CalculateLength()
    {
        this->chord_length = GetLength(chord_coords);
        this->gps_length = GetLength(gps_coords);
        this->updated_length = GetLength(updated_coords);
    }

    inline bool isValid() const
    {
        //if (this->chord_length < 1)
        //    return false;

        //Debug << gps_coords.size();
        if (gps_coords.size() < 2)
            return false;

        return true;

        if (gps_length < 1)
            return false;

        double lenRatio = gps_length / this->chord_length;
        //Debug << lenRatio;
        if (lenRatio < 0.4 || lenRatio > 2.5)
            return false;

        return true;
    }

    inline double GetShortestDistance(const VehiclePos& pos)
    {
        double minDist = DOUBLE_MAX;
        for (int i = 1; i < chord_coords.size(); i ++)
        {
            double dist = _NMath::shortestDistance(chord_coords[i - 1].x(), chord_coords[i - 1].y(),
                    chord_coords[i].x(), chord_coords[i].y(),
                    pos.x(), pos.y());
            if (dist < minDist)
                minDist = dist;
        }
        return minDist;
    }

    inline void calcUpdatedCoord()
    {
        double d1 = chord_coords.first().GetDistance(gps_coords.first()) +
                chord_coords.last().GetDistance(gps_coords.last());

        double d2 = chord_coords.first().GetDistance(gps_coords.last()) +
                chord_coords.last().GetDistance(gps_coords.first());

        if (d1 <= d2)
        {
            updated_coords << chord_coords.first();
            updated_coords.append(gps_coords);
            updated_coords << chord_coords.last();
        }
        else
        {
            updated_coords << chord_coords.first();
            for (int i = gps_coords.size() - 1; i >= 0; i --)
                updated_coords << gps_coords[i];
            updated_coords << chord_coords.last();
        }
    }

};

typedef Vector<Way>       WayVec;

}
