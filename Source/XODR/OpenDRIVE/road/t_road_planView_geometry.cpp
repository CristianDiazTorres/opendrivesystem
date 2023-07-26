#include "XODR/OpenDRIVE/road/t_road_planView_geometry.h"

namespace _NOD
{

void t_road_planView_geometry::calcXY(const a_s_t& st, XY& xy) const
{
    xy.rx() = this->x() + (st.s - this->s) * cos(this->hdg) + st.t * cos(this->hdg + PI / 2);
    xy.ry() = this->y() + (st.s - this->s) * sin(this->hdg) + st.t * sin(this->hdg + PI / 2);
}

}
