#pragma once

#include "Math/Internal/Internal.h"
#include "Common/Main/String.h"
#include "UniversialType/Main/UniversialType.h"

namespace _NMath
{

struct XY : public QPointF
{
public:
    XY(){}

    XY(double x, double y)
        : QPointF(x, y)
    {}

    XY(const QPointF& other)
        : QPointF(other)
    {}

    inline XY& operator=(const QPointF& other)
    {
        (QPointF&)(*this) = other;
        return *this;
    }

public:
    XmlStatus read(const XmlElement& node)
    {
        XmlStatus status = XmlElement::SUCCEEDED;

        _UNIVERSIAL_TYPE_ATTRIBUTE_READ_REQUIRED1(x, rx());
        _UNIVERSIAL_TYPE_ATTRIBUTE_READ_REQUIRED1(y, ry());

        return status;
    }

    void write(XmlStreamWriter& xmlWriter, bool forceToWriteOptionalValues = false)
    {
        Q_UNUSED(forceToWriteOptionalValues);

        _UNIVERSIAL_TYPE_ATTRIBUTE_WRITE_REQUIRED1(x, x());
        _UNIVERSIAL_TYPE_ATTRIBUTE_WRITE_REQUIRED1(y, y());
    }

    void read(QJsonObject obj)
    {
        _UNIVERSIAL_TYPE_ATTRIBUTE_JSON_READ_REQUIRED1(x, rx());
        _UNIVERSIAL_TYPE_ATTRIBUTE_JSON_READ_REQUIRED1(y, ry());
    }

    void write(QJsonObject& obj, bool forceToWriteOptionalValues = false)
    {
        Q_UNUSED(forceToWriteOptionalValues);

        _UNIVERSIAL_TYPE_ATTRIBUTE_JSON_WRITE_REQUIRED1(x, x());
        _UNIVERSIAL_TYPE_ATTRIBUTE_JSON_WRITE_REQUIRED1(y, y());
    }

    void setTestData()
    {
        rx() = 1;
        ry() = 2;
    }

    void AddToGeoJsonTemplateData(QJsonArray& features, QJsonObject geomObject, QString tagName)
    {
        Q_UNUSED(features);
        Q_UNUSED(geomObject);
        Q_UNUSED(tagName);
    }

    void saveGeoJsonTemplateData(QString path, QJsonObject geomObject)
    {
        Q_UNUSED(path);
        Q_UNUSED(geomObject);
    }

public:
    inline double calcDistance(const XY& other) const
    {
        double dx = x() - other.x();
        double dy = y() - other.y();
        return sqrt(dx * dx + dy * dy);
    }

public:
    inline void parseString(QString text)
    {
        _NCM::parse2NumbersFromString(text, rx(), ry());
    }
};

typedef QVector<XY>      XYVec;
typedef QVector<XYVec>   XYVecVec;

template <typename T>
inline double calcLengthOfVector(const QVector<T>& data)
{
    double len = 0;
    for (int i = 1; i < data.size(); i ++)
        len += data[i].calcDistance(data[i - 1]);
    return len;
}

template <typename T>
inline QRectF calcBoundInXY(const QVector<T>& points)
{
    double left, top, right, bottom;
    left = right = points.first().x();
    top = bottom = points.first().y();
    for (int i = 1; i < points.size(); i ++)
    {
        const XY& pt = points[i];
        if (pt.x() < left)
            left = pt.x();
        else if (pt.x() > right)
            right = pt.x();

        if (pt.y() < top)
            top = pt.y();
        else if (pt.y() > bottom)
            bottom = pt.y();
    }

    return QRectF(left, top, right - left, bottom - top);
}

}
