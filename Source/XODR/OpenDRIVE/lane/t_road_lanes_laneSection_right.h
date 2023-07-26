#pragma once

#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection_right_lane.h"

/*
    <xs:complexType name="t_road_lanes_laneSection_right">
        <xs:annotation>
            <xs:documentation>For easier navigation through an OpenDRIVE road description, the lanes within a lane section are grouped into left, center, and right lanes. Each lane section shall contain one &lt;center&gt; element and at least one &lt;right&gt; or &lt;left&gt; element.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="lane" type="t_road_lanes_laneSection_right_lane" minOccurs="1" maxOccurs="unbounded"/>
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
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 1, x, t_road_lanes_laneSection_right_lane, lane) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_lanes_laneSection_right : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_DEFINE(t_road_lanes_laneSection_right)

public:
    int getRealLaneCount() const
    {
        int laneCount = 0;
        for (int i = 0; i < lane_sequence.size(); i ++)
            if (lane_sequence[i].type != e_laneType::BORDER)
                laneCount ++;
        return laneCount;
    }

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
        qDebug() << "t_road_lanes_laneSection_right" << "          : updateGeoJSONData_Body";
        if (geojsonData.tag == "t_road_lanes_laneSection_right")
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
        if (geojsonData.condPropsObj.contains("_t_road_lanes_laneSection_lcr_lane"))
        {
            QJsonObject condPropsObj = geojsonData.condPropsObj["_t_road_lanes_laneSection_lcr_lane"].toObject();
            if (condPropsObj.contains("id"))
            {
                int id = condPropsObj["id"].toInt();
                // id = [-1 ~ -size()]
                if (id > -1 || id < -lane_sequence.size())
                    return false;

                return lane_sequence[- id - 1].updateGeoJSONData(geojsonData, inserted);
            }
        }

        double t = fabs(geojsonData.st.t);
        double offset = 0;
        for (t_road_lanes_laneSection_right_lane& lane : lane_sequence)
        {
            offset += lane.getWidth();
            if (t <= offset)
                return lane.updateGeoJSONData(geojsonData, inserted);
        }

        t_road_lanes_laneSection_right_lane lane;
        if (!lane_sequence.isEmpty())
            lane = getOutsideRealLane();
        else
            lane.setDefaultValues();

        addRealLanes(1, lane);

        bool ret = getOutsideRealLane().updateGeoJSONData(geojsonData, inserted);
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

    bool addRealLanes(int addedCount, const t_road_lanes_laneSection_lr_lane& referLane)
    {
        if (addedCount <= 0)
            return false;

        // We will add lanes right side (at end)
        QVector<t_road_lanes_laneSection_right_lane>::iterator iter = lane_sequence.end(); // iter is invalid

        // Skip last border lane
        if (!lane_sequence.isEmpty() && lane_sequence.last().type == e_laneType::BORDER)
            iter --; // iter is border

        // Insert lanes before iter
        t_road_lanes_laneSection_right_lane lane;
        (t_road_lanes_laneSection_lr_lane&)lane = referLane;
        lane_sequence.insert(iter, addedCount, lane);

        // Add border lane right side (at end)
        if (lane_sequence.last().type != e_laneType::BORDER)
        {
            t_road_lanes_laneSection_right_lane border;
            border.type = e_laneType::BORDER;
            lane_sequence.append(border);
        }

        // Renumber
        renumberLaneIds();

        return true;
    }

    bool removeRealLanes(int removedCount)
    {
        if (removedCount >= getRealLaneCount())
            return false;

        QVector<t_road_lanes_laneSection_right_lane>::iterator iter = lane_sequence.end(); // iter is invalid

        if (!lane_sequence.isEmpty() && lane_sequence.last().type == e_laneType::BORDER)
            iter --;

        iter -= removedCount;

        lane_sequence.erase(iter, iter + removedCount);

        if (getRealLaneCount() == 0)
            lane_sequence.clear();

        // Renumber
        renumberLaneIds();

        return true;
    }

    const t_road_lanes_laneSection_right_lane& getOutsideRealLane() const
    {
        for (int i = lane_sequence.size() - 1; i >= 0; i --)
        {
            if (lane_sequence[i].type != e_laneType::BORDER)
                return lane_sequence[i];
        }
        Q_ASSERT(getRealLaneCount() > 0);
        return lane_sequence[0];
    }

    t_road_lanes_laneSection_right_lane& getOutsideRealLane()
    {
        for (int i = lane_sequence.size() - 1; i >= 0; i --)
        {
            if (lane_sequence[i].type != e_laneType::BORDER)
                return lane_sequence[i];
        }
        Q_ASSERT(getRealLaneCount() > 0);
        return lane_sequence[0];
    }

    const t_road_lanes_laneSection_right_lane& getInsideRealLane() const
    {
        for (int i = 0; i < lane_sequence.size(); i ++)
        {
            if (lane_sequence[i].type != e_laneType::BORDER)
                return lane_sequence[i];
        }
        Q_ASSERT(getRealLaneCount() > 0);
        return lane_sequence[0];
    }

    t_road_lanes_laneSection_right_lane& getInsideRealLane()
    {
        for (int i = 0; i < lane_sequence.size(); i ++)
        {
            if (lane_sequence[i].type != e_laneType::BORDER)
                return lane_sequence[i];
        }
        Q_ASSERT(getRealLaneCount() > 0);
        return lane_sequence[0];
    }

    void addInsideBorderLane()
    {
        if (lane_sequence.first().type != e_laneType::BORDER)
        {
            t_road_lanes_laneSection_right_lane border;
            border.type = e_laneType::BORDER;
            lane_sequence.prepend(border);

            // Renumber
            renumberLaneIds();
        }
    }

    void removeInsideBorderLane()
    {
        // Remove left side border lane (at first)
        if (lane_sequence.first().type == e_laneType::BORDER)
        {
            lane_sequence.pop_front();

            // Renumber
            renumberLaneIds();
        }
    }

    void renumberLaneIds()
    {
        for (int i = 0; i < lane_sequence.size(); i ++)
            lane_sequence[i].id = - (i + 1);
    }
};

}
