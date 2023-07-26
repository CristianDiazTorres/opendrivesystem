#ifndef __COMMON_VEHICLEPOS_H__
#define __COMMON_VEHICLEPOS_H__

#include "Common/LatLon.h"
#include <math.h>

#define SQUARE_GRID_AREA_SIZE		5

namespace Common
{

	struct VehiclePos
	{
        double gpsTow;
		QString date;
		QString time;
		LatLon coord;
		double sog;
        double roll; // In radians
        double pitch; // In radians
        double heading; // In radians
		double hdop;
		double ehpe;
		double evpe;

		// Derived properties
		double time_seconds;
		int zone;
		double x;
		double y;
        double length;
		double vx;
		double vy;
		double ax;
		double ay;
		int grid_row;
		int grid_col;

	public:
		VehiclePos()
		{
            gpsTow = 0;
            coord.lat = 0;
            coord.lon = 0;
			sog = 0;
            roll = 0;
            pitch = 0;
            heading = 0;
			hdop = 0;
			ehpe = 0;
			evpe = 0;

            time_seconds = 0;
            zone = 0;
            x = 0;
            y = 0;
            length = 0;
            vx = 0;
            vy = 0;
            ax = 0;
            ay = 0;
            grid_row = 0;
            grid_col = 0;
		}

		inline bool IsSameGrid(CONST VehiclePos& other) CONST
		{
			return this->zone == other.zone &&
				this->grid_row == other.grid_row &&
				this->grid_col == other.grid_col;
		}

		inline double GetDistance(CONST VehiclePos& other) CONST
		{
			double dx = this->x - other.x;
			double dy = this->y - other.y;
			return sqrt(dx * dx + dy * dy);
		}

        inline QJsonArray ToQJsonArray() const
		{
			QJsonArray arr;
            arr.push_back(this->gpsTow);
            arr.push_back(this->date);
            arr.push_back(this->time);
            arr.push_back(this->coord.lat);
            arr.push_back(this->coord.lon);
            arr.push_back(this->sog);
            arr.push_back(this->roll);
            arr.push_back(this->pitch);
            arr.push_back(this->heading);
            arr.push_back(this->hdop);
            arr.push_back(this->ehpe);
            arr.push_back(this->evpe);
            arr.push_back(this->x);
            arr.push_back(this->y);
            arr.push_back(this->length);
            return arr;
		}

        inline QJsonObject ToQJsonObject() const
		{
			QJsonObject obj;
            obj["gpsTow"] = this->gpsTow;
            obj["date"] = this->date;
            obj["time"] = this->time;
			obj["coord"] = this->coord.ToQJsonObject();
            obj["sog"] = this->sog;
            obj["roll"] = this->roll;
            obj["pitch"] = this->pitch;
            obj["heading"] = this->heading;
            obj["hdop"] = this->hdop;
            obj["ehpe"] = this->ehpe;
            obj["evpe"] = this->evpe;
            obj["x"] = this->x;
            obj["y"] = this->y;
            obj["length"] = this->length;
            return obj;
		}

        inline operator QJsonArray() const
        {
            return ToQJsonArray();
        }

        inline operator QJsonObject() const
        {
            return ToQJsonObject();
        }

		void UpdateDerivedProps();

        inline void UpdateLengthFromNext(CONST VehiclePos& next)
        {
            this->length = GetDistance(next);
        }

		inline void UpdateAccelFromPrev(CONST VehiclePos& prev)
		{
			double dt = this->time_seconds - prev.time_seconds;
			this->ax = (this->vx - prev.vx) / dt;
			this->ay = (this->vy - prev.vy) / dt;
		}

		inline void UpdateAccelFromNext(CONST VehiclePos& next)
		{
			this->ax = next.ax;
			this->ay = next.ay;
		}

		void SetFromPredictedPos(CONST VehiclePos& pos, double x, double y, double vx, double vy);
	};

	typedef CONST VehiclePos			ConstVehiclePos;
	typedef QVector<VehiclePos>		VehiclePosVec;
	typedef CONST VehiclePosVec			ConstVehiclePosVec;
	typedef QVector<VehiclePosVec>		VehiclePosVecVec;

	inline LatLonVec ToLatLonVec(ConstVehiclePosVec& poses)
	{
		LatLonVec result(poses.size());
		for (int i = 0; i < poses.size(); i++)
			result[i] = poses[i].coord;
		return result;
	}

}

#endif // __COMMON_VEHICLEPOS_H__
