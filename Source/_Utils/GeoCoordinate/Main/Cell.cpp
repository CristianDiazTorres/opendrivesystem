#include "GeoCoordinate/Main/Cell.h"
#include "GeoCoordinate/Main/LL.h"
#include "GeoCoordinate/GeoCoordinate.h"
#include "GeoCoordinate/Main/LLCoordSysXYCell.h"

namespace _NGC
{

double Cell::SQUARE_CELL_SIZE = 0.01;

QRectF Cell::getCellBoundInMeters() const
{
    QVector<XY> points;
    points << getCellCenterXY();

    for (int direction = North; direction < DirectionCount; direction ++)
        points << getCornerXY((CardinalDirection)direction);

    return _NMath::calcBoundInXY(points);
}

XY Cell::getCellCenterXY() const
{
    return convertLLCellToXY(getCellCenterLL());
}
/*
LL Cell::toLL(const XY& xy)
{
    LL ll;
    convert(xy, 0, ll);
    return ll;
}
*/

void Cell::setFromLL(const LL& ll)
{
    cellRow = (int)(ll.lat / SQUARE_CELL_SIZE);
    cellCol = (int)(ll.lon / SQUARE_CELL_SIZE);

    if (ll.lat < 0 && cellRow * SQUARE_CELL_SIZE > ll.lat)
    {
        cellRow --;
    }

    if (ll.lon < 0 && cellCol * SQUARE_CELL_SIZE > ll.lon)
    {
        cellCol --;
    }
}

void Cell::setFromCoordDirection(const CoordSysXYCell& coord, CardinalDirection direction)
{
    setFromLL(coord.getNeighbourCenter(direction));
}
/*
QVector<Cell> Cell::getCells(const QRectF& boundInMeter)
{
    XY centerInMeter = boundInMeter.center();

    QVector<LL> points;
    points << toLL(XY(centerInMeter.x(), centerInMeter.y()));

    points << toLL(XY(boundInMeter.x(), boundInMeter.y()));
    points << toLL(XY(centerInMeter.x(), boundInMeter.y()));
    points << toLL(XY(boundInMeter.right(), boundInMeter.y()));
    points << toLL(XY(boundInMeter.right(), centerInMeter.y()));
    points << toLL(XY(boundInMeter.right(), boundInMeter.bottom()));
    points << toLL(XY(centerInMeter.x(), boundInMeter.bottom()));
    points << toLL(XY(boundInMeter.x(), boundInMeter.bottom()));
    points << toLL(XY(boundInMeter.x(), centerInMeter.y()));

    QRectF bound = LL::calcBound(points);

    double left = bound.left() - SQUARE_CELL_SIZE / 2;
    double top = bound.top() - SQUARE_CELL_SIZE / 2;
    double right = bound.right() + SQUARE_CELL_SIZE / 2;
    double bottom = bound.bottom() + SQUARE_CELL_SIZE / 2;

    QMap<int, QMap<int, Cell> > cellsMap;

    for (double lon = left; lon <= right; lon += SQUARE_CELL_SIZE / 2)
    {
        for (double lat = top; lat <= bottom; lat += SQUARE_CELL_SIZE / 2)
        {
            Cell cell;
            cell.setFromLL(LL(lat, lon));
            cellsMap[cell.cellRow][cell.cellCol] = cell;
        }
    }

    QVector<Cell> result;
    int count = (int)((right - left) / SQUARE_CELL_SIZE * (bottom - top) / SQUARE_CELL_SIZE);
    result.reserve(count);
    for (QMap<int, QMap<int, Cell> >::iterator iter1 = cellsMap.begin(); iter1 != cellsMap.end(); iter1 ++)
    {
        for (QMap<int, Cell>::iterator iter2 = iter1.value().begin(); iter2 != iter1.value().end(); iter2 ++)
        {
            result << iter2.value();
        }
    }
    return result;
}
*/
LL Cell::getCornerLL(CardinalDirection direction) const
{
    LL center = getCellCenterLL();

    if ((direction == North) || (direction == NorthEast) || (direction == NorthWest))
        center.lat += SQUARE_CELL_SIZE / 2;
    else if ((direction == South) || (direction == SouthEast) || (direction == SouthWest))
        center.lat -= SQUARE_CELL_SIZE / 2;

    if ((direction == East) || (direction == NorthEast) || (direction == SouthEast))
        center.lon += SQUARE_CELL_SIZE / 2;
    else if ((direction == West) || (direction == NorthWest) || (direction == SouthWest))
        center.lon -= SQUARE_CELL_SIZE / 2;

    return center;
}

XY Cell::getCornerXY(CardinalDirection direction) const
{
    return convertLLCellToXY(getCornerLL(direction));
}

LL Cell::getNeighbourCenter(CardinalDirection direction) const
{
    LL center = getCellCenterLL();

    if ((direction == North) || (direction == NorthEast) || (direction == NorthWest))
        center.lat += SQUARE_CELL_SIZE;
    else if ((direction == South) || (direction == SouthEast) || (direction == SouthWest))
        center.lat -= SQUARE_CELL_SIZE;

    if ((direction == East) || (direction == NorthEast) || (direction == SouthEast))
        center.lon += SQUARE_CELL_SIZE;
    else if ((direction == West) || (direction == NorthWest) || (direction == SouthWest))
        center.lon -= SQUARE_CELL_SIZE;

    return center;
}

XY Cell::convertLLCellToXY(const LL& ll) const
{
    CoordSys coordSys;
    coordSys.setFromCell(*this);
    return convert(ll, coordSys);
}

}
