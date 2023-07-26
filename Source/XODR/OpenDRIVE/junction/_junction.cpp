#include "XODR/OpenDRIVE/junction/e_contactPoint.h"
#include "XODR/OpenDRIVE/junction/e_elementDir.h"
#include "XODR/OpenDRIVE/junction/e_junction_type.h"
#include "XODR/OpenDRIVE/junction/e_junctionGroup_type.h"
#include "XODR/OpenDRIVE/junction/e_road_surface_CRG_mode.h"
#include "XODR/OpenDRIVE/junction/e_road_surface_CRG_purpose.h"

namespace _NOD
{

/**************************************************************/

_OD_STRING_ENUM_e_contactPoint(DEFINE)
_OD_STRING_ENUM_e_elementDir(DEFINE)
_OD_STRING_ENUM_e_junction_type(DEFINE)
_OD_STRING_ENUM_e_junctionGroup_type(DEFINE)
_OD_STRING_ENUM_e_road_surface_CRG_mode(DEFINE)
_OD_STRING_ENUM_e_road_surface_CRG_purpose(DEFINE)

/**************************************************************/

class junction_initializer
{
    public:
    junction_initializer()
    {
        _OD_STRING_ENUM_e_contactPoint(INIT)
        _OD_STRING_ENUM_e_elementDir(INIT)
        _OD_STRING_ENUM_e_junction_type(INIT)
        _OD_STRING_ENUM_e_junctionGroup_type(INIT)
        _OD_STRING_ENUM_e_road_surface_CRG_mode(INIT)
        _OD_STRING_ENUM_e_road_surface_CRG_purpose(INIT)
    }
};

static junction_initializer s_junctionInitializer;

}
