#include "GeoCoordinate/Main/LLCoordSysXYCell.h"
#include "GeoCoordinate/GeoCoordinate.h"
#include <time.h>

namespace _NGC
{

void LLCoordSysXYCell::updateAllFromLL()
{
    ((CoordSys&)*this).setFromLL(*this);
    (XY&)*this = convert((const LL&)*this, (const CoordSys&)*this);
    Cell::setFromLL(*this);
}

void LLCoordSysXYCell::setFromXY(const XY& xy, const CoordSys& coordSysForXY)
{
    (LL&)*this = convert(xy, coordSysForXY);
    (CoordSys&)*this = coordSysForXY;
    (XY&)*this = xy;
    Cell::setFromLL(*this);
}

void LLCoordSysXYCell::setFromLLCoordSys(const LL& ll, const CoordSys& coordSys)
{
    (LL&)*this = ll;
    (CoordSys&)*this = coordSys;
    (XY&)*this = convert(ll, coordSys);
    Cell::setFromLL(*this);
}

void LLCoordSysXYCell::setNeighbourCellCenterFrom(const CoordSysXYCell& coord, CardinalDirection direction)
{
    setFromLL(coord.getNeighbourCenter(direction));
}

}
