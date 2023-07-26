#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"
#include "XODR/OpenDRIVE/core/t_include.h"
#include "XODR/OpenDRIVE/core/t_userData.h"
#include "XODR/OpenDRIVE/core/t_dataQuality.h"

/*
    <xs:group name="g_additionalData">
        <xs:annotation>
            <xs:documentation>OpenDRIVE offers the possibility to include external data. The processing of this data depends on the application.
Additional data may be placed at any position in OpenDRIVE.</xs:documentation>
        </xs:annotation>
        <xs:sequence>
            <xs:element name="include" type="t_include" minOccurs="0" maxOccurs="unbounded"/>
            <xs:element name="userData" type="t_userData" minOccurs="0" maxOccurs="unbounded"/>
            <xs:element name="dataQuality" type="t_dataQuality" minOccurs="0" maxOccurs="1"/>
        </xs:sequence>
    </xs:group>
*/

namespace _NOD
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_core) \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_include       , include) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, x, t_userData      , userData) lineEnd \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 0, 1, t_dataQuality   , dataQuality) lineEnd \
    EMPTY_COMMAND

struct g_additionalData : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_DEFINE(g_additionalData)

public:
    void setTestData()
    {
    }

public:
    const t_userData& getUserData(const string& code) const
    {
        for (const t_userData& userData : userData_sequence)
            if (userData.code == code)
                return userData;
        return t_userData::EMPTY_USER_DATA;
    }

    string getUserDataValue(const string& code) const
    {
        return getUserData(code).value;
    }

    const _vector<_vehiclePos>& getGPSData() const
    {
        return getUserData(_SC_gps).gps_sequence;
    }

    const _vector<_vehiclePos>& getTrajectoryData() const
    {
        return getUserData(_SC_trajectory).trajectory_sequence;
    }

    const _vector<_NOSM::Way>& getOSMWayDataOnCell() const
    {
        return getUserData(_SC_osmWay).osmWay_sequence;
    }

    void setUserData(const string& code, const string& value)
    {
        for (t_userData& userData : userData_sequence)
        {
            if (userData.code == code)
            {
                userData.value = value;
                return;
            }
        }

        userData_sequence << t_userData(code, value);
    }
};

#define _OD_G_ADDITIONAL_DATA(usingType) \
    _OD_G_ADDITIONAL_DATA_##usingType

#define _OD_G_ADDITIONAL_DATA_DECLARE \
    g_additionalData additionalData

#define _OD_G_ADDITIONAL_DATA_SET_PARENT \
    additionalData.setParent(this, resetChildren)

#define _OD_G_ADDITIONAL_DATA_COMPARE \
    this->additionalData == other.additionalData

#define _OD_G_ADDITIONAL_DATA_READ \
    status |= additionalData.read(node)

#define _OD_G_ADDITIONAL_DATA_WRITE \
    additionalData.write(xmlWriter)

#define _OD_G_ADDITIONAL_DATA_JSON_READ \
    additionalData.read(obj)

#define _OD_G_ADDITIONAL_DATA_JSON_WRITE \
    additionalData.write(obj)

#define _OD_G_ADDITIONAL_DATA_SET_TEST_DATA \
    additionalData.setTestData()

#define _OD_G_ADDITIONAL_DATA_SAVE_GEO_JSON_DATA

#define _OD_G_ADDITIONAL_DATA_UPDATE_GEO_JSON_DATA_LINE

#define _OD_G_ADDITIONAL_DATA_UPDATE_GEO_JSON_DATA_POINT

#define _OD_G_ADDITIONAL_DATA_CALC_ABS_POS \
    additionalData.calcAbsolutePosIncludingChildren(road)

#define _OD_G_ADDITIONAL_DATA_CALC_REL_POS \
    additionalData.calcRelativePosIncludingChildren(road)

}

