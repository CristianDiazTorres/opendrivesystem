#include "XODR/OpenDRIVE/road/t_road_planView.h"
#include "Math/Math.h"


namespace _NOD
{

void t_road_planView::calcST(const XY& xy, a_s_t &st) const
{
    st.s = 0;
    st.t = 0;

    double minDist = DOUBLE_MAX;

    for (int i = 0; i < geometry_sequence.size() - 1; i ++)
    {
        const t_road_planView_geometry& geom = geometry_sequence[i];
        double dx = geom.length * cos(geom.hdg);
        double dy = geom.length * sin(geom.hdg);
        double u = 0;
        double dist = _NMath::calcDistance(geom, XY(geom.x() + dx, geom.y() + dy), xy, u);
        if (dist < minDist)
        {
            minDist = dist;
            st.s = geom.s + u * geom.length;

            double side = _NMath::getSideOnLine2(geom, XY(dx, dy), xy);
            if (side >= 0)
                st.t = dist; // Point is on left of line
            else
                st.t = - dist; // Point is on right of line
        }
    }
}

void t_road_planView::calcXY(const a_s_t &st, XY &xy) const
{
    getPoint(st.s).calcXY(st, xy);
}

}
