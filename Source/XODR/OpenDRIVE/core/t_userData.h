#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"
#include "XODR/OpenDRIVE/core/t_cell.h"
#include "OSM/Way/Way.h"

/*
    <xs:complexType name="t_userData">
        <xs:annotation>
            <xs:documentation>Ancillary data should be described near the element it refers to. Ancillary data contains data that are not yet described in OpenDRIVE, or data that is needed by an application for a specific reason. Examples are different road textures.
In OpenDRIVE, ancillary data is represented by &lt;userData&gt; elements. They may be stored at any element in OpenDRIVE.</xs:documentation>
        </xs:annotation>
        <xs:sequence>
            <xs:any processContents="skip" minOccurs="0" maxOccurs="unbounded"/>
        </xs:sequence>
        <xs:attribute name="code" use="required" type="xs:string">
            <xs:annotation>
                <xs:documentation>Code for the user data. Free text, depending on application.</xs:documentation>
            </xs:annotation>
        </xs:attribute>
        <xs:attribute name="value" use="optional" type="xs:string">
            <xs:annotation>
                <xs:documentation>User data. Free text, depending on application. </xs:documentation>
            </xs:annotation>
        </xs:attribute>
    </xs:complexType>
*/

namespace _NOD
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_core) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string        , code   , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string        , value  , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_cell   , cell) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, _xodrStringPairs, osm) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, _vehiclePos, gps) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, _vehiclePos, trajectory) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, _NOSM::Way, osmWay) lineEnd \
    EMPTY_COMMAND

struct t_userData : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_isCompatible_operatorEqualNotEqual_DEFINE(t_userData)
    _UNIVERSIAL_TYPE_read_write_DEFINE(t_userData)

public:
    static t_userData EMPTY_USER_DATA;

public:
    t_userData(){}
    t_userData(const string& code, const string& value = "") : code(code), value(value){}

public:
    void* parent;
    inline void setParent(void* parent = 0, bool resetChildren = true)
    {
        Q_UNUSED(resetChildren)
        this->parent = parent;
    }

public:
    void setTestData()
    {
        code = "testCode";
        value = "testValue";
    }

    void AddToGeoJsonTemplateData(QJsonArray& features, QJsonObject geomObject, QString tagName)
    {
        Q_UNUSED(features);
        Q_UNUSED(geomObject);
        Q_UNUSED(tagName);
    }

    void saveGeoJsonTemplateData(QString path, QJsonObject geomObject)
    {
        Q_UNUSED(path);
        Q_UNUSED(geomObject);
    }

    void calcAbsolutePosIncludingChildren(t_road& road)
    {
        Q_UNUSED(road);
    }

    void calcRelativePosIncludingChildren(t_road& road)
    {
        Q_UNUSED(road);
    }
};

}

