#pragma once

#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/junction/e_junction_type.h"
#include "XODR/OpenDRIVE/junction/t_junction_connection.h"
#include "XODR/OpenDRIVE/junction/t_junction_priority.h"
#include "XODR/OpenDRIVE/junction/t_junction_controller.h"
#include "XODR/OpenDRIVE/junction/t_junction_surface.h"

/*
    <xs:complexType name="t_junction">
        <xs:annotation>
            <xs:documentation>Contains information about all possible connections between roads meeting at a physical junction.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="connection" type="t_junction_connection" minOccurs="1" maxOccurs="unbounded"/>
                    <xs:element name="priority" type="t_junction_priority" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:element name="controller" type="t_junction_controller" minOccurs="0" maxOccurs="unbounded"/>
                    <xs:element name="surface" type="t_junction_surface" minOccurs="0" maxOccurs="1"/>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
                <xs:attribute name="name" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Name of the junction. May be chosen freely.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="id" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Unique ID within database</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="type" use="optional" type="e_junction_type">
                    <xs:annotation>
                        <xs:documentation>Type of the junction; regular junctions are of type "default". The attribute is mandatory for virtual junctions</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
            </xs:extension>
        </xs:complexContent>
    </xs:complexType>
*/

namespace _NOD
{

/* Changed e_junction_type from optional to required */
#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_junction) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string                     , name      , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _junctionId                , id        , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_junction_type            , type      , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 1, x, t_junction_connection , connection) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_junction_priority   , priority) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_junction_controller , controller) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_junction_surface    , surface) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_junction : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_junction)

public:
    template <typename T>
    double calcDistance(const T& point, const OpenDRIVE& content) const
    {
        return getJunctionPos(content, *this).calcDistance((const XY&)point);
    }

    template <typename T>
    double calcDistance(const QVector<T> &points, const OpenDRIVE& content) const
    {
        return getJunctionPos(content, *this).calcDistance((const XY&)points.first());
    }

    double calcDistance(const a_s_t& st) const
    {
        return _OpenDriveElement::calcDistance(st);
    }
};

}
