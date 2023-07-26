#include "GeoCoordinate/GeoCoordinate.h"
#include "Common/Main/StringContants.h"

#ifdef _WIN32
#include "C:/OSGeo4W64/include/proj.h"
#else
#include "proj.h"
#endif

namespace _NGC
{

class PROJMaps
{
public:
    PJ_CONTEXT* pjContext;
    QMap<int, PJ*> pjFromWGS84;
    QMap<QString, PJ*> pjMaps;

    PROJMaps()
    {
        pjContext = proj_context_create();

#ifdef _WIN32
        proj_context_set_database_path(pjContext, "C:\\OSGeo4W64\\share\\proj\\proj.db", NULL, NULL);
#endif
    }

    ~PROJMaps()
    {
        for (QMap<int, PJ*>::iterator iter = pjFromWGS84.begin(); iter != pjFromWGS84.end(); iter ++)
            proj_destroy (iter.value());

        for (QMap<QString, PJ*>::iterator iter = pjMaps.begin(); iter != pjMaps.end(); iter ++)
            proj_destroy (iter.value());

        proj_context_destroy (pjContext);
    }

    PJ* getProjectionFromWGS84(const CoordSys& coordSys)
    {
        coordSys.assertIfValid();

        if (pjFromWGS84.contains(coordSys.coordSysId))
            return pjFromWGS84[coordSys.coordSysId];

        PJ* projection = proj_create_crs_to_crs (pjContext,
                                                 _SC_EPSG_4326_A,
                                                 coordSys.getProj4(),
                                                 NULL);

        /* This will ensure that the order of coordinates for the input CRS */
        /* will be longitude, latitude, whereas EPSG:4326 mandates latitude, */
        /* longitude */
        PJ* normalizedProjection = proj_normalize_for_visualization(pjContext, projection);
        proj_destroy(projection);

        return (pjFromWGS84[coordSys.coordSysId] = normalizedProjection);
    }

    PJ* getProjectionFromAnyString(const char* definition)
    {
        if (pjMaps.contains(definition))
            return pjMaps[definition];

        return (pjMaps[definition] = proj_create(pjContext, definition));
    }

} s_projMaps;

const char* getWKT(const char* anyFormat)
{
    PJ* pj = s_projMaps.getProjectionFromAnyString(anyFormat);
    return proj_as_wkt(s_projMaps.pjContext, pj, PJ_WKT2_2019, NULL);
}

const char* getWKT(const CoordSys& coordSys)
{
    return getWKT(coordSys.getProj4());
}

XY convert(const LL& ll, const CoordSys& coordSys)
{
    coordSys.assertIfValid();

    PJ* projection = s_projMaps.getProjectionFromWGS84(coordSys);

    /* a coordinate union representing Copenhagen: 55d N, 12d E    */
    /* Given that we have used proj_normalize_for_visualization(), the order of */
    /* coordinates is longitude, latitude, and values are expressed in degrees. */
    PJ_COORD from = proj_coord(ll.lon, ll.lat, 0, 0);
    PJ_COORD to = proj_trans(projection, PJ_FWD, from);
    XY xy;
    xy.rx() = to.enu.e;
    xy.ry() = to.enu.n;
    //printf ("easting: %.3f, northing: %.3f\n", b.enu.e, b.enu.n);
    return xy;
}

LL convert(const XY& xy, const CoordSys& coordSys)
{
    coordSys.assertIfValid();

    PJ* projection = s_projMaps.getProjectionFromWGS84(coordSys);

    PJ_COORD from = proj_coord(xy.x(), xy.y(), 0, 0);
    PJ_COORD to = proj_trans(projection, PJ_INV, from);
    LL ll;
    ll.lon = to.lp.lam;
    ll.lat = to.lp.phi;
    //printf ("longitude: %g, latitude: %g\n", b.lp.lam, b.lp.phi);
    return ll;
}

}
