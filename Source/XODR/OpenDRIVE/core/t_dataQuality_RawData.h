#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"
#include "XODR/OpenDRIVE/core/e_dataQuality_RawData_Source.h"
#include "XODR/OpenDRIVE/core/e_dataQuality_RawData_PostProcessing.h"

/*
    <xs:complexType name="t_dataQuality_RawData">
        <xs:annotation>
            <xs:documentation>Some basic metadata containing information about raw data included in OpenDRIVE is described by the &lt;rawData&gt; element within the &lt;dataQuality&gt; element. </xs:documentation>
        </xs:annotation>
        <xs:sequence/>
        <xs:attribute name="date" use="required" type="xs:string">
            <xs:annotation>
                <xs:documentation>Date of the delivery of raw data, to be given in ISO 8601 notification (YYYY-MM-DDTHH:MM:SS) [9]. Time-of-day may be omitted</xs:documentation>
            </xs:annotation>
        </xs:attribute>
        <xs:attribute name="source" use="required" type="e_dataQuality_RawData_Source">
            <xs:annotation>
                <xs:documentation>Source that has been used for retrieving the raw data; further sources to be added in upcoming versions. For values see UML Model</xs:documentation>
            </xs:annotation>
        </xs:attribute>
        <xs:attribute name="sourceComment" use="optional" type="xs:string">
            <xs:annotation>
                <xs:documentation>Comments concerning the @source . Free text, depending on the application</xs:documentation>
            </xs:annotation>
        </xs:attribute>
        <xs:attribute name="postProcessing" use="required" type="e_dataQuality_RawData_PostProcessing">
            <xs:annotation>
                <xs:documentation>Information about the kind of data handling before exporting data into the ASAM OpenDRIVE file. For values see UML Model</xs:documentation>
            </xs:annotation>
        </xs:attribute>
        <xs:attribute name="postProcessingComment" use="optional" type="xs:string">
            <xs:annotation>
                <xs:documentation>Comments concerning the postprocessing attribute. Free text, depending on the application</xs:documentation>
            </xs:annotation>
        </xs:attribute>
    </xs:complexType>
*/

namespace _NOD
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_core) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, _date                                  , date                  , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_dataQuality_RawData_Source           , source                , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string                                 , sourceComment         , OPTIONAL) lineEnd \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, e_dataQuality_RawData_PostProcessing   , postProcessing        , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string                                 , postProcessingComment , OPTIONAL) lineEnd \
    EMPTY_COMMAND

struct t_dataQuality_RawData : public _OpenDriveElement
{
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(t_dataQuality_RawData)
};

}

