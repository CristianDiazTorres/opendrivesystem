#pragma once

#include "OSM/Internal/Internal.h"
#include "Network/Main/HttpRequest.h"

namespace _NOSM
{

class PolygonAPI : public HttpRequest
{
public:

    /*
        https://polygons.openstreetmap.fr/get_wkt.py?id=80500&params=0
        SRID=4326;MULTIPOLYGON((
    */

    static inline QString getResponse(const QString& osmId)
    {
        const QString& response = QString::fromUtf8(getGetResponse("https://polygons.openstreetmap.fr/get_wkt.py", "id=" + osmId + "&params=0")).trimmed();
        if (!response.startsWith("SRID"))
            return response;

        int index = response.indexOf(';');
        return response.mid(index + 1).trimmed();
    }
};

}

