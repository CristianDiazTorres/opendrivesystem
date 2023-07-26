#pragma once

#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/road/e_trafficRule.h"
#include "XODR/OpenDRIVE/road/t_road_link.h"
#include "XODR/OpenDRIVE/road/t_road_type.h"
#include "XODR/OpenDRIVE/road/t_road_planView.h"
#include "XODR/OpenDRIVE/road/t_road_elevationProfile.h"
#include "XODR/OpenDRIVE/road/t_road_lateralProfile.h"
#include "XODR/OpenDRIVE/lane/t_road_lanes.h"
#include "XODR/OpenDRIVE/object/t_road_objects.h"
#include "XODR/OpenDRIVE/signal/t_road_signals.h"
#include "XODR/OpenDRIVE/road/t_road_surface.h"
#include "XODR/OpenDRIVE/railroad/t_road_railroad.h"

#pragma push_macro("signals")
#undef signals

/*
    <xs:complexType name="t_road">
        <xs:annotation>
            <xs:documentation>In OpenDRIVE, the road network is represented by &lt;road&gt; elements. Each road runs along one road reference line. A road shall have at least one lane with a width larger than 0.
OpenDRIVE roads may be roads in the real road network or artificial road network created for application use. Each road is described by one or more &lt;road&gt; elements. One &lt;road&gt; element may cover a long stretch of a road, shorter stretches between junctions, or even several roads. A new &lt;road&gt; element should only start if the properties of the road cannot be described within the previous &lt;road&gt; element or if a junction is required.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="link" type="t_road_link" minOccurs="0" maxOccurs="1"/>
                    <xs:element name="type" type="t_road_type" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:element name="planView" type="t_road_planView" minOccurs="1" maxOccurs="1"/>
                    <xs:element name="elevationProfile" type="t_road_elevationProfile" minOccurs="0" maxOccurs="1"/>
                    <xs:element name="lateralProfile" type="t_road_lateralProfile" minOccurs="0" maxOccurs="1"/>
                    <xs:element name="lanes" type="t_road_lanes" minOccurs="1" maxOccurs="1"/>
                    <xs:element name="objects" type="t_road_objects" minOccurs="0" maxOccurs="1"/>
                    <xs:element name="signals" type="t_road_signals" minOccurs="0" maxOccurs="1"/>
                    <xs:element name="surface" type="t_road_surface" minOccurs="0" maxOccurs="1"/>
                    <xs:element name="railroad" type="t_road_railroad" minOccurs="0" maxOccurs="1"/>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
                <xs:attribute name="name" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Name of the road. May be chosen freely.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="length" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Total length of the reference line in the xy-plane. Change in length due to elevation is not considered</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="id" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Unique ID within the database. If it represents an integer number, it should comply to uint32_t and stay within the given range.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="junction" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>ID of the junction to which the road belongs as a connecting road (= -1 for none)</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="rule" use="optional" type="e_trafficRule">
                    <xs:annotation>
                        <xs:documentation>Basic rule for using the road; RHT=right-hand traffic, LHT=left-hand traffic. When this attribute is missing, RHT is assumed.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
            </xs:extension>
        </xs:complexContent>
    </xs:complexType>
*/

namespace _NOD
{

enum _e_road_link_type : int
{
    Incoming = 0,
    Outgoing,
    LinkTypeCount
};

struct _t_road_link_info
{
    _e_road_link_type linkType;
    _roadId thisId;
    e_contactPoint contactPointOnThis;
    _roadId linkedRoadId;
    e_contactPoint contactPointOnLinkedRoad;
};

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_road) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string         , name      , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double         , length    , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _roadId        , id        , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _junctionId    , junction  , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_trafficRule  , rule      , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_link           , link) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_road_type           , type) lineEnd \
    _UNIVERSIAL_TYPE_TAG(usingType           , t_road_planView       , planView) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_elevationProfile, elevationProfile) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_lateralProfile , lateralProfile) lineEnd \
    _UNIVERSIAL_TYPE_TAG(usingType           , t_road_lanes          , lanes) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_objects        , objects) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_signals        , signals) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_surface        , surface) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_road_railroad       , railroad) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_DEFINE(t_road)

    /*****************************************************/

    string referenceId;
    string junctionType; // From OSM
    XY start;
    XY end;
    bool oneway;

    /*****************************************************/

    _vector<_t_road_link_info> incomingRoadsInfo;
    _vector<_t_road_link_info> outgoingRoadsInfo;
    _map<e_contactPoint, _map<_e_road_link_type, _vector<_t_road_link_info> > > linkedRoadsInfoPerLTPerCP;
    _map<e_contactPoint, _map<_roadId, _roadId> > linkedRoadsPerCP;

    int tempRealJunctionIndex = -1;

    /*****************************************************/

public:

    /*****************************************************/

    void addIncomingLink(e_contactPoint contactPointOnThis, _roadId roadId, e_contactPoint contactPointOnLinkedRoad)
    {
        _t_road_link_info linkInfo;
        linkInfo.linkType = Incoming;
        linkInfo.thisId = id;
        linkInfo.contactPointOnThis = contactPointOnThis;
        linkInfo.linkedRoadId = roadId;
        linkInfo.contactPointOnLinkedRoad = contactPointOnLinkedRoad;

        incomingRoadsInfo << linkInfo;
        linkedRoadsInfoPerLTPerCP[contactPointOnThis][Incoming] << linkInfo;
        linkedRoadsPerCP[contactPointOnThis][roadId] = roadId;
    }

    void addOutgoingLink(e_contactPoint contactPointOnThis, _roadId roadId, e_contactPoint contactPointOnLinkedRoad)
    {
        _t_road_link_info linkInfo;
        linkInfo.linkType = Outgoing;
        linkInfo.thisId = id;
        linkInfo.contactPointOnThis = contactPointOnThis;
        linkInfo.linkedRoadId = roadId;
        linkInfo.contactPointOnLinkedRoad = contactPointOnLinkedRoad;

        outgoingRoadsInfo << linkInfo;
        linkedRoadsInfoPerLTPerCP[contactPointOnThis][Outgoing] << linkInfo;
        linkedRoadsPerCP[contactPointOnThis][roadId] = roadId;
    }

    /*****************************************************/

public:
    virtual void onAfterRead()
    {
        referenceId = additionalData.getUserDataValue(_SC_CA_referenceId_A);
        junctionType = additionalData.getUserDataValue(_SC_CA_junctionType_A);
    }

    virtual void onBeforeWrite()
    {
        additionalData.setUserData(_SC_CA_referenceId_A, referenceId);
        additionalData.setUserData(_SC_CA_junctionType_A, junctionType);
    }

public:
    bool isSimilar(const t_road& other) const;

    inline void calcST(const XY& xy, a_s_t& st) const
    {
        planView.calcST(xy, st);
    }

    inline void calcXY(const a_s_t& st, XY& xy) const
    {
        planView.calcXY(st, xy);
    }

    inline void calcStartEndOneway()
    {
        Q_ASSERT(!planView.geometry_sequence.isEmpty());
        start = planView.geometry_sequence[0];
        end = planView.geometry_sequence.last();
        Q_ASSERT(!lanes.laneSection_sequence.isEmpty());
        oneway = lanes.laneSection_sequence[0].calcOneway();
    }

    // @incomplete
    void setCurvatureSlope(const XY& pos, double curvature, double slope);

    template <typename T>
    double calcDistance(const T& point) const
    {
        return planView.calcDistance(point);
    }

    template <typename T>
    double calcDistance(const QVector<T> &points) const
    {
        return planView.calcDistance(points);
    }

    template <typename T>
    void init(const QVector<T>& points)
    {
        planView.init(points);
        this->length = planView.geometry_sequence.last().s + planView.geometry_sequence.last().length;
    }

    bool updateGeoJSONData(_GeoJSONData& geojsonData, bool& inserted)
    {
        preUpdateGeoJSONData(geojsonData, inserted);
        bool ret = updateGeoJSONData_Body(geojsonData, inserted);
        postUpdateGeoJSONData(geojsonData, inserted);
        return ret;
    }

    void preUpdateGeoJSONData(_GeoJSONData& geojsonData, bool& inserted);

    bool updateGeoJSONData_Body(_GeoJSONData& geojsonData, bool& inserted)
    {
        qDebug() << "t_road" << "          : updateGeoJSONData_Body";
        if (geojsonData.tag == "t_road")
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

    bool updateGeoJSONData_NonGeneral(_GeoJSONData& geojsonData, bool& inserted);

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
        Q_UNUSED(geojsonData);
        Q_UNUSED(inserted);
        return false;
    }

    bool updateGeoJSONData_Children_Post(_GeoJSONData& geojsonData, bool& inserted)
    {
        Q_UNUSED(geojsonData);
        Q_UNUSED(inserted);
        return false;
    }

    void postUpdateGeoJSONData(_GeoJSONData& geojsonData, bool& inserted);

    inline const t_road_planView_geometry& getPoint(e_contactPoint at) const
    {
        return planView.getPoint(at);
    }

    inline t_road_planView_geometry& getPoint(e_contactPoint at)
    {
        return planView.getPoint(at);
    }

    inline const t_road_planView_geometry& getPoint(double s) const
    {
        return planView.getPoint(s);
    }

    inline t_road_planView_geometry& getPoint(double s)
    {
        return planView.getPoint(s);
    }
};

}

#pragma pop_macro("signals")
