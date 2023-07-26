#pragma once

#include "OSM/Internal/Internal.h"

namespace _NOSM
{

struct OSMTileImageParam
{
    int zoom;
    int row;
    int col;

public:
    OSMTileImageParam(){}

    OSMTileImageParam(int zoom, int row, int col)
        : zoom(zoom)
        , row(row)
        , col(col)
    {
    }
};

inline int long2tilex(double lon, int z)
{
    return (int)(floor((lon + 180.0) / 360.0 * (1 << z)));
}

inline int lat2tiley(double lat, int z)
{
    double latrad = lat * PI / 180.0;
    return (int)(floor((1.0 - asinh(tan(latrad)) / PI) / 2.0 * (1 << z)));
}

inline double tilex2long(int x, int z)
{
    return x / (double)(1 << z) * 360.0 - 180;
}

inline double tiley2lat(int y, int z)
{
    double n = PI - 2.0 * PI * y / (double)(1 << z);
    return 180.0 / PI * atan(0.5 * (exp(n) - exp(-n)));
}

}

Q_DECLARE_METATYPE(_NOSM::OSMTileImageParam)

inline bool operator<(const _NOSM::OSMTileImageParam& a, const _NOSM::OSMTileImageParam& b)
{
    return a.zoom < b.zoom
        || (a.zoom == b.zoom && a.row < b.row)
        || (a.zoom == b.zoom && a.row == b.row && a.col < b.col);
}
