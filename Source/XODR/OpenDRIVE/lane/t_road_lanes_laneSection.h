#pragma once


#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/lane/t_bool_default_true.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection_left.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection_center.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection_right.h"

/*
    <xs:complexType name="t_road_lanes_laneSection">
        <xs:annotation>
            <xs:documentation>Lanes may be split into multiple lane sections. Each lane section contains a fixed number of lanes. Every time the number of lanes changes, a new lane section is required.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="left" type="t_road_lanes_laneSection_left" minOccurs="0" maxOccurs="1"/>
                    <xs:element name="center" type="t_road_lanes_laneSection_center" minOccurs="1" maxOccurs="1"/>
                    <xs:element name="right" type="t_road_lanes_laneSection_right" minOccurs="0" maxOccurs="1"/>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
                <xs:attribute name="s" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>s-coordinate of start position</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="singleSide" use="optional" type="t_bool">
                    <xs:annotation>
                        <xs:documentation>Lane section element is valid for one side only (left, center, or right), depending on the child elements.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
            </xs:extension>
        </xs:complexContent>
    </xs:complexType>
*/

namespace _NOD
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_lane) \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, a_s) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType     , t_bool_default_false              , singleSide      , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_lanes_laneSection_left     , left) lineEnd \
    _UNIVERSIAL_TYPE_TAG(usingType           , t_road_lanes_laneSection_center   , center) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_lanes_laneSection_right    , right) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_lanes_laneSection : public a_s
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_DEFINE(t_road_lanes_laneSection)

    /*****************************************************/
    bool oneway;

public:
    bool calcOneway();

    double calcDistance(const a_s& other) const;

    int getRealLaneCount() const
    {
        return getRealLeftLaneCount() + getRealRightLaneCount();
    }

    int getRealLeftLaneCount() const
    {
        if (!left_sequence.isEmpty())
            return left_sequence[0].getRealLaneCount();

        return 0;
    }

    int getRealRightLaneCount() const
    {
        if (!right_sequence.isEmpty())
            return right_sequence[0].getRealLaneCount();

        return 0;
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
        qDebug() << "t_road_lanes_laneSection" << "          : updateGeoJSONData_Body";
        if (geojsonData.tag == "t_road_lanes_laneSection")
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
        Q_UNUSED(inserted)

        if (geojsonData.operCommand == "lane_count") {

            QString operAt = geojsonData.propsObj["operate_diff_lanes_at"].toString();
            int laneCount = geojsonData.propsObj["lane_count"].toInt();
            int diffCount = laneCount - getRealLaneCount();
            if (diffCount == 0)
                return false;

            if (diffCount > 0)
            {
                int leftAddedCount = 0, rightAddedCount = 0;
                if (operAt == "left")
                {
                    leftAddedCount = diffCount;
                }
                else if (operAt == "right")
                {
                    rightAddedCount = diffCount;
                }
                else if (operAt == "both_and_left_one")
                {
                    rightAddedCount = diffCount / 2;
                    leftAddedCount = diffCount - rightAddedCount;
                }
                else if (operAt == "both_and_right_one")
                {
                    leftAddedCount = diffCount / 2;
                    rightAddedCount = diffCount - leftAddedCount;
                }
                else
                    return false;

                if (leftAddedCount > 0)
                {
                    if (left_sequence.isEmpty())
                        left_sequence.resize(1);

                    t_road_lanes_laneSection_lr_lane referLane;
                    if (getRealLeftLaneCount() != 0)
                        referLane = left_sequence[0].getOutsideRealLane();
                    else if (getRealRightLaneCount() != 0)
                        referLane = right_sequence[0].getInsideRealLane();
                    else
                        referLane.setDefaultValues();

                    left_sequence[0].addRealLanes(leftAddedCount, referLane);
                }

                if (rightAddedCount > 0)
                {
                    if (right_sequence.isEmpty())
                        right_sequence.resize(1);

                    t_road_lanes_laneSection_lr_lane referLane;
                    if (getRealRightLaneCount() != 0)
                        referLane = right_sequence[0].getOutsideRealLane();
                    else if (getRealLeftLaneCount() != 0)
                        referLane = left_sequence[0].getInsideRealLane();
                    else
                        referLane.setDefaultValues();

                    right_sequence[0].addRealLanes(rightAddedCount, referLane);
                }

                if (!left_sequence.isEmpty()
                        && !left_sequence[0].lane_sequence.isEmpty()
                        && !right_sequence.isEmpty()
                        && !right_sequence[0].lane_sequence.isEmpty())
                {
                    left_sequence[0].removeInsideBorderLane();
                    right_sequence[0].removeInsideBorderLane();
                }

                return true;
            }

            // if (diffCount < 0)
            diffCount = - diffCount;

            int leftRemovedCount = 0, rightRemovedCount = 0;
            if (operAt == "left")
            {
                leftRemovedCount = qMin(diffCount, getRealLeftLaneCount());
                rightRemovedCount = diffCount - leftRemovedCount;
            }
            else if (operAt == "right")
            {
                rightRemovedCount = qMin(diffCount, getRealRightLaneCount());
                leftRemovedCount = diffCount - rightRemovedCount;
            }
            else if (operAt == "both_and_left_one")
            {
                rightRemovedCount = qMin(diffCount / 2, getRealLeftLaneCount());
                leftRemovedCount = diffCount - rightRemovedCount;
            }
            else if (operAt == "both_and_right_one")
            {
                leftRemovedCount = qMin(diffCount / 2, getRealRightLaneCount());
                rightRemovedCount = diffCount - leftRemovedCount;
            }
            else
                return false;

            if (leftRemovedCount > 0)
                left_sequence[0].removeRealLanes(leftRemovedCount);

            if (rightRemovedCount > 0)
                right_sequence[0].removeRealLanes(rightRemovedCount);

            if (getRealLeftLaneCount() == 0 && getRealRightLaneCount() > 0)
                right_sequence[0].addInsideBorderLane();

            if (getRealRightLaneCount() == 0 && getRealLeftLaneCount() > 0)
                left_sequence[0].addInsideBorderLane();

            return true;
        }
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
                if (id > 0)
                {
                    if (left_sequence.isEmpty())
                        return false;
                    return left_sequence.first().updateGeoJSONData(geojsonData, inserted);
                }
                else if (id == 0)
                {
                    return center.updateGeoJSONData(geojsonData, inserted);
                }
                else
                {
                    if (right_sequence.isEmpty())
                        return false;
                    return right_sequence.first().updateGeoJSONData(geojsonData, inserted);
                }
            }
        }

        if (geojsonData.st.t > 0)
        {
            if (left_sequence.isEmpty())
            {
                left_sequence.resize(1);
                bool ret = left_sequence.first().updateGeoJSONData(geojsonData, inserted);
                inserted = true;
                return ret;
            }
            return left_sequence.first().updateGeoJSONData(geojsonData, inserted);
        }
        else if (geojsonData.st.t == 0)
        {
            return center.updateGeoJSONData(geojsonData, inserted);
        }
        else // if (geojsonData.st.t < 0)
        {
            if (right_sequence.isEmpty())
            {
                right_sequence.resize(1);
                bool ret = right_sequence.first().updateGeoJSONData(geojsonData, inserted);
                inserted = true;
                return ret;
            }
            return right_sequence.first().updateGeoJSONData(geojsonData, inserted);
        }
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
