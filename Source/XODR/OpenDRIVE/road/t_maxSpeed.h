#pragma once

#include "XODR/OpenDRIVE/core/t_grEqZero.h"
#include "XODR/OpenDRIVE/road/e_maxSpeedString.h"

/*
    <xs:simpleType name="t_maxSpeed">
        <xs:union memberTypes="t_grEqZero e_maxSpeedString"/>
    </xs:simpleType>
*/

namespace _NOD
{
struct t_maxSpeed : public e_maxSpeedString
{
    t_grEqZero value;
    bool isNumber; // isNumber => t_grEqZero, else => e_maxSpeedString

public:
    string toString() const
    {
        return this->isNumber ? _NCM::toString(value) : e_maxSpeedString::toString();
    }

    //operator string() const
    //{
    //    return toString();
    //}

    double toDouble() const
    {
        return this->isNumber ? value : 0;
    }

    operator double() const
    {
        return toDouble();
    }

    t_maxSpeed& operator=(t_grEqZero value_)
    {
        value = value_;
        isNumber = true;
        return *this;
    }

    t_maxSpeed& operator=(const string& str)
    {
        if (str == e_maxSpeedString::NO_LIMIT)
        {
            (e_maxSpeedString&)(*this) = e_maxSpeedString::NO_LIMIT;
            isNumber = false;
        }
        else if (str.isEmpty() || str == e_maxSpeedString::UNDEFINED)
        {
            (e_maxSpeedString&)(*this) = e_maxSpeedString::UNDEFINED;
            isNumber = false;
        }
        else
        {
            _NCM::setFromString(value, str);
            isNumber = true;
        }
        return *this;
    }

    bool operator==(const t_maxSpeed& other) const
    {
        if (this->isNumber != other.isNumber)
            return false;

        if (this->isNumber)
            return _UNIVERSIAL_TYPE_ATTRIBUTE_COMPARE1(value);
        return _UNIVERSIAL_TYPE_BASE_GEO_JSON_COMPARE(e_maxSpeedString);
    }

    bool operator!=(const t_maxSpeed& other) const
    {
        return !(*this == other);
    }
};
}
