#pragma once

#include "Common/Common.h"

namespace _NGPS
{

/*
_SC_GPS_Week_A
_SC_GPS_TOW__s__A
_SC_Pos_Mode_A
_SC_INS_Mode_A
_SC_Hdg_Mode_A
_SC_SVs_Tracked_A
_SC_SVs_Used_A
_SC_UTC_Date_A
_SC_UTC_Time_A
_SC_Lat__deg__A
_SC_Lon__deg__A
_SC_Alt_Ellips__m__A
_SC_SOG__m_s__A
_SC_COG__deg__A
_SC_Hdg__deg__A
_SC_Vert_Vel__m_s__A
_SC_Roll__deg__A
_SC_Pitch__deg__A
_SC_Yaw__deg__A
_SC_PDOP
_SC_HDOP
_SC_EHPE__m__A
_SC_EVPE__m__A
_SC_Baseline_2D__m__A
_SC_Baseline_3D__m__A
_SC_Corr__Age__s__A
_SC_Delta_TOW__ms__A
_SC_2D_Delta_Pos__m__A
_SC_3D_Delta_Pos__m__A
*/

struct NativeGPSData : public StringMap
{

};

}
