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

#include "OSM/Main/RequestLauncher.h"
#include "OSM/Main/OverpassAPI.h"
#include "GeoCoordinate/Main/VehiclePos.h"

namespace _NOSM
{

QJsonArray RequestLauncher::getNearestRoadsForPath(VehiclePosVec poses)
{
    QJsonArray result;

    DefaultLogger_File << "Processing vehicle poses : " << poses.size();

    /* connecting to server and getting result */
    try
    {
        int maxPointCountInBatch = 1000;
        int batchCount = (poses.size() + maxPointCountInBatch - 1) / maxPointCountInBatch;

        for (int i = 0; i < batchCount; i ++)
        {
            VehiclePosVec batch = poses.mid(i * maxPointCountInBatch, maxPointCountInBatch);

            DefaultLogger_File << "Processing sub-request with " << batch.size() << " points ...";

            QJsonValue json = OverpassAPI::getWaysData(_NCM::convertVectorElementType<LL>(batch));

            if (json.toArray().isEmpty())
                DefaultLogger_File << "No ways";
            else
                DefaultLogger_File << json.toArray().size() << " ways";

            result.push_back(json); // Considering SLR3, SLR4, SLR5, SLR6
        }

        this->request_status = SUCCESS;
    }
    catch (const Exception & e)
    {
        DefaultLogger_File << "Connect failed";

        this->request_status = FAILED;

        throw Exception(e); // SLR7

        return result;
    }

    return result;
}

QJsonArray RequestLauncher::getNearestRoadsForPath(double lat, double lon, double bufferDistance)
{
    QJsonArray result;

    /* connecting to server and getting result */
    try
    {
        QJsonValue json = OverpassAPI::getWaysData(lat, lon, bufferDistance);

        if (json.toArray().isEmpty())
            DefaultLogger_File << "No ways";
        else
            DefaultLogger_File << json.toArray().size() << " ways";

        result.push_back(json); // Considering SLR3, SLR4, SLR5, SLR6

        this->request_status = SUCCESS;
    }
    catch (const Exception & e)
    {
        DefaultLogger_File << "Connect failed";

        this->request_status = FAILED;

        throw Exception(e); // SLR7

        return result;
    }

    return result;
}

QJsonArray RequestLauncher::getWayNodes(double lat, double lon, double bufferDistance)
{
    QJsonArray result;

    DefaultLogger_File << "Getting way nodes : ";

    DefaultLogger_File << "Connecting...";

    /* connecting to server and getting result */
    try
    {
        QJsonValue json = OverpassAPI::getNodesData(lat, lon, bufferDistance);

        result = json.toArray();
        if (result.isEmpty())
            DefaultLogger_File << "No node";
        else
            DefaultLogger_File << json.toArray().size() << " nodes";

        this->request_status = SUCCESS;
    }
    catch (const Exception & e)
    {
        DefaultLogger_File << "Connect failed";

        this->request_status = FAILED;

        throw Exception(e); // SLR7

        return result;
    }

    return result;
}
}
