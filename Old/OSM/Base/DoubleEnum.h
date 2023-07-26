#pragma once

#define _OSM_STRING_ENUM_MEMBER(usingType, stringEnumType, name, value) \
    _OSM_STRING_ENUM_MEMBER_##usingType(stringEnumType, name, value)

#define _OSM_STRING_ENUM_MEMBER_DECLARE(stringEnumType, name, value) \
    const static String name;

#define _OSM_STRING_ENUM_MEMBER_DEFINE(stringEnumType, name, value) \
    const String stringEnumType::name = value;

#define _OSM_STRING_ENUM_MEMBER_ADD(stringEnumType, name, value) \
{ \
    Int64 key = stringEnumType::intToStr.size(); \
    stringEnumType::intToStr[key] = stringEnumType::name; \
    stringEnumType::strToInt[stringEnumType::name] = key; \
    }

#define _OSM_STRING_ENUM_MEMBERS_DECLARE(stringEnumType) \
public: \
    _OSM_STRING_ENUM_MEMBER_DECLARE(stringEnumType, NULL_VALUE, "") \
    stringEnumType##_MEMBERS(DECLARE) \
    static Map<Int64, String>   intToStr; \
    static Map<String, Int64>   strToInt; \
    Int64 value; \
    stringEnumType() \
    { \
        this->value = 0; /* Default value */ \
    } \
    stringEnumType(Int64 value) \
{ \
    this->value = value; \
    } \
    \
    stringEnumType(const String& value) \
{ \
    this->value = strToInt[value]; \
    } \
    \
    String toString() const \
{ \
    return intToStr[this->value]; \
    } \
    \
    bool isEmpty() const \
{ \
    return this->value == 0; \
    } \
    \
    stringEnumType& operator=(const String& value) \
{ \
    this->value = strToInt[value]; \
    return *this; \
    } \
    \
    bool operator==(const stringEnumType& other) const \
{ \
    return this->value == other.value; \
    } \
    \
    bool operator!=(const stringEnumType& other) const \
{ \
    return !(*this == other); \
    } \
    /* \
    operator String() const \
    { \
    return toString(); \
    }*/

#define _OSM_STRING_ENUM_MEMBERS_DEFINE(stringEnumType) \
    _OSM_STRING_ENUM_MEMBER_DEFINE(stringEnumType, NULL_VALUE, "") \
    stringEnumType##_MEMBERS(DEFINE) \
    Map<Int64, String>   stringEnumType::intToStr; \
    Map<String, Int64>   stringEnumType::strToInt;

#define _OSM_STRING_ENUM_MEMBERS_ADD(stringEnumType) \
    _OSM_STRING_ENUM_MEMBER_ADD(stringEnumType, NULL_VALUE, "") \
    stringEnumType##_MEMBERS(ADD)
