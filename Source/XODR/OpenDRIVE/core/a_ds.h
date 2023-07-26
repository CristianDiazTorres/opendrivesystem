#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

namespace _NOD
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_core) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero, ds, REQUIRED) lineEnd \
    EMPTY_COMMAND

struct a_ds : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW1_TEST_DEFINE(a_ds)

public:
    inline operator const double&() const
    {
        return (const double&)*this;
    }

    inline operator double&()
    {
        return (double&)*this;
    }

    //inline operator const a_ds&() const
    //{
    //    return (const a_ds&)*this;
    //}
    //
    //inline operator a_ds&()
    //{
    //    return (a_ds&)*this;
    //}

    inline operator const a_s&() const
    {
        return (const a_s&)*this;
    }

    inline operator a_s&()
    {
        return (a_s&)*this;
    }

    inline operator const a_sOffset&() const
    {
        return (const a_sOffset&)*this;
    }

    inline operator a_sOffset&()
    {
        return (a_sOffset&)*this;
    }

    double calcDistance(const a_s& other) const;

    double calcDistance(const a_s_t& other) const;

    void updateST(const a_s_t& other);
};

}
