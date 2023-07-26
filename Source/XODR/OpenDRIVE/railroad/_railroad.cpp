#include "XODR/OpenDRIVE/railroad/e_road_railroad_switch_position.h"
#include "XODR/OpenDRIVE/railroad/e_station_platform_segment_side.h"
#include "XODR/OpenDRIVE/railroad/e_station_type.h"

namespace _NOD
{

_OD_STRING_ENUM_e_road_railroad_switch_position(DEFINE)
_OD_STRING_ENUM_e_station_platform_segment_side(DEFINE)
_OD_STRING_ENUM_e_station_type(DEFINE)

/**************************************************************/

class railroad_initializer
{
    public:
    railroad_initializer()
    {
        _OD_STRING_ENUM_e_road_railroad_switch_position(INIT)
        _OD_STRING_ENUM_e_station_platform_segment_side(INIT)
        _OD_STRING_ENUM_e_station_type(INIT)

        /**************************************************************/
    }
};

static railroad_initializer s_railroadInitializer;

}
