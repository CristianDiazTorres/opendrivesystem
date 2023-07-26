#pragma once

#include "XODR/Main/MeasurementContent.h"
#include "Math/Math.h"
#include "XODR/OpenDRIVE/core/OpenDRIVE.h"
#include "Debugger/Main/Logger.h"

namespace _NXODR
{

/*
 * 4.5 FileReader interfaces
 * 	Template parameters: OutputType in MeasurementContent, _NOD::OpenDRIVE
 *
 * 4.5.1 I/O
 * 	Input: Modules implementing FileReader shall be supplied with a file path.
 * 	Output: Modules implementing FileReader shall output an object of the same type as the template parameter.
 * 	FR-1: the FileReader shall read a 1le located a given path and convert its content to an instance of MeasurementContent or _NOD::OpenDRIVE depending on the template parameter.
*/

template <typename T>
class FileReader
{
public:
    T read(const QString& filePath, int start = 0, int lineCount = INT_MAX);
};

template<>
inline MeasurementContent FileReader<MeasurementContent>::read(const QString& filePath, int start, int lineCount)
{
    Q_UNUSED(lineCount);

    DefaultLogger << "========== Reading data from csv file ==========";

    MeasurementContent result;
    //if (lineCount <= 0)
    //    return result;

    result.reserve(10000);
    //result.reserve(lineCount);

    /* open csv file */
    QFile fin(filePath);
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
    StringVec fieldNames = line.split(",").toVector();
    for (int i = 0; i < fieldNames.size(); i ++)
    {
        QString fieldName = fieldNames[i].trimmed();
        if (fieldName == _SC_GPS_TOW__s__A)
            gpsTowIndex = i;
        else if (fieldName == _SC_UTC_Date_A)
            dateIndex = i;
        else if (fieldName == _SC_UTC_Time_A)
            timeIndex = i;
        else if (fieldName == _SC_Lat__deg__A)
            latIndex = i;
        else if (fieldName == _SC_Lon__deg__A)
            lonIndex = i;
        else if (fieldName == _SC_SOG__m_s__A)
            sogIndex = i;
        else if (fieldName == _SC_Roll__deg__A)
            rollIndex = i;
        else if (fieldName == _SC_Pitch__deg__A)
            pitchIndex = i;
        else if (fieldName == _SC_Yaw__deg__A)
            headingIndex = i;
        else if (fieldName == _SC_HDOP)
            hdopIndex = i;
        else if (fieldName == _SC_EHPE__m__A)
            ehpeIndex = i;
        else if (fieldName == _SC_EVPE__m__A)
            evpeIndex = i;
    }

    VehiclePos lastPos;

    // skip lines
    if (false)
    {
        DefaultLogger << "Skipping Lines : " << start;
        for (int i = 0; i < start; i ++)
            fin.readLine();
    }

    int readLineCount = 0;

    /* read by one line */
    while (!fin.atEnd()/* && readLineCount < lineCount*/)
    {
        line = QString::fromUtf8(fin.readLine());
        readLineCount ++;
        line += ',';

        VehiclePos pos;

        int fieldIndex = 0;
        int prevPos = 0;
        bool invalidRow = false;
        while (true)
        {
            int curPos = line.indexOf(',', prevPos);
            if (curPos == -1)
                break;

            QString value = line.mid(prevPos, curPos - prevPos);
            if (fieldIndex == gpsTowIndex)
            {
                if (!value.isEmpty())
                    pos.gpsTow = value.toDouble();
            }
            else if (fieldIndex == dateIndex)
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
            else if (fieldIndex == timeIndex)
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
            else if (fieldIndex == latIndex)
            {
                if (value.isEmpty())
                {
                    invalidRow = true;
                    break;
                }
                pos.lat = value.toDouble(); // In degrees
            }
            else if (fieldIndex == lonIndex)
            {
                if (value.isEmpty())
                {
                    invalidRow = true;
                    break;
                }
                pos.lon = value.toDouble(); // In degrees
            }
            else if (fieldIndex == sogIndex)
            {
                if (!value.isEmpty())
                    pos.sog = value.toDouble();
            }
            else if (fieldIndex == rollIndex)
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
            else if (fieldIndex == pitchIndex)
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
            else if (fieldIndex == headingIndex)
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
            else if (fieldIndex == hdopIndex)
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
            else if (fieldIndex == ehpeIndex)
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
            else if (fieldIndex == evpeIndex)
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

            fieldIndex++;
            prevPos = curPos + 1;
        }

        if (invalidRow)
            continue;

        if (!result.isEmpty() && pos.date == result.last().date && pos.time == result.last().time)
            result.last() = pos;
        else
            result.push_back(pos);

        lastPos = pos;
    }

    for (int i = 0; i < result.size(); i ++)
    {
        result[i].updateDerivedProps();
        if (i != 0)
            result[i].updateAccelFromPrev(result[i - 1]);
    }

    if (result.size() > 1)
        result.front().updateAccelFromNext(result[1]);

    DefaultLogger << "Read Lines : " << readLineCount;
    DefaultLogger << "Read Points : " << result.size();

    return result;
}

template<>
inline _NOD::OpenDRIVE FileReader<_NOD::OpenDRIVE>::read(const QString& filePath, int start, int lineCount)
{
    Q_UNUSED(start);
    Q_UNUSED(lineCount);
    _NOD::OpenDRIVE result;
    result.read(filePath);
    return result;
}

}

