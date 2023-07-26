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
#include "OSM/Main/RequestLauncher.h"
#include "OSM/Main/RequestAnalyzer.h"
#include "OSM/Main/ResultGenerator.h"
#include "Debugger/Main/Logger.h"
#include "DB/Main/PGDatabaseConnector.h"
#include "OSM/Way/OSMWaySettingsOnPGDatabase.h"
#include "OSM/Node/OSMNodeSettingsOnPGDatabase.h"

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

RequestStatus getNearestRoadsForPath(bool useBasicTables, VehiclePosVec poses, WayVec& allOSMWays, WayVec& nearestWays)
{
    //if (poses.size() > OSM_MAX_POINTS_COUNT) // SLR6
    //    poses.resize(OSM_MAX_POINTS_COUNT);

    if (useBasicTables)
    {
        StringVec json_results;
        PGDatabaseConnector_getDefaultInstance.getOSMWayDataOnCell(poses[0], json_results);

        // Analyze json results
        RequestAnalyzer().getNearestRoadsForPath(poses, json_results, allOSMWays, nearestWays);
    }
    else
    {
        // Get Json results by Overpass Api
        RequestLauncher request_launcher;
        QJsonArray json_results;
        try
        {
            LL centerLL = poses[0].getCellCenterLL();
            //json_results = request_launcher.getNearestRoadsForPath(poses); // Considering SLR2, SLR3, SLR7
            json_results = request_launcher.getNearestRoadsForPath(centerLL.lat, centerLL.lon, Cell::SQUARE_CELL_SIZE * 100000); // Considering SLR2, SLR3, SLR7
        }
        catch (RequestLauncher::ConstException & e)
        {
            DefaultLogger << "Custom Exception occurred : " << e.getInternalException().what();
            DefaultLogger << "========== OSM Failed ==========";
            return FAILED; // SLR5
        }

        // Analyze json results
        RequestAnalyzer().getNearestRoadsForPath(poses, json_results, allOSMWays, nearestWays);
    }

    // Output into json file
    ResultGenerator result_generator;
    result_generator.writeJsonParserOutput(nearestWays, OSMWaySettingsOnPGDatabase_getDefaultInstance.getJsonPath());
    QByteArray json_str = result_generator.getJSONData(nearestWays);
    //DefaultLogger << json_str.data(); // Output to screen

    DefaultLogger << "========== OSM Succeeded ==========";
    return SUCCESS; // SLR1
}

RequestStatus getNodes(bool useBasicTables, Cell cell, NodeVec& nodes)
{
    if (useBasicTables)
    {
        StringVec json_results;
        PGDatabaseConnector_getDefaultInstance.getOSMNodeDataOnCell(cell, json_results);

        // Analyze json results
        nodes = RequestAnalyzer().getWayNodes(json_results);
    }
    else
    {
        // Get Json results by Overpass Api
        RequestLauncher request_launcher;
        QJsonArray json_results;
        try
        {
            LL centerLL = cell.getCellCenterLL();
            json_results = request_launcher.getWayNodes(centerLL.lat, centerLL.lon, Cell::SQUARE_CELL_SIZE * 100000); // Considering SLR2, SLR3, SLR7
        }
        catch (RequestLauncher::ConstException & e)
        {
            DefaultLogger << "Custom Exception occurred : " << e.getInternalException().what();
            DefaultLogger << "========== OSM Failed ==========";
            return FAILED; // SLR5
        }

        // Analyze json results
        nodes = RequestAnalyzer().getWayNodes(json_results);
    }

    // Output into json file
    ResultGenerator result_generator;

    result_generator.writeJsonParserOutput(nodes, OSMNodeSettingsOnPGDatabase_getDefaultInstance.getJsonPath());
    QByteArray json_str = result_generator.getJSONData(nodes);
    //DefaultLogger << json_str.data(); // Output to screen

    DefaultLogger << "========== OSM Succeeded ==========";
    return SUCCESS; // SLR1
}

}
