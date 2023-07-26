#include "XODR/OpenDRIVE/core/e_dataQuality_RawData_PostProcessing.h"
#include "XODR/OpenDRIVE/core/e_dataQuality_RawData_Source.h"
#include "XODR/OpenDRIVE/core/e_unit.h"
#include "XODR/OpenDRIVE/core/e_unitDistance.h"
#include "XODR/OpenDRIVE/core/e_unitMass.h"
#include "XODR/OpenDRIVE/core/e_unitSlope.h"
#include "XODR/OpenDRIVE/core/e_unitSpeed.h"

namespace _NOD
{

_OD_STRING_ENUM_e_dataQuality_RawData_PostProcessing(DEFINE)
_OD_STRING_ENUM_e_dataQuality_RawData_Source(DEFINE)
_OD_STRING_ENUM_e_unitDistance(DEFINE)
_OD_STRING_ENUM_e_unitMass(DEFINE)
_OD_STRING_ENUM_e_unitSlope(DEFINE)
_OD_STRING_ENUM_e_unitSpeed(DEFINE)
_OD_STRING_ENUM_MAIN_DEFINE(e_unit)

class core_initializer
{
public:
    core_initializer()
    {
        _OD_STRING_ENUM_e_dataQuality_RawData_PostProcessing(INIT)
        _OD_STRING_ENUM_e_dataQuality_RawData_Source(INIT)
        _OD_STRING_ENUM_e_unitDistance(INIT)
        _OD_STRING_ENUM_e_unitMass(INIT)
        _OD_STRING_ENUM_e_unitSlope(INIT)
        _OD_STRING_ENUM_e_unitSpeed(INIT)

        _OD_STRING_ENUM_SUB_ENUM_APPEND(e_unit, e_unitDistance);
        _OD_STRING_ENUM_SUB_ENUM_APPEND(e_unit, e_unitMass);
        _OD_STRING_ENUM_SUB_ENUM_APPEND(e_unit, e_unitSlope);
        _OD_STRING_ENUM_SUB_ENUM_APPEND(e_unit, e_unitSpeed);
    }
};

static core_initializer s_coreInitializer;

}
