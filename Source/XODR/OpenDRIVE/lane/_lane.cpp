#include "XODR/OpenDRIVE/lane/e_accessRestrictionType.h"
#include "XODR/OpenDRIVE/lane/e_laneType.h"
#include "XODR/OpenDRIVE/lane/e_road_lanes_laneSection_lcr_lane_roadMark_laneChange.h"
#include "XODR/OpenDRIVE/lane/e_road_lanes_laneSection_lr_lane_access_rule.h"
#include "XODR/OpenDRIVE/lane/e_roadMarkColor.h"
#include "XODR/OpenDRIVE/lane/e_roadMarkRule.h"
#include "XODR/OpenDRIVE/lane/e_roadMarkType.h"
#include "XODR/OpenDRIVE/lane/e_roadMarkWeight.h"

namespace _NOD
{

_OD_STRING_ENUM_e_accessRestrictionType(DEFINE)
_OD_STRING_ENUM_e_laneType(DEFINE)
_OD_STRING_ENUM_e_road_lanes_laneSection_lcr_lane_roadMark_laneChange(DEFINE)
_OD_STRING_ENUM_e_road_lanes_laneSection_lr_lane_access_rule(DEFINE)
_OD_STRING_ENUM_e_roadMarkColor(DEFINE)
_OD_STRING_ENUM_e_roadMarkRule(DEFINE)
_OD_STRING_ENUM_e_roadMarkType(DEFINE)
_OD_STRING_ENUM_e_roadMarkWeight(DEFINE)

/**************************************************************/

class lane_initializer
{
    public:
    lane_initializer()
    {
        _OD_STRING_ENUM_e_accessRestrictionType(INIT)
        _OD_STRING_ENUM_e_laneType(INIT)
        _OD_STRING_ENUM_e_road_lanes_laneSection_lcr_lane_roadMark_laneChange(INIT)
        _OD_STRING_ENUM_e_road_lanes_laneSection_lr_lane_access_rule(INIT)
        _OD_STRING_ENUM_e_roadMarkColor(INIT)
        _OD_STRING_ENUM_e_roadMarkRule(INIT)
        _OD_STRING_ENUM_e_roadMarkType(INIT)
        _OD_STRING_ENUM_e_roadMarkWeight(INIT)
    }
};

static lane_initializer s_laneInitializer;

}
