#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:complexType name="t_junction_controller">
        <xs:annotation>
            <xs:documentation>Lists the controllers that are used for the management of a junction.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="id" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>ID of the controller</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="type" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Type of control for this junction. Free text, depending on the application.</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="sequence" use="optional" type="xs:nonNegativeInteger">
                    <xs:annotation>
                        <xs:documentation>Sequence number (priority) of this controller with respect to other controllers in the same junction</xs:documentation>
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
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_junction) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _junctionControllerId      , id        , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string                     , type      , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _nonNegativeInteger        , sequence  , OPTIONAL) lineEnd \
    EMPTY_COMMAND

struct t_junction_controller : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_junction_controller)

};

}
