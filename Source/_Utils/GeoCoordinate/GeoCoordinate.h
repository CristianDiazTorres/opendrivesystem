#pragma once

#include "GeoCoordinate/Internal/Internal.h"
#include "GeoCoordinate/Main/CardinalDirection.h"
#include "GeoCoordinate/Main/LLCoordSysXYCell.h"

// Direction:
//  X <=> Lon (Left=>Right)
//  Y <=> Lat (Bottom=>Up)

namespace _NGC
{

const char* getWKT(const char* anyFormat);
const char* getWKT(const CoordSys& coordSys);

XY convert(const LL& ll, const CoordSys& coordSys);
LL convert(const XY& xy, const CoordSys& coordSys);

}
