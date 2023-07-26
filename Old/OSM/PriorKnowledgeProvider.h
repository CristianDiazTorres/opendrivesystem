
/*
 * This file is part of OSM module and header of PriorKnowledgeProvider submodule.
 * Developed for the OpenStreet Data Management System.
 *
 * This module is submodule for provide lanes of way detail property.
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

#ifndef __OSM_PRIORKNOWLEDGEPROVIDER_H__
#define __OSM_PRIORKNOWLEDGEPROVIDER_H__

#include "OSM/RoadMarking.h"
#include "OSM/RoadMarkingColor.h"

namespace _NOSM
{

/*
    *======================================================================
    * NOTE & MODIFIED : Merged RoadPart, RoadInfo and LocalRoadDescription into Way
    *======================================================================
    *
    * Input: The PriorKnowledgeProvider submodule shall be supplied with:
    * a country name
    * a type of way corresponding to the OSM tag
    * (see Highway Key of OpenStreetMap. May 2020. URL:https://wiki.openstreetmap.org/wiki/Key:highway,
                    Key_highway - OpenStreetMap Wiki.mhtml).
    *
    * Output: The PriorKnowledgeProvider submodule shall return
    * the number of lanes for the given type of way
    * the width of each lane
    *
    * System Level Requirements (SLR)
    * 1: the PriorKnowledgeProvider shall return one output per input request
    * 2: the PriorKnowledgeProvider shall return the number of lane, type and color of roadmarking on eachside,
                and width of each lane for every pair of country and OSM way type
    *
    *======================================================================
    * NOTE & MODIFIED : Merged RoadPart, RoadInfo and LocalRoadDescription into Way
    *======================================================================
    */
class PriorKnowledgeProvider
{
public:
    int GetWayWidth(const String& country, const String& highway);
    int GetMaxSpeed(const String& country, const String& highway);
    int GetLaneCount(const String& country, const String& highway);
    int GetLaneWidth(const String& country, const String& highway);

    RoadMarking GetLeftMarking(const String& country, const String& highway);
    RoadMarking GetRightMarking(const String& country, const String& highway);
    RoadMarkingColor GetLeftMarkingColor(const String& country, const String& highway);
    RoadMarkingColor GetRightMarkingColor(const String& country, const String& highway);
};

}

#endif // __OSM_PRIORKNOWLEDGEPROVIDER_H__
