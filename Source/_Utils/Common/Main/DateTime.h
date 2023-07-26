#pragma once

#include <QDateTime>

namespace _NCM
{

inline QString convertToPGTimeStampWithTimeZone(const QDateTime& dateTime)
{
    QString result = dateTime.toString("yyyy-MM-dd HH:mm:ss.z");

    int offset = dateTime.offsetFromUtc();
    result += (offset > 0 ? "+" : "-");

    int hour = abs(offset) / 3600;
    result += QString().sprintf("%02d", hour);

    int min = (abs(offset) - hour * 3600) / 60;
    if (min != 0)
        result += QString().sprintf(":%02d", min);

    return result;
}

inline QString getCurrentDateTimeAsPGTimeStampWithTimeZone()
{
    return convertToPGTimeStampWithTimeZone(QDateTime::currentDateTime());
}

}
