#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

void OSMToOpenDRIVE::convertRoadTypeSpeed(DatabaseConnector& database_connector, const _NOSM::Way& osmWay, _NOD::t_road_type& od_road_type)
{
    Q_UNUSED(database_connector);

    _NOD::t_road_type_speed odRoadTypeSpeed;

    if (!osmWay.osm.contains(_SC_maxspeed) && !osmWay.osm.contains(_SC_maxspeed_lanes_A))
    {
        odRoadTypeSpeed.max = _NOD::e_maxSpeedString::UNDEFINED;
        od_road_type.speed_sequence << odRoadTypeSpeed;
        return;
    }

    StringVec maxspeeds;

    QList<QString> lanesMaxSpeeds = osmWay.getSplit(_SC_maxspeed);
    lanesMaxSpeeds.append(osmWay.getSplit(_SC_maxspeed_lanes_A));

    for (const QString& maxspeed : lanesMaxSpeeds)
        maxspeeds.append(maxspeed.split(';').toVector());

    for (QString& maxspeed : maxspeeds)
        maxspeed = maxspeed.trimmed();

    if (maxspeeds.contains(_SC_no) ||
        maxspeeds.contains(_SC_none) ||
        maxspeeds.contains("-1"))
    {
        odRoadTypeSpeed.max = _NOD::e_maxSpeedString::NO_LIMIT;
        od_road_type.speed_sequence << odRoadTypeSpeed;
        return;
    }

    double maxSpeedKmh = 0;
    double maxSpeedNumber = 0;
    _NOD::e_unitSpeed maxSpeedUnit;

    for (QString& maxspeed : maxspeeds)
    {
        int startIndexOfNum;
        for (startIndexOfNum = 0; startIndexOfNum < maxspeed.size(); startIndexOfNum ++)
        {
            if (maxspeed[startIndexOfNum].isNumber() || maxspeed[startIndexOfNum] == '.')
                break;
        }

        if (startIndexOfNum >= maxspeed.size())
            continue;

        int endIndexOfNum;
        for (endIndexOfNum = startIndexOfNum + 1; endIndexOfNum < maxspeed.size(); endIndexOfNum ++)
        {
            if (!maxspeed[endIndexOfNum].isNumber() && maxspeed[endIndexOfNum] != '.')
                break;
        }

        double speedKmh;
        double speedNumber = maxspeed.mid(startIndexOfNum, endIndexOfNum - startIndexOfNum).toDouble();

        _NOD::e_unitSpeed speedUnit;
        if (maxspeed.indexOf(_SC_mph, endIndexOfNum) > 0)
        {
            speedKmh = speedNumber * 1.60934; // knot : 1.852 km/h
            speedUnit = _NOD::e_unitSpeed::MPH;
        }
        else
        {
            speedKmh = speedNumber;
            speedUnit = _NOD::e_unitSpeed::KM_H;

            // OSM has kph (km/h)
            // OSM has no m/s
            // OSM has knots and kt, these would be ignored
        }

        if (speedKmh > maxSpeedKmh)
        {
            maxSpeedKmh = speedKmh;
            maxSpeedNumber = speedNumber;
            maxSpeedUnit = speedUnit;
        }
    }

    if (maxSpeedKmh <= 0)
    {
        odRoadTypeSpeed.max = _NOD::e_maxSpeedString::UNDEFINED;
        od_road_type.speed_sequence << odRoadTypeSpeed;
        return;
    }

    odRoadTypeSpeed.max = maxSpeedNumber;
    odRoadTypeSpeed.unit = maxSpeedUnit;
    od_road_type.speed_sequence << odRoadTypeSpeed;
}

}
