#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

namespace _NOD
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_core) \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, XY) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, hdg, REQUIRED) lineEnd \
    EMPTY_COMMAND

struct a_xy_hdg : public XY
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_isComp_opENE_RW1_TEST_DEFINE(a_xy_hdg)
    _UNIVERSIAL_TYPE_empty_setParent_DEFINE(a_xy_hdg)
};

}
