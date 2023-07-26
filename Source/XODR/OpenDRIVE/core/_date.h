#pragma once

#include "XODR/OpenDRIVE/internal/_internal.h"
#include <QDateTime>

namespace _NOD
{
struct _date: public QDateTime
{
public:
    static const _date DEFAULT_VALUE;
    static const _date INVALID_VALUE;

public:
    _date()
    {
        //*this = DEFAULT_VALUE;
    }

    _date(const QDateTime& other)
        : QDateTime(other)
    {
    }

    _date(const _date& other)
        : QDateTime(other)
    {
    }

    _date(const string& str)
        : QDateTime(QDateTime::fromString(str, Qt::ISODate).toUTC()) // ISO 8601
    {
    }

public:
    string toString() const
    {
        return QDateTime::toString(Qt::ISODate); // ISO 8601
        //return QDateTime::toString("yyyy-MM-ddThh:mm:ss");
        //return QDateTime::toString("ddd MMM d hh:mm:ss yyyy");
    }

    _date& operator=(const QDateTime& other)
    {
        (QDateTime&)(*this) = other;
        return *this;
    }

    _date& operator=(const _date& other)
    {
        (QDateTime&)(*this) = (QDateTime&)other;
        return *this;
    }

    _date& operator=(const string& str)
    {
        (QDateTime&)(*this) = QDateTime::fromString(str, Qt::ISODate).toUTC();
        return *this;
    }

    //operator string() const
    //{
    //    return toString();
    //}

    bool isEmpty() const
    {
        return isNull();
    }
};
}
