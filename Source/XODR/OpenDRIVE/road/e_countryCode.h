#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_countryCode">
        <xs:union memberTypes="e_countryCode_iso3166alpha2 e_countryCode_iso3166alpha3_deprecated e_countryCode_deprecated"/>
    </xs:simpleType>
*/

namespace _NOD
{
struct e_countryCode : public _e_base
{
public:
    e_countryCode()
    {
        this->value = 0; // Default value
    }

    _OD_STRING_ENUM_MAIN_DECLARE(e_countryCode)
};
}
