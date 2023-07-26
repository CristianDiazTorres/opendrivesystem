#pragma once

#include "OSM/Internal/Internal.h"
#include "Thread/Main/Thread.h"
#include "OSM/TileImage/OSMTileImageParam.h"
#include <QMutex>
#include "Common/Main/Cacher.h"
#include <QImage>
#include <QtNetwork/QNetworkAccessManager>

namespace _NOSM
{

class OSMTileImageDownloader : public Thread
{
    Q_OBJECT
    _NCM_DEFAULT_INSTANCE_THREAD_DECLARE(OSMTileImageDownloader, *, )

protected:
    _NCM::Cacher<OSMTileImageParam, QByteArray> tileImgs;
    QNetworkAccessManager networkAccessManager;
    int requestCountInRunning;

public:
    OSMTileImageDownloader();

public:
    bool getTileImage(const OSMTileImageParam &tileImgParam, QByteArray& tileImg);

signals:
    void sendTileImageRequest(_NOSM::OSMTileImageParam tileImgParam);
    void tileImageDownloaded(_NOSM::OSMTileImageParam tileImgParam);

public slots:
    void onSendTileImageRequest(_NOSM::OSMTileImageParam tileImgParam);
    void onTileImageDownloaded();

public:
    virtual void stopThread();

protected:
    virtual void run();

};

#define OSMTileImageDownloader_createDefaultInstance                _NOSM::OSMTileImageDownloader::createDefaultInstance()
#define OSMTileImageDownloader_getDefaultInstance                   _NOSM::OSMTileImageDownloader::getDefaultInstance()
#define OSMTileImageDownloader_deleteDefaultInstance                _NOSM::OSMTileImageDownloader::deleteDefaultInstance()
#define OSMTileImageDownloader_isDefaultInstanceAlive               _NOSM::OSMTileImageDownloader::isDefaultInstanceAlive()
#define OSMTileImageDownloader_stopDefaultInstanceThreadIfAlive     _NOSM::OSMTileImageDownloader::stopDefaultInstanceThreadIfAlive()

}

