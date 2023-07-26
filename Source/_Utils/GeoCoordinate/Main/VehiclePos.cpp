#include "GeoCoordinate/Main/VehiclePos.h"
#include <QDateTime>

namespace _NGC
{
void VehiclePos::updateDerivedProps()
{
    if (!this->date.isEmpty() && !this->time.isEmpty())
    {
        QString dateTimeStr;
        if (this->date.count("/") == 2)
        {
            StringVec ymd = this->date.split("/").toVector();
            dateTimeStr = ymd[2] + "-" + ymd[0] + "-" + ymd[1];
        }
        else
        {
            dateTimeStr = this->date;
        }

        dateTimeStr += "T";
        if (this->time.count(":") == 1)
            dateTimeStr += "00:";
        dateTimeStr += this->time;
        //qDebug() << dateTimeStr;
        //qDebug() << QDateTime::fromString(dateTimeStr, Qt::ISODateWithMs).toUTC().toString();
        this->timeSeconds = QDateTime::fromString(dateTimeStr, Qt::ISODateWithMs).toUTC().toMSecsSinceEpoch() / 1000.0;
        //qDebug() << this->timeSeconds;
    }

    // Degrees to meters

    this->vx = this->sog * cos(this->heading); // heading : In radians
    this->vy = this->sog * sin(this->heading); // heading : In radians

    updateAllFromLL();
}

void VehiclePos::setFromPredictedPos(const VehiclePos& pos, const XY& xy, double vx, double vy)
{
    *this = pos;

    setFromXY(xy, pos);

    this->sog = sqrt(vx * vx + vy * vy);
    this->heading = atan2(vy, vx); // heading : In radians
    this->vx = vx;
    this->vy = vy;
}

void VehiclePos::setFromIntersectedPos(const VehiclePos& pos, const LL& ll, double vx, double vy)
{
    *this = pos;

    setFromLL(ll);

    this->sog = sqrt(vx * vx + vy * vy);
    this->heading = atan2(vy, vx); // heading : In radians
    this->vx = vx;
    this->vy = vy;
}

void VehiclePos::setFrom2Poses_Prev(const VehiclePos& prev, const VehiclePos& next, LL ll)
{
    // TODO: may incorrect ???
    if (next.lat > prev.lat)
        ll.lat -= DOUBLE_EPSILON2;
    else if (next.lat < prev.lat)
        ll.lat += DOUBLE_EPSILON2;

    if (next.lon > prev.lon)
        ll.lon -= DOUBLE_EPSILON2;
    else if (next.lon < prev.lon)
        ll.lon += DOUBLE_EPSILON2;

    setFromIntersectedPos(prev, ll, prev.vx, prev.vy);
}

void VehiclePos::setFrom2Poses_Next(const VehiclePos& prev, const VehiclePos& next, LL ll)
{
    // TODO: may incorrect ???
    if (next.lat > prev.lat)
        ll.lat += DOUBLE_EPSILON2;
    else if (next.lat < prev.lat)
        ll.lat -= DOUBLE_EPSILON2;

    if (next.lon > prev.lon)
        ll.lon += DOUBLE_EPSILON2;
    else if (next.lon < prev.lon)
        ll.lon -= DOUBLE_EPSILON2;

    setFromIntersectedPos(next, ll, next.vx, next.vy);
}

}
