#ifndef __OCSM_FILEREADER_H__
#define __OCSM_FILEREADER_H__

#include <QFile>
#include "OCSM/MeasurementContent.h"
#include "OpenDRIVE/core/OpenDRIVE.h"

namespace OCSM
{

	/*
	 * 4.5 FileReader interfaces
	 * 	Template parameters: OutputType in MeasurementContent, OpenDRIVE::OpenDRIVE
	 *
	 * 4.5.1 I/O
	 * 	Input: Modules implementing FileReader shall be supplied with a file path.
	 * 	Output: Modules implementing FileReader shall output an object of the same type as the template parameter.
	 * 	FR-1: the FileReader shall read a 1le located a given path and convert its content to an instance of MeasurementContent or OpenDRIVE::OpenDRIVE depending on the template parameter.
	*/

	template <typename T>
	class FileReader
	{
	public:
        T Read(ConstQString& file_path, int point_count = INT_MAX);
	};

	template<>
	MeasurementContent FileReader<MeasurementContent>::Read(ConstQString& file_path, int point_count)
	{
		MyCout << "========== Reading data from csv file ==========" << MyEndl;

		MeasurementContent result;
		result.reserve(point_count);

		/* open csv file */
        QFile fin(file_path);
        if (!fin.open(QIODevice::ReadOnly))
			return result;

        QString line = QString::fromUtf8(fin.readLine());

        int gpsTowIndex = -1;
        int dateIndex = -1;
        int timeIndex = -1;
        int latIndex = -1;
        int lonIndex = -1;
        int sogIndex = -1;
        int rollIndex = -1;
        int pitchIndex = -1;
        int headingIndex = -1;
        int hdopIndex = -1;
        int ehpeIndex = -1;
        int evpeIndex = -1;
        QVector<QString> fieldNames = line.split(",").toVector();
        for (int i = 0; i < fieldNames.size(); i ++)
        {
            QString fieldName = fieldNames[i].trimmed();
            if (fieldName == "GPS TOW [s]")
                gpsTowIndex = i;
            else if (fieldName == "UTC Date")
                dateIndex = i;
            else if (fieldName == "UTC Time")
                timeIndex = i;
            else if (fieldName == "Lat [deg]")
                latIndex = i;
            else if (fieldName == "Lon [deg]")
                lonIndex = i;
            else if (fieldName == "SOG [m/s]")
                sogIndex = i;
            else if (fieldName == "Roll [deg]")
                rollIndex = i;
            else if (fieldName == "Pitch [deg]")
                pitchIndex = i;
            else if (fieldName == "Yaw [deg]")
                headingIndex = i;
            else if (fieldName == "HDOP")
                hdopIndex = i;
            else if (fieldName == "EHPE [m]")
                ehpeIndex = i;
            else if (fieldName == "EVPE [m]")
                evpeIndex = i;
        }

        Common::VehiclePos lastPos;

		/* read by one line */
        while (!fin.atEnd())
		{
            line = QString::fromUtf8(fin.readLine());
			line += ',';

			Common::VehiclePos pos;

			int field_index = 0;
            int prev_pos = 0;
            bool invalidRow = false;
			while (true)
			{
                int cur_pos = line.indexOf(',', prev_pos);
                if (cur_pos == -1)
					break;

                QString value = line.mid(prev_pos, cur_pos - prev_pos);
                if (field_index == gpsTowIndex)
                {
                    if (!value.isEmpty())
                        pos.gpsTow = value.toDouble();
                }
                else if (field_index == dateIndex)
				{
                    if (value.isEmpty())
                    {
                        pos.date = lastPos.date;
                    }
                    else
                    {
                        pos.date = value;
                    }
				}
                else if (field_index == timeIndex)
				{
                    if (value.isEmpty())
                    {
                        pos.time = lastPos.time;
                    }
                    else
                    {
                        pos.time = value;
                    }
				}
                else if (field_index == latIndex)
				{
                    if (value.isEmpty())
                    {
                        invalidRow = true;
                        break;
                    }
                    pos.coord.lat = value.toDouble(); // In degrees
				}
                else if (field_index == lonIndex)
				{
                    if (value.isEmpty())
                    {
                        invalidRow = true;
                        break;
                    }
                    pos.coord.lon = value.toDouble(); // In degrees
				}
                else if (field_index == sogIndex)
				{
					if (!value.isEmpty())
                        pos.sog = value.toDouble();
				}
                else if (field_index == rollIndex)
				{
					if (value.isEmpty())
					{
                        pos.roll = lastPos.roll;
					}
					else
					{
                        pos.roll = DEG_TO_RAD(value.toDouble()); // To radians
					}
				}
                else if (field_index == pitchIndex)
				{
                    if (value.isEmpty())
                    {
                        pos.pitch = lastPos.pitch;
                    }
                    else
                    {
                        pos.pitch = DEG_TO_RAD(value.toDouble()); // To radians
                    }
				}
                else if (field_index == headingIndex)
				{
                    if (value.isEmpty())
                    {
                        pos.heading = lastPos.heading;
                    }
                    else
                    {
                        pos.heading = DEG_TO_RAD(value.toDouble()); // To radians
                    }
				}
                else if (field_index == hdopIndex)
				{
                    if (value.isEmpty())
                    {
                        pos.hdop = lastPos.hdop;
                    }
                    else
                    {
                        pos.hdop = value.toDouble();
                    }
				}
                else if (field_index == ehpeIndex)
				{
                    if (value.isEmpty())
                    {
                        pos.ehpe = lastPos.ehpe;
                    }
                    else
                    {
                        pos.ehpe = value.toDouble();
                    }
				}
                else if (field_index == evpeIndex)
				{
                    if (value.isEmpty())
                    {
                        pos.evpe = lastPos.evpe;
                    }
                    else
                    {
                        pos.evpe = value.toDouble();
                    }
				}

				field_index++;
				prev_pos = cur_pos + 1;
			}

            if (invalidRow)
                continue;

            if (!result.isEmpty() && pos.date == result.last().date && pos.time == result.last().time)
                result.last() = pos;
            else
                result.push_back(pos);

            if (result.size() > point_count) // not >=
				break;

            lastPos = pos;
		}

        // check if size() = point_count + 1
        if (result.size() >= point_count)
            result.resize(point_count);

        for (int i = 0; i < result.size(); i ++)
        {
            result[i].UpdateDerivedProps();
            if (i != 0)
                result[i].UpdateAccelFromPrev(result[i - 1]);
        }

        if (result.size() > 1)
            result.front().UpdateAccelFromNext(result[1]);

		return result;
	}

	template<>
    OpenDRIVE::OpenDRIVE FileReader<OpenDRIVE::OpenDRIVE>::Read(ConstQString& file_path, int point_count)
	{
        Q_UNUSED(point_count)
        OpenDRIVE::OpenDRIVE result;
        result.read(file_path);
        return result;
	}
}

#endif // __OCSM_FILEREADER_H__

