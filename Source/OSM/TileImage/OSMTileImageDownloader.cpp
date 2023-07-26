#include "OSM/TileImage/OSMTileImageDownloader.h"
#include "OSM/TileImage/OSMTileImageAPI.h"

namespace _NOSM
{

OSMTileImageDownloader* OSMTileImageDownloader::defaultInstance = 0;

OSMTileImageDownloader::OSMTileImageDownloader()
{
    moveToThread(this);
    networkAccessManager.moveToThread(this);
    requestCountInRunning = 0;
}

bool OSMTileImageDownloader::getTileImage(const OSMTileImageParam &tileImgParam, QByteArray &tileImg)
{
    if (tileImgs.exists(tileImgParam))
    {
        tileImg = tileImgs.getContent(tileImgParam);
        return !tileImg.isNull();
    }

    if (requestCountInRunning > 10)
        return false;

    requestCountInRunning ++;
    tileImgs.update(tileImgParam, QByteArray());
    emit sendTileImageRequest(tileImgParam);
    return false;
}

void OSMTileImageDownloader::onSendTileImageRequest(_NOSM::OSMTileImageParam tileImgParam)
{
    OSMTileImageAPI::getResponse(networkAccessManager, tileImgParam, this, SLOT(onTileImageDownloaded()));
}

void OSMTileImageDownloader::onTileImageDownloaded()
{
    requestCountInRunning --;

    QNetworkReply* reply = (QNetworkReply*)sender();
    if (reply->error() != 0)
    {
        qDebug() << "Network return code : " << reply->error() << " , " << reply->url().toString();

        reply->deleteLater();
        return;
    }

    QString url = reply->url().toString();
    _NCM::removeCharsAtEnd(url, 4);
    QVector<QString> elems = url.split('/').toVector();

    OSMTileImageParam tileImgParam(elems[elems.size() - 3].toInt()
            , elems[elems.size() - 1].toInt()
            , elems[elems.size() - 2].toInt());

    QByteArray tileData = reply->readAll();
    /*
    QImage tileImg;
    tileImg.loadFromData(tileData);
    */
    tileImgs.update(tileImgParam, tileData);

    reply->deleteLater();

    emit tileImageDownloaded(tileImgParam);
}

void OSMTileImageDownloader::stopThread()
{
    QThread::quit();
    Thread::stopThread();
}

void OSMTileImageDownloader::run()
{
    connect(this, SIGNAL(sendTileImageRequest(_NOSM::OSMTileImageParam)), this, SLOT(onSendTileImageRequest(_NOSM::OSMTileImageParam)));
    QThread::run(); // Will call exec() to enter event loop
}

}

