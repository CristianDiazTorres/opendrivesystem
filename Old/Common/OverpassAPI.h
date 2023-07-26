#ifndef __COMMON_OVERPASSAPI_H__
#define __COMMON_OVERPASSAPI_H__

#include "Common/LatLon.h"
#include "Common/VehiclePos.h"
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QEventLoop>

namespace Common
{

	class OverpassAPI
	{
	public:
        static inline QByteArray GetResponse(QString query)
		{
            //qDebug() << query;

            QNetworkRequest request(QUrl("https://www.overpass-api.de/api/interpreter"));
            request.setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(query.size()));
            request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

            QEventLoop waitLoop;
            QNetworkAccessManager connection;
            QNetworkReply* reply = connection.post(request, query.toUtf8());
            QObject::connect(reply, SIGNAL(finished()), &waitLoop, SLOT(quit()));
            waitLoop.exec();

            int net_ret_code = (*reply).error();

            QByteArray result;
            if (net_ret_code == 0)
            {
                result = (*reply).readAll();
                //qDebug () << result;
            }
            else
            {
                qDebug() << "Network return code : " << net_ret_code;
            }

            delete reply;

            return result;
		}

        static inline QJsonValue GetWayData(LatLon coord)
		{
            QString query = "[out:json];way(around:15,"
                    + QString::number(coord.lat, 'f', 10) + "," + QString::number(coord.lon, 'f', 10)
                    + ");out tags geom;";

            QByteArray data = GetResponse(query);

			//MyCout << data;

            QJsonDocument doc = QJsonDocument::fromJson(data);

            return doc.object()["elements"];
		}

        static inline QJsonValue GetWayData(ConstLatLonVec& coords)
		{
			QString query = "[out:json];way(around:10";
			for (int i = 0; i < coords.size(); i++)
			{
				ConstLatLon& coord = coords[i];
                query += "," + QString::number(coord.lat, 'f', 10) + "," + QString::number(coord.lon, 'f', 10);
			}
			query += ");out tags geom;";

            QByteArray data = GetResponse(query);

            //MyCout << data;

            QJsonDocument doc = QJsonDocument::fromJson(data);

            return doc.object()["elements"];
		}

#define NODE_AROUND_WAY_TAG_COUNT	7

        static inline QJsonValue GetNodesData(ConstVehiclePosVec& coords)
		{
			QString tags[NODE_AROUND_WAY_TAG_COUNT] =
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

            QString filter = "(around:1000";
			for (int i = 0; i < coords.size(); i++)
                filter += "," + QString::number(coords[i].coord.lat, 'f', 10) + "," + QString::number(coords[i].coord.lon, 'f', 10);
			filter += ");";

			QString query = "[out:json];(";
			for (int i = 0; i < NODE_AROUND_WAY_TAG_COUNT; i++)
				query += "node[" + tags[i] + "]" + filter;
			query += ");out tags geom;";

			//MyCout << query << MyEndl;

			try
			{
                QByteArray data = GetResponse(query);

                //MyCout << data;

                QJsonDocument doc = QJsonDocument::fromJson(data);

                return doc.object()["elements"];

			}
			catch (ConstMyException & e)
			{
				MyCout << e.what() << MyEndl;
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
		static inline QString GetCountryName(LatLon coord)
		{
			try
			{
                QString query = "[out:csv(\"ISO3166-1\")];is_in("
                        + QString::number(coord.lat, 'f', 10) + "," + QString::number(coord.lon, 'f', 10)
                        + ");area._[admin_level=\"2\"];out;";

                QString data = QString::fromUtf8(GetResponse(query));

                //MyCout << data;

				// get second line(ignore first line and third line)
                int start = data.indexOf('\n');
                int end = data.indexOf('\n', start + 1);

                return data.mid(start + 1, end - start - 1);
			}
			catch (ConstMyException&)
			{
				return "";
			}
		}
	};

}

#endif // __COMMON_OVERPASSAPI_H__
