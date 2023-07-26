#pragma once

#include "GeoCoordinate/Main/CoordSys.h"
#include "GeoCoordinate/Main/Cell.h"

namespace _NGC
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_gc) \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, CoordSys) lineEnd \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, Cell) lineEnd \
    EMPTY_COMMAND


struct CoordSysCell : public CoordSys, public Cell
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_isComp_opENE_RW1_TEST_DEFINE(CoordSysCell)
};

}
