#include "OSMWaySettingsOnPGDatabase.h"

namespace _NOSM
{

OSMWaySettingsOnPGDatabase* OSMWaySettingsOnPGDatabase::defaultInstance = 0;

OSMWaySettingsOnPGDatabase::OSMWaySettingsOnPGDatabase()
    : SettingsOnPGDatabase("OSMWaySettings")
{

}

QString OSMWaySettingsOnPGDatabase::getJsonPath()
{
    return getValue("JsonPath");
}

void OSMWaySettingsOnPGDatabase::setJsonPath(const QString& path)
{
    setValue("JsonPath", path);
}

}
