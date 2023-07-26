#pragma once

#include "OSM/Internal/Internal.h"
#include "Network/Main/HttpRequest.h"
#include "OSM/TileImage/OSMTileImageParam.h"

namespace _NOSM
{

class OSMTileImageAPI : public HttpRequest
{
public:

//accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9
//accept-encoding: gzip, deflate, br
//accept-language: en,ko;q=0.9,zh-CN;q=0.8,zh;q=0.7
//sec-ch-ua: "Google Chrome";v="93", " Not;A Brand";v="99", "Chromium";v="93"
//sec-ch-ua-mobile: ?0
//vsec-ch-ua-platform: "Windows"
//sec-fetch-dest: document
//sec-fetch-mode: navigate
//sec-fetch-site: none
//sec-fetch-user: ?1
//upgrade-insecure-requests: 1
//user-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/93.0.4577.82 Safari/537.36

    static inline void getResponse(QNetworkAccessManager& networkAccessManager, const OSMTileImageParam& param, QObject* receiver, const char* slot)
    {
        static int index = 0;
        index ++;
        index = index % 3;
        getGetResponse(networkAccessManager
                       , receiver
                       , slot
                       , QString().sprintf("https://%c.tile.openstreetmap.org/%d/%d/%d.png"
                                           , (char)('a' + index), param.zoom, param.col, param.row));
    }

};

}

