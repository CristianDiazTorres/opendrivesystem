#include "Common/VehiclePos.h"
#include "Common/UTM.h"
#include <time.h>

namespace Common
{

	void VehiclePos::UpdateDerivedProps()
	{
        if (!this->date.isEmpty() && !this->time.isEmpty())
        {
            tm tm;
            memset(&tm, 0, sizeof(tm));

            tm.tm_year = this->date.mid(0, 4).toInt() - 1900;
            tm.tm_mon = this->date.mid(5, 2).toInt() - 1;
            tm.tm_mday = this->date.mid(8, 2).toInt();

            tm.tm_hour = this->time.mid(0, 2).toInt();
            tm.tm_min = this->time.mid(3, 2).toInt();
            tm.tm_sec = this->time.mid(6, 2).toInt();
            int ms = this->time.mid(9, 3).toInt();

            tm.tm_isdst = -1;

            this->time_seconds = mktime(&tm) + ms / 1000.0;
        }

        // Degrees to meters
		this->zone = LatLonToUTMXY(this->coord.lat, this->coord.lon, 0, this->x, this->y);
        this->vx = this->sog * cos(this->heading); // heading : In radians
        this->vy = this->sog * sin(this->heading); // heading : In radians

		// Grid
		this->grid_row = (int)(this->y / SQUARE_GRID_AREA_SIZE);
		this->grid_col = (int)(this->x / SQUARE_GRID_AREA_SIZE);
	}

	void VehiclePos::SetFromPredictedPos(CONST VehiclePos& pos, double x, double y, double vx, double vy)
	{
		*this = pos;

        double nlat, nlon; // In degrees
		UTMXYToLatLon(x, y, pos.zone, false, nlat, nlon);
        double dnlat = pos.coord.lat - nlat; // In degrees
        double dnlon = pos.coord.lon - nlon; // In degrees
		double dn = sqrt(dnlat * dnlat + dnlon * dnlon);

        double slat, slon; // In degrees
		UTMXYToLatLon(x, y, pos.zone, true, slat, slon);
        double dslat = pos.coord.lat - slat; // In degrees
        double dslon = pos.coord.lon - slon; // In degrees
		double ds = sqrt(dslat * dslat + dslon * dslon);

		if (dn < ds)
		{
            this->coord.lat = nlat; // In degrees
            this->coord.lon = nlon; // In degrees
		}
		else
		{
            this->coord.lat = slat; // In degrees
            this->coord.lon = slon; // In degrees
		}

		this->sog = sqrt(vx * vx + vy * vy);
        this->heading = atan2(vy, vx); // heading : In radians
		this->x = x;
		this->y = y;
		this->vx = vx;
		this->vy = vy;

		// Recalculate x, y, zone, grid
        // Degrees to meters
		this->zone = LatLonToUTMXY(this->coord.lat, this->coord.lon, 0, this->x, this->y);
		this->grid_row = (int)(this->y / SQUARE_GRID_AREA_SIZE);
		this->grid_col = (int)(this->x / SQUARE_GRID_AREA_SIZE);
	}

}
