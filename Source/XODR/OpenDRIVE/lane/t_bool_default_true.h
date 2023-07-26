#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="t_bool">
        <xs:restriction base="xs:string">
            <xs:enumeration value="true"/>
            <xs:enumeration value="false"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{
struct t_bool_default_false;

struct t_bool_default_true
{
    bool value;

public:
    t_bool_default_true()
    {
        this->value = true;
    }

    t_bool_default_true(bool value)
    {
        this->value = value;
    }

    t_bool_default_true(const string& value)
    {
        this->value = value == _SC_true;
    }

    bool toBool() const
    {
        return value;
    }

    bool isEmpty() const
    {
        return value; // == true;
    }

    operator bool() const
    {
        return value;
    }

    operator bool&()
    {
        return value;
    }

    operator t_bool_default_false&()
    {
        return (t_bool_default_false&)*this;
    }

    string toString() const
    {
        return value ? _SC_true : _SC_false;
    }

    //operator string() const
    //{
    //    return toString();
    //}

    t_bool_default_true& operator=(bool value)
    {
        this->value = value;
        return *this;
    }

    t_bool_default_true& operator=(const string& value)
    {
        this->value = value == _SC_true;
        return *this;
    }
};
}
