#pragma once

#include "XODR/OpenDRIVE/core/t_header_GeoReference.h"
#include "XODR/OpenDRIVE/core/t_header_Offset.h"
#include "XODR/OpenDRIVE/core/g_additionalData.h"

/*
    <xs:complexType name="t_header">
        <xs:annotation>
            <xs:documentation>The &lt;header&gt; element is the very first element within the &lt;OpenDRIVE&gt; element.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="geoReference" type="t_header_GeoReference" minOccurs="0" maxOccurs="1"/>
                    <xs:element name="offset" type="t_header_Offset" minOccurs="0" maxOccurs="1"/>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
                <xs:attribute name="revMajor" use="required" fixed="1" type="xs:integer">
                    <xs:annotation>
                        <xs:documentation>Major revision number of OpenDRIVE format </xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="revMinor" use="required" type="xs:integer">
                    <xs:annotation>
                        <xs:documentation>Minor revision number of OpenDRIVE format; 6 for OpenDrive 1.6 </xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="name" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Database name</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="version" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Version of this road network</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="date" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Time/date of database creation according to ISO 8601
(preference: YYYY-MM-DDThh:mm:ss)</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="north" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Maximum inertial y value</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="south" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Minimum inertial y value</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="east" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Maximum inertial x value</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="west" use="optional" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Minimum inertial x value</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="vendor" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Vendor name</xs:documentation>
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
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_core) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, integer        , revMajor  , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, integer        , revMinor  , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string         , name      , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string         , version   , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _date          , date      , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double         , north     , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double         , south     , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double         , east      , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double         , west      , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string         , vendor    , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_header_GeoReference , geoReference) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_header_Offset       , offset) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_header : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_setParent_DEFINE(t_header)
    _UNIVERSIAL_TYPE_isCompatible_operatorEqualNotEqual_DEFINE(t_header)
    _UNIVERSIAL_TYPE_read_write_DEFINE(t_header)
    _UNIVERSIAL_TYPE_setTestData_DEFINE(t_header)

public:
     void init(const Cell& cell);
};

}

