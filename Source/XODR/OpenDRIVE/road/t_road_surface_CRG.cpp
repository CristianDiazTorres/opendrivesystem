#include "XODR/OpenDRIVE/road/t_road_surface_CRG.h"


namespace _NOD
{

double t_road_surface_CRG::calcDistance(const a_s_t& st) const
{
    if (st.s < sStart)
        return sStart - st.s;

    if (st.s < sEnd)
        return 0;

    return st.s - sEnd;
}

void t_road_surface_CRG::updateST(const a_s_t &st)
{
    sStart = sEnd = st.s;
}

}
