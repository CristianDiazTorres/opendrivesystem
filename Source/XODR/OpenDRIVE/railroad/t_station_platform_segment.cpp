#include "XODR/OpenDRIVE/railroad/t_station_platform_segment.h"


namespace _NOD
{

double t_station_platform_segment::calcDistance(const a_s_t& st) const
{
    if (st.s < sStart)
        return sStart - st.s;

    if (st.s < sEnd)
        return 0;

    return st.s - sEnd;
}

void t_station_platform_segment::updateST(const a_s_t &st)
{
    sStart = sEnd = st.s;
}

}
