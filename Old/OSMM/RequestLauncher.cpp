/*
 * This file is part of OSMM module and implemention of RequestLauncher submodule.
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

#include "OSMM/RequestLauncher.h"
#include "Common/OverpassAPI.h"

namespace OSMM
{

	/**
	* Process a request.
	*
	* @param request Request.
	* @return JSON result array.
	*
	* @except This function throw Exception.
	*/
	QJsonArray RequestLauncher::Process(Request request)
	{
		this->sub_requests = request.poses.size();

        QJsonArray result;

		MyCout << "========== " << this->sub_requests << " sub request(s) are processed ==========" << MyEndl;

        for (int i = 0; i < this->sub_requests; ++i)
		{
			Common::ConstVehiclePos& pos = request.poses[i];
			Common::ConstLatLon& coord = pos.coord;

			MyCout << "Proceeding vehicle pos : " << i
                << " lat " << QString::number(coord.lat, 'f', 10)
                << " lon " << QString::number(coord.lon, 'f', 10)
                << " heading " << QString::number(pos.heading, 'f', 10);

            MyCout << "Connecting...";

			/* connecting to server and getting result */
			try
			{
                QJsonValue json = Common::OverpassAPI::GetWayData(coord);

                if (json.toArray().isEmpty())
					MyCout << "No ways" << MyEndl;
				else
                    MyCout << json.toArray().size() << " ways" << MyEndl;

				result.push_back(json); // Considering SLR3, SLR4, SLR5, SLR6

				this->request_status = SUCCESS;

				this->total_request_count++;
			}
			catch (ConstMyException & e)
			{
				MyCout << "Connect failed" << MyEndl;

				this->request_status = FAILED;

				throw Exception(e); // SLR7

				return result;
			}
		}

		return result;
	}

	QJsonArray RequestLauncher::Process2(Request request)
	{
		this->sub_requests = 1;

        QJsonArray result;

		MyCout << "========== " << this->sub_requests << " sub request(s) are processed ==========" << MyEndl;

        MyCout << "Proceeding vehicle poses : " << request.poses.size();

        MyCout << "Connecting...";

		/* connecting to server and getting result */
		try
		{
            QJsonValue json = Common::OverpassAPI::GetWayData(ToLatLonVec(request.poses));

            if (json.toArray().isEmpty())
				MyCout << "No ways" << MyEndl;
			else
                MyCout << json.toArray().size() << " ways" << MyEndl;

			result.push_back(json); // Considering SLR3, SLR4, SLR5, SLR6

			this->request_status = SUCCESS;

			this->total_request_count++;
		}
		catch (ConstMyException & e)
		{
			MyCout << "Connect failed" << MyEndl;

			this->request_status = FAILED;

			throw Exception(e); // SLR7

			return result;
		}

		return result;
	}

}
