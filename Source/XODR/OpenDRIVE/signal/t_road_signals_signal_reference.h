#pragma once

#include "XODR/OpenDRIVE/signal/e_road_signals_signal_reference_elementType.h"

/*
    <xs:complexType name="t_road_signals_signal_reference">
        <xs:annotation>
            <xs:documentation>Provides a means to link a signal to a series of other elements (for example, objects and signals). </xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence/>
                <xs:attribute name="elementType" use="required" type="e_road_signals_signal_reference_elementType">
                    <xs:annotation>
                        <xs:documentation>Type of the linked element, For values see UML Model</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="elementId" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Unique ID of the linked element</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="type" use="optional" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Type of the linkage
Free text, depending on application</xs:documentation>
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
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_road_signals_signal_reference_elementType, elementType   , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _elementId /* _objectId or _signalId */, elementId         , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string, type                                               , OPTIONAL) lineEnd \
    EMPTY_COMMAND

struct t_road_signals_signal_reference : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_road_signals_signal_reference)

};

}
