#pragma once

#include "UniversialType/Main/UniversialType.h"
#include <QJsonArray>

namespace _NUniversialType
{

struct StringPairs : public StringMap
{
public:
    bool useXMLAttr = true;

public:
    StringPairs()
    {}

    StringPairs(const StringMap& other)
        : StringMap(other)
    {}

    StringPairs& operator=(const StringMap& other)
    {
        (StringMap&)(*this) = other;
        return *this;
    }

    bool operator==(const StringPairs& other) const
    {
        return
                _UNIVERSIAL_TYPE_BASE_GEO_JSON_COMPARE(StringMap) &&
                true;
    }

    bool operator!=(const StringPairs& other) const
    {
        return !(*this == other);
    }

public:
    XmlStatus read(const XmlElement& node)
    {
        XmlStatus status = XmlElement::SUCCEEDED;

        if (useXMLAttr)
        {
            QDomNamedNodeMap nodeMap = node.attributes();
            for (int i = 0; i < nodeMap.count(); i ++)
            {
                QDomAttr attr = nodeMap.item(i).toAttr();
                (*this)[attr.name()] = attr.value();
            }
        }
        else
        {
            XmlElement subNode = node.firstChildElement();
            while (!subNode.isNull())
            {
                QString key = subNode.tagName();
                QString value = subNode.firstChild().toText().data();
                (*this)[key] = value;
                subNode = subNode.nextSiblingElement();
            }
        }

        return status;
    }

    void write(XmlStreamWriter& xmlWriter, bool forceToWriteOptionalValues = false)
    {
        Q_UNUSED(forceToWriteOptionalValues);

        const_iterator iter = constBegin();
        for (; iter != constEnd(); iter ++)
        {
            const QString& key = iter.key();
            const QString& value = iter.value();

            if (useXMLAttr)
            {
                xmlWriter.writeAttribute(key, value);
            }
            else
            {
                xmlWriter.writeStartElement(key);
                xmlWriter.writeCharacters(value);
                xmlWriter.writeEndElement();
            }
        }
    }

    void read(QJsonObject obj)
    {
        QJsonArray keys = obj["keys"].toArray();
        QJsonArray values = obj["values"].toArray();
        for (int i = 0; i < keys.size(); i ++)
            (*this)[keys[i].toString()] = values[i].toString();
    }

    void write(QJsonObject& obj, bool forceToWriteOptionalValues = false)
    {
        Q_UNUSED(forceToWriteOptionalValues);

        QJsonArray keys, values;
        const_iterator iter = constBegin();
        for (; iter != constEnd(); iter ++)
        {
            const QString& key = iter.key();
            const QString& value = iter.value();

            keys.append(key);
            values.append(value);
        }
        obj["keys"] = keys;
        obj["values"] = values;
    }

    void setTestData()
    {
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

