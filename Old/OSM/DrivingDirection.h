#ifndef __OSM_DRIVINGDIRECTION_H__
#define __OSM_DRIVINGDIRECTION_H__

#include "OSM/Internal.h"

namespace _NOSM
{

enum DrivingDirection
{
    POSITIVE,
    NEGATIVE,
    BOTH
};

static inline String GetDrivingDirectionString(DrivingDirection driving_direction)
{
    static String driving_directions[] =
    {
        "POSITIVE",
        "NEGATIVE",
        "BOTH"
    };

    return driving_directions[(int)driving_direction];
}

}

#endif // __OSM_DRIVINGDIRECTION_H__
