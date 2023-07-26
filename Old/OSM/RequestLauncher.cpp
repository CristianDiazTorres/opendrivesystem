/*
 * This file is part of OSM module and implemention of RequestLauncher submodule.
 *
 * Developed for the OpenStreet Data Management System.
 *
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

#include "OSM/RequestLauncher.h"
#include "OSM/OverpassAPI.h"

namespace _NOSM
{
JsonArray RequestLauncher::getNearestRoadsForPath(VehiclePosVec poses)
{
    JsonArray result;

    Debug << "Processing vehicle poses : " << poses.size();

    /* connecting to server and getting result */
    try
    {
        int maxPointCountInBatch = 1000;
        int batchCount = (poses.size() + maxPointCountInBatch - 1) / maxPointCountInBatch;

        for (int i = 0; i < batchCount; i ++)
        {
            VehiclePosVec batch = poses.mid(i * maxPointCountInBatch, maxPointCountInBatch);

            Debug << "Processing sub-request with " << batch.size() << " points ...";

            JsonValue json = OverpassAPI::GetWayData(ToLLVec(batch));

            if (json.toArray().isEmpty())
                Debug << "No ways";
            else
                Debug << json.toArray().size() << " ways";

            result.push_back(json); // Considering SLR3, SLR4, SLR5, SLR6
        }

        this->request_status = SUCCESS;
    }
    catch (const Exception & e)
    {
        Debug << "Connect failed" << ENDL;

        this->request_status = FAILED;

        throw Exception(e); // SLR7

        return result;
    }

    return result;
}

JsonArray RequestLauncher::getWayNodes(double lat, double lon, double areaSize)
{
    JsonArray result;

    Debug << "Getting way nodes : ";

    Debug << "Connecting...";

    /* connecting to server and getting result */
    try
    {
        JsonValue json = OverpassAPI::GetNodesData(lat, lon, areaSize);

        result = json.toArray();
        if (result.isEmpty())
            Debug << "No node" << ENDL;
        else
            Debug << json.toArray().size() << " nodes" << ENDL;

        this->request_status = SUCCESS;
    }
    catch (const Exception & e)
    {
        Debug << "Connect failed" << ENDL;

        this->request_status = FAILED;

        throw Exception(e); // SLR7

        return result;
    }

    return result;
}
}
