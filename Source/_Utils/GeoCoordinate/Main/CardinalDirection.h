#pragma once

#include "GeoCoordinate/Internal/Internal.h"

namespace _NGC
{

enum CardinalDirection
{
    North = 0,
    South,
    East,
    West,
    NorthEast,
    NorthWest,
    SouthEast,
    SouthWest,
    DirectionCount
};

inline QString toString(CardinalDirection direction)
{
    static QString strs[] = {
        "North",
        "South",
        "East",
        "West",
        "NorthEast",
        "NorthWest",
        "SouthEast",
        "SouthWest"
    };
    return strs[(int)direction];
}

}
