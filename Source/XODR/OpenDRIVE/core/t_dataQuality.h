#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"
#include "XODR/OpenDRIVE/core/t_dataQuality_Error.h"
#include "XODR/OpenDRIVE/core/t_dataQuality_RawData.h"

/*
    <xs:complexType name="t_dataQuality">
        <xs:annotation>
            <xs:documentation>Raw data or data from external sources that is integrated in OpenDRIVE may be of varying quality. It is possible to describe quality and accuracy of external data in OpenDRIVE.
The description of the data quality is represented by &lt;dataQuality&gt; elements. They may be stored at any position in OpenDRIVE.
Measurement data derived from external sources like GPS that is integrated in OpenDRIVE may be inaccurate. The error range, given in [m], may be listed in the application.</xs:documentation>
        </xs:annotation>
        <xs:sequence>
            <xs:element name="error" type="t_dataQuality_Error" minOccurs="0" maxOccurs="1"/>
            <xs:element name="rawData" type="t_dataQuality_RawData" minOccurs="0" maxOccurs="1"/>
        </xs:sequence>
    </xs:complexType>
*/

namespace _NOD
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_core) \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_dataQuality_Error   , error) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_dataQuality_RawData , rawData) lineEnd \
    EMPTY_COMMAND

struct t_dataQuality : public _OpenDriveElement
{
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_dataQuality)
};

}

