#ifndef __OSM_ROADMARKING_H__
#define __OSM_ROADMARKING_H__

#include "OSM/Internal.h"

namespace _NOSM
{

enum RoadMarking
{
    NONE,
    CONTINUOUS,
    DASHED,
    DOUBLED // instead of DOUBLE, to avoid error
};

static inline String GetRoadMarkingString(RoadMarking road_marking)
{
    static String road_markings[] =
    {
        "NONE",
        "CONTINUOUS",
        "DASHED",
        "DOUBLED" // instead of DOUBLE, to avoid error
    };

    return road_markings[(int)road_marking];
}

}

#endif // __OSM_ROADMARKING_H__
