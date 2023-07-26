#include "XODRSettingsOnPGDatabase.h"

namespace _NXODR
{

XODRSettingsOnPGDatabase* XODRSettingsOnPGDatabase::defaultInstance = 0;

XODRSettingsOnPGDatabase::XODRSettingsOnPGDatabase()
    : SettingsOnPGDatabase("XODRSettings")
{

}

bool XODRSettingsOnPGDatabase::haveToWriteOSM()
{
    return getValue("HaveToWriteOSM") == "Yes";
}

void XODRSettingsOnPGDatabase::setHaveToWriteOSM(bool value)
{
    setValue("HaveToWriteOSM", value ? "Yes" : "No");
}

bool XODRSettingsOnPGDatabase::haveToWriteGPS()
{
    return getValue("HaveToWriteGPS") == "Yes";
}

bool XODRSettingsOnPGDatabase::haveToWriteTrajectory()
{
    return getValue("HaveToWriteTrajectory") == "Yes";
}

bool XODRSettingsOnPGDatabase::haveToWriteOSMWay()
{
    return getValue("HaveToWriteOSMWay") == "Yes";
}

}
