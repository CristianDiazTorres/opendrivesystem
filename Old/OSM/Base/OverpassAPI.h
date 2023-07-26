#ifndef __COMMON_OVERPASSAPI_H__
#define __COMMON_OVERPASSAPI_H__

#include "OSM/Internal.h"
#include "GeoCoordinate/LL.h"
#include "GeoCoordinate/VehiclePos.h"
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QEventLoop>

namespace _NOSM
{

class OverpassAPI
{
public:
    static inline ByteArray GetResponse(String query)
    {
        //Debug << query;

        QNetworkRequest request(QUrl("https://www.overpass-api.de/api/interpreter"));
        request.setHeader(QNetworkRequest::ContentLengthHeader, ByteArray::number(query.size()));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

        QEventLoop waitLoop;
        QNetworkAccessManager connection;
        QNetworkReply* reply = connection.post(request, query.toUtf8());
        QObject::connect(reply, SIGNAL(finished()), &waitLoop, SLOT(quit()));
        waitLoop.exec();

        int net_ret_code = (*reply).error();

        ByteArray result;
        if (net_ret_code == 0)
        {
            result = (*reply).readAll();
            //qDebug () << result;
        }
        else
        {
            Debug << "Network return code : " << net_ret_code;
        }

        delete reply;

        return result;
    }

    static inline JsonValue GetWayData(const LLVec& coords)
    {
        String query = "[out:json];way(around:10";
        for (int i = 0; i < coords.size(); i++)
        {
            const LL& coord = coords[i];
            query += "," + String::number(coord.lat, 'f', 10) + "," + String::number(coord.lon, 'f', 10);
        }
        query += ");out tags geom;";

        ByteArray data = GetResponse(query);

        //Debug << data;

        JsonDocument doc = JsonDocument::fromJson(data);

        return doc.object()["elements"];
    }

#define NODE_AROUND_WAY_TAG_COUNT	7

    static inline JsonValue GetNodesData(double lat, double lon, double areaSize)
    {
        String tags[NODE_AROUND_WAY_TAG_COUNT] =
        {
            //"highway",
            "barrier",
            //"traffic_calming",
            //"restriction",
            //"bus",
            "railway",
            //"motorway",
            //"bicycle",
            "foot",
            "footway",
            "parking",
            "crossing",
            //"amenity=bus_station",
            "route",
            //"public_transport"
        };

        String filter = "(around:" + String::number(areaSize);
        filter += "," + String::number(lat, 'f', 10) + "," + String::number(lon, 'f', 10);
        filter += ");";

        String query = "[out:json];(";
        for (int i = 0; i < NODE_AROUND_WAY_TAG_COUNT; i++)
            query += "node[" + tags[i] + "]" + filter;
        query += ");out tags geom;";

        //Debug << query << ENDL;

        try
        {
            ByteArray data = GetResponse(query);

            //Debug << data;

            JsonDocument doc = JsonDocument::fromJson(data);

            return doc.object()["elements"];

        }
        catch (const Exception & e)
        {
            Debug << e.what() << ENDL;
            return 0;
        }
    }

    /**
         * Get country name of given location.
         *
         * @param coord location.
         * @return country name.
         *
         * @exceptsafe This function does not throw exceptions.
         */
    static inline String GetCountryName(LL coord)
    {
        try
        {
            String query = "[out:csv(\"ISO3166-1\")];is_in("
                    + String::number(coord.lat, 'f', 10) + "," + String::number(coord.lon, 'f', 10)
                    + ");area._[admin_level=\"2\"];out;";

            String data = String::fromUtf8(GetResponse(query));

            //Debug << data;

            // get second line(ignore first line and third line)
            int start = data.indexOf('\n');
            int end = data.indexOf('\n', start + 1);

            return data.mid(start + 1, end - start - 1);
        }
        catch (const Exception&)
        {
            return "";
        }
    }
};

}

#endif // __COMMON_OVERPASSAPI_H__
