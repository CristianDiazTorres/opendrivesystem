/*
 * This file is part of OSMM module and implemention of PriorKnowledgeProvider submodule.
 * Developed for the OpenStreet Data Management System.
 *
 * This module is submodule for provide lanes of road detail property.
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.
 */
#include "OSMM/PriorKnowledgeProvider.h"

namespace OSMM
{

	int PriorKnowledgeProvider::GetWayWidth(ConstQString& country, ConstQString& highway)
	{
        Q_UNUSED(highway);

        if (country == "AU")
		{
			return 20;
		}
		else if (country == "Austria")
		{
			return 20;
		}
		else if (country == "Belarus")
		{
			return 20;
		}
		else if (country == "Belgium")
		{
			return 20;
		}
		else if (country == "Brazil")
		{
			return 20;
		}
		else if (country == "Croatia")
		{
			return 20;
		}
		else if (country == "Czechia")
		{
			return 20;
		}
		else if (country == "Denmark")
		{
			return 20;
		}
		else if (country == "Dominican Republic")
		{
			return 20;
		}
		else if (country == "France")
		{
			return 20;
		}
		else if (country == "Georgia")
		{
			return 20;
		}
		else if (country == "Germany")
		{
			return 20;
		}
		else if (country == "Greece")
		{
			return 20;
		}
		else if (country == "Hungary")
		{
			return 20;
		}
		else if (country == "Indonesia")
		{
			return 20;
		}
		else if (country == "Iran")
		{
			return 20;
		}
		else if (country == "Israel")
		{
			return 20;
		}
		else if (country == "Italy")
		{
			return 20;
		}
		else if (country == "Japan")
		{
			return 20;
		}
		else if (country == "Korea")
		{
			return 20;
		}
		else if (country == "Malaysia")
		{
			return 20;
		}
		else if (country == "Netherlands")
		{
			return 20;
		}
		else if (country == "New Zealand")
		{
			return 20;
		}
		else if (country == "Norway")
		{
			return 20;
		}
		else if (country == "Philippines")
		{
			return 20;
		}
		else if (country == "Poland")
		{
			return 20;
		}
		else if (country == "Portugal")
		{
			return 20;
		}
		else if (country == "Romania")
		{
			return 20;
		}
		else if (country == "Russia")
		{
			return 20;
		}
		else if (country == "Spain")
		{
			return 20;
		}
		else if (country == "Sweden")
		{
			return 20;
		}
		else if (country == "Switzerland")
		{
			return 20;
		}
		else if (country == "Turkey")
		{
			return 20;
		}
		else if (country == "United Kingdom")
		{
			return 20;
		}
		else if (country == "United States")
		{
			return 20;
		}
		else
		{
			return 20;
		}
	}

	int PriorKnowledgeProvider::GetMaxSpeed(ConstQString& country, ConstQString& highway)
	{
        Q_UNUSED(highway);

        if (country == "AU")
		{
			return 100;
		}
		else if (country == "Austria")
		{
			return 100;
		}
		else if (country == "Belarus")
		{
			return 100;
		}
		else if (country == "Belgium")
		{
			return 100;
		}
		else if (country == "Brazil")
		{
			return 100;
		}
		else if (country == "Croatia")
		{
			return 100;
		}
		else if (country == "Czechia")
		{
			return 100;
		}
		else if (country == "Denmark")
		{
			return 100;
		}
		else if (country == "Dominican Republic")
		{
			return 100;
		}
		else if (country == "France")
		{
			return 100;
		}
		else if (country == "Georgia")
		{
			return 100;
		}
		else if (country == "Germany")
		{
			return 100;
		}
		else if (country == "Greece")
		{
			return 100;
		}
		else if (country == "Hungary")
		{
			return 100;
		}
		else if (country == "Indonesia")
		{
			return 100;
		}
		else if (country == "Iran")
		{
			return 100;
		}
		else if (country == "Israel")
		{
			return 100;
		}
		else if (country == "Italy")
		{
			return 100;
		}
		else if (country == "Japan")
		{
			return 100;
		}
		else if (country == "Korea")
		{
			return 100;
		}
		else if (country == "Malaysia")
		{
			return 100;
		}
		else if (country == "Netherlands")
		{
			return 100;
		}
		else if (country == "New Zealand")
		{
			return 100;
		}
		else if (country == "Norway")
		{
			return 100;
		}
		else if (country == "Philippines")
		{
			return 100;
		}
		else if (country == "Poland")
		{
			return 100;
		}
		else if (country == "Portugal")
		{
			return 100;
		}
		else if (country == "Romania")
		{
			return 100;
		}
		else if (country == "Russia")
		{
			return 100;
		}
		else if (country == "Spain")
		{
			return 100;
		}
		else if (country == "Sweden")
		{
			return 100;
		}
		else if (country == "Switzerland")
		{
			return 100;
		}
		else if (country == "Turkey")
		{
			return 100;
		}
		else if (country == "United Kingdom")
		{
			return 100;
		}
		else if (country == "United States")
		{
			return 100;
		}
		else
		{
			return 100;
		}
	}

	int PriorKnowledgeProvider::GetLaneCount(ConstQString& country, ConstQString& highway)
	{
        Q_UNUSED(highway);

        if (country == "AU")
		{
			return 2;
		}
		else if (country == "Austria")
		{
			return 2;
		}
		else if (country == "Belarus")
		{
			return 2;
		}
		else if (country == "Belgium")
		{
			return 2;
		}
		else if (country == "Brazil")
		{
			return 2;
		}
		else if (country == "Croatia")
		{
			return 2;
		}
		else if (country == "Czechia")
		{
			return 2;
		}
		else if (country == "Denmark")
		{
			return 2;
		}
		else if (country == "Dominican Republic")
		{
			return 2;
		}
		else if (country == "France")
		{
			return 2;
		}
		else if (country == "Georgia")
		{
			return 2;
		}
		else if (country == "Germany")
		{
			return 2;
		}
		else if (country == "Greece")
		{
			return 2;
		}
		else if (country == "Hungary")
		{
			return 2;
		}
		else if (country == "Indonesia")
		{
			return 2;
		}
		else if (country == "Iran")
		{
			return 2;
		}
		else if (country == "Israel")
		{
			return 2;
		}
		else if (country == "Italy")
		{
			return 2;
		}
		else if (country == "Japan")
		{
			return 2;
		}
		else if (country == "Korea")
		{
			return 2;
		}
		else if (country == "Malaysia")
		{
			return 2;
		}
		else if (country == "Netherlands")
		{
			return 2;
		}
		else if (country == "New Zealand")
		{
			return 2;
		}
		else if (country == "Norway")
		{
			return 2;
		}
		else if (country == "Philippines")
		{
			return 2;
		}
		else if (country == "Poland")
		{
			return 2;
		}
		else if (country == "Portugal")
		{
			return 2;
		}
		else if (country == "Romania")
		{
			return 2;
		}
		else if (country == "Russia")
		{
			return 2;
		}
		else if (country == "Spain")
		{
			return 2;
		}
		else if (country == "Sweden")
		{
			return 2;
		}
		else if (country == "Switzerland")
		{
			return 2;
		}
		else if (country == "Turkey")
		{
			return 2;
		}
		else if (country == "United Kingdom")
		{
			return 2;
		}
		else if (country == "United States")
		{
			return 2;
		}
		else
		{
			return 2;
		}
	}

	int PriorKnowledgeProvider::GetLaneWidth(ConstQString& country, ConstQString& highway)
	{
        Q_UNUSED(highway);

        if (country == "AU")
		{
			return 6;
		}
		else if (country == "Austria")
		{
			return 6;
		}
		else if (country == "Belarus")
		{
			return 6;
		}
		else if (country == "Belgium")
		{
			return 6;
		}
		else if (country == "Brazil")
		{
			return 6;
		}
		else if (country == "Croatia")
		{
			return 6;
		}
		else if (country == "Czechia")
		{
			return 6;
		}
		else if (country == "Denmark")
		{
			return 6;
		}
		else if (country == "Dominican Republic")
		{
			return 6;
		}
		else if (country == "France")
		{
			return 6;
		}
		else if (country == "Georgia")
		{
			return 6;
		}
		else if (country == "Germany")
		{
			return 6;
		}
		else if (country == "Greece")
		{
			return 6;
		}
		else if (country == "Hungary")
		{
			return 6;
		}
		else if (country == "Indonesia")
		{
			return 6;
		}
		else if (country == "Iran")
		{
			return 6;
		}
		else if (country == "Israel")
		{
			return 6;
		}
		else if (country == "Italy")
		{
			return 6;
		}
		else if (country == "Japan")
		{
			return 6;
		}
		else if (country == "Korea")
		{
			return 6;
		}
		else if (country == "Malaysia")
		{
			return 6;
		}
		else if (country == "Netherlands")
		{
			return 6;
		}
		else if (country == "New Zealand")
		{
			return 6;
		}
		else if (country == "Norway")
		{
			return 6;
		}
		else if (country == "Philippines")
		{
			return 6;
		}
		else if (country == "Poland")
		{
			return 6;
		}
		else if (country == "Portugal")
		{
			return 6;
		}
		else if (country == "Romania")
		{
			return 6;
		}
		else if (country == "Russia")
		{
			return 6;
		}
		else if (country == "Spain")
		{
			return 6;
		}
		else if (country == "Sweden")
		{
			return 6;
		}
		else if (country == "Switzerland")
		{
			return 6;
		}
		else if (country == "Turkey")
		{
			return 6;
		}
		else if (country == "United Kingdom")
		{
			return 6;
		}
		else if (country == "United States")
		{
			return 6;
		}
		else
		{
			return 6;
		}
	}

	RoadMarking PriorKnowledgeProvider::GetLeftMarking(ConstQString& country, ConstQString& highway)
	{
        Q_UNUSED(highway);

        if (country == "AU")
		{
			return NONE;
		}
		else if (country == "Austria")
		{
			return NONE;
		}
		else if (country == "Belarus")
		{
			return NONE;
		}
		else if (country == "Belgium")
		{
			return NONE;
		}
		else if (country == "Brazil")
		{
			return NONE;
		}
		else if (country == "Croatia")
		{
			return NONE;
		}
		else if (country == "Czechia")
		{
			return NONE;
		}
		else if (country == "Denmark")
		{
			return NONE;
		}
		else if (country == "Dominican Republic")
		{
			return NONE;
		}
		else if (country == "France")
		{
			return NONE;
		}
		else if (country == "Georgia")
		{
			return NONE;
		}
		else if (country == "Germany")
		{
			return NONE;
		}
		else if (country == "Greece")
		{
			return NONE;
		}
		else if (country == "Hungary")
		{
			return NONE;
		}
		else if (country == "Indonesia")
		{
			return NONE;
		}
		else if (country == "Iran")
		{
			return NONE;
		}
		else if (country == "Israel")
		{
			return NONE;
		}
		else if (country == "Italy")
		{
			return NONE;
		}
		else if (country == "Japan")
		{
			return NONE;
		}
		else if (country == "Korea")
		{
			return NONE;
		}
		else if (country == "Malaysia")
		{
			return NONE;
		}
		else if (country == "Netherlands")
		{
			return NONE;
		}
		else if (country == "New Zealand")
		{
			return NONE;
		}
		else if (country == "Norway")
		{
			return NONE;
		}
		else if (country == "Philippines")
		{
			return NONE;
		}
		else if (country == "Poland")
		{
			return NONE;
		}
		else if (country == "Portugal")
		{
			return NONE;
		}
		else if (country == "Romania")
		{
			return NONE;
		}
		else if (country == "Russia")
		{
			return NONE;
		}
		else if (country == "Spain")
		{
			return NONE;
		}
		else if (country == "Sweden")
		{
			return NONE;
		}
		else if (country == "Switzerland")
		{
			return NONE;
		}
		else if (country == "Turkey")
		{
			return NONE;
		}
		else if (country == "United Kingdom")
		{
			return NONE;
		}
		else if (country == "United States")
		{
			return NONE;
		}
		else
		{
			return NONE;
		}
	}

	RoadMarking PriorKnowledgeProvider::GetRightMarking(ConstQString& country, ConstQString& highway)
	{
        Q_UNUSED(highway);

        if (country == "AU")
		{
			return NONE;
		}
		else if (country == "Austria")
		{
			return NONE;
		}
		else if (country == "Belarus")
		{
			return NONE;
		}
		else if (country == "Belgium")
		{
			return NONE;
		}
		else if (country == "Brazil")
		{
			return NONE;
		}
		else if (country == "Croatia")
		{
			return NONE;
		}
		else if (country == "Czechia")
		{
			return NONE;
		}
		else if (country == "Denmark")
		{
			return NONE;
		}
		else if (country == "Dominican Republic")
		{
			return NONE;
		}
		else if (country == "France")
		{
			return NONE;
		}
		else if (country == "Georgia")
		{
			return NONE;
		}
		else if (country == "Germany")
		{
			return NONE;
		}
		else if (country == "Greece")
		{
			return NONE;
		}
		else if (country == "Hungary")
		{
			return NONE;
		}
		else if (country == "Indonesia")
		{
			return NONE;
		}
		else if (country == "Iran")
		{
			return NONE;
		}
		else if (country == "Israel")
		{
			return NONE;
		}
		else if (country == "Italy")
		{
			return NONE;
		}
		else if (country == "Japan")
		{
			return NONE;
		}
		else if (country == "Korea")
		{
			return NONE;
		}
		else if (country == "Malaysia")
		{
			return NONE;
		}
		else if (country == "Netherlands")
		{
			return NONE;
		}
		else if (country == "New Zealand")
		{
			return NONE;
		}
		else if (country == "Norway")
		{
			return NONE;
		}
		else if (country == "Philippines")
		{
			return NONE;
		}
		else if (country == "Poland")
		{
			return NONE;
		}
		else if (country == "Portugal")
		{
			return NONE;
		}
		else if (country == "Romania")
		{
			return NONE;
		}
		else if (country == "Russia")
		{
			return NONE;
		}
		else if (country == "Spain")
		{
			return NONE;
		}
		else if (country == "Sweden")
		{
			return NONE;
		}
		else if (country == "Switzerland")
		{
			return NONE;
		}
		else if (country == "Turkey")
		{
			return NONE;
		}
		else if (country == "United Kingdom")
		{
			return NONE;
		}
		else if (country == "United States")
		{
			return NONE;
		}
		else
		{
			return NONE;
		}
	}

	RoadMarkingColor PriorKnowledgeProvider::GetLeftMarkingColor(ConstQString& country, ConstQString& highway)
	{
        Q_UNUSED(highway);

        if (country == "AU")
		{
			return GREEN;
		}
		else if (country == "Austria")
		{
			return GREEN;
		}
		else if (country == "Belarus")
		{
			return GREEN;
		}
		else if (country == "Belgium")
		{
			return GREEN;
		}
		else if (country == "Brazil")
		{
			return GREEN;
		}
		else if (country == "Croatia")
		{
			return GREEN;
		}
		else if (country == "Czechia")
		{
			return GREEN;
		}
		else if (country == "Denmark")
		{
			return GREEN;
		}
		else if (country == "Dominican Republic")
		{
			return GREEN;
		}
		else if (country == "France")
		{
			return GREEN;
		}
		else if (country == "Georgia")
		{
			return GREEN;
		}
		else if (country == "Germany")
		{
			return GREEN;
		}
		else if (country == "Greece")
		{
			return GREEN;
		}
		else if (country == "Hungary")
		{
			return GREEN;
		}
		else if (country == "Indonesia")
		{
			return GREEN;
		}
		else if (country == "Iran")
		{
			return GREEN;
		}
		else if (country == "Israel")
		{
			return GREEN;
		}
		else if (country == "Italy")
		{
			return GREEN;
		}
		else if (country == "Japan")
		{
			return GREEN;
		}
		else if (country == "Korea")
		{
			return GREEN;
		}
		else if (country == "Malaysia")
		{
			return GREEN;
		}
		else if (country == "Netherlands")
		{
			return GREEN;
		}
		else if (country == "New Zealand")
		{
			return GREEN;
		}
		else if (country == "Norway")
		{
			return GREEN;
		}
		else if (country == "Philippines")
		{
			return GREEN;
		}
		else if (country == "Poland")
		{
			return GREEN;
		}
		else if (country == "Portugal")
		{
			return GREEN;
		}
		else if (country == "Romania")
		{
			return GREEN;
		}
		else if (country == "Russia")
		{
			return GREEN;
		}
		else if (country == "Spain")
		{
			return GREEN;
		}
		else if (country == "Sweden")
		{
			return GREEN;
		}
		else if (country == "Switzerland")
		{
			return GREEN;
		}
		else if (country == "Turkey")
		{
			return GREEN;
		}
		else if (country == "United Kingdom")
		{
			return GREEN;
		}
		else if (country == "United States")
		{
			return GREEN;
		}
		else
		{
			return GREEN;
		}
	}

	RoadMarkingColor PriorKnowledgeProvider::GetRightMarkingColor(ConstQString& country, ConstQString& highway)
	{
        Q_UNUSED(highway);

        if (country == "AU")
		{
			return GREEN;
		}
		else if (country == "Austria")
		{
			return GREEN;
		}
		else if (country == "Belarus")
		{
			return GREEN;
		}
		else if (country == "Belgium")
		{
			return GREEN;
		}
		else if (country == "Brazil")
		{
			return GREEN;
		}
		else if (country == "Croatia")
		{
			return GREEN;
		}
		else if (country == "Czechia")
		{
			return GREEN;
		}
		else if (country == "Denmark")
		{
			return GREEN;
		}
		else if (country == "Dominican Republic")
		{
			return GREEN;
		}
		else if (country == "France")
		{
			return GREEN;
		}
		else if (country == "Georgia")
		{
			return GREEN;
		}
		else if (country == "Germany")
		{
			return GREEN;
		}
		else if (country == "Greece")
		{
			return GREEN;
		}
		else if (country == "Hungary")
		{
			return GREEN;
		}
		else if (country == "Indonesia")
		{
			return GREEN;
		}
		else if (country == "Iran")
		{
			return GREEN;
		}
		else if (country == "Israel")
		{
			return GREEN;
		}
		else if (country == "Italy")
		{
			return GREEN;
		}
		else if (country == "Japan")
		{
			return GREEN;
		}
		else if (country == "Korea")
		{
			return GREEN;
		}
		else if (country == "Malaysia")
		{
			return GREEN;
		}
		else if (country == "Netherlands")
		{
			return GREEN;
		}
		else if (country == "New Zealand")
		{
			return GREEN;
		}
		else if (country == "Norway")
		{
			return GREEN;
		}
		else if (country == "Philippines")
		{
			return GREEN;
		}
		else if (country == "Poland")
		{
			return GREEN;
		}
		else if (country == "Portugal")
		{
			return GREEN;
		}
		else if (country == "Romania")
		{
			return GREEN;
		}
		else if (country == "Russia")
		{
			return GREEN;
		}
		else if (country == "Spain")
		{
			return GREEN;
		}
		else if (country == "Sweden")
		{
			return GREEN;
		}
		else if (country == "Switzerland")
		{
			return GREEN;
		}
		else if (country == "Turkey")
		{
			return GREEN;
		}
		else if (country == "United Kingdom")
		{
			return GREEN;
		}
		else if (country == "United States")
		{
			return GREEN;
		}
		else
		{
			return GREEN;
		}
	}

}
