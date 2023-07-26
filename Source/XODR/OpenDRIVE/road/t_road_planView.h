#pragma once

#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/road/t_road_planView_geometry.h"
#include "XODR/OpenDRIVE/junction/e_contactPoint.h"

/*
    <xs:complexType name="t_road_planView">
        <xs:annotation>
            <xs:documentation>Contains geometry elements that define the layout of the road reference line in the x/y-plane (plan view).</xs:documentation>
        </xs:annotation>
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:sequence>
                    <xs:element name="geometry" type="t_road_planView_geometry" minOccurs="1" maxOccurs="unbounded"/>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:sequence>
            </xs:extension>
        </xs:complexContent>
    </xs:complexType>
*/

namespace _NOD
{

struct a_s_t;

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_road) \
    _UNIVERSIAL_TYPE_SEQUENCE(usingType, 1, x, t_road_planView_geometry, geometry) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_road_planView : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_DEFINE(t_road_planView)

public:
    template <typename T>
    double calcDistance(const T& xy) const
    {
        return _NMath::calcDistance(xy, geometry_sequence);
    }

    template <typename T>
    double calcDistance(const QVector<T> &points) const
    {
        return _NMath::calcDistance(geometry_sequence, points);
    }

    void calcST(const XY& xy, a_s_t& st) const;
    void calcXY(const a_s_t& st, XY& xy) const;

    template <typename T>
    void init(const QVector<T>& points)
    {
        if (points.size() < 2)
            return;

        geometry_sequence.clear();

        for (const T& pos : points)
        {
            // line
            t_road_planView_geometry od_geom;
            (XY&)od_geom = pos;
            //od_geom.hdg = pos.heading; // In radians

            geometry_sequence << od_geom;
        }

        for (int i = 0; i < geometry_sequence.size(); i ++)
        {
            t_road_planView_geometry& curGeom = geometry_sequence[i];

            if (i != 0)
            {
                t_road_planView_geometry& prevGeom = geometry_sequence[i - 1];
                curGeom.s = prevGeom.s + prevGeom.length;
            }
            else
            {
                curGeom.s = 0;
            }

            if (i != geometry_sequence.size() - 1)
            {
                t_road_planView_geometry& nextGeom = geometry_sequence[i + 1];

                XY delta = nextGeom - curGeom;
                curGeom.hdg = atan2(delta.y(), delta.x()); // In radians
                curGeom.length = ((a_xy_hdg&)curGeom).calcDistance(nextGeom);
            }
            else
            {
                t_road_planView_geometry& prevGeom = geometry_sequence[i - 1];
                curGeom.hdg = prevGeom.hdg;
                curGeom.length = 0;
            }
        }
    }

    void setTestData()
    {
        _OD_MEMBERS(SET_TEST_DATA, SEMICOLON)
    }

    void AddToGeoJsonTemplateData(QJsonArray& features, QJsonObject geomObject, QString tagName)
    {
        QJsonObject object;
        object["type"] = "Feature";
        object["geometry"] = geomObject;

        QJsonObject attrObj;
        attrObj["tag"] = tagName;
        attrObj["update_st"] = true;
        object["properties"] = attrObj;

        features.append(object);
    }

    void saveGeoJsonTemplateData(QString path, QJsonObject geomObject)
    {
        QJsonObject featureCollection;
        QJsonArray features;
        AddToGeoJsonTemplateData(features, geomObject, "t_road_planView");
        featureCollection["type"] = "FeatureCollection";
        featureCollection["features"] = features;
        QByteArray content = QJsonDocument(featureCollection).toJson();
        QString filePath = path + "/";
        filePath += "t_road_planView";
        filePath += ".geojson";
        QFile file(filePath);
        file.open(QIODevice::WriteOnly);
        file.write(content);
        file.close();
    }

    bool updateGeoJSONData(_GeoJSONData& geojsonData, bool& inserted)
    {
        preUpdateGeoJSONData(geojsonData, inserted);
        bool ret = updateGeoJSONData_Body(geojsonData, inserted);
        postUpdateGeoJSONData(geojsonData, inserted);
        return ret;
    }

    void preUpdateGeoJSONData(_GeoJSONData& geojsonData, bool& inserted)
    {
        Q_UNUSED(geojsonData);
        Q_UNUSED(inserted);
    }

    bool updateGeoJSONData_Body(_GeoJSONData& geojsonData, bool& inserted)
    {
        qDebug() << "t_road_planView" << "          : updateGeoJSONData_Body";
        if (geojsonData.tag == "t_road_planView")
        {
            if (geojsonData.operCommand != ""
                && geojsonData.operCommand != "general")
            {
                return updateGeoJSONData_NonGeneral(geojsonData, inserted);
            }
            if (updateGeoJSONData_Itself_Pre(geojsonData, inserted))
                return true;
            if (geojsonData.updateST)
                updateST(geojsonData.st);
            read(geojsonData.propsObj);
            inserted = false;
            return updateGeoJSONData_Itself_Post(geojsonData, inserted);
        }
        if (updateGeoJSONData_Children_Pre(geojsonData, inserted))
            return true;
        //_OD_MEMBERS(UPDATE_GEO_JSON_DATA_LINE, SEMICOLON)
        //_OD_MEMBERS(UPDATE_GEO_JSON_DATA_POINT, SEMICOLON)
        return updateGeoJSONData_Children_Post(geojsonData, inserted);
    }

    bool updateGeoJSONData_NonGeneral(_GeoJSONData& geojsonData, bool& inserted)
    {
        Q_UNUSED(geojsonData);
        Q_UNUSED(inserted);
        return false;
    }

    bool updateGeoJSONData_Itself_Pre(_GeoJSONData& geojsonData, bool& inserted)
    {
        Q_UNUSED(geojsonData);
        Q_UNUSED(inserted);
        return false;
    }

    bool updateGeoJSONData_Itself_Post(_GeoJSONData& geojsonData, bool& inserted)
    {
        Q_UNUSED(inserted);
        init(geojsonData.points);
        return true;
    }

    bool updateGeoJSONData_Children_Pre(_GeoJSONData& geojsonData, bool& inserted)
    {
        Q_UNUSED(geojsonData);
        Q_UNUSED(inserted);
        return false;
    }

    bool updateGeoJSONData_Children_Post(_GeoJSONData& geojsonData, bool& inserted)
    {
        Q_UNUSED(geojsonData);
        Q_UNUSED(inserted);
        return false;
    }

    void postUpdateGeoJSONData(_GeoJSONData& geojsonData, bool& inserted)
    {
        Q_UNUSED(geojsonData);
        Q_UNUSED(inserted);
    }

    inline const t_road_planView_geometry& getPoint(e_contactPoint at) const
    {
        if (at == e_contactPoint::START)
            return geometry_sequence.first();
        return geometry_sequence.last();
    }

    inline t_road_planView_geometry& getPoint(e_contactPoint at)
    {
        if (at == e_contactPoint::START)
            return geometry_sequence.first();
        return geometry_sequence.last();
    }

    inline const t_road_planView_geometry& getPoint(double s) const
    {
        for (const t_road_planView_geometry& geom : geometry_sequence)
        {
            if (s < geom.s + geom.length)
                return geom;
        }

        return geometry_sequence.last();
    }

    inline t_road_planView_geometry& getPoint(double s)
    {
        for (t_road_planView_geometry& geom : geometry_sequence)
        {
            if (s < geom.s + geom.length)
                return geom;
        }

        return geometry_sequence.last();
    }
};

}
