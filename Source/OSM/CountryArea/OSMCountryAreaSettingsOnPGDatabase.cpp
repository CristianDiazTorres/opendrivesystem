#include "OSMCountryAreaSettingsOnPGDatabase.h"

namespace _NOSM
{

OSMCountryAreaSettingsOnPGDatabase* OSMCountryAreaSettingsOnPGDatabase::defaultInstance = 0;

OSMCountryAreaSettingsOnPGDatabase::OSMCountryAreaSettingsOnPGDatabase()
    : SettingsOnPGDatabase("OSMCntryAreaSettings")
{

}

bool OSMCountryAreaSettingsOnPGDatabase::haveToGetCountryAreaOnlyForAU()
{
    return getValue("HaveToGetCountryAreaOnlyForAU") != "No";
}

void OSMCountryAreaSettingsOnPGDatabase::setHaveToGetCountryAreaOnlyForAU(bool onlyForAU)
{
    setValue("HaveToGetCountryAreaOnlyForAU", onlyForAU ? "Yes" : "No");
}

}
