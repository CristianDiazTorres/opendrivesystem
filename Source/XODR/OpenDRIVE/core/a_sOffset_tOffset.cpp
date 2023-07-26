#include "XODR/OpenDRIVE/core/a_sOffset_tOffset.h"


namespace _NOD
{

double a_sOffset_tOffset::calcDistance(const a_s_t& other) const
{
    double ds = sOffset - other.s;
    double dt = tOffset - other.t;
    return sqrt(ds * ds + dt * dt);
}

void a_sOffset_tOffset::updateST(const a_s_t& other)
{
    sOffset = other.s;
    tOffset = other.t;
}

}
