#pragma once

#include "Common/Internal/Internal.h"

namespace _NCM
{

template <typename T>
using QVector01 = QVector<T>; // 0..1

template <typename T>
using QVector0x = QVector<T>; // 0..*

template <typename T>
using QVector1x = QVector<T>; // 1..*

template <typename T>
using QVector2x = QVector<T>; // 2..*

template <typename DT, typename ST>
inline QVector<DT> convertVectorElementType(const QVector<ST>& src)
{
    QVector<DT> result(src.size());
    for (int i = 0; i < src.size(); i++)
        result[i] = src[i];
    return result;
}

template <typename DT, typename ST>
inline void appendForce(QVector<DT>& dest, QVector<ST>& src)
{
    for (const ST& elem : src)
        dest << (const DT&)elem;
}

}
