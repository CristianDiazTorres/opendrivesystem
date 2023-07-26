#include "XODR/OpenDRIVE/core/a_sOffset.h"


namespace _NOD
{

double a_sOffset::calcDistance(const a_s& other) const
{
    return fabs(sOffset - other.s);
}

double a_sOffset::calcDistance(const a_s_t& other) const
{
    return fabs(sOffset - other.s);
}

void a_sOffset::updateST(const a_s_t& other)
{
    sOffset = other.s;
}

}
