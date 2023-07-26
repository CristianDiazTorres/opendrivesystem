#pragma once

#include "Common/Internal/Internal.h"
#include <QJsonArray>

namespace _NCM
{

template <typename T>
inline QJsonArray toJsonArrayOfObject(const QVector<T>& data)
{
    QJsonArray result;
    for (const T& elem : data)
        result.append((QJsonObject)elem);
    return result;
}

template <typename T>
inline QJsonArray toJsonArrayOfArray(const QVector<T>& data)
{
    QJsonArray result;
    for (const T& elem : data)
        result.append((QJsonArray)elem);
    return result;
}

}
