#include "GlobalSettingsOnPGDatabase.h"
#include "PGDatabaseConnector.h"

namespace _NDB
{

GlobalSettingsOnPGDatabase* GlobalSettingsOnPGDatabase::defaultInstance = 0;

GlobalSettingsOnPGDatabase::GlobalSettingsOnPGDatabase()
    : SettingsOnPGDatabase("_GlobalSettings")
{
}

}
