/*
 * This file is part of OSM module and header of ResultGenerator submodule.
 * Developed for the OpenStreet Data Management System.
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

#pragma once

#include "OSM/Way/Way.h"

namespace _NOSM
{

/*
    *======================================================================
    * NOTE & MODIFIED : Merged RoadPart, RoadInfo and LocalRoadDescription into Way
    *======================================================================
    *
    * Input: The ResultGenerator submodule shall be supplied with
    * the number of subrequests
    * an array of local way descriptions
    * Output: The ResultGenerator submodule shall output an RequestStatus.
    *
    * System Level Requirements (SLR)
    * 1: The ResultGenerator shall return one and only one RequestStatus per Request.
    * 2: The ResultGenerator shall tag the RequestStatus as FAILED if the request could not be performed.
    * 3: The ResultGenerator shall tag the RequestStatus as NOTFOUND all the request result is empty.
    * 4: The ResultGenerator shall correct positive or negative change in the number of lane if the change isbigger than 2.
    * 5: The ResultGenerator shall correct local inversion of driving direction on any lane along the way path.
    * 6: The ResultGenerator shall deduce the lateral offset of the various lanes compositing each of the LaneSections.
    * 7: The ResultGenerator shall ensure that the way markings are consistent all along the path of the way.
    *
    * Software Level Requirements
    * Interface : LocalRoadDescription
    * laneSection : LaneSection
    * country : QString
    *
    * ResultGenerator
    * Append(LocalRoadDescription)
    * RequestStatus Process()
    * void writeJsonParserOutput()
    *
    * Detailed Requirements (DR)
    * 1: The ResultGenerator shall expose a method to accept a LocalRoadDescription and store it.
    * 2: The ResultGenerator shall expose a function that returns the RequestStatus.
    * 3: The ResultGenerator shall ensure that all id of the Lane objects present in the ways are unique ids.
    * 4: The ResultGenerator shall parse the chain of Way objects to define the next id and previous id ofeach Lane object.
    * 5: The ResultGenerator shall set the previous id of lanes that have no previous section to -1 (case of branching).
    * 6: The ResultGenerator shall set the next id of lanes that have no next section to -1 (case of merging).
    * 7: The ResultGenerator shall ensure that, when following a chain of Lane object using the id, next id andprevious id attribute,
    * there is never a change of DrivingDirection from Positive to Negative or vice-versa.
    * 8: The ResultGenerator shall set the lateral offset of every Lane according to the width of theneighboring lanes.
    * 9: The ResultGenerator shall add LaneSection objects to the Way object adequatly, to ensure that,when parsing the Way,
    * there is never more than one merging or branching per driving direction.
    *
    *======================================================================
    * NOTE & MODIFIED : Merged RoadPart, RoadInfo and LocalRoadDescription into Way
    *======================================================================
    */
class ResultGenerator
{

public:
    /* output with JSON format */
    void writeJsonParserOutput(WayVec& ways, const QString& jsonPath);
    void writeJsonParserOutput(NodeVec& nodes, const QString& jsonPath);

    QByteArray getJSONData(WayVec& ways);
    QByteArray getJSONData(NodeVec& nodes);

};

}

