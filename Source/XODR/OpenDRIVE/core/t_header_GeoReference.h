#pragma once

#include "XODR/OpenDRIVE/core/g_additionalData.h"

/*
    <xs:complexType name="t_header_GeoReference" mixed="true">
        <xs:annotation>
            <xs:documentation>Spatial reference systems are standardized by the European Petroleum Survey Group Geodesy (EPSG) and are defined by parameters describing the geodetic datum. A geodetic datum is a coordinate reference system for a collection of positions that are relative to an ellipsoid model of the earth.
A geodetic datum is described by a projection string according to PROJ, that is, a format for the exchange of data between two coordinate systems. This data shall be marked as CDATA, because it may contain characters that interfere with the XML syntax of an element's attribute.
In OpenDRIVE, the information about the geographic reference of an OpenDRIVE dataset is represented by the &lt;geoReference&gt; element within the &lt;header&gt; element.</xs:documentation>
        </xs:annotation>
        <xs:sequence>
            <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
        </xs:sequence>
    </xs:complexType>
*/

/*
    <geoReference>
      <![CDATA[+proj=utm +zone=32 +ellps=GRS80 +towgs84=0,0,0,0,0,0,0 +units=m +no_defs]]>
    </geoReference>
*/

namespace _NOD
{

#undef _OD_MEMBERS
#define _OD_MEMBERS(usingType, lineEnd) \
    _UNIVERSIAL_TYPE_SCHEMA(sc_dt_od_core) \
    _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, string        , proj  , REQUIRED) lineEnd \
    _OD_G_ADDITIONAL_DATA(usingType) lineEnd \
    EMPTY_COMMAND

struct t_header_GeoReference : public _OpenDriveElement
{
public:
    _OD_MEMBERS(DECLARE, SEMICOLON)
    _UNIVERSIAL_TYPE_isCompatible_operatorEqualNotEqual_DEFINE(t_header_GeoReference)
    _UNIVERSIAL_TYPE_updateGeoJSONData_DEFINE(t_header_GeoReference)
    _UNIVERSIAL_TYPE_setParent_DEFINE(t_header_GeoReference)

public:
    _xodrStatus read(const _xodrElement& node)
    {
        _xodrStatus status = _xodrElement::SUCCEEDED;

        {
            _xodrNode subNode = node.firstChild();
            if (subNode.isCDATASection())
            {
                _xodrCDATASection cdataSection = subNode.toCDATASection();
                proj = cdataSection.data();
            }
        }

        _OD_G_ADDITIONAL_DATA_READ;

        return status;
    }

    void write(XmlStreamWriter& xmlWriter, bool forceToWriteOptionalValues = false)
    {
        Q_UNUSED(forceToWriteOptionalValues);

        xmlWriter.writeCDATA(proj);

        _OD_G_ADDITIONAL_DATA_WRITE;
    }

    void read(QJsonObject obj)
    {
        proj = obj["proj"].toString();
    }

    void write(QJsonObject& obj, bool forceToWriteOptionalValues = false)
    {
        Q_UNUSED(forceToWriteOptionalValues);
        obj["proj"] = proj;
    }

    void setTestData()
    {
        proj = CoordSys::getAusCoordSys().getProj4();
    }

    void AddToGeoJsonTemplateData(QJsonArray& features, QJsonObject geomObject, QString tagName)
    {
        Q_UNUSED(features);
        Q_UNUSED(geomObject);
        Q_UNUSED(tagName);
    }

    void saveGeoJsonTemplateData(QString path, QJsonObject geomObject)
    {
        Q_UNUSED(path);
        Q_UNUSED(geomObject);
    }
};

}

