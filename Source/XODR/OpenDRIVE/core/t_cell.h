#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"
#include "GeoCoordinate/Main/Cell.h"

namespace _NOD
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_core) \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, Cell) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double     , centerX  , REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double     , centerY  , REQUIRED) lineEnd \
    EMPTY_COMMAND

struct t_cell : public Cell
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_isComp_opENE_RW1_TEST_DEFINE(t_cell)
};

}
