#include "OSM/Way/Way.h"
#include "Common/Main/JsonArray.h"
#include "Debugger/Main/Logger.h"

namespace _NOSM
{

void Way::parseFromOSMJson(QJsonObject obj)
{
    osm[_SC_id] = QString::number((qint64)obj[_SC_id].toDouble());

    QJsonObject tags = obj[_SC_tags].toObject();

    QJsonObject::iterator iter = tags.begin();
    for (; iter != tags.end(); iter ++)
        osm[iter.key().trimmed()] = iter.value().toString().trimmed();

    // Confirm country name
    osm[_SC_addr_country_A] = osm[_SC_addr_country_A].toUpper();

    parseLaneCount1();
    parseJunction();
    parseOneway();
    parseLanesWidth();
    parseLaneCount2();
    parseRoadMark();
}

QJsonObject Way::toJsonObject() const
{
    QJsonObject obj;

    StringMap::ConstIterator iter = osm.constBegin();
    for (; iter != osm.constEnd(); iter ++)
        obj[iter.key()] = iter.value();

    obj[_SC_center_coord] = this->center_coord.toJsonArray();

    obj[_SC_chord_coords] = _NCM::toJsonArrayOfArray(this->chord_coords_sequence);
    obj[_SC_gps_coords] = _NCM::toJsonArrayOfArray(this->gps_coords_sequence);
    obj[_SC_updated_coords] = _NCM::toJsonArrayOfArray(this->updated_coords_sequence);

    return obj;
}

void Way::calcUpdatedCoord()
{
    DefaultLogger_File << "chord_coords.size(): " << chord_coords_sequence.size();
    DefaultLogger_File << "gps_coords.size(): " << gps_coords_sequence.size();

    double d1 = chord_coords_sequence.first().calcDistance(gps_coords_sequence.first()) +
            chord_coords_sequence.last().calcDistance(gps_coords_sequence.last());

    double d2 = chord_coords_sequence.first().calcDistance(gps_coords_sequence.last()) +
            chord_coords_sequence.last().calcDistance(gps_coords_sequence.first());

    if (d1 <= d2)
    {
        updated_coords_sequence << chord_coords_sequence.first();
        updated_coords_sequence.append(gps_coords_sequence);
        updated_coords_sequence << chord_coords_sequence.last();
    }
    else
    {
        updated_coords_sequence << chord_coords_sequence.first();
        for (int i = gps_coords_sequence.size() - 1; i >= 0; i --)
            updated_coords_sequence << gps_coords_sequence[i];
        updated_coords_sequence << chord_coords_sequence.last();
    }
}

}
