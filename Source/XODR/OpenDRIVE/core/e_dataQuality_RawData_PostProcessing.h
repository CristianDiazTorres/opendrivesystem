#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_dataQuality_RawData_PostProcessing">
        <xs:restriction base="xs:string">
            <xs:enumeration value="raw"/>
            <xs:enumeration value="cleaned"/>
            <xs:enumeration value="processed"/>
            <xs:enumeration value="fused"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_dataQuality_RawData_PostProcessing(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_dataQuality_RawData_PostProcessing) \
    _OD_STRING_ENUM_CONST(usingType, e_dataQuality_RawData_PostProcessing, RAW         , _SC_raw) \
    _OD_STRING_ENUM_CONST(usingType, e_dataQuality_RawData_PostProcessing, CLEANED     , _SC_cleaned) \
    _OD_STRING_ENUM_CONST(usingType, e_dataQuality_RawData_PostProcessing, PROCESSED   , _SC_processed) \
    _OD_STRING_ENUM_CONST(usingType, e_dataQuality_RawData_PostProcessing, FUSED       , _SC_fused) \
    EMPTY_COMMAND

struct e_dataQuality_RawData_PostProcessing : public _e_base
{
    _OD_STRING_ENUM_e_dataQuality_RawData_PostProcessing(DECLARE)

public:
    e_dataQuality_RawData_PostProcessing()
    {
        this->value = 0; // Default value
    }
};

}

