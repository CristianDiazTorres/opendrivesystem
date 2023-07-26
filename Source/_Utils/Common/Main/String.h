#pragma once

#include "Common/Internal/Internal.h"

namespace _NCM
{

inline void parse2NumbersFromString(QString text, double& v1, double &v2)
{
    text = text.trimmed();
    int index = qMax(text.indexOf(' '), text.indexOf(','));
    QString v1Str = text.left(index).replace(',', "").replace(' ', "");
    QString v2Str = text.mid(index + 1).replace(',', "").replace(' ', "");
    v1 = v1Str.toDouble();
    v2 = v2Str.toDouble();
}

inline QString preProcessStringForPG(QString str)
{
    str.replace("'", "''");
    return str;
}

template <typename T>
inline QString toString(const T& value)
{
    return value.toString();
}

template <>
inline QString toString(const QString& value)
{
    return value;
}

inline QString toString(int value)
{
    return QString::number(value);
}

inline QString toString(qint64 value)
{
    return QString::number(value);
}

inline QString doubleToStringFullPrecision(double value)
{
    return QString::number(value, 'f', 10);
}

inline QString doubleToStringE16(double value)
{
    return QString::number(value, 'e', 16);
}

inline QString toString(double value)
{
    return doubleToStringE16(value);
}

template <typename T>
inline void setFromString(T& value, const QString& str)
{
    value = str;
}

template <>
inline void setFromString(int& value, const QString& str)
{
    value = str.toInt();
}

template <>
inline void setFromString(qint64& value, const QString& str)
{
    value = str.toLongLong();
}

template <>
inline void setFromString(double& value, const QString& str)
{
    value = str.toDouble();
}

inline void removeCharsAtEnd(QString& str, int count)
{
    if (str.size() >= count)
        str.truncate(str.size() - count);
}

inline void removeOneAtEnd(QString& str)
{
    if (str.size() > 0)
        str.truncate(str.size() - 1);
}

inline void replaceIfEmpty(QList<QString>& data, const QString& newElem)
{
    for (QString& elem : data)
        if (elem.isEmpty())
            elem = newElem;
}

inline void append(QList<QString>& data, const QString& newElem, int totalCount)
{
    for (int i = data.size(); i < totalCount; i ++)
        data << newElem;
}

inline void duplicateLast(QList<QString>& data, int totalCount)
{
    for (int i = data.size(); i < totalCount; i ++)
        data << data.last();
}

inline QString getJoined(const QList<QString>& data, const QString& delimiter)
{
    QString result;
    for (const QString& elem : data)
        result += elem + delimiter;

    removeCharsAtEnd(result, delimiter.size());
    return result;
}

inline QString getJoined(const QList<QString>& data)
{
    QString result;
    for (const QString& elem : data)
        result += elem + '|';

    removeOneAtEnd(result);
    return result;
}

inline QString getAppendedJoined(QList<QString>& data, const QString& newElem, int totalCount)
{
    append(data, newElem, totalCount);
    return getJoined(data);
}

inline QString getReplacedifEmptyAppendedJoined(QList<QString>& data, const QString& newElem, int totalCount)
{
    replaceIfEmpty(data, newElem);
    append(data, newElem, totalCount);
    return getJoined(data);
}

inline QString getDuplicatedLastJoined(QList<QString>& data, int totalCount)
{
    duplicateLast(data, totalCount);
    return getJoined(data);
}

inline QString getDuplicatedJoind(const QString& value, int count)
{
    if (count <= 0)
        return "";

    QString result = value;
    for (int i = 1; i < count; i ++)
        result += "|" + value;
    return result;
}

}
