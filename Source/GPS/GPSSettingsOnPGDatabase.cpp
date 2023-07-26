#include "GPSSettingsOnPGDatabase.h"

namespace _NOSM
{

GPSSettingsOnPGDatabase* GPSSettingsOnPGDatabase::defaultInstance = 0;

GPSSettingsOnPGDatabase::GPSSettingsOnPGDatabase()
    : SettingsOnPGDatabase("GPSSettings")
{

}

}
