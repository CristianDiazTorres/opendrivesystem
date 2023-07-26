#include "OSM/Main/OverpassAPI.h"
#include "OSM/CountryArea/OSMCountryAreaSettingsOnPGDatabase.h"

namespace _NOSM
{

QJsonValue OverpassAPI::getCountryAreaData()
{
    QString query = "[out:json];rel[admin_level=2][type=boundary][boundary=administrative]";

    if (OSMCountryAreaSettingsOnPGDatabase_getDefaultInstance.haveToGetCountryAreaOnlyForAU())
        query += "[name=Australia]";

    query += ";out ids tags;";

    return getResponseAsJson(query);
}

}

