#ifndef __COMMON_LATLON_H__
#define __COMMON_LATLON_H__

#include "Common/Common.h"

namespace Common
{

	struct LatLon
	{
        double lat; // In degrees
        double lon; // In degrees

	public:
		LatLon()
		{
		}

		LatLon(double lat, double lon)
		{
			this->lat = lat;
			this->lon = lon;
		}

        LatLon(const QJsonValue& json)
		{
            this->lat = json.toObject()["lat"].toDouble();
            this->lon = json.toObject()["lon"].toDouble();
		}

        inline QJsonArray ToQJsonArray() const
		{
			QJsonArray arr;
            arr.push_back(this->lat);
            arr.push_back(this->lon);
            return arr;
		}

        inline QJsonObject ToQJsonObject() const
		{
			QJsonObject obj;
            obj["lat"] = this->lat;
            obj["lon"] = this->lon;
            return obj;
		}

        inline operator QJsonArray() const
        {
            return ToQJsonArray();
        }

        inline operator QJsonObject() const
        {
            return ToQJsonObject();
        }
	};

	typedef CONST LatLon		ConstLatLon;
    typedef QVector<LatLon>     LatLonVec;
	typedef CONST LatLonVec		ConstLatLonVec;
	typedef QVector<LatLonVec>	LatLonVecVec;
	typedef CONST LatLonVecVec	ConstLatLonVecVec;

}

#endif // __COMMON_LATLON_H__
