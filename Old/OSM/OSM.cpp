/**
 * This file is implemention part of OSM module.
 * Developed for the OpenStreet Data Management System.
 *
 * This module is interface for request to server.
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

#include "OSM/OSM.h"
#include "OSM/RequestLauncher.h"
#include "OSM/RequestAnalyzer.h"
#include "OSM/ResultGenerator.h"

namespace _NOSM
{

/**
    * Send request Overpass api query to server.
    *
    * @param value contain request which have vehicle GPS points .
    * @return result of OSM module.
    *
    * @exceptsafe This function does not throw exceptions.
    *
    *
    *======================================================================
    * NOTE & MODIFIED : Merged RoadPart, RoadInfo and LocalRoadDescription into Way
    *======================================================================
    *
    * The main method to communicate with the module is:
    *		This method performs a synchronous request and return a pointer to the output request structure.
    *
    * Functional System Level Requirements (SLR)
    *		1: When being provided with a Request, the OSM shall return a RequestStatus.
    *		2: The OSM shall give result for GPS traces located in any country of the world.
    *		3: If a GPS trace does not perfectly matches a way trace recorded in the OSM database,
    *			the requestresult shall contain information about the closest plausible way trace.
    *		4: If no plausible way trace exist nearby the supplied GPS trace, the OSM shall tag the result as NOTFOUND.
    *		5: If a connection problem with the OSM servers occur, or if the result from the OSM server is corrupted,
    *			the OSM shall tag the result as FAILED.
    *		6: The module shall be able to process requests with up to 72 geocoordinates.
    *		7: The module shall be able to process requests with a single geocoordinate.
    *
    * General Architecture
    *		The Request is processed by the RequestLauncher.
    *		This module will process n singlesubrequests with the OverpassAPI.
    *		Each of the single subrequest result from the OverpassAPI will beprocessed by a JsonParser module
    *			that will extract relevant information.
    *		Each of these extractions willbe passed to a RequestAnalyzer that will build a consistent local way description.
    *		The RequestAnalyzer will use the PriorKnowledgeProvider, to enrich and or fill gaps in the data.
    *		Each of the local roaddescriptions will be supplied to the ResultGenerator,
    *			that will build a consistent result along thegeodetic path supplied in the request.
    *
    *======================================================================
    * NOTE & MODIFIED : Merged RoadPart, RoadInfo and LocalRoadDescription into Way
    *======================================================================
    */
RequestStatus getNearestRoadsForPath(VehiclePosVec poses, WayVec& ways)
{
    //if (poses.size() > OSM_MAX_POINTS_COUNT) // SLR6
    //    poses.resize(OSM_MAX_POINTS_COUNT);

    // Get Json results by Overpass Api
    RequestLauncher request_launcher;
    JsonArray json_results;
    try
    {
        json_results = request_launcher.getNearestRoadsForPath(poses); // Considering SLR2, SLR3, SLR7
    }
    catch (RequestLauncher::ConstException & e)
    {
        Debug << "Custom Exception occurred : " << e.GetInternalException().what() << ENDL;
        Debug << "========== OSM Failed ==========" << ENDL;
        return FAILED; // SLR5
    }

    // Check again
    if (request_launcher.GetRequestStatus() == FAILED)
    {
        Debug << "========== OSM Failed ==========" << ENDL;
        return FAILED; // SLR5
    }

    if (json_results.isEmpty())
    {
        Debug << "========== OSM Not found ==========" << ENDL;
        return NOTFOUND; // SLR4
    }

    // Analyze json results
    ways = RequestAnalyzer().getNearestRoadsForPath(poses, json_results);

    // Output into json file
    ResultGenerator result_generator;
    result_generator.JsonParserOutput(ways);
    ByteArray json_str = result_generator.GetJSONData(ways);
    //Debug << json_str.data(); // Output to screen

    Debug << "========== OSM Succeeded ==========" << ENDL;
    return SUCCESS; // SLR1
}

RequestStatus getNodes(double lat, double lon, double areaSize, NodeVec& nodes)
{
    // Get Json results by Overpass Api
    RequestLauncher request_launcher;
    JsonArray json_results;
    try
    {
        json_results = request_launcher.getWayNodes(lat, lon, areaSize); // Considering SLR2, SLR3, SLR7
    }
    catch (RequestLauncher::ConstException & e)
    {
        Debug << "Custom Exception occurred : " << e.GetInternalException().what() << ENDL;
        Debug << "========== OSM Failed ==========" << ENDL;
        return FAILED; // SLR5
    }

    // Check again
    if (request_launcher.GetRequestStatus() == FAILED)
    {
        Debug << "========== OSM Failed ==========" << ENDL;
        return FAILED; // SLR5
    }

    if (json_results.isEmpty())
    {
        Debug << "========== OSM Not found ==========" << ENDL;
        return NOTFOUND; // SLR4
    }

    // Analyze json results
    nodes = RequestAnalyzer().getWayNodes(json_results);

    // Output into json file
    ResultGenerator result_generator;

    result_generator.JsonParserOutput(nodes);
    ByteArray json_str = result_generator.GetJSONData(nodes);
    //Debug << json_str.data(); // Output to screen

    Debug << "========== OSM Succeeded ==========" << ENDL;
    return SUCCESS; // SLR1
}
}
