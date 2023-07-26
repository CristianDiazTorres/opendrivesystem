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
struct t_bool_default_true;

struct t_bool_default_false
{
    bool value;

public:
    t_bool_default_false()
    {
        this->value = false;
    }

    t_bool_default_false(bool value)
    {
        this->value = value;
    }

    t_bool_default_false(const string& value)
    {
        this->value = value == _SC_true;
    }

    bool toBool() const
    {
        return value;
    }

    bool isEmpty() const
    {
        return !value; // == false;
    }

    operator bool() const
    {
        return value;
    }

    operator bool&()
    {
        return value;
    }

    operator t_bool_default_true&()
    {
        return (t_bool_default_true&)*this;
    }

    string toString() const
    {
        return value ? _SC_true : _SC_false;
    }

    //operator string() const
    //{
    //    return toString();
    //}

    t_bool_default_false& operator=(bool value)
    {
        this->value = value;
        return *this;
    }

    t_bool_default_false& operator=(const string& value)
    {
        this->value = value == _SC_true;
        return *this;
    }
};
}
