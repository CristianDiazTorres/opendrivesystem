#include "XODR/OpenDRIVE/core/OpenDRIVE.h"
#include "Common/Main/File.h"

namespace _NOD
{

bool OpenDRIVE::read(const string& filePath)
{
    _file file(filePath);
    if (!file.open(_ioDevice::ReadOnly))
        return false;

    _byteArray buffer = file.readAll();
    file.close();

    //Read and load QFile
    _xodrDocument doc(filePath);
    bool loaded = doc.setContent(buffer);
    if (loaded)
    {
        _xodrElement rootNode = doc.firstChildElement(_SC_OpenDRIVE);
        read(rootNode);

        this->setParent();

        return true;
    }

    //failed to read the file
    DefaultLogger << "Could not read file: " << filePath;
    return false;
}

// TODO: ???
// attributes : xmlns="http://www.opendrive.org"
bool OpenDRIVE::write(const string& filePath, bool forceToWriteOptionalValues)
{
    // XML document
    _byteArray xmlContent;
    XmlStreamWriter xmlWriter(&xmlContent);

    xmlWriter.setAutoFormatting(true);
    xmlWriter.setAutoFormattingIndent(4);

    xmlWriter.writeStartDocument("1.0", _SC_yes);

    xmlWriter.writeStartElement(_SC_OpenDRIVE);
    write(xmlWriter, forceToWriteOptionalValues);
    xmlWriter.writeEndElement();

    xmlWriter.writeEndDocument();

    // Saves the XML structure to the file
    return _NCM::writeToFile(filePath, xmlContent);
}

void OpenDRIVE::readFromJson(QString json)
{
//    DefaultLogger << "json : " << json;

    QJsonDocument doc = QJsonDocument::fromJson(json.toUtf8());

    read(doc.object());

    this->setParent();
}

QString OpenDRIVE::writeToJson(bool forceToWriteOptionalValues)
{
    QJsonObject obj;
    write(obj, forceToWriteOptionalValues);

    return QString::fromUtf8(QJsonDocument(obj).toJson());
}

bool OpenDRIVE::writeToJson(const string& filePath, bool forceToWriteOptionalValues)
{
    return _NCM::writeToFile(filePath, writeToJson(forceToWriteOptionalValues));
}

// @incomplete
bool OpenDRIVE::setCurvatureSlope(const XY& pos, double curvature, double slope)
{
    double minDist = 0;
    int index = _NMath::getNearestIndex(pos, road_sequence, minDist);

    if (minDist > 1)
        return false;

    road_sequence[index].setCurvatureSlope(pos, curvature, slope);

    return true;
}

double OpenDRIVE::calcDistance(const LLCoordSysXYCellVec &points, QString tag) const
{
    if (tag.startsWith("t_road"))
        return calcDistance_road(points);

    if (tag.startsWith("t_junction"))
        return calcDistance_junction(points);

    return DOUBLE_MAX;
}

double OpenDRIVE::calcDistance(const LLCoordSysXYCell& point, QString tag) const
{
    if (tag.startsWith("t_road"))
        return calcDistance_road(point);

    if (tag.startsWith("t_junction"))
        return calcDistance_junction(point);

    return DOUBLE_MAX;
}

double OpenDRIVE::calcDistance_road(const LLCoordSysXYCellVec &points) const
{
    double minDist = 0;
    _NMath::getNearestIndex(points, road_sequence, minDist);
    return minDist;
}

double OpenDRIVE::calcDistance_road(const LLCoordSysXYCell& point) const
{
    double minDist = 0;
    _NMath::getNearestIndex(point, road_sequence, minDist);
    return minDist;
}

double OpenDRIVE::calcDistance_junction(const LLCoordSysXYCellVec &points) const
{
    double minDist = 0;
    _NMath::getNearestIndex(points, junction_sequence, *this, minDist);
    return minDist;
}

double OpenDRIVE::calcDistance_junction(const LLCoordSysXYCell& point) const
{
    double minDist = 0;
    _NMath::getNearestIndex(point, junction_sequence, *this, minDist);
    return minDist;
}

bool OpenDRIVE::updateGeoJSONData(_GeoJSONData& geojsonData, bool& inserted)
{
    if (geojsonData.tag.startsWith("t_road"))
        return updateGeoJSONData_road(geojsonData, inserted);

    if (geojsonData.tag.startsWith("t_junction"))
        return updateGeoJSONData_junction(geojsonData, inserted);

    return false;
}

bool OpenDRIVE::updateGeoJSONData_road(_GeoJSONData& geojsonData, bool& inserted)
{
    if (geojsonData.isLine)
    {
        double minDist = 0;
        int index = _NMath::getNearestIndex(geojsonData.points, road_sequence, minDist);

        if (minDist > 1)
        {
            road_sequence.resize(road_sequence.size() + 1);
            road_sequence.last().init(geojsonData.points);
            index = road_sequence.size() - 1;
        }

        bool ret = road_sequence[index].updateGeoJSONData(geojsonData, inserted);

        if (minDist > 1)
            inserted = true;

        return ret;
    }
    else
    {
        double minDist = 0;
        int index = _NMath::getNearestIndex(geojsonData.point, road_sequence, minDist);

        if (minDist > 20)
            return false;

        return road_sequence[index].updateGeoJSONData(geojsonData, inserted);
    }

}

bool OpenDRIVE::updateGeoJSONData_junction(_GeoJSONData& geojsonData, bool& inserted)
{
    if (geojsonData.isLine)
    {
        double minDist = 0;
        int index = _NMath::getNearestIndex(geojsonData.points, junction_sequence, *this, minDist);

        if (minDist > 20)
        {
            junction_sequence.resize(junction_sequence.size() + 1);
            index = junction_sequence.size() - 1;
        }

        bool ret = junction_sequence[index].updateGeoJSONData(geojsonData, inserted);

        if (minDist > 20)
            inserted = true;

        return ret;
    }
    else
    {
        double minDist = 0;
        int index = _NMath::getNearestIndex(geojsonData.point, junction_sequence, *this, minDist);

        if (minDist > 20)
            return false;

        return junction_sequence[index].updateGeoJSONData(geojsonData, inserted);
    }
}

}
