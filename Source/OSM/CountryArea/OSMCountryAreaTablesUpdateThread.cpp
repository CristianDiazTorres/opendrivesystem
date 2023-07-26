#include "OSM/CountryArea/OSMCountryAreaTablesUpdateThread.h"
#include "OSM/Main/OverpassAPI.h"
#include "OSM/Main/PolygonAPI.h"
#include "DB/Main/PGDatabaseConnector.h"

namespace _NOSM
{

OSMCountryAreaTablesUpdateThread* OSMCountryAreaTablesUpdateThread::defaultInstance = 0;

bool OSMCountryAreaTablesUpdateThread::onPreLoop()
{
    setProgress(0);

    if (hasToStop())
        return false;

    StringVec countries;
    StringVec jsons;
    StringVec areas;

    QJsonArray elements = OverpassAPI::getCountryAreaData().toArray();

    setProgress(10);

    if (hasToStop())
        return false;

    countries.resize(elements.size());
    jsons.resize(elements.size());
    areas.resize(elements.size());

    for (int i = 0; i < elements.size(); i ++)
    {
        if (hasToStop())
            return false;

        QJsonObject countryData = elements[i].toObject();
        jsons[i] = QJsonDocument(countryData).toJson();

        QJsonObject tags = countryData["tags"].toObject();
        countries[i] = tags["ISO3166-1"].toString();

        DefaultLogger << "Country : " << countries[i] << " : now getting polygon data using polygon api";

        const QString& id = QString::number((qint64)countryData["id"].toDouble());
        areas[i] = PolygonAPI::getResponse(id);

        setProgress(10 + (70 * (i + 1) / elements.size()));

        if (areas[i].isEmpty())
            DefaultLogger << "PolygonAPI failed, please check network connection";
        else
            DefaultLogger << "PolygonAPI ok";

        if (hasToStop())
            return false;
    }

    if (hasToStop())
        return false;

    bool dbWasUpdated = PGDatabaseConnector_getDefaultInstance.updateOSMCountryAreaDataAndHist(countries, jsons, areas);

    if (dbWasUpdated)
        DefaultLogger << "Finished !!!";
    else
        DefaultLogger << "Database update failed, please check database setting or network connection";

    setProgress(100);

    return false;
}

}
