#include "XODR/Main/RoadFusor.h"
#include "Debugger/Main/Logger.h"

namespace _NXODR
{
QVector<_NOD::t_road> RoadFusor::fuse(const QVector<_NOD::t_road>& old_roads, const QVector<_NOD::t_road>& new_roads)
{
    QVector<_NOD::t_road> result;

    for (const _NOD::t_road& r1 : old_roads)
    {
        bool foundSimilar = false;
        for (const _NOD::t_road& r2 : new_roads)
        {
            if (r1.isSimilar(r2))
            {
                foundSimilar = true;
                break;
            }
        }

        if (foundSimilar)
            continue;

        result << r1;
    }

    result.append(new_roads);
    DefaultLogger << "    Fuse : " << old_roads.size() << " , " << new_roads.size() << " => " << result.size();
    return result;
}

}
