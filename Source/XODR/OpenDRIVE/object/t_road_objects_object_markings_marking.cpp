#include "XODR/OpenDRIVE/object/t_road_objects_object_markings_marking.h"


namespace _NOD
{

double t_road_objects_object_markings_marking::calcDistance(const a_s_t& st) const
{
    if (st.s < startOffset)
        return startOffset - st.s;

    if (st.s < stopOffset)
        return 0;

    return st.s - stopOffset;
}

void t_road_objects_object_markings_marking::updateST(const a_s_t &st)
{
    startOffset = stopOffset = st.s;
}

}
