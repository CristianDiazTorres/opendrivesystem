#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_unit">
        <xs:union memberTypes="e_unitDistance e_unitSpeed e_unitMass e_unitSlope"/>
    </xs:simpleType>
*/

namespace _NOD
{

struct e_unit : public _e_base
{
public:
    e_unit()
    {
        this->value = 0; // Default value
    }

    _OD_STRING_ENUM_MAIN_DECLARE(e_unit)
};

}

