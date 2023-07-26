/*
 * This file is part of OSM module and header of RequestLauncher submodule.
 * Developed for the OpenStreet Data Management System.
 * The RequestLauncher submodule shall be supplied with a Request.
 * The RequestLauncher submodule shall output an array of JSON objects.
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

#include "OSM/Main/RequestStatus.h"

namespace _NOSM
{

/*
    *======================================================================
    * NOTE & MODIFIED : Merged RoadPart, RoadInfo and LocalRoadDescription into Way
    *======================================================================
    *
    * Input: The RequestLauncher submodule shall be supplied with a Request.
    * Output: The RequestLauncher submodule shall output an array of JSON objects.
    *
    * System Level Requirements (SLR)
    * 1: The RequestLauncher shall compute how much subrequests will have to be launched over the OverpassAPI.
    * 2: The RequestLauncher shall store the number of subrequests
    * 3: The RequestLauncher shall compute a search area that is wide enough for the way to be likely
    * in the search area by taking into account the deviations between real vehicle position and GPS trace,
    * and realway position and OSM way position.
    * 4: The RequestLauncher shall establish connection with the OSM server through OverpassAPI.
    * 5: The RequestLauncher shall perform each required subrequest to the API.
    * 6: The RequestLauncher shall pass each subrequest answer provided by the OSM server to the JsonParser submodule.
    * 7: The RequestLauncher shall throw a custom Exception if an answer is not receive after a timeout.
    *
    * Relevant way information: Information such as coordinate, way type, country of location or anything related to the description of a way.
    * It is stored in the form of a JSON array.
    *
    *======================================================================
    * NOTE & MODIFIED : Merged RoadPart, RoadInfo and LocalRoadDescription into Way
    *======================================================================
    */
class RequestLauncher
{
public:
    // For SLR7
    class Exception : public std::exception
    {
    private:
        std::exception e;

    public:
        Exception(const std::exception& e)
        {
            this->e = e;
        }

        inline const std::exception& getInternalException() const
        {
            return this->e;
        }
    };

    typedef const Exception ConstException;

private:
    /* last request status */
    RequestStatus request_status; // for external reference

public:
    RequestLauncher()
    {
        this->request_status = SUCCESS;
    }

    /* last request status */
    inline RequestStatus getRequestStatus()
    {
        return this->request_status;
    }

    /* result output of RequestLauncher submodule */
    QJsonArray getNearestRoadsForPath(VehiclePosVec poses); // throw Exception // SLR7
    QJsonArray getNearestRoadsForPath(double lat, double lon, double bufferDistance); // throw Exception // SLR7
    QJsonArray getWayNodes(double lat, double lon, double bufferDistance);
};

}

