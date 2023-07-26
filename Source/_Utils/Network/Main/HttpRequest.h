#pragma once

#include "Network/Internal/Internal.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include "Debugger/Main/Logger.h"

namespace _NNetwork
{

class HttpRequest
{
public:
    static inline QJsonObject getPostResponseAsJson(const QString& url, const QString& requestContentTypeHeader, const QString& postData)
    {
        return getResponseAsJson(getPostResponse(url, requestContentTypeHeader, postData));
    }

    static inline QByteArray getPostResponse(const QString& url, const QString& requestContentTypeHeader, const QString& postData)
    {
        return getPostResponse(url, requestContentTypeHeader, postData.toUtf8());
    }

    static inline QByteArray getPostResponse(const QString& url, const QString& requestContentTypeHeader, const QByteArray& postData)
    {
        DefaultLogger << url;
        DefaultLogger << postData;

        QNetworkRequest request;
        request.setUrl(url);
        request.setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(postData.size()));
        request.setHeader(QNetworkRequest::ContentTypeHeader, requestContentTypeHeader);

        QEventLoop waitLoop;
        QNetworkAccessManager connection;
        QNetworkReply* reply = connection.post(request, postData);
        QObject::connect(reply, SIGNAL(finished()), &waitLoop, SLOT(quit()));
        waitLoop.exec();

        int errCode = (*reply).error();

        QByteArray result;
        if (errCode == 0)
        {
            result = (*reply).readAll();
            //DefaultLogger << result;
        }
        else
        {
            DefaultLogger << "Network return code : " << errCode;
        }

        delete reply;

        return result;
    }

    static inline QJsonObject getGetResponseAsJson(const QString& url, const QString& queryData = "")
    {
        return getResponseAsJson(getGetResponse(url, queryData));
    }

    static inline QByteArray getGetResponse(const QString& urlStr, const QString& queryData = "")
    {
        QEventLoop waitLoop;
        QNetworkAccessManager networkAccessManager;
        QNetworkReply* reply = getGetResponse(networkAccessManager, &waitLoop, SLOT(quit()), urlStr, queryData);
        waitLoop.exec();

        int errCode = (*reply).error();

        QByteArray result;
        if (errCode == 0)
        {
            result = (*reply).readAll();
            //qDebug() << QString::fromUtf8(result);
            //DefaultLogger << result;
        }
        else
        {
            DefaultLogger << "Network return code : " << errCode;
        }

        reply->deleteLater();

        return result;
    }

    static inline QNetworkReply* getGetResponse(QNetworkAccessManager& networkAccessManager, QObject* receiver, const char* slot, const QString& urlStr, const QString& queryData = "")
    {
        DefaultLogger << urlStr;
        DefaultLogger << queryData;

        QString requestUrl = urlStr;
        if (!queryData.isEmpty())
            requestUrl += "?" + queryData;

        QUrl url(requestUrl);
        QNetworkRequest request(url);

        request.setRawHeader("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,*/*;q=0.8");
        request.setRawHeader("Accept-Encoding", "identity"); // "gzip, deflate, br"
        request.setRawHeader("Accept-Language", "en-US,en;q=0.5");
        request.setRawHeader("Connection", "keep-alive");
        request.setRawHeader("Sec-Fetch-Dest", "document");
        request.setRawHeader("Sec-Fetch-Mode", "navigate");
        request.setRawHeader("Sec-Fetch-Site", "none");
        request.setRawHeader("Sec-Fetch-User", "?1");
        request.setRawHeader("Upgrade-Insecure-Requests", "1");
        request.setRawHeader("User-Agent", "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:94.0) Gecko/20100101 Firefox/94.0");

        QNetworkReply* reply = networkAccessManager.get(request);
        QObject::connect(reply, SIGNAL(finished()), receiver, slot);
        //QEventLoop waitLoop;
        //QObject::connect(reply, SIGNAL(finished()), &waitLoop, SLOT(quit()));
        //waitLoop.exec();
        return reply;
    }

    static inline QJsonObject getResponseAsJson(const QByteArray& response)
    {
        try
        {
            return QJsonDocument::fromJson(response).object();
        }
        catch (const std::exception& e)
        {
            DefaultLogger << e.what();
            return QJsonObject();
        }
    }

};

}

