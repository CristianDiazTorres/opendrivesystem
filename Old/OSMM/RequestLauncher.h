/*
 * This file is part of OSMM module and header of RequestLauncher submodule.
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

#ifndef __OSMM_REQUESTLAUNCHER_H__
#define __OSMM_REQUESTLAUNCHER_H__

#include "OSMM/OSMM.h"

namespace OSMM
{

    /*
    *======================================================================
    * NOTE & MODIFIED : Merged RoadPart, RoadInfo and LocalRoadDescription into Road
    *======================================================================
    *
    * Input: The RequestLauncher submodule shall be supplied with a Request.
    * Output: The RequestLauncher submodule shall output an array of JSON objects.
    *
    * System Level Requirements (SLR)
    * 1: The RequestLauncher shall compute how much subrequests will have to be launched over the Common::OverpassAPI.
    * 2: The RequestLauncher shall store the number of subrequests
    * 3: The RequestLauncher shall compute a search area that is wide enough for the road to be likely
    * in the search area by taking into account the deviations between real vehicle position and GPS trace,
    * and realroad position and OSM road position.
    * 4: The RequestLauncher shall establish connection with the OSM server through Common::OverpassAPI.
    * 5: The RequestLauncher shall perform each required subrequest to the API.
    * 6: The RequestLauncher shall pass each subrequest answer provided by the OSM server to the JsonParser submodule.
    * 7: The RequestLauncher shall throw a custom MyException if an answer is not receive after a timeout.
    *
    * Relevant road information: Information such as coordinate, road type, country of location or anything related to the description of a road.
    * It is stored in the form of a JSON array.
    *
    *======================================================================
    * NOTE & MODIFIED : Merged RoadPart, RoadInfo and LocalRoadDescription into Road
    *======================================================================
    */
    class RequestLauncher
    {
    public:
        // For SLR7
        class Exception : public MyException
        {
        private:
            MyException e;

        public:
            Exception(ConstMyException& e)
            {
                this->e = e;
            }

            inline ConstMyException& GetInternalException() CONST
            {
                return this->e;
            }
        };

        typedef CONST Exception ConstException;

    private:
        // TODO: need to be static ???
        int total_request_count; // SLR1
        int sub_requests; // SLR2

        /* last request status */
        RequestStatus request_status; // for external reference

    public:
        RequestLauncher()
        {
            this->total_request_count = 0;
            this->sub_requests = 0;
            this->request_status = SUCCESS;
        }

        inline size_t GetTotalRequestCount() // SLR1
        {
            return this->total_request_count;
        }

        inline size_t GetSubRequests() // SLR2
        {
            return this->sub_requests;
        }

        /* last request status */
        inline RequestStatus GetRequestStatus()
        {
            return this->request_status;
        }

        /* result output of RequestLauncher submodule */
        QJsonArray Process(Request request); // throw Exception // SLR7
        QJsonArray Process2(Request request); // throw Exception // SLR7
    };

}

#endif // __OSMM_REQUESTLAUNCHER_H__
