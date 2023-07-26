#pragma once

#include "XML/Internal/Internal.h"
#include <QDomElement>
#include "XML/Main/XmlStream.h"
#include "Common/Main/String.h"
#include <QJsonObject>
#include <QJsonArray>
#include "Debugger/Main/Logger.h"

namespace _NXML
{

/**************************************************************/

class XmlElement : public QDomElement
{
public:
    static const XmlStatus SUCCEEDED;
    static const XmlStatus FAILED;

public:
    XmlElement(){}

    XmlElement(const QDomElement& element)
        : QDomElement(element)
    {
    }

    template <typename T>
    XmlStatus attributeRequired(const QString& attrName, T& outValue) const
    {
        if (!hasAttribute(attrName))
            return FAILED;

        _NCM::setFromString(outValue, attribute(attrName));
        return SUCCEEDED;
    }

    template <typename T>
    XmlStatus attributeOptional(const QString& attrName, T& outValue) const
    {
        if (hasAttribute(attrName))
            _NCM::setFromString(outValue, attribute(attrName));
        return SUCCEEDED;
    }

    template <typename T>
    XmlStatus attributeOptional(const QString& attrName, T& outValue, const T& defaultValue) const
    {
        if (hasAttribute(attrName))
            outValue = attribute(attrName);
        else
            outValue = defaultValue;
        return SUCCEEDED;
    }
};

template <typename T>
XmlStatus readTagContent(const XmlElement& node, T& tag)
{
    return tag.read(node);
}

template <typename T>
XmlStatus readTag(const XmlElement& node, T& tag, const QString& tagName)
{
    //DefaultLogger << tagName;
    XmlElement subNode = node.firstChildElement(tagName);
    if (subNode.isNull())
        return XmlElement::FAILED;
    return readTagContent(subNode, tag);
}

template <typename T>
XmlStatus readTagIfExists(const XmlElement& node, T& tag, const QString& tagName, bool& read)
{
    XmlElement subNode = node.firstChildElement(tagName);
    if (subNode.isNull())
    {
        read = false;
        return XmlElement::SUCCEEDED;
    }

    read = true;
    return readTagContent(subNode, tag);
}

template <typename T>
void writeTagContent(XmlStreamWriter& xmlWriter, T& tag)
{
    tag.write(xmlWriter);
}

template <typename T>
void writeTag(XmlStreamWriter& xmlWriter, T& tag, const QString& tagName)
{
    xmlWriter.writeStartElement(tagName);
    writeTagContent(xmlWriter, tag);
    xmlWriter.writeEndElement();
}

template <typename T>
XmlStatus readSequence(const XmlElement& node, QVector<T>& sequence, const QString& tagName)
{
    sequence.clear();

    XmlStatus status = XmlElement::SUCCEEDED;
    XmlElement subNode = node.firstChildElement(tagName);
    while (!subNode.isNull())
    {
        T tag;
        status |= readTagContent(subNode, tag);
        sequence << tag;
        subNode = subNode.nextSiblingElement(tagName);
    }
    return status;
}

template <typename T>
void writeSequence(XmlStreamWriter& xmlWriter, QVector<T>& sequence, const QString& tagName)
{
    for (T& element : sequence)
        writeTag(xmlWriter, element, tagName);
}

}
