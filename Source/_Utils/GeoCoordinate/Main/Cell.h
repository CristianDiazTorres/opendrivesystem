#pragma once

#include "GeoCoordinate/Main/CardinalDirection.h"
#include "GeoCoordinate/Main/LL.h"

namespace _NGC
{

struct CoordSys;
struct CoordSysXYCell;
struct LLCoordSysXYCell;

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_gc) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, int, cellRow, REQUIRED) lineEnd \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, int, cellCol, REQUIRED) lineEnd \
    EMPTY_COMMAND

struct Cell
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_isComp_opENE_RW1_TEST_DEFINE(Cell)

public:
    static double SQUARE_CELL_SIZE;

public:
    Cell()
        : cellRow(0)
        , cellCol(0)
    {
    }

    Cell(int cellRow, int cellCol)
        : cellRow(cellRow)
        , cellCol(cellCol)
    {
    }

    Cell(const CoordSysXYCell& coord, CardinalDirection direction)
    {
        setFromCoordDirection(coord, direction);
    }

    inline QJsonArray toJsonArray() const
    {
        QJsonArray result;
        result.push_back(this->cellRow);
        result.push_back(this->cellCol);
        return result;
    }

    inline QJsonObject toJsonObject() const
    {
        QJsonObject result;
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

    QString getName() const
    {
        return QString::number(this->cellRow) + "-" + QString::number(this->cellCol);
    }

    LL getCellCenterLL() const
    {
        return LL(cellRow * SQUARE_CELL_SIZE + SQUARE_CELL_SIZE / 2 /* lat */
                  , cellCol * SQUARE_CELL_SIZE + SQUARE_CELL_SIZE / 2 /* lon */);
    }

    XY getCellCenterXY() const;

    QRectF getCellBoundInDegrees() const
    {
        return QRectF(cellCol * SQUARE_CELL_SIZE,
                      cellRow * SQUARE_CELL_SIZE,
                      SQUARE_CELL_SIZE,
                      SQUARE_CELL_SIZE);
    }

    QRectF getCellBoundInMeters() const;

    //static LL toLL(const XY& xy);

    void setFromLL(const LL& ll);

    void setFromCoordDirection(const CoordSysXYCell& coord, CardinalDirection direction);

    //static QVector<Cell> getCells(const QRectF& boundInMeter);

    LL getCornerLL(CardinalDirection direction) const;
    XY getCornerXY(CardinalDirection direction) const;

    LL getNeighbourCenter(CardinalDirection direction) const;

    XY convertLLCellToXY(const LL& ll) const;
};

}

inline bool operator<(_NGC::Cell a, _NGC::Cell b)
{
    return a.cellRow < b.cellRow || (a.cellRow == b.cellRow && a.cellCol < b.cellCol);
}
