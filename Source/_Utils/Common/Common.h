#pragma once

#include "Common/Internal/Internal.h"

namespace _NCM
{

template <typename T>
inline bool isEmpty(const T& value)
{
    return value.isEmpty();
}

inline bool isEmpty(qint64 value)
{
    return value == INTEGER_INVALID_VALUE;
}

inline bool isEmpty(double value)
{
    return value == DOUBLE_INVALID_VALUE;
}

}
