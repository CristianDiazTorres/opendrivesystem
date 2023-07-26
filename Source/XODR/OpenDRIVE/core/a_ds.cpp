#include "XODR/OpenDRIVE/core/a_ds.h"

namespace _NOD
{

double a_ds::calcDistance(const a_s& other) const
{
    return fabs(ds - other.s);
}

double a_ds::calcDistance(const a_s_t& other) const
{
    return fabs(ds - other.s);
}

void a_ds::updateST(const a_s_t& other)
{
    ds = other.s;
}

}
