#pragma once

#include "OSM/Internal.h"
#include "OSM/StringEnum.h"
#include "OSM/IntEnum.h"
#include "OSM/DoubleEnum.h"
#include "OSM/UnitEnum.h"

namespace _NOSM
{

#define WayTest1StringEnum_MEMBER(usingType, name, value) \
    _OSM_STRING_ENUM_MEMBER(usingType, WayTest1, name, value)

#define WayTest1StringEnum_MEMBERS(usingType) \
    WayTest1StringEnum_MEMBER(usingType, COMMERCIAL        , "commercial") \
    WayTest1StringEnum_MEMBER(usingType, INDUSTRIAL        , "industrial") \
    EMPTY_COMMAND

#define WayTest1IntEnum_MEMBER(usingType, name, value) \
    _OSM_INT_ENUM_MEMBER(usingType, WayTest1, name, value)

#define WayTest1IntEnum_MEMBERS(usingType) \
    WayTest1IntEnum_MEMBER(usingType, _1, 1) \
    WayTest1IntEnum_MEMBER(usingType, _2, 2) \
    EMPTY_COMMAND

#define WayTest1DoubleEnum_MEMBER(usingType, name, value) \
    _OSM_DOUBLE_ENUM_MEMBER(usingType, WayTest1, name, value)

#define WayTest1DoubleEnum_MEMBERS(usingType) \
    WayTest1DoubleEnum_MEMBER(usingType, _1_1, 1) \
    WayTest1DoubleEnum_MEMBER(usingType, __2_2, 2) \
    EMPTY_COMMAND

#define WayTest1UnitEnum_MEMBER(usingType, name, value) \
    _OSM_UNIT_ENUM_MEMBER(usingType, WayTest1, name, value)

#define WayTest1UnitEnum_MEMBERS(usingType) \
    WayTest1UnitEnum_MEMBER(usingType, COMMERCIAL        , "commercial") \
    WayTest1UnitEnum_MEMBER(usingType, INDUSTRIAL        , "industrial") \
    EMPTY_COMMAND

struct WayTest1
{
	struct StringEnum
	{
	    _OSM_STRING_ENUM_MEMBERS_DECLARE(WayTest1)
	};

	struct IntEnum
	{
	    _OSM_INT_ENUM_MEMBERS_DECLARE(WayTest1)
	};

	struct DoubleEnum
	{
	    _OSM_DOUBLE_ENUM_MEMBERS_DECLARE(WayTest1)
	};

	struct UnitEnum
	{
	    _OSM_UNIT_ENUM_MEMBERS_DECLARE(WayTest1)
	};

	struct SingleAttrVariant
	{
		SingleAttrType type;
		union
		{
			String stringValue;
			Int intValue;
			Double doubleValue;
			DateTime dateTimeValue;
			StringEnum stringEnumValue;
			IntEnum intEnumValue;
			DoubleEnum doubleEnumValue;
			DoubleUnitEnum doubleUnitEnumValue;
		};
	};
	
	struct ComplexAttrVariant
	{
		ComplexAttrType type;
		union
		{
			String stringValue;
			Int intValue;
			Double doubleValue;
			DateTime dateTimeValue;
			StringEnum stringEnumValue;
			IntEnum intEnumValue;
			DoubleEnum doubleEnumValue;
			DoubleUnitEnum doubleUnitEnumValue;

			Vector<String> stringVectorValue;
			Vector<Int> intVectorValue;
			Vector<Double> doubleVectorValue;
			Vector<DateTime> dateTimeVectorValue;
			Vector<StringEnum> stringEnumVectorValue;
			Vector<IntEnum> intEnumVectorValue;
			Vector<DoubleEnum> doubleEnumVectorValue;
			Vector<Double> doubleUnitEnumVectorValue;

			Vector<SingleAttrVariant> singleAttrVariantVectorValue;
		};
	};
	
	/* OR */
	String value;
	Int value;
	Double value;
	DateTime value;
	StringEnum value;
	IntEnum value;
	DoubleEnum value;
	DoubleUnitEnum value;
	
	SingleAttrVariant value;
	
	Vector<String> value;
	Vector<Int> value;
	Vector<Double> value;
	Vector<DateTime> value;
	Vector<StringEnum> value;
	Vector<IntEnum> value;
	Vector<DoubleEnum> value;
	Vector<DoubleUnitEnum> value;
	
	Vector<SigngleAttrVariant> value;
	
	ComplexAttrVariant value;
	
	_OSM_TAG_MEMBERS_DECLARE(WayTag1, "tag1", "tag1");
};
}

// "highway"="???"