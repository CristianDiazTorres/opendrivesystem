#pragma once

#include "XODR/OpenDRIVE/internal/_internal.h"

namespace _NOD
{

struct _e_base
{
    integer value;
};

inline bool operator<(const _e_base& a, const _e_base& b)
{
    return a.value < b.value;
}

inline bool operator<=(const _e_base& a, const _e_base& b)
{
    return a.value <= b.value;
}

inline bool operator>=(const _e_base& a, const _e_base& b)
{
    return a.value >= b.value;
}

inline bool operator>(const _e_base& a, const _e_base& b)
{
    return a.value > b.value;
}

}

#define _OD_STRING_ENUM_MAIN(usingType, type) \
    _OD_STRING_ENUM_MAIN_##usingType(type)

#define _OD_STRING_ENUM_MAIN_DECLARE(enumStringType) \
    static _map<integer, string>   intToStr; \
    static _map<string, integer>   strToInt; \
    enumStringType(integer value) \
{ \
    this->value = value; \
    } \
    \
    enumStringType(const string& value) \
{ \
    this->value = strToInt[value]; \
    } \
    \
    string toString() const \
{ \
    return intToStr[this->value]; \
    } \
    \
    bool isEmpty() const \
{ \
    return this->value == 0; \
    } \
    \
    enumStringType& operator=(const string& value) \
{ \
    this->value = strToInt[value]; \
    return *this; \
    } \
    \
    bool operator==(const enumStringType& other) const \
{ \
    return this->value == other.value; \
    } \
    \
    bool operator!=(const enumStringType& other) const \
{ \
    return !(*this == other); \
    } \
    /* \
    operator string() const \
    { \
    return toString(); \
    }*/

#define _OD_STRING_ENUM_MAIN_DEFINE(type) \
    _map<integer, string>   type::intToStr; \
    _map<string, integer>   type::strToInt;

#define _OD_STRING_ENUM_MAIN_INIT(type)

#define _OD_STRING_ENUM_CONST(usingType, type, name, value) \
    _OD_STRING_ENUM_CONST_##usingType(type, name, value)

#define _OD_STRING_ENUM_CONST_DECLARE(type, member, value) \
    static const string member;

#define _OD_STRING_ENUM_CONST_DEFINE(type, member, value) \
    const string type::member = value;

#define _OD_STRING_ENUM_CONST_INIT(type, member, value) \
    _OD_STRING_ENUM_CONST_APPEND(type, type::member);

#define _OD_STRING_ENUM_CONST_APPEND(type, const_value) \
{ \
    integer key = type::intToStr.size(); \
    type::intToStr[key] = const_value; \
    type::strToInt[const_value] = key; \
    }

#define _OD_STRING_ENUM_SUB_ENUM_APPEND(type, member_type) \
    for (_map<integer, string>::iterator iter = member_type::intToStr.begin(); \
    iter != member_type::intToStr.end(); \
    iter ++) \
{ \
    _OD_STRING_ENUM_CONST_APPEND(type, iter.value()) \
    }
