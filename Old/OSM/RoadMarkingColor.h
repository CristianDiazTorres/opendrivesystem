#ifndef __OSM_ROADMARKINGCOLOR_H__
#define __OSM_ROADMARKINGCOLOR_H__

#include "OSM/Internal.h"

namespace _NOSM
{

enum RoadMarkingColor
{
    WHITE,
    YELLOW,
    RED,
    GREEN,
    BLUE
};

static inline String GetRoadMarkingColorString(RoadMarkingColor road_marking_color)
{
    static String road_marking_colors[]
    {
        "WHITE",
        "YELLOW",
        "RED",
        "GREEN",
        "BLUE"
    };

    return road_marking_colors[(int)road_marking_color];
}

}

#endif // __OSM_ROADMARKINGCOLOR_H__
