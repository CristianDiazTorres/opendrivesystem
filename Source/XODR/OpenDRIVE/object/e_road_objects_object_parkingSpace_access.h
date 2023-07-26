#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_road_objects_object_parkingSpace_access">
        <xs:restriction base="xs:string">
            <xs:enumeration value="all"/>
            <xs:enumeration value="car"/>
            <xs:enumeration value="women"/>
            <xs:enumeration value="handicapped"/>
            <xs:enumeration value="bus"/>
            <xs:enumeration value="truck"/>
            <xs:enumeration value="electric"/>
            <xs:enumeration value="residents"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_road_objects_object_parkingSpace_access(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_road_objects_object_parkingSpace_access) \
    _OD_STRING_ENUM_CONST(usingType, e_road_objects_object_parkingSpace_access, ALL          , _SC_all) \
    _OD_STRING_ENUM_CONST(usingType, e_road_objects_object_parkingSpace_access, CAR          , _SC_car) \
    _OD_STRING_ENUM_CONST(usingType, e_road_objects_object_parkingSpace_access, WOMEN        , _SC_women) \
    _OD_STRING_ENUM_CONST(usingType, e_road_objects_object_parkingSpace_access, HANDICAPPED  , _SC_handicapped) \
    _OD_STRING_ENUM_CONST(usingType, e_road_objects_object_parkingSpace_access, BUS          , _SC_bus) \
    _OD_STRING_ENUM_CONST(usingType, e_road_objects_object_parkingSpace_access, TRUCK        , _SC_truck) \
    _OD_STRING_ENUM_CONST(usingType, e_road_objects_object_parkingSpace_access, ELECTRIC     , _SC_electric) \
    _OD_STRING_ENUM_CONST(usingType, e_road_objects_object_parkingSpace_access, RESIDENTS    , _SC_residents) \
    EMPTY_COMMAND

struct e_road_objects_object_parkingSpace_access : public _e_base
{
    _OD_STRING_ENUM_e_road_objects_object_parkingSpace_access(DECLARE)

public:
    e_road_objects_object_parkingSpace_access()
    {
        this->value = 0; // Default value
    }
};
}
