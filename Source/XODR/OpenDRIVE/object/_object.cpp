#include "XODR/OpenDRIVE/object/e_borderType.h"
#include "XODR/OpenDRIVE/object/e_bridgeType.h"
#include "XODR/OpenDRIVE/object/e_objectType.h"
#include "XODR/OpenDRIVE/object/e_orientation.h"
#include "XODR/OpenDRIVE/object/e_outlineFillType.h"
#include "XODR/OpenDRIVE/object/e_road_objects_object_parkingSpace_access.h"
#include "XODR/OpenDRIVE/object/e_sideType.h"
#include "XODR/OpenDRIVE/object/e_tunnelType.h"

namespace _NOD
{

_OD_STRING_ENUM_e_borderType(DEFINE)
_OD_STRING_ENUM_e_bridgeType(DEFINE)
_OD_STRING_ENUM_e_objectType(DEFINE)
_OD_STRING_ENUM_e_orientation(DEFINE)
_OD_STRING_ENUM_e_outlineFillType(DEFINE)
_OD_STRING_ENUM_e_road_objects_object_parkingSpace_access(DEFINE)
_OD_STRING_ENUM_e_sideType(DEFINE)
_OD_STRING_ENUM_e_tunnelType(DEFINE)

/**************************************************************/

class object_initializer
{
    public:
    object_initializer()
    {
        _OD_STRING_ENUM_e_borderType(INIT)
        _OD_STRING_ENUM_e_bridgeType(INIT)
        _OD_STRING_ENUM_e_objectType(INIT)
        _OD_STRING_ENUM_e_orientation(INIT)
        _OD_STRING_ENUM_e_outlineFillType(INIT)
        _OD_STRING_ENUM_e_road_objects_object_parkingSpace_access(INIT)
        _OD_STRING_ENUM_e_sideType(INIT)
        _OD_STRING_ENUM_e_tunnelType(INIT)

        /**************************************************************/
    }
};

static object_initializer s_objectInitializer;

}
