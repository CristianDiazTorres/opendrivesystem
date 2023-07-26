#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="t_yesNo">
        <xs:restriction base="xs:string">
            <xs:enumeration value="yes"/>
            <xs:enumeration value="no"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

struct t_yesNo
{
    bool value;

public:
    t_yesNo()
    {
        //this->value = false;
    }

    t_yesNo(bool value)
    {
        this->value = value;
    }

    t_yesNo(const string& value)
    {
        this->value = value == _SC_yes;
    }

    bool toBool() const
    {
        return value;
    }

    bool isEmpty() const
    {
        return !value;
    }

    operator bool() const
    {
        return value;
    }

    string toString() const
    {
        return value ? _SC_yes : _SC_no;
    }

    //operator string() const
    //{
    //    return toString();
    //}

    t_yesNo& operator=(bool value)
    {
        this->value = value;
        return *this;
    }

    t_yesNo& operator=(const string& value)
    {
        this->value = value == _SC_yes;
        return *this;
    }
};

}

