#pragma once

#include "GeoCoordinate/Main/LL.h"
#include "GeoCoordinate/Main/CoordSysXYCell.h"

namespace _NGC
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_gc) \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, LL) lineEnd \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, CoordSysXYCell) lineEnd \
    EMPTY_COMMAND


struct LLCoordSysXYCell : public LL, public CoordSysXYCell
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_isComp_opENE_RW1_TEST_DEFINE(LLCoordSysXYCell)

public:
    inline QJsonArray toJsonArray() const
    {
        QJsonArray result;
        result.push_back(this->lat);
        result.push_back(this->lon);
        result.push_back(this->cellRow);
        result.push_back(this->cellCol);
        result.push_back(this->x());
        result.push_back(this->y());
        return result;
    }

    inline QJsonObject toJsonObject() const
    {
        QJsonObject result;
        result[_SC_lat] = this->lat;
        result[_SC_lon] = this->lon;
        result[_SC_cellRow] = this->cellRow;
        result[_SC_cellCol] = this->cellCol;
        result[_SC_x] = this->x();
        result[_SC_y] = this->y();
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

    void updateAllFromLL();

    void setFromXY(const XY& xy, const CoordSys& coordSysForXY);

    void setFromLL(const LL& ll)
    {
        (LL&)*this = ll;
        updateAllFromLL();
    }

    void setFromLLCoordSys(const LL& ll, const CoordSys& coordSys);

    void setNeighbourCellCenterFrom(const CoordSysXYCell& coord, CardinalDirection direction);
};

typedef QVector<LLCoordSysXYCell>        LLCoordSysXYCellVec;
typedef QVector<LLCoordSysXYCellVec>		LLCoordSysXYCellVecVec;

}
