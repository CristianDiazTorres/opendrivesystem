#include "GeoCoordinate/Main/CoordSys.h"

#define _NGC_START_COORD_SYS_ID 0

#define _NGC_3857_COORD_SYS_ID  0
// Australia, EPSG:3112, EPSG:1736
#define _NGC_AUS_COORD_SYS_ID   1

#define _NGC_COORD_SYS_ID_COUNT 2

static const char* s_proj4s[] =
{
    "+proj=merc +a=6378137 +b=6378137 +lat_ts=0.0 +lon_0=0.0 +x_0=0.0 +y_0=0 +k=1.0 +units=m +nadgrids=@null +wktext  +no_defs"
    // Australia, EPSG:3112, EPSG:1736
    , "+proj=lcc +lat_1=-18 +lat_2=-36 +lat_0=0 +lon_0=134 +x_0=0 +y_0=0 +ellps=GRS80 +towgs84=0,0,0,0,0,0,0 +units=m +no_defs"
};

namespace _NGC
{

bool CoordSys::isValid() const
{
    return coordSysId >= _NGC_START_COORD_SYS_ID && coordSysId < _NGC_COORD_SYS_ID_COUNT;
}

const char* CoordSys::getProj4() const
{
    assertIfValid();
    return s_proj4s[coordSysId];
}

CoordSys CoordSys::get3857()
{
    return CoordSys(_NGC_3857_COORD_SYS_ID);
}

CoordSys CoordSys::getAusCoordSys()
{
    return CoordSys(_NGC_AUS_COORD_SYS_ID);
}

void CoordSys::setFromLL(const LL& ll)
{
    Q_UNUSED(ll);
    coordSysId = _NGC_AUS_COORD_SYS_ID;
}

void CoordSys::setFromCell(const Cell& cell)
{
    Q_UNUSED(cell);
    coordSysId = _NGC_AUS_COORD_SYS_ID;
}

}
