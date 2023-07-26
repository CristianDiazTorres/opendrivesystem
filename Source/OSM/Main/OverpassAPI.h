#pragma once

#include "OSM/Internal/Internal.h"
#include "Network/Main/HttpRequest.h"
#include "Common/Main/StringContants.h"
#include "GeoCoordinate/Main/LL.h"

namespace _NOSM
{

class OverpassAPI : public HttpRequest
{
public:
    static inline QJsonValue getResponseAsJson(const QString& query)
    {
        return HttpRequest::getResponseAsJson(getResponse(query))[_SC_elements];
    }

    static inline QByteArray getResponse(const QString& query)
    {
        return getPostResponse("https://www.overpass-api.de/api/interpreter", "application/x-www-form-urlencoded", query);
    }

    static inline QString getQuery(const LLVec& coords, double bufferDistance)
    {
        QString query = _NCM::doubleToStringFullPrecision(bufferDistance);
        for (int i = 0; i < coords.size(); i++)
        {
            const LL& coord = coords[i];
            query += "," + _NCM::doubleToStringFullPrecision(coord.lat) + "," + _NCM::doubleToStringFullPrecision(coord.lon);
        }
        query += ");";

        return query;
    }

    static inline QString getQuery(double lat, double lon, double bufferDistance)
    {
        QString query = _NCM::doubleToStringFullPrecision(bufferDistance);
        query += "," + _NCM::doubleToStringFullPrecision(lat) + "," + _NCM::doubleToStringFullPrecision(lon);
        query += ");";

        return query;
    }

    static inline QJsonValue getWaysData(const LLVec& coords)
    {
        return getResponseAsJson("[out:json];way(around:" + getQuery(coords, 10) + "out ids tags geom;");
    }

    static inline QJsonValue getWaysData(double lat, double lon, double bufferDistance)
    {
        return getResponseAsJson("[out:json];way(around:" + getQuery(lat, lon, bufferDistance) + "out ids tags geom;");
    }

    static inline QJsonValue getNodesData(double lat, double lon, double bufferDistance)
    {
        return getResponseAsJson("[out:json];node(around:" + getQuery(lat, lon, bufferDistance) + "out ids tags geom;");
    }

    /*
        [out:json];
        relation["boundary"="administrative"]["admin_level"="2"][type!=multilinestring];
        out ids tags geom;

        https://stackoverflow.com/questions/41723087/get-administrative-borders-with-overpass-ql/41760485

        rel["ISO3166-2"~"^FR"]
           [admin_level=4]
           [type=boundary]
           [boundary=administrative];
        out body geom;
    */

    static QJsonValue getCountryAreaData();

    /**
     * Get country name of given location.
     *
     * @param coord location.
     * @return country name.
     *
     * @exceptsafe This function does not throw exceptions.
     */
    static inline QString getCountryName(LL coord)
    {
        try
        {
            QString query = "[out:csv(\"ISO3166-1\")];is_in("
                    + _NCM::doubleToStringFullPrecision(coord.lat) + "," + _NCM::doubleToStringFullPrecision(coord.lon)
                    + ");area._[admin_level=\"2\"];out;";

            QString data = QString::fromUtf8(getResponse(query));

            //DefaultLogger << data;

            // get second line(ignore first line and third line)
            int start = data.indexOf('\n');
            int end = data.indexOf('\n', start + 1);

            return data.mid(start + 1, end - start - 1).toUpper();
        }
        catch (const std::exception&)
        {
            return "";
        }
    }
};

}

