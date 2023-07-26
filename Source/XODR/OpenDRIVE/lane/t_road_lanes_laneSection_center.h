#pragma once

#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection_center_lane.h"

/*
    <xs:complexType name="t_road_lanes_laneSection_center">
        <xs:annotation>
            <xs:documentation>For easier navigation through an OpenDRIVE road description, the lanes within a lane section are grouped into left, center, and right lanes. Each lane section shall contain one &lt;center&gt; element and at least one &lt;right&gt; or &lt;left&gt; element.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="lane" type="t_road_lanes_laneSection_center_lane" minOccurs="1" maxOccurs="unbounded"/>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
            </xs:extension>
        </xs:complexContent>
    </xs:complexType>
*/

namespace _NOD
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_lane) \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 1, x, t_road_lanes_laneSection_center_lane, lane) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_lanes_laneSection_center : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_DEFINE(t_road_lanes_laneSection_center)

public:
    t_road_lanes_laneSection_center()
    {
        lane_sequence.resize(1);
        lane_sequence[0].id = 0; // Fixed
        lane_sequence[0].type = e_laneType::NONE;
    }

public:
    bool updateGeoJSONData(_GeoJSONData& geojsonData, bool& inserted)
    {
        preUpdateGeoJSONData(geojsonData, inserted);
        bool ret = updateGeoJSONData_Body(geojsonData, inserted);
        postUpdateGeoJSONData(geojsonData, inserted);
        return ret;
    }

    void preUpdateGeoJSONData(_GeoJSONData& geojsonData, bool& inserted)
    {
        Q_UNUSED(geojsonData);
        Q_UNUSED(inserted);
    }

    bool updateGeoJSONData_Body(_GeoJSONData& geojsonData, bool& inserted)
    {
        qDebug() << "t_road_lanes_laneSection_center" << "          : updateGeoJSONData_Body";
        if (geojsonData.tag == "t_road_lanes_laneSection_center")
        {
            if (geojsonData.operCommand != ""
                && geojsonData.operCommand != "general")
            {
                return updateGeoJSONData_NonGeneral(geojsonData, inserted);
            }
            if (updateGeoJSONData_Itself_Pre(geojsonData, inserted))
                return true;
            if (geojsonData.updateST)
                updateST(geojsonData.st);
            read(geojsonData.propsObj);
            inserted = false;
            return updateGeoJSONData_Itself_Post(geojsonData, inserted);
        }
        if (updateGeoJSONData_Children_Pre(geojsonData, inserted))
            return true;
        if (geojsonData.isLine)
        {
            _OD_MEMBERS(UPDATE_GEO_JSON_DATA_LINE, SEMICOLON)
        }
        else
        {
            _OD_MEMBERS(UPDATE_GEO_JSON_DATA_POINT, SEMICOLON)
        }

        return updateGeoJSONData_Children_Post(geojsonData, inserted);
    }

    bool updateGeoJSONData_NonGeneral(_GeoJSONData& geojsonData, bool& inserted)
    {
        Q_UNUSED(geojsonData);
        Q_UNUSED(inserted);
        return false;
    }

    bool updateGeoJSONData_Itself_Pre(_GeoJSONData& geojsonData, bool& inserted)
    {
        Q_UNUSED(geojsonData);
        Q_UNUSED(inserted);
        return false;
    }

    bool updateGeoJSONData_Itself_Post(_GeoJSONData& geojsonData, bool& inserted)
    {
        Q_UNUSED(geojsonData);
        Q_UNUSED(inserted);
        return true;
    }

    bool updateGeoJSONData_Children_Pre(_GeoJSONData& geojsonData, bool& inserted)
    {
        if (!lane_sequence.isEmpty())
            return lane_sequence.first().updateGeoJSONData(geojsonData, inserted);

        double t = fabs(geojsonData.st.t);
        double offset = 0;
        for (t_road_lanes_laneSection_center_lane& lane : lane_sequence)
        {
            offset += lane.getWidth();
            if (t <= offset)
                return lane.updateGeoJSONData(geojsonData, inserted);
        }

        lane_sequence.resize(lane_sequence.size() + 1);
        bool ret = lane_sequence.last().updateGeoJSONData(geojsonData, inserted);
        inserted = true;
        return ret;
    }

    bool updateGeoJSONData_Children_Post(_GeoJSONData& geojsonData, bool& inserted)
    {
        Q_UNUSED(geojsonData);
        Q_UNUSED(inserted);
        return false;
    }

    void postUpdateGeoJSONData(_GeoJSONData& geojsonData, bool& inserted)
    {
        Q_UNUSED(geojsonData);
        Q_UNUSED(inserted);
    }
};

}
