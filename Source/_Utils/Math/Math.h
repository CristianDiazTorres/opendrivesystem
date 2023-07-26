#pragma once

#include "Math/Main/XY.h"

namespace _NMath
{

template <typename BoundComponentType,
          typename BoundType,
          typename PointComponentType,
          typename PointTypeToClip,
          typename PointTypeToReturn>
class ClipperXY;

template <typename BoundComponentType,
          typename BoundType,
          typename PointComponentType,
          typename PointTypeToClip,
          typename PointTypeToReturn>
class ClipperLL;

// (xy3.x(), xy3.y()) <=> ((xy1.x(), xy1.y()), (xy2.x(), xy2.y()))
inline double calcDistance(const XY& xy1, const XY& xy2, const XY& xy3)
{
    double dx = xy2.x() - xy1.x();
    double dy = xy2.y() - xy1.y();
    double temp = (dx * dx) + (dy * dy);
    if (temp <= 0.000001)
        return xy1.calcDistance(xy3);

    double u = ((xy3.x() - xy1.x()) * dx + (xy3.y() - xy1.y()) * dy) / temp;

    if (u >= 1)
        return xy2.calcDistance(xy3);
    else if (u <= 0)
        return xy1.calcDistance(xy3);

    return xy3.calcDistance(XY(xy1.x() + u * dx, xy1.y() + u * dy));
}

// (xy3.x(), xy3.y()) <=> ((xy1.x(), xy1.y()), (xy2.x(), xy2.y()))
// 0 <= u <= 1
inline double calcDistance(const XY& xy1, const XY& xy2, const XY& xy3, double& u)
{
    double dx = xy2.x() - xy1.x();
    double dy = xy2.y() - xy1.y();
    double temp = (dx * dx) + (dy * dy);
    if (temp <= 0.000001)
    {
        u = 0;
        return xy1.calcDistance(xy3);
    }

    u = ((xy3.x() - xy1.x()) * dx + (xy3.y() - xy1.y()) * dy) / temp;

    if (u >= 1)
    {
        u = 1;
        return xy2.calcDistance(xy3);
    }
    else if (u <= 0)
    {
        u = 0;
        return xy1.calcDistance(xy3);
    }

    return xy3.calcDistance(XY(xy1.x() + u * dx, xy1.y() + u * dy));
}

// (xy3.x(), xy3.y()) <=> ((xy1.x(), xy1.y()), (xy2.x(), xy2.y()))
// 0 : on line, + : left, - : right
inline double getSideOnLine1(const XY& xy1, const XY& xy2, const XY& xy3)
{
    return (xy2.x() - xy1.x()) * (xy3.y() - xy1.y()) - (xy2.y() - xy1.y()) * (xy3.x() - xy1.x());
}

inline double getSideOnLine2(const XY& xy1, const XY& dxy, const XY& xy3)
{
    return dxy.x() * (xy3.y() - xy1.y()) - dxy.y() * (xy3.x() - xy1.x());
}

template <typename T1, typename T2>
inline double calcDistance(const T1& point, const QVector<T2>& points)
{
    double minDist = DOUBLE_MAX;
    for (int i = 1; i < points.size(); i ++)
    {
        double dist = calcDistance(points[i - 1], points[i], point);
        if (dist < minDist)
            minDist = dist;
    }
    return minDist;
}

template <typename T1, typename T2>
inline double calcDistance(const QVector<T1>& d1, const QVector<T2>& d2)
{
    double distance = 0;
    for (const T1& point : d1)
        distance += calcDistance(point, d2);

    for (const T2& point : d2)
        distance += calcDistance(point, d1);

    return distance / (d1.size() + d2.size());
}

template <typename T1, typename T2>
inline int getNearestIndex(const T1& pointOrPoints, const QVector<T2>& data, double& minDist)
{
    minDist = DOUBLE_MAX;
    int index = -1;
    for (int i = 0; i < data.size(); i ++)
    {
        double dist = data[i].calcDistance(pointOrPoints);
        if (dist < minDist)
        {
            minDist = dist;
            index = i;
        }
    }
    return index;
}

template <typename T1, typename T2, typename T3>
inline int getNearestIndex(const T1& pointOrPoints, const QVector<T2>& data, const T3& param, double& minDist)
{
    minDist = DOUBLE_MAX;
    int index = -1;
    for (int i = 0; i < data.size(); i ++)
    {
        double dist = data[i].calcDistance(pointOrPoints, param);
        if (dist < minDist)
        {
            minDist = dist;
            index = i;
        }
    }
    return index;
}

}
