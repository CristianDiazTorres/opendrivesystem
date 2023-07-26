#pragma once



/*
    <xs:complexType name="t_road_objects_object_repeat">
        <xs:annotation>
            <xs:documentation>To avoid lengthy XML code, objects of the same type may be repeated. The attributes of the repeated object may be changed. Attributes of the repeated object shall overrule the attributes from the original object. If attributes are omitted in the repeated objects, the attributes from the original object apply.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="s" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>s-coordinate of start position, overrides the corresponding argument in the original &lt;object&gt; record</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="length" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Length of the repeat area, along the reference line in s-direction.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="distance" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Distance between two instances of the object;
If this value is zero, then the object is treated like a continuous feature, for example, a guard rail, a wall, etc.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="tStart" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Lateral offset of objects reference point at @s	</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="tEnd" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Lateral offset of object's reference point at @s + @length</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="heightStart" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Height of the object at @s</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="heightEnd" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Height of the object at @s + @length</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="zOffsetStart" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>z-offset of the object at @s, relative to the elevation of the reference line</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="zOffsetEnd" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>z-offset of the object at @s + @length, relative to the elevation of the reference line</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="widthStart" use="optional" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Width of the object at @s</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="widthEnd" use="optional" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Width of the object at @s + @length</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="lengthStart" use="optional" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Length of the object at @sh</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="lengthEnd" use="optional" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Length of the object at @s + @length</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="radiusStart" use="optional" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Radius of the object at @s</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="radiusEnd" use="optional" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>Radius of the object at @s + @length</xs:documentation>
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
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_object) \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, a_s) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero, length        , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero, distance      , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, tStart            , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, tEnd              , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, heightStart       , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, heightEnd         , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, zOffsetStart      , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, zOffsetEnd        , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero, widthStart    , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero, widthEnd      , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero, lengthStart   , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero, lengthEnd     , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero, radiusStart   , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero, radiusEnd     , OPTIONAL) lineEnd \
    EMPTY_COMMAND

struct t_road_objects_object_repeat : public a_s
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_objects_object_repeat)
};

}
