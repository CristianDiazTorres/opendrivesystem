/*
 * This file is part of OSMM module and header of ResultGenerator submodule.
 * Developed for the OpenStreet Data Management System.
 * This is submodule for complete OSMModuleRequestResult.
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


#include "OSMM/ResultGenerator.h"
#include <QFile>

#define JSON_PATH				"Results.json"

namespace OSMM
{

	/**
	* Complete result of OSM module request.
	*
	* @param values contain number of sub requests.
	* @return completed OSMModuleRequestResult object pointer.
	*
	* @exceptsafe This function does not throw exceptions.
	*/
    OSMModuleRequestResult ResultGenerator::Process(size_t sub_requests, RoadVec& roads)
	{
        Q_UNUSED(sub_requests);

        this->roads = roads;

		return Process();
	}
	OSMModuleRequestResult ResultGenerator::Process()
	{
		MyCout << "========== Generating OSMM result ==========" << MyEndl;

        OSMModuleRequestResult result;

        if (this->roads.isEmpty())
		{
            result.request_status = NOTFOUND;
		}
		else
		{
            result.request_status = SUCCESS;
		}

        result.roads = this->roads;

        return result;
	}

	/* append result */
    void ResultGenerator::Append(Road& road)
	{
        this->roads.push_back(road);
	};

	/* output with JSON format */
	void ResultGenerator::JsonParserOutput()
	{
        QFile file(JSON_PATH);
        file.open(QIODevice::WriteOnly);
        file.write(GetJSONData());
	};

    QByteArray ResultGenerator::GetJSONData()
	{
        QJsonDocument doc(Common::ToQJsonArrayOfObject(this->roads));
        return doc.toJson(QJsonDocument::Indented);
	}

	/**
	* Search lane properties and add it on OSMModuleRequestResult.
	*
	* @param value contain OSMModuleRequestResult object pointer.
	* @return OSMModuleRequestResult object pointer .
	*
	* @exceptsafe This function does not throw exceptions.
	*/
	/*
	OSMModuleRequestResult& Output1(OSMModuleRequestResult& res)
	{
		int k_id = 0;

        RoadVec& roads = res.roads;

        for (int j = 0; j < res.roads.size(); j++)
		{
            if (j > 0 && j < res.roads.size() - 1)
			{

                for (size_t k = 0; k < roads[j].lane_sections[0].lanes.size(); k++)
				{
                    for (size_t m = 0; m < roads[j - 1].lane_sections[0].lanes.size(); m++)
					{
                        if (roads[j].lane_sections[0].lanes[k].driving_direction ==
                            roads[j - 1].lane_sections[0].lanes[m].driving_direction)
						{
                            roads[j].lane_sections[0].lanes[m].previous_id = roads[j - 1].lane_sections[0].lanes[m].id;
						}
					}
				}

                for (size_t k = 0; k < roads[j].lane_sections[0].lanes.size(); k++)
				{
                    for (size_t m = 0; m < roads[j + 1].lane_sections[0].lanes.size(); m++)
					{
                        if (roads[j].lane_sections[0].lanes[k].driving_direction ==
                            roads[j + 1].lane_sections[0].lanes[m].driving_direction)
						{
                            roads[j].lane_sections[0].lanes[m].next_id = roads[j + 1].lane_sections[0].lanes[m].id;
						}
					}
				}
			}
		}

		return res;
	}
	*/

}
