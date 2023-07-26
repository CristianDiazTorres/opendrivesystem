#pragma once

#include "XML/XML.h"
#include "UniversialType/UniversialType.h"

#include <math.h>

#define PI                      3.1415926535897932384626433832795

#define RADIAN_IN_DEGREE		0.01745329251994329576923690768489
#define DEGREE_IN_RADIAN		57.295779513082320876798154814105

#define DEG_TO_RAD(x)           ((x) * RADIAN_IN_DEGREE)
#define RAD_TO_DEG(x)           ((x) * DEGREE_IN_RADIAN)

#define CLAMP(x, min, max)      if (x < min) x = min; else if (x > max) x = max;

using namespace _NXML;
using namespace _NUniversialType;

namespace _NMath
{

}
