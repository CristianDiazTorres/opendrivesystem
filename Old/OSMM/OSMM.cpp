/*
 * This file is implemention part of OSMM module.
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

#include "OSMM/OSMM.h"
#include "OSMM/RequestLauncher.h"
#include "OSMM/RequestAnalyzer.h"
#include "OSMM/ResultGenerator.h"

namespace OSMM
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
    * NOTE & MODIFIED : Merged RoadPart, RoadInfo and LocalRoadDescription into Road
	*======================================================================
	*
	* The main method to communicate with the module is:
    *		OSMModuleRequestResult *getRoadDataForPath (Request request );
	*		This method performs a synchronous request and return a pointer to the output request structure.
	*
	* Functional System Level Requirements (SLR)
	*		1: When being provided with a Request, the OSMM shall return a OSMModuleRequestResult.
	*		2: The OSMM shall give result for GPS traces located in any country of the world.
	*		3: If a GPS trace does not perfectly matches a road trace recorded in the OSM database,
	*			the requestresult shall contain information about the closest plausible road trace.
	*		4: If no plausible road trace exist nearby the supplied GPS trace, the OSMM shall tag the result as NOTFOUND.
	*		5: If a connection problem with the OSM servers occur, or if the result from the OSM server is corrupted,
	*			the OSMM shall tag the result as FAILED.
	*		6: The module shall be able to process requests with up to 72 geocoordinates.
	*		7: The module shall be able to process requests with a single geocoordinate.
	*
	* General Architecture
	*		The Request is processed by the RequestLauncher.
	*		This module will process n singlesubrequests with the Common::OverpassAPI.
	*		Each of the single subrequest result from the Common::OverpassAPI will beprocessed by a JsonParser module
	*			that will extract relevant information.
	*		Each of these extractions willbe passed to a RequestAnalyzer that will build a consistent local road description.
	*		The RequestAnalyzer will use the PriorKnowledgeProvider, to enrich and or fill gaps in the data.
	*		Each of the local roaddescriptions will be supplied to the ResultGenerator,
	*			that will build a consistent result along thegeodetic path supplied in the request.
	*
	*======================================================================
    * NOTE & MODIFIED : Merged RoadPart, RoadInfo and LocalRoadDescription into Road
	*======================================================================
	*/
	OSMModuleRequestResult getRoadDataForPath(Request request)
	{
		if (request.poses.size() > OSMM_MAX_POINTS_COUNT) // SLR6
			request.poses.resize(OSMM_MAX_POINTS_COUNT);

		size_t sub_requests = request.poses.size();

		// Get Json results by Overpass Api
		RequestLauncher request_launcher;
		QJsonArray json_results;
		try
		{
			json_results = request_launcher.Process(request); // Considering SLR2, SLR3, SLR7
		}
		catch (RequestLauncher::ConstException & e)
		{
			MyCout << "Custom Exception occurred : " << e.GetInternalException().what() << MyEndl;
			MyCout << "========== OSMM Failed ==========" << MyEndl;
			return OSMModuleRequestResult(FAILED); // SLR5
		}

		// Check again
		if (request_launcher.GetRequestStatus() == FAILED)
		{
			MyCout << "========== OSMM Failed ==========" << MyEndl;
			return OSMModuleRequestResult(FAILED); // SLR5
		}

		if (json_results.isEmpty())
		{
			MyCout << "========== OSMM Not found ==========" << MyEndl;
			return OSMModuleRequestResult(NOTFOUND); // SLR4
		}

		// Analyze json results
		RoadVec roads = RequestAnalyzer().Process(request, json_results);

		// Generate OSMModuleRequestResult
		ResultGenerator result_generator;
		OSMModuleRequestResult result = result_generator.Process(sub_requests, roads);

		// Output into json file
        result_generator.JsonParserOutput();
        QByteArray json_str = result_generator.GetJSONData();
        qDebug() << json_str.data(); // Output to screen

		MyCout << "========== OSMM Succeeded ==========" << MyEndl;
		return result; // SLR1
	}

	OSMModuleRequestResult getRoadDataForPath2(Request request)
	{
		if (request.poses.size() > OSMM_MAX_POINTS_COUNT) // SLR6
			request.poses.resize(OSMM_MAX_POINTS_COUNT);

		size_t sub_requests = request.poses.size();

		// Get Json results by Overpass Api
		RequestLauncher request_launcher;
		QJsonArray json_results;
		try
		{
			json_results = request_launcher.Process2(request); // Considering SLR2, SLR3, SLR7
		}
		catch (RequestLauncher::ConstException & e)
		{
			MyCout << "Custom Exception occurred : " << e.GetInternalException().what() << MyEndl;
			MyCout << "========== OSMM Failed ==========" << MyEndl;
			return OSMModuleRequestResult(FAILED); // SLR5
		}

		// Check again
		if (request_launcher.GetRequestStatus() == FAILED)
		{
			MyCout << "========== OSMM Failed ==========" << MyEndl;
			return OSMModuleRequestResult(FAILED); // SLR5
		}

		if (json_results.isEmpty())
		{
			MyCout << "========== OSMM Not found ==========" << MyEndl;
			return OSMModuleRequestResult(NOTFOUND); // SLR4
		}

		// Analyze json results
		RoadVec roads = RequestAnalyzer().Process2(request, json_results);

		// Generate OSMModuleRequestResult
		ResultGenerator result_generator;
		OSMModuleRequestResult result = result_generator.Process(sub_requests, roads);

		// Output into json file
		result_generator.JsonParserOutput();
        QByteArray json_str = result_generator.GetJSONData();
        qDebug() << json_str.data(); // Output to screen

		MyCout << "========== OSMM Succeeded ==========" << MyEndl;
		return result; // SLR1
	}
}
