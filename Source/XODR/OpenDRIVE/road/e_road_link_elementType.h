#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_road_link_elementType">
        <xs:restriction base="xs:string">
            <xs:enumeration value="road"/>
            <xs:enumeration value="junction"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_road_link_elementType(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_road_link_elementType) \
    _OD_STRING_ENUM_CONST(usingType, e_road_link_elementType, ROAD       , _SC_road) \
    _OD_STRING_ENUM_CONST(usingType, e_road_link_elementType, JUNCTION   , _SC_junction) \
    EMPTY_COMMAND

struct e_road_link_elementType : public _e_base
{
    _OD_STRING_ENUM_e_road_link_elementType(DECLARE)

public:
    e_road_link_elementType()
    {
        this->value = 0; // Default value
    }
};
}
