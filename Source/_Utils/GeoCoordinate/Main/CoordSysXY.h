#pragma once

#include "GeoCoordinate/Main/CoordSys.h"

namespace _NGC
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_gc) \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, CoordSys) lineEnd \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, XY) lineEnd \
    EMPTY_COMMAND


struct CoordSysXY : public CoordSys, public XY
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_isComp_opENE_RW1_TEST_DEFINE(CoordSysXY)
};

}
