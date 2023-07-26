#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_elementDir">
        <xs:restriction base="xs:string">
            <xs:enumeration value="+"/>
            <xs:enumeration value="-"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_elementDir(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_elementDir) \
    _OD_STRING_ENUM_CONST(usingType, e_elementDir, PLUS  , "+") \
    _OD_STRING_ENUM_CONST(usingType, e_elementDir, MINUS , "-") \
    EMPTY_COMMAND

struct e_elementDir : public _e_base
{
    _OD_STRING_ENUM_e_elementDir(DECLARE)

public:
    e_elementDir()
    {
        this->value = 0; // Default value
    }
};
}
