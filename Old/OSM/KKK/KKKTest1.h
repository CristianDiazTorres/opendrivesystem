#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"

namespace _NOSM
{

#define WayTest1StringEnum_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayTest1, name, value)

#define WayTest1StringEnum_MEMBERS(usingType) \
    WayTest1StringEnum_MEMBER(usingType, COMMERCIAL        , "commercial") \
    WayTest1StringEnum_MEMBER(usingType, INDUSTRIAL        , "industrial") \
    EMPTY_COMMAND

struct WayTest1
{
	struct StringEnum
	{
	    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayTest1)
	};

	
	/* OR */
	String value;
	StringEnum value;
	
	SingleAttrVariant value;
	
	Vector<String> value;
	Vector<StringEnum> value;
	
	Vector<SingleAttrVariant> value;
	
	_OSM_TAG_MEMBERS_DECLARE(WayTag1, "tag1", "tag1");
};
}

// "highway"="???"