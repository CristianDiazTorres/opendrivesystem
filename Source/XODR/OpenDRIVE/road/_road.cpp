#include "XODR/OpenDRIVE/road/e_countryCode.h"
#include "XODR/OpenDRIVE/road/e_countryCode_deprecated.h"
#include "XODR/OpenDRIVE/road/e_countryCode_iso3166alpha2.h"
#include "XODR/OpenDRIVE/road/e_countryCode_iso3166alpha3_deprecated.h"
#include "XODR/OpenDRIVE/road/e_direction.h"
#include "XODR/OpenDRIVE/road/e_maxSpeedString.h"
#include "XODR/OpenDRIVE/road/e_paramPoly3_pRange.h"
#include "XODR/OpenDRIVE/road/e_road_link_elementType.h"
#include "XODR/OpenDRIVE/road/e_roadType.h"
#include "XODR/OpenDRIVE/road/e_trafficRule.h"

namespace _NOD
{

_OD_STRING_ENUM_e_countryCode_deprecated(DEFINE)
_OD_STRING_ENUM_e_countryCode_iso3166alpha2(DEFINE)
_OD_STRING_ENUM_e_countryCode_iso3166alpha3_deprecated(DEFINE)
_OD_STRING_ENUM_e_direction(DEFINE)
_OD_STRING_ENUM_e_maxSpeedString(DEFINE)
_OD_STRING_ENUM_e_paramPoly3_pRange(DEFINE)
_OD_STRING_ENUM_e_road_link_elementType(DEFINE)
_OD_STRING_ENUM_e_roadType(DEFINE)
_OD_STRING_ENUM_e_trafficRule(DEFINE)
_OD_STRING_ENUM_MAIN_DEFINE(e_countryCode)

/**************************************************************/

class road_initializer
{
    public:
    road_initializer()
    {
        _OD_STRING_ENUM_e_countryCode_deprecated(INIT)
        _OD_STRING_ENUM_e_countryCode_iso3166alpha2(INIT)
        _OD_STRING_ENUM_e_countryCode_iso3166alpha3_deprecated(INIT)
        _OD_STRING_ENUM_e_direction(INIT)
        _OD_STRING_ENUM_e_maxSpeedString(INIT)
        _OD_STRING_ENUM_e_paramPoly3_pRange(INIT)
        _OD_STRING_ENUM_e_road_link_elementType(INIT)
        _OD_STRING_ENUM_e_roadType(INIT)
        _OD_STRING_ENUM_e_trafficRule(INIT)

        _OD_STRING_ENUM_SUB_ENUM_APPEND(e_countryCode, e_countryCode_iso3166alpha2);
        _OD_STRING_ENUM_SUB_ENUM_APPEND(e_countryCode, e_countryCode_iso3166alpha3_deprecated);
        _OD_STRING_ENUM_SUB_ENUM_APPEND(e_countryCode, e_countryCode_deprecated);
    }
};

static road_initializer s_roadInitializer;

}
