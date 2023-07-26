	struct SingleAttrVariant
	{
		bool useEnum
		union
		{
			String stringValue;
			StringEnum stringEnumValue;
		};
	};