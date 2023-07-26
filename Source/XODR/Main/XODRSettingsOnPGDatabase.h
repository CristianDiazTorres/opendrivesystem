#pragma once

#include "XODR/Internal/Internal.h"
#include "DB/Main/SettingsOnPGDatabase.h"
#include "Common/Main/DefaultInstance.h"

namespace _NXODR
{

class XODRSettingsOnPGDatabase : public SettingsOnPGDatabase
{
    _NCM_DEFAULT_INSTANCE_INIT_DECLARE(XODRSettingsOnPGDatabase, &, *)

public:
    XODRSettingsOnPGDatabase();

public:
    bool haveToWriteOSM();
    void setHaveToWriteOSM(bool value);

    bool haveToWriteGPS();
    bool haveToWriteTrajectory();
    bool haveToWriteOSMWay();
};

#define XODRSettingsOnPGDatabase_createDefaultInstance    _NXODR::XODRSettingsOnPGDatabase::createDefaultInstance()
#define XODRSettingsOnPGDatabase_initDefaultInstance      _NXODR::XODRSettingsOnPGDatabase::initDefaultInstance()
#define XODRSettingsOnPGDatabase_getDefaultInstance       _NXODR::XODRSettingsOnPGDatabase::getDefaultInstance()

}
