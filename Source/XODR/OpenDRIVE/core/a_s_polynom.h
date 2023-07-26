#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"
#include "XODR/OpenDRIVE/core/a_polynom.h"

namespace _NOD
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_core) \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, a_s) lineEnd \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, a_polynom) lineEnd \
    EMPTY_COMMAND

struct a_s_polynom : public a_s, public a_polynom
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW1_TEST_DEFINE(a_s_polynom)

public:
    inline operator const a_ds_polynom&() const
    {
        return (const a_ds_polynom&)*this;
    }

    inline operator a_ds_polynom&()
    {
        return (a_ds_polynom&)*this;
    }

    inline operator const a_sOffset_polynom&() const
    {
        return (const a_sOffset_polynom&)*this;
    }

    inline operator a_sOffset_polynom&()
    {
        return (a_sOffset_polynom&)*this;
    }
};

}
