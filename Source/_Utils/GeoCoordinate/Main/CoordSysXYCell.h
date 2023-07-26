#pragma once

#include "GeoCoordinate/Main/CoordSysXY.h"
#include "GeoCoordinate/Main/Cell.h"

namespace _NGC
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_gc) \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, CoordSysXY) lineEnd \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, Cell) lineEnd \
    EMPTY_COMMAND


struct CoordSysXYCell : public CoordSysXY, public Cell
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_isComp_opENE_RW1_TEST_DEFINE(CoordSysXYCell)

public:
    inline QJsonArray toJsonArray() const
    {
        QJsonArray result;
        result.push_back(this->coordSysId);
        result.push_back(this->x());
        result.push_back(this->y());
        result.push_back(this->cellRow);
        result.push_back(this->cellCol);
        return result;
    }

    inline QJsonObject toJsonObject() const
    {
        QJsonObject result;
        result[_SC_coordSysId] = this->coordSysId;
        result[_SC_x] = this->x();
        result[_SC_y] = this->y();
        result[_SC_cellRow] = this->cellRow;
        result[_SC_cellCol] = this->cellCol;
        return result;
    }

    inline operator QJsonArray() const
    {
        return toJsonArray();
    }

    inline operator QJsonObject() const
    {
        return toJsonObject();
    }

    inline bool isOnSameCell(const CoordSysXYCell& other) const
    {
        return (const Cell&)*this == other;
    }
};

}
