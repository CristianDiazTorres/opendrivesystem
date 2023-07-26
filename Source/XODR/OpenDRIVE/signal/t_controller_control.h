#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:complexType name="t_controller_control">
        <xs:annotation>
            <xs:documentation>Provides information about a single signal controlled by the corresponding controller.</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="signalId" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>ID of the controlled signal</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="type" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Type of control.
Free Text, depends on the application.</xs:documentation>
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
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_signal) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _signalId, signalId    , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string, type           , OPTIONAL) lineEnd \
    EMPTY_COMMAND

struct t_controller_control : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_controller_control)

};

}
