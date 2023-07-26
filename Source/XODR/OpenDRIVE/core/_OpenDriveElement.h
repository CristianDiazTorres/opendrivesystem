#pragma once

#include "XODR/OpenDRIVE/core/_integer.h"
#include "XODR/OpenDRIVE/core/_double.h"
#include "XODR/OpenDRIVE/core/_date.h"
#include "XODR/OpenDRIVE/core/_stringEnum.h"
#include "XODR/OpenDRIVE/core/t_grEqZero.h"

namespace _NOD
{

struct _OpenDriveElement : public _NUniversialType::UniversialType
{
public:
    static XY getJunctionPos(const OpenDRIVE& content, const t_junction& junction);
    virtual double calcDistance(const a_s_t& st) const
    {
        Q_UNUSED(st);
        return 0;
    }

    virtual void updateST(const a_s_t& st)
    {
        Q_UNUSED(st);
    }

    virtual void calcAbsolutePos(t_road& road)
    {
        Q_UNUSED(road);
    }

    virtual void calcRelativePos(t_road& road)
    {
        Q_UNUSED(road);
    }
};

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_core) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, t_grEqZero, s, REQUIRED) lineEnd \
    EMPTY_COMMAND

struct a_s : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_isComp_opENE_RW1_TEST_DEFINE(a_s)
    _UNIVERSIAL_TYPE_empty_setParent_DEFINE(a_s)

public:
    inline operator const double&() const
    {
        return (const double&)*this;
    }

    inline operator double&()
    {
        return (double&)*this;
    }

    inline operator const a_ds&() const
    {
        return (const a_ds&)*this;
    }

    inline operator a_ds&()
    {
        return (a_ds&)*this;
    }

    //inline operator const a_s&() const
    //{
    //    return (const a_s&)*this;
    //}
    //
    //inline operator a_s&()
    //{
    //    return (a_s&)*this;
    //}

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

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_core) \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, a_s) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, double, t, REQUIRED) lineEnd \
    EMPTY_COMMAND

struct a_s_t : public a_s, public XY
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_isComp_opENE_RW1_TEST_DEFINE(a_s_t)

public:
    inline operator const a_sOffset_tOffset&() const
    {
        return (const a_sOffset_tOffset&)*this;
    }

    inline operator a_sOffset_tOffset&()
    {
        return (a_sOffset_tOffset&)*this;
    }

public:
    double calcDistance(const a_s_t& other) const;

    void updateST(const a_s_t& other);

    void calcAbsolutePos(t_road& road);

    void calcRelativePos(t_road& road);
};

struct _GeoJSONData
{
    QString geojsonVersion;
    bool updateST;
    QString tag;
    QString operCommand;
    QString operType;
    QJsonObject condPropsObj;
    QJsonObject propsObj;

    bool isLine;

    LLCoordSysXYCellVec points;
    QVector<a_s_t> sts;

    LLCoordSysXYCell point;
    a_s_t st;
};

}
