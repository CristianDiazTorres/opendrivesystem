#pragma once


#include "XODR/OpenDRIVE/core/a_xy_hdg.h"
#include "XODR/OpenDRIVE/core/g_additionalData.h"
#include "XODR/OpenDRIVE/road/t_road_planView_geometry_line.h"
#include "XODR/OpenDRIVE/road/t_road_planView_geometry_spiral.h"
#include "XODR/OpenDRIVE/road/t_road_planView_geometry_arc.h"
#include "XODR/OpenDRIVE/road/t_road_planView_geometry_poly3.h"
#include "XODR/OpenDRIVE/road/t_road_planView_geometry_paramPoly3.h"

/*
    <xs:complexType name="t_road_planView_geometry">
        <xs:complexContent>
            <xs:extension base="_OpenDriveElement">
                <xs:choice>
                    <xs:element name="line" type="t_road_planView_geometry_line" minOccurs="1" maxOccurs="1"/>
                    <xs:element name="spiral" type="t_road_planView_geometry_spiral" minOccurs="1" maxOccurs="1"/>
                    <xs:element name="arc" type="t_road_planView_geometry_arc" minOccurs="1" maxOccurs="1"/>
                    <xs:element name="poly3" type="t_road_planView_geometry_poly3" minOccurs="1" maxOccurs="1"/>
                    <xs:element name="paramPoly3" type="t_road_planView_geometry_paramPoly3" minOccurs="1" maxOccurs="1"/>
                    <xs:group ref="g_additionalData" minOccurs="0" maxOccurs="unbounded"/>
                </xs:choice>
                <xs:attribute name="s" use="required" type="t_grEqZero">
                    <xs:annotation>
                        <xs:documentation>s-coordinate of start position</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="x" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Start position (x inertial)</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="y" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Start position (y inertial)</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="hdg" use="required" type="xs:double">
                    <xs:annotation>
                        <xs:documentation>Start orientation (inertial heading)</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
                <xs:attribute name="length" use="required" type="xs:string">
                    <xs:annotation>
                        <xs:documentation>Length of the element's reference line</xs:documentation>
                    </xs:annotation>
                </xs:attribute>
            </xs:extension>
        </xs:complexContent>
    </xs:complexType>
*/

namespace _NOD
{
enum _e_geometry_type
{
    _OD_GEOM_LINE,
    _OD_GEOM_SPIRAL,
    _OD_GEOM_ARC,
    _OD_GEOM_POLY3,
    _OD_GEOM_PARAMPOLY3
};

struct t_road_planView_geometry : public a_s, public a_xy_hdg
{
    // Table 5. Attributes of the planView element

    //t_grEqZero s;
    //double x;
    //double y;
    //double hdg;
    double length; // string length;

    _OD_G_ADDITIONAL_DATA_DECLARE;

    // Non-Attribute
    _e_geometry_type type;
    void* parent;

    t_road_planView_geometry_line line;
    t_road_planView_geometry_spiral spiral;
    t_road_planView_geometry_arc arc;
    t_road_planView_geometry_poly3 poly3;
    t_road_planView_geometry_paramPoly3 paramPoly3;

    _UNIVERSIAL_TYPE_empty_POS_DEFINE(t_road_planView_geometry)

public:
    t_road_planView_geometry(_e_geometry_type type_ = _OD_GEOM_LINE)
        : a_s()
        , a_xy_hdg()
        , length()
        , additionalData()
        , type(type_)
    {
    }

    t_road_planView_geometry(const t_road_planView_geometry& other)
        : a_s(other)
        , a_xy_hdg(other)
        , length(other.length)
        , additionalData(other.additionalData)
        , type(other.type)
    {
        switch (this->type)
        {
        case _OD_GEOM_LINE:
            this->line = other.line;
            break;

        case _OD_GEOM_SPIRAL:
            this->spiral = other.spiral;
            break;

        case _OD_GEOM_ARC:
            this->arc = other.arc;
            break;

        case _OD_GEOM_POLY3:
            this->poly3 = other.poly3;
            break;

        case _OD_GEOM_PARAMPOLY3:
            this->paramPoly3 = other.paramPoly3;
            break;
        }
    }

    inline void setParent(void* parent = 0, bool resetChildren = true)
    {
        this->parent = parent;

        if (resetChildren)
        {
            switch (this->type)
            {
            case _OD_GEOM_LINE:
                this->line.setParent(this, resetChildren);
                break;

            case _OD_GEOM_SPIRAL:
                this->spiral.setParent(this, resetChildren);
                break;

            case _OD_GEOM_ARC:
                this->arc.setParent(this, resetChildren);
                break;

            case _OD_GEOM_POLY3:
                this->poly3.setParent(this, resetChildren);
                break;

            case _OD_GEOM_PARAMPOLY3:
                this->paramPoly3.setParent(this, resetChildren);
                break;
            }

            additionalData.setParent(this, resetChildren);
        }
    }

    t_road_planView_geometry& operator=(const t_road_planView_geometry& other)
    {
        (a_s&)(*this) = (a_s&)other;
        (a_xy_hdg&)(*this) = (a_xy_hdg&)other;
        this->length = other.length;
        this->additionalData = other.additionalData;
        this->type = other.type;

        switch (this->type)
        {
        case _OD_GEOM_LINE:
            this->line = other.line;
            break;

        case _OD_GEOM_SPIRAL:
            this->spiral = other.spiral;
            break;

        case _OD_GEOM_ARC:
            this->arc = other.arc;
            break;

        case _OD_GEOM_POLY3:
            this->poly3 = other.poly3;
            break;

        case _OD_GEOM_PARAMPOLY3:
            this->paramPoly3 = other.paramPoly3;
            break;
        }

        return *this;
    }

    bool operator==(const t_road_planView_geometry& other) const
    {
        if ((a_s&)(*this) != (a_s&)other ||
                (a_xy_hdg&)(*this) != (a_xy_hdg&)other ||
                this->length != other.length ||
                this->additionalData != other.additionalData ||
                this->type != other.type)
        {
            return false;
        }

        switch (this->type)
        {
        case _OD_GEOM_LINE:
            return this->line == other.line;

        case _OD_GEOM_SPIRAL:
            return this->spiral == other.spiral;

        case _OD_GEOM_ARC:
            return this->arc == other.arc;

        case _OD_GEOM_POLY3:
            return this->poly3 == other.poly3;

        case _OD_GEOM_PARAMPOLY3:
            return this->paramPoly3 == other.paramPoly3;
        }

        return true;
    }

    bool operator!=(const t_road_planView_geometry& other) const
    {
        return !(*this == other);
    }

public:
    _xodrStatus read(const _xodrElement& node)
    {
        _xodrStatus status = _xodrElement::SUCCEEDED;

        _UNIVERSIAL_TYPE_BASE_GEO_JSON_READ(a_s);
        _UNIVERSIAL_TYPE_BASE_GEO_JSON_READ(a_xy_hdg);
        _UNIVERSIAL_TYPE_ATTRIBUTE_READ_REQUIRED(length);

        bool read = false;
        _UNIVERSIAL_TYPE_TAG_READ_IF_EXISTS(line, read);
        if (read)
        {
            this->type = _OD_GEOM_LINE;
        }
        else
        {
            _UNIVERSIAL_TYPE_TAG_READ_IF_EXISTS(spiral, read);
            if (read)
            {
                this->type = _OD_GEOM_SPIRAL;
            }
            else
            {
                _UNIVERSIAL_TYPE_TAG_READ_IF_EXISTS(arc, read);
                if (read)
                {
                    this->type = _OD_GEOM_ARC;
                }
                else
                {
                    _UNIVERSIAL_TYPE_TAG_READ_IF_EXISTS(poly3, read);
                    if (read)
                    {
                        this->type = _OD_GEOM_POLY3;
                    }
                    else
                    {
                        _UNIVERSIAL_TYPE_TAG_READ_IF_EXISTS(paramPoly3, read);
                        if (read)
                            this->type = _OD_GEOM_PARAMPOLY3;
                    }
                }
            }
        }

        _OD_G_ADDITIONAL_DATA_READ;

        return status;
    }

    void write(XmlStreamWriter& xmlWriter, bool forceToWriteOptionalValues = false)
    {
        Q_UNUSED(forceToWriteOptionalValues);

        _UNIVERSIAL_TYPE_BASE_GEO_JSON_WRITE(a_s);
        _UNIVERSIAL_TYPE_BASE_GEO_JSON_WRITE(a_xy_hdg);
        _UNIVERSIAL_TYPE_ATTRIBUTE_WRITE_REQUIRED(length);

        switch (this->type)
        {
        case _OD_GEOM_LINE:
            _UNIVERSIAL_TYPE_TAG_WRITE1(line);
            break;

        case _OD_GEOM_SPIRAL:
            _UNIVERSIAL_TYPE_TAG_WRITE1(spiral);
            break;

        case _OD_GEOM_ARC:
            _UNIVERSIAL_TYPE_TAG_WRITE1(arc);
            break;

        case _OD_GEOM_POLY3:
            _UNIVERSIAL_TYPE_TAG_WRITE1(poly3);
            break;

        case _OD_GEOM_PARAMPOLY3:
            _UNIVERSIAL_TYPE_TAG_WRITE1(paramPoly3);
            break;
        }

        _OD_G_ADDITIONAL_DATA_WRITE;
    }

    void read(QJsonObject obj)
    {
        _UNIVERSIAL_TYPE_BASE_GEO_JSON_JSON_READ(a_s);
        _UNIVERSIAL_TYPE_BASE_GEO_JSON_JSON_READ(a_xy_hdg);
        _UNIVERSIAL_TYPE_ATTRIBUTE_JSON_READ_REQUIRED(length);

        bool read = false;
        _UNIVERSIAL_TYPE_TAG_JSON_READ_IF_EXISTS(line, read);
        if (read)
        {
            this->type = _OD_GEOM_LINE;
        }
        else
        {
            _UNIVERSIAL_TYPE_TAG_JSON_READ_IF_EXISTS(spiral, read);
            if (read)
            {
                this->type = _OD_GEOM_SPIRAL;
            }
            else
            {
                _UNIVERSIAL_TYPE_TAG_JSON_READ_IF_EXISTS(arc, read);
                if (read)
                {
                    this->type = _OD_GEOM_ARC;
                }
                else
                {
                    _UNIVERSIAL_TYPE_TAG_JSON_READ_IF_EXISTS(poly3, read);
                    if (read)
                    {
                        this->type = _OD_GEOM_POLY3;
                    }
                    else
                    {
                        _UNIVERSIAL_TYPE_TAG_JSON_READ_IF_EXISTS(paramPoly3, read);
                        if (read)
                            this->type = _OD_GEOM_PARAMPOLY3;
                    }
                }
            }
        }

        _OD_G_ADDITIONAL_DATA_JSON_READ;
    }

    void write(QJsonObject& obj, bool forceToWriteOptionalValues = false)
    {
        Q_UNUSED(forceToWriteOptionalValues);

        _UNIVERSIAL_TYPE_BASE_GEO_JSON_JSON_WRITE(a_s);
        _UNIVERSIAL_TYPE_BASE_GEO_JSON_JSON_WRITE(a_xy_hdg);
        _UNIVERSIAL_TYPE_ATTRIBUTE_JSON_WRITE_REQUIRED(length);

        switch (this->type)
        {
        case _OD_GEOM_LINE:
            _UNIVERSIAL_TYPE_TAG_JSON_WRITE1(line);
            break;

        case _OD_GEOM_SPIRAL:
            _UNIVERSIAL_TYPE_TAG_JSON_WRITE1(spiral);
            break;

        case _OD_GEOM_ARC:
            _UNIVERSIAL_TYPE_TAG_JSON_WRITE1(arc);
            break;

        case _OD_GEOM_POLY3:
            _UNIVERSIAL_TYPE_TAG_JSON_WRITE1(poly3);
            break;

        case _OD_GEOM_PARAMPOLY3:
            _UNIVERSIAL_TYPE_TAG_JSON_WRITE1(paramPoly3);
            break;
        }

        _OD_G_ADDITIONAL_DATA_JSON_WRITE;
    }

    void setTestData()
    {
        a_s::setTestData();
        a_xy_hdg::setTestData();

        switch (this->type)
        {
        case _OD_GEOM_LINE:
            line.setTestData();
            break;

        case _OD_GEOM_SPIRAL:
            spiral.setTestData();
            break;

        case _OD_GEOM_ARC:
            arc.setTestData();
            break;

        case _OD_GEOM_POLY3:
            poly3.setTestData();
            break;

        case _OD_GEOM_PARAMPOLY3:
            paramPoly3.setTestData();
            break;
        }

        _OD_G_ADDITIONAL_DATA_SET_TEST_DATA;
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

public:
    inline double calcDistance(const a_s_t& st) const
    {
        double ds;
        if (st.s < this->s)
            ds = this->s - st.s;
        else if (st.s <= this->s + this->length)
            ds = 0;
        else
            ds = st.s - this->s;

        return sqrt(ds * ds + st.t * st.t);
    }

    void calcXY(const a_s_t& st, XY& xy) const;
};

}
