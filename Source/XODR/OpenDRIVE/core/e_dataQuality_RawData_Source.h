#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_dataQuality_RawData_Source">
        <xs:restriction base="xs:string">
            <xs:enumeration value="sensor"/>
            <xs:enumeration value="cadaster"/>
            <xs:enumeration value="custom"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_dataQuality_RawData_Source(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_dataQuality_RawData_Source) \
    _OD_STRING_ENUM_CONST(usingType, e_dataQuality_RawData_Source, SENSOR    , _SC_sensor) \
    _OD_STRING_ENUM_CONST(usingType, e_dataQuality_RawData_Source, CADASTER  , _SC_cadaster) \
    _OD_STRING_ENUM_CONST(usingType, e_dataQuality_RawData_Source, CUSTOM    , _SC_custom) \
    EMPTY_COMMAND

struct e_dataQuality_RawData_Source : public _e_base
{
    _OD_STRING_ENUM_e_dataQuality_RawData_Source(DECLARE)

public:
    e_dataQuality_RawData_Source()
    {
        this->value = 0; // Default value
    }
};

}

