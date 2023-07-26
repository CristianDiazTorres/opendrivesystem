#include "OSMNodeSettingsOnPGDatabase.h"

namespace _NOSM
{

OSMNodeSettingsOnPGDatabase* OSMNodeSettingsOnPGDatabase::defaultInstance = 0;

OSMNodeSettingsOnPGDatabase::OSMNodeSettingsOnPGDatabase()
    : SettingsOnPGDatabase("OSMNodeSettings")
{

}

QString OSMNodeSettingsOnPGDatabase::getJsonPath()
{
    return getValue("JsonPath");
}

void OSMNodeSettingsOnPGDatabase::setJsonPath(const QString& path)
{
    setValue("JsonPath", path);
}

}
