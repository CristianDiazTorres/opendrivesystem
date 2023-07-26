
/*
 * This file is part of OSMM module and header of PriorKnowledgeProvider submodule.
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

#ifndef __OSMM_PRIORKNOWLEDGEPROVIDER_H__
#define __OSMM_PRIORKNOWLEDGEPROVIDER_H__

#include "OSMM/OSMM.h"

namespace OSMM
{

    /*
    *======================================================================
    * NOTE & MODIFIED : Merged RoadPart, RoadInfo and LocalRoadDescription into Road
    *======================================================================
    *
    * Input: The PriorKnowledgeProvider submodule shall be supplied with:
    * a country name
    * a type of road corresponding to the OSM tag
    * (see Highway Key of OpenStreetMap. May 2020. URL:https://wiki.openstreetmap.org/wiki/Key:highway,
                    Key_highway - OpenStreetMap Wiki.mhtml).
    *
    * Output: The PriorKnowledgeProvider submodule shall return
    * the number of lanes for the given type of road
    * the width of each lane
    *
    * System Level Requirements (SLR)
    * 1: the PriorKnowledgeProvider shall return one output per input request
    * 2: the PriorKnowledgeProvider shall return the number of lane, type and color of roadmarking on eachside,
                and width of each lane for every pair of country and OSM road type
    *
    *======================================================================
    * NOTE & MODIFIED : Merged RoadPart, RoadInfo and LocalRoadDescription into Road
    *======================================================================
    */
    class PriorKnowledgeProvider
    {
    public:
        int GetWayWidth(ConstQString& country, ConstQString& highway);
        int GetMaxSpeed(ConstQString& country, ConstQString& highway);
        int GetLaneCount(ConstQString& country, ConstQString& highway);
        int GetLaneWidth(ConstQString& country, ConstQString& highway);

        RoadMarking GetLeftMarking(ConstQString& country, ConstQString& highway);
        RoadMarking GetRightMarking(ConstQString& country, ConstQString& highway);
        RoadMarkingColor GetLeftMarkingColor(ConstQString& country, ConstQString& highway);
        RoadMarkingColor GetRightMarkingColor(ConstQString& country, ConstQString& highway);
    };

}

#endif // __OSMM_PRIORKNOWLEDGEPROVIDER_H__