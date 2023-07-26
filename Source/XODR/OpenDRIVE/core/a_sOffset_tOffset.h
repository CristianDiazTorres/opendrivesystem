#pragma once

#include "XODR/OpenDRIVE/core/a_sOffset.h"

namespace _NOD
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_core) \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, a_sOffset) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, tOffset, REQUIRED) lineEnd \
    EMPTY_COMMAND

struct a_sOffset_tOffset : public a_sOffset
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW1_TEST_DEFINE(a_sOffset_tOffset)

public:
    inline operator const a_s_t&() const
    {
        return (const a_s_t&)*this;
    }

    inline operator a_s_t&()
    {
        return (a_s_t&)*this;
    }

public:
    double calcDistance(const a_s_t& other) const;

    void updateST(const a_s_t& other);
};

}
