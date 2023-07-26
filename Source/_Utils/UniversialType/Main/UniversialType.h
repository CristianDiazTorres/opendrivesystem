#pragma once

#include "UniversialType/Internal/Internal.h"
#include "Common/Main/String.h"
#include "Common/Main/Vector.h"
#include "XML/Main/XmlElement.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>

namespace _NUniversialType
{

template <typename T>
void readJsonValue(QJsonValue json, T& value)
{
    if (json.isNull())
        return;

    _NCM::setFromString(value, json.toString());
    //qDebug() << "readJsonValue(QJsonValue json, T& value)" << ":" << json.toString();
}

template <>
inline void readJsonValue(QJsonValue json, int& value)
{
    if (json.isNull())
        return;

    if (json.isString())
        value = json.toString().toInt();
    else
        value = json.toInt();
    //qDebug() << "readJsonValue(QJsonValue json, int& value)" << ":" << value;
}

template <>
inline void readJsonValue(QJsonValue json, uint& value)
{
    if (json.isNull())
        return;

    if (json.isString())
        value = (uint)json.toString().toDouble();
    else
        value = (uint)json.toDouble();
    //qDebug() << "readJsonValue(QJsonValue json, uint& value)" << ":" << value;
}

template <>
inline void readJsonValue(QJsonValue json, qint64& value)
{
    if (json.isNull())
        return;

    if (json.isString())
        value = (qint64)json.toString().toDouble();
    else
        value = (qint64)json.toDouble();
    //qDebug() << "readJsonValue(QJsonValue json, qint64& value)" << ":" << value;
}

template <>
inline void readJsonValue(QJsonValue json, quint64& value)
{
    if (json.isNull())
        return;

    if (json.isString())
        value = (quint64)json.toString().toDouble();
    else
        value = (quint64)json.toDouble();
    //qDebug() << "readJsonValue(QJsonValue json, quint64& value)" << ":" << value;
}

template <>
inline void readJsonValue(QJsonValue json, double& value)
{
    if (json.isNull())
        return;

    if (json.isString())
        value = json.toString().toDouble();
    else
        value = json.toDouble();
    //qDebug() << "readJsonValue(QJsonValue json, double& value)" << ":" << value;
}

template <typename T>
void writeJsonValue(QJsonObject& obj, const QString& attr, const T& value)
{
    obj[attr] = _NCM::toString(value);
}

template <>
inline void writeJsonValue(QJsonObject& obj, const QString& attr, const int& value)
{
    obj[attr] = value;
}

template <>
inline void writeJsonValue(QJsonObject& obj, const QString& attr, const uint& value)
{
    obj[attr] = (double)value;
}

template <>
inline void writeJsonValue(QJsonObject& obj, const QString& attr, const qint64& value)
{
    obj[attr] = (double)value;
}

template <>
inline void writeJsonValue(QJsonObject& obj, const QString& attr, const quint64& value)
{
    obj[attr] = (double)value;
}

template <>
inline void writeJsonValue(QJsonObject& obj, const QString& attr, const double& value)
{
    obj[attr] = value;
}

template <typename T>
void readSequence(QJsonObject& obj, QVector<T>& sequence, const QString& tagName)
{
    //DefaultLogger_File << "Reading sequence : " << tagName;

    if (obj.contains(tagName + "_sequence"))
    {
        sequence.clear();

        QJsonArray arr = obj[tagName + "_sequence"].toArray();
        sequence.resize(arr.size());
        //DefaultLogger_File << tagName << " : arr.size()" << arr.size();

        for (int i = 0; i < arr.size(); i ++)
            sequence[i].read(arr[i].toObject());
    }
}

template <typename T>
void writeSequence(QJsonObject& obj, QVector<T>& sequence, const QString& tagName)
{
    //DefaultLogger_File << "Writing sequence : " << tagName;

    QJsonArray arr;
    for (int i = 0; i < sequence.size(); i ++)
    {
        QJsonObject value;
        sequence[i].write(value);
        arr.append(value);
    }

    //DefaultLogger_File << tagName << " : arr.size()" << arr.size();

    if (!arr.isEmpty())
        obj[tagName + "_sequence"] = arr;
}

template <typename T>
inline void AddToGeoJsonTemplateData(QJsonArray& features, QJsonObject geomObject, QString tagName, QString attrName, const T& value)
{
    QJsonObject object;
    object["type"] = "Feature";
    object["geometry"] = geomObject;

    QJsonObject attrObj;
    attrObj["tag"] = tagName;
    attrObj["update_st"] = true;
    writeJsonValue(attrObj, attrName, value);
    object["properties"] = attrObj;

    features.append(object);
}

template <>
inline void AddToGeoJsonTemplateData(QJsonArray& features, QJsonObject geomObject, QString tagName, QString attrName, const double& value)
{
    QJsonObject object;
    object["type"] = "Feature";
    object["geometry"] = geomObject;

    QJsonObject attrObj;
    attrObj["tag"] = tagName;
    attrObj["update_st"] = true;
    writeJsonValue(attrObj, attrName, value + 1);
    object["properties"] = attrObj;

    features.append(object);
}

/***********************************************************************/
// NOTE:
// _UNIVERSIAL_TYPE_BASE_GEO_JSON & _UNIVERSIAL_TYPE_ATTRIBUTE & _UNIVERSIAL_TYPE_ATTR_INIT < _UNIVERSIAL_TYPE_TAG & _UNIVERSIAL_TYPE_SEQUENCE
/***********************************************************************/

#define _UNIVERSIAL_TYPE_SCHEMA(schema)

/***********************************************************************/

#define _UNIVERSIAL_TYPE_BASE_GEO_JSON(usingType, baseType) \
    _UNIVERSIAL_TYPE_BASE_GEO_JSON_##usingType(baseType)

#define _UNIVERSIAL_TYPE_BASE_GEO_JSON_DECLARE(baseType)

#define _UNIVERSIAL_TYPE_BASE_GEO_JSON_SET_PARENT(baseType) \
    baseType::setParent(parent, resetChildren);

#define _UNIVERSIAL_TYPE_BASE_GEO_JSON_COMPARE(baseType) \
    (const baseType&)(*this) == (const baseType&)other

#define _UNIVERSIAL_TYPE_BASE_GEO_JSON_READ(baseType) \
    status |= baseType::read(node)

#define _UNIVERSIAL_TYPE_BASE_GEO_JSON_JSON_READ(baseType) \
    baseType::read(obj)

#define _UNIVERSIAL_TYPE_BASE_GEO_JSON_WRITE(baseType) \
    baseType::write(xmlWriter)

#define _UNIVERSIAL_TYPE_BASE_GEO_JSON_JSON_WRITE(baseType) \
    baseType::write(obj)

#define _UNIVERSIAL_TYPE_BASE_GEO_JSON_SET_TEST_DATA(baseType) \
    baseType::setTestData()

#define _UNIVERSIAL_TYPE_BASE_GEO_JSON_SAVE_GEO_JSON_DATA(baseType) \
    baseType::AddToGeoJsonTemplateData(features, geomObject, tagName)

#define _UNIVERSIAL_TYPE_BASE_GEO_JSON_UPDATE_GEO_JSON_DATA_LINE(baseType) \
    if (baseType::updateGeoJSONData(geojsonData, inserted)) \
        return true;

#define _UNIVERSIAL_TYPE_BASE_GEO_JSON_UPDATE_GEO_JSON_DATA_POINT(baseType) \
    if (baseType::updateGeoJSONData(geojsonData, inserted)) \
        return true;

#define _UNIVERSIAL_TYPE_BASE_GEO_JSON_CALC_ABS_POS(baseType)

#define _UNIVERSIAL_TYPE_BASE_GEO_JSON_CALC_REL_POS(baseType)

/***********************************************************************/

#define _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON(usingType, baseType) \
    _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON_##usingType(baseType)

#define _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON_DECLARE(baseType)

#define _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON_SET_PARENT(baseType) \
    baseType::setParent(parent, resetChildren);

#define _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON_COMPARE(baseType) \
    (const baseType&)(*this) == (const baseType&)other

#define _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON_READ(baseType) \
    status |= baseType::read(node)

#define _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON_JSON_READ(baseType) \
    baseType::read(obj)

#define _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON_WRITE(baseType) \
    baseType::write(xmlWriter)

#define _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON_JSON_WRITE(baseType) \
    baseType::write(obj)

#define _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON_SET_TEST_DATA(baseType) \
    baseType::setTestData()

#define _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON_SAVE_GEO_JSON_DATA(baseType) \
    baseType::AddToGeoJsonTemplateData(features, geomObject, tagName)

#define _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON_UPDATE_GEO_JSON_DATA_LINE(baseType)

#define _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON_UPDATE_GEO_JSON_DATA_POINT(baseType)

#define _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON_CALC_ABS_POS(baseType)

#define _UNIVERSIAL_TYPE_BASE_NO_GEO_JSON_CALC_REL_POS(baseType)

/***********************************************************************/

#define _UNIVERSIAL_TYPE_ATTRIBUTE(usingType, type, name, required) \
    _UNIVERSIAL_TYPE_ATTRIBUTE_##usingType(type, name, required)

#define _UNIVERSIAL_TYPE_ATTRIBUTE_DECLARE(type, name, required) \
    type name

#define _UNIVERSIAL_TYPE_ATTRIBUTE_SET_PARENT(type, name, required)

#define _UNIVERSIAL_TYPE_ATTRIBUTE_COMPARE(type, name, required) \
    this->name == other.name

#define _UNIVERSIAL_TYPE_ATTRIBUTE_COMPARE1(member) \
    this->member == other.member

#define _UNIVERSIAL_TYPE_ATTRIBUTE_READ(type, name, required) \
    _UNIVERSIAL_TYPE_ATTRIBUTE_READ_##required(name)

#define _UNIVERSIAL_TYPE_ATTRIBUTE_JSON_READ(type, name, required) \
    _UNIVERSIAL_TYPE_ATTRIBUTE_JSON_READ_##required(name)

#define _UNIVERSIAL_TYPE_ATTRIBUTE_READ_REQUIRED(name) \
    status |= node.attributeRequired(#name, name)

#define _UNIVERSIAL_TYPE_ATTRIBUTE_READ_REQUIRED1(attributeName, attribute) \
    status |= node.attributeRequired(#attributeName, attribute)

#define _UNIVERSIAL_TYPE_ATTRIBUTE_READ_OPTIONAL(name) \
    status |= node.attributeOptional(#name, name)

#define _UNIVERSIAL_TYPE_ATTRIBUTE_JSON_READ_REQUIRED(name) \
    readJsonValue(obj[#name], name)

#define _UNIVERSIAL_TYPE_ATTRIBUTE_JSON_READ_REQUIRED1(attributeName, attribute) \
    readJsonValue(obj[#attributeName], attribute)

#define _UNIVERSIAL_TYPE_ATTRIBUTE_JSON_READ_OPTIONAL(name) \
    if (obj.contains(#name)) \
    readJsonValue(obj[#name], name)

#define _UNIVERSIAL_TYPE_ATTRIBUTE_WRITE(type, name, required) \
    _UNIVERSIAL_TYPE_ATTRIBUTE_WRITE_##required(name)

#define _UNIVERSIAL_TYPE_ATTRIBUTE_JSON_WRITE(type, name, required) \
    _UNIVERSIAL_TYPE_ATTRIBUTE_JSON_WRITE_##required(name)

#define _UNIVERSIAL_TYPE_ATTRIBUTE_WRITE_REQUIRED(name) \
    xmlWriter.writeAttribute(#name, _NCM::toString(name))

#define _UNIVERSIAL_TYPE_ATTRIBUTE_WRITE_REQUIRED1(attributeName, attribute) \
    xmlWriter.writeAttribute(#attributeName, _NCM::toString(attribute))

#define _UNIVERSIAL_TYPE_ATTRIBUTE_WRITE_OPTIONAL(name) \
    if (forceToWriteOptionalValues || !_NCM::isEmpty(name)) \
    xmlWriter.writeAttribute(#name, _NCM::toString(name))

#define _UNIVERSIAL_TYPE_ATTRIBUTE_JSON_WRITE_REQUIRED(name) \
    writeJsonValue(obj, #name, name)

#define _UNIVERSIAL_TYPE_ATTRIBUTE_JSON_WRITE_REQUIRED1(attributeName, attribute) \
    writeJsonValue(obj, #attributeName, attribute)

#define _UNIVERSIAL_TYPE_ATTRIBUTE_JSON_WRITE_OPTIONAL(name) \
    if (forceToWriteOptionalValues || !_NCM::isEmpty(name)) \
    writeJsonValue(obj, #name, name)

#define _UNIVERSIAL_TYPE_ATTRIBUTE_SET_TEST_DATA(type, name, required)

#define _UNIVERSIAL_TYPE_ATTRIBUTE_SAVE_GEO_JSON_DATA(type, name, required) \
    ::AddToGeoJsonTemplateData(features, geomObject, tagName, #name, name);

#define _UNIVERSIAL_TYPE_ATTRIBUTE_UPDATE_GEO_JSON_DATA_LINE(type, name, required)

#define _UNIVERSIAL_TYPE_ATTRIBUTE_UPDATE_GEO_JSON_DATA_POINT(type, name, required)

#define _UNIVERSIAL_TYPE_ATTRIBUTE_CALC_ABS_POS(type, name, required)

#define _UNIVERSIAL_TYPE_ATTRIBUTE_CALC_REL_POS(type, name, required)

/***********************************************************************/

#define _UNIVERSIAL_TYPE_ATTR_INIT(usingType, type, name, initValue, required) \
    _UNIVERSIAL_TYPE_ATTR_INIT_##usingType(type, name, initValue, required)

#define _UNIVERSIAL_TYPE_ATTR_INIT_DECLARE(type, name, initValue, required) \
    type name = initValue

#define _UNIVERSIAL_TYPE_ATTR_INIT_SET_PARENT(type, name, initValue, required)

#define _UNIVERSIAL_TYPE_ATTR_INIT_COMPARE(type, name, initValue, required) \
    this->name == other.name

#define _UNIVERSIAL_TYPE_ATTR_INIT_READ(type, name, initValue, required) \
    _UNIVERSIAL_TYPE_ATTR_INIT_READ_##required(type, name)

#define _UNIVERSIAL_TYPE_ATTR_INIT_JSON_READ(type, name, initValue, required) \
    _UNIVERSIAL_TYPE_ATTR_INIT_JSON_READ_##required(type, name)

#define _UNIVERSIAL_TYPE_ATTR_INIT_READ_REQUIRED(type, name) \
    status |= node.attributeRequired(#name, name)

#define _UNIVERSIAL_TYPE_ATTR_INIT_READ_OPTIONAL(type, name) \
    status |= node.attributeOptional(#name, name)

#define _UNIVERSIAL_TYPE_ATTR_INIT_JSON_READ_REQUIRED(type, name) \
    readJsonValue(obj[#name], name)

#define _UNIVERSIAL_TYPE_ATTR_INIT_JSON_READ_OPTIONAL(type, name) \
    if (obj.contains(#name)) \
    readJsonValue(obj[#name], name)

#define _UNIVERSIAL_TYPE_ATTR_INIT_WRITE(type, name, initValue, required) \
    _UNIVERSIAL_TYPE_ATTR_INIT_WRITE_##required(type, name)

#define _UNIVERSIAL_TYPE_ATTR_INIT_JSON_WRITE(type, name, initValue, required) \
    _UNIVERSIAL_TYPE_ATTR_INIT_JSON_WRITE_##required(type, name)

#define _UNIVERSIAL_TYPE_ATTR_INIT_WRITE_REQUIRED(type, name) \
    xmlWriter.writeAttribute(#name, _NCM::toString(name))

#define _UNIVERSIAL_TYPE_ATTR_INIT_WRITE_OPTIONAL(type, name) \
    if (forceToWriteOptionalValues || !_NCM::isEmpty(name)) \
    xmlWriter.writeAttribute(#name, _NCM::toString(name))

#define _UNIVERSIAL_TYPE_ATTR_INIT_JSON_WRITE_REQUIRED(type, name) \
    writeJsonValue(obj, #name, name)

#define _UNIVERSIAL_TYPE_ATTR_INIT_JSON_WRITE_OPTIONAL(type, name) \
    if (forceToWriteOptionalValues || !_NCM::isEmpty(name)) \
    writeJsonValue(obj, #name, name)

#define _UNIVERSIAL_TYPE_ATTR_INIT_SET_TEST_DATA(type, name, initValue, required)

#define _UNIVERSIAL_TYPE_ATTR_INIT_SAVE_GEO_JSON_DATA(type, name, initValue, required) \
    ::AddToGeoJsonTemplateData(features, geomObject, tagName, #name, name);

#define _UNIVERSIAL_TYPE_ATTR_INIT_UPDATE_GEO_JSON_DATA_LINE(type, name, initValue, required)

#define _UNIVERSIAL_TYPE_ATTR_INIT_UPDATE_GEO_JSON_DATA_POINT(type, name, initValue, required)

#define _UNIVERSIAL_TYPE_ATTR_INIT_CALC_ABS_POS(type, name, initValue, required)

#define _UNIVERSIAL_TYPE_ATTR_INIT_CALC_REL_POS(type, name, initValue, required)

/***********************************************************************/

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE(usingType, type, name, required) \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_##usingType(type, name, required)

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_DECLARE(type, name, required) \
    type name

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_SET_PARENT(type, name, required)

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_COMPARE(type, name, required) \
    this->name == other.name

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_COMPARE1(member) \
    this->member == other.member

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_READ(type, name, required) \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_READ_##required(name)

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_JSON_READ(type, name, required) \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_JSON_READ_##required(name)

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_READ_REQUIRED(name) \
    status |= node.attributeRequired(#name, name)

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_READ_REQUIRED1(attributeName, attribute) \
    status |= node.attributeRequired(#attributeName, attribute)

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_READ_OPTIONAL(name) \
    status |= node.attributeOptional(#name, name)

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_JSON_READ_REQUIRED(name) \
    readJsonValue(obj[#name], name)

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_JSON_READ_REQUIRED1(attributeName, attribute) \
    readJsonValue(obj[#attributeName], attribute)

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_JSON_READ_OPTIONAL(name) \
    if (obj.contains(#name)) \
    readJsonValue(obj[#name], name)

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_WRITE(type, name, required) \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_WRITE_##required(name)

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_JSON_WRITE(type, name, required) \
    _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_JSON_WRITE_##required(name)

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_WRITE_REQUIRED(name) \
    xmlWriter.writeAttribute(#name, _NCM::toString(name))

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_WRITE_REQUIRED1(attributeName, attribute) \
    xmlWriter.writeAttribute(#attributeName, _NCM::toString(attribute))

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_WRITE_OPTIONAL(name) \
    if (forceToWriteOptionalValues || !_NCM::isEmpty(name)) \
    xmlWriter.writeAttribute(#name, _NCM::toString(name))

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_JSON_WRITE_REQUIRED(name) \
    writeJsonValue(obj, #name, name)

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_JSON_WRITE_REQUIRED1(attributeName, attribute) \
    writeJsonValue(obj, #attributeName, attribute)

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_JSON_WRITE_OPTIONAL(name) \
    if (forceToWriteOptionalValues || !_NCM::isEmpty(name)) \
    writeJsonValue(obj, #name, name)

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_SET_TEST_DATA(type, name, required)

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_SAVE_GEO_JSON_DATA(type, name, required) \
    for (_map<integer, string>::const_iterator iter = type::intToStr.constBegin(); iter != type::intToStr.constEnd(); iter ++) \
        ::AddToGeoJsonTemplateData(features, geomObject, tagName, #name, iter.value());

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_UPDATE_GEO_JSON_DATA_LINE(type, name, required)

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_UPDATE_GEO_JSON_DATA_POINT(type, name, required)

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_CALC_ABS_POS(type, name, required)

#define _UNIVERSIAL_TYPE_ENUM_ATTRIBUTE_CALC_REL_POS(type, name, required)

/***********************************************************************/

#define _UNIVERSIAL_TYPE_ENUM_ATTR_INIT(usingType, type, name, initValue, required) \
    _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_##usingType(type, name, initValue, required)

#define _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_DECLARE(type, name, initValue, required) \
    type name = initValue

#define _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_SET_PARENT(type, name, initValue, required)

#define _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_COMPARE(type, name, initValue, required) \
    this->name == other.name

#define _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_READ(type, name, initValue, required) \
    _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_READ_##required(type, name)

#define _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_JSON_READ(type, name, initValue, required) \
    _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_JSON_READ_##required(type, name)

#define _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_READ_REQUIRED(type, name) \
    status |= node.attributeRequired(#name, name)

#define _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_READ_OPTIONAL(type, name) \
    status |= node.attributeOptional(#name, name)

#define _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_JSON_READ_REQUIRED(type, name) \
    readJsonValue(obj[#name], name)

#define _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_JSON_READ_OPTIONAL(type, name) \
    if (obj.contains(#name)) \
    readJsonValue(obj[#name], name)

#define _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_WRITE(type, name, initValue, required) \
    _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_WRITE_##required(type, name)

#define _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_JSON_WRITE(type, name, initValue, required) \
    _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_JSON_WRITE_##required(type, name)

#define _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_WRITE_REQUIRED(type, name) \
    xmlWriter.writeAttribute(#name, _NCM::toString(name))

#define _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_WRITE_OPTIONAL(type, name) \
    if (forceToWriteOptionalValues || !_NCM::isEmpty(name)) \
    xmlWriter.writeAttribute(#name, _NCM::toString(name))

#define _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_JSON_WRITE_REQUIRED(type, name) \
    writeJsonValue(obj, #name, name)

#define _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_JSON_WRITE_OPTIONAL(type, name) \
    if (forceToWriteOptionalValues || !_NCM::isEmpty(name)) \
    writeJsonValue(obj, #name, name)

#define _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_SET_TEST_DATA(type, name, initValue, required)

#define _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_SAVE_GEO_JSON_DATA(type, name, initValue, required) \
    for (_map<integer, string>::const_iterator iter = type::intToStr.constBegin(); iter != type::intToStr.constEnd(); iter ++) \
        ::AddToGeoJsonTemplateData(features, geomObject, tagName, #name, iter.value());

#define _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_UPDATE_GEO_JSON_DATA_LINE(type, name, initValue, required)

#define _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_UPDATE_GEO_JSON_DATA_POINT(type, name, initValue, required)

#define _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_CALC_ABS_POS(type, name, initValue, required)

#define _UNIVERSIAL_TYPE_ENUM_ATTR_INIT_CALC_REL_POS(type, name, initValue, required)

/***********************************************************************/

#define _UNIVERSIAL_TYPE_TAG(usingType, type, name) \
    _UNIVERSIAL_TYPE_TAG_##usingType(type, name)

#define _UNIVERSIAL_TYPE_TAG_DECLARE(type, name) \
    type name

#define _UNIVERSIAL_TYPE_TAG_SET_PARENT(type, name) \
    name.setParent(this, resetChildren)

#define _UNIVERSIAL_TYPE_TAG_COMPARE(type, name) \
    this->name == other.name

#define _UNIVERSIAL_TYPE_TAG_READ(type, name) \
    status |= _NXML::readTag(node, name, #name)

#define _UNIVERSIAL_TYPE_TAG_READ_IF_EXISTS(tag, read) \
    status |= _NXML::readTagIfExists(node, tag, #tag, read)

#define _UNIVERSIAL_TYPE_TAG_JSON_READ(type, name) \
    if (obj.contains(#name)) \
        name.read(obj[#name].toObject())

#define _UNIVERSIAL_TYPE_TAG_JSON_READ_IF_EXISTS(tag, read) \
    if (obj.contains(#tag)) \
    { tag.read(obj[#tag].toObject()); read = true; } \
    else \
        read = false

#define _UNIVERSIAL_TYPE_TAG_WRITE(type, name) \
    _NXML::writeTag(xmlWriter, name, #name)

#define _UNIVERSIAL_TYPE_TAG_WRITE1(tag) \
    _NXML::writeTag(xmlWriter, tag, #tag)

#define _UNIVERSIAL_TYPE_TAG_JSON_WRITE(type, name) \
    { \
        QJsonObject child; \
        name.write(child); \
        if (!child.isEmpty()) \
            obj[#name] = child; \
    }

#define _UNIVERSIAL_TYPE_TAG_JSON_WRITE1(tag) \
    { \
        QJsonObject child; \
        tag.write(child); \
        if (!child.isEmpty()) \
            obj[#tag] = child; \
    }

#define _UNIVERSIAL_TYPE_TAG_SET_TEST_DATA(type, name) \
    name.setTestData()

#define _UNIVERSIAL_TYPE_TAG_SAVE_GEO_JSON_DATA(type, name)

#define _UNIVERSIAL_TYPE_TAG_UPDATE_GEO_JSON_DATA_LINE(type, name) \
    if (geojsonData.tag.startsWith(#type)) \
    { \
        return name.updateGeoJSONData(geojsonData, inserted); \
    }

#define _UNIVERSIAL_TYPE_TAG_UPDATE_GEO_JSON_DATA_POINT(type, name) \
    if (geojsonData.tag.startsWith(#type)) \
    { \
        return name.updateGeoJSONData(geojsonData, inserted); \
    }

#define _UNIVERSIAL_TYPE_TAG_CALC_ABS_POS(type, name) \
    name.calcAbsolutePosIncludingChildren(road)

#define _UNIVERSIAL_TYPE_TAG_CALC_REL_POS(type, name) \
    name.calcRelativePosIncludingChildren(road)

/***********************************************************************/

#define _UNIVERSIAL_TYPE_SEQUENCE(usingType, start, end, type, name) \
    _UNIVERSIAL_TYPE_SEQUENCE_##usingType(start, end, type, name)

#define _UNIVERSIAL_TYPE_SEQUENCE_DECLARE(start, end, type, name) \
    QVector##start##end<type> name##_sequence

#define _UNIVERSIAL_TYPE_SEQUENCE_SET_PARENT(start, end, type, name) \
    for (int i = 0; i < name##_sequence.size(); i ++) \
        name##_sequence[i].setParent(this, resetChildren)

#define _UNIVERSIAL_TYPE_SEQUENCE_COMPARE(start, end, type, name) \
    this->name##_sequence == other.name##_sequence

#define _UNIVERSIAL_TYPE_SEQUENCE_READ(start, end, type, name) \
    status |= _NXML::readSequence(node, name##_sequence, #name)

#define _UNIVERSIAL_TYPE_SEQUENCE_WRITE(start, end, type, name) \
    _NXML::writeSequence(xmlWriter, name##_sequence, #name)

#define _UNIVERSIAL_TYPE_SEQUENCE_JSON_READ(start, end, type, name) \
    _NUniversialType::readSequence(obj, name##_sequence, #name)

#define _UNIVERSIAL_TYPE_SEQUENCE_JSON_WRITE(start, end, type, name) \
    _NUniversialType::writeSequence(obj, name##_sequence, #name)

#define _UNIVERSIAL_TYPE_SEQUENCE_SET_TEST_DATA(start, end, type, name) \
    this->name##_sequence.resize(1); \
    this->name##_sequence[0].setTestData()

#define _UNIVERSIAL_TYPE_SEQUENCE_SAVE_GEO_JSON_DATA(start, end, type, name)

#define _UNIVERSIAL_TYPE_SEQUENCE_UPDATE_GEO_JSON_DATA_LINE(start, end, type, name) \
    if (geojsonData.tag.startsWith(#type)) \
    { \
        if (this->name##_sequence.isEmpty()) \
        { \
            this->name##_sequence.resize(1); \
            bool ret = this->name##_sequence.first().updateGeoJSONData(geojsonData, inserted); \
            inserted = true; \
            return ret; \
        } \
        return this->name##_sequence.first().updateGeoJSONData(geojsonData, inserted); \
    }

#define _UNIVERSIAL_TYPE_SEQUENCE_UPDATE_GEO_JSON_DATA_POINT(start, end, type, name) \
    _UNIVERSIAL_TYPE_SEQUENCE_UPDATE_GEO_JSON_DATA_POINT_##end(start, end, type, name)

#define _UNIVERSIAL_TYPE_SEQUENCE_UPDATE_GEO_JSON_DATA_POINT_1(start, end, type, name) \
    if (geojsonData.tag.startsWith(#type)) \
    { \
        if (this->name##_sequence.isEmpty()) \
        { \
            this->name##_sequence.resize(1); \
            bool ret = this->name##_sequence.first().updateGeoJSONData(geojsonData, inserted); \
            inserted = true; \
            return ret; \
        } \
        return this->name##_sequence.first().updateGeoJSONData(geojsonData, inserted); \
    }

#define _UNIVERSIAL_TYPE_SEQUENCE_UPDATE_GEO_JSON_DATA_POINT_x(start, end, type, name) \
    if (geojsonData.tag.startsWith(#type)) \
    { \
        double minDist = DOUBLE_MAX; \
        int index = _NMath::getNearestIndex(geojsonData.st, this->name##_sequence, minDist); \
        if (minDist > 5) \
        { \
            this->name##_sequence.resize(this->name##_sequence.size() + 1); \
            /*if (geojsonData.updateST)*/ \
                this->name##_sequence.last().updateST(geojsonData.st); \
            bool ret = this->name##_sequence.last().updateGeoJSONData(geojsonData, inserted); \
            inserted = true; \
            return ret; \
        } \
        return this->name##_sequence[index].updateGeoJSONData(geojsonData, inserted); \
    }

#define _UNIVERSIAL_TYPE_SEQUENCE_CALC_ABS_POS(start, end, type, name) \
    for (int i = 0; i < name##_sequence.size(); i ++) \
        name##_sequence[i].calcAbsolutePosIncludingChildren(road)

#define _UNIVERSIAL_TYPE_SEQUENCE_CALC_REL_POS(start, end, type, name) \
    for (int i = 0; i < name##_sequence.size(); i ++) \
        name##_sequence[i].calcRelativePosIncludingChildren(road)

/***********************************************************************/

#define _UNIVERSIAL_TYPE_empty_setParent_DEFINE(tagType) \
inline void setParent(void* parent = 0, bool resetChildren = true) \
{ \
    Q_UNUSED(parent) \
    Q_UNUSED(resetChildren) \
}

#define _UNIVERSIAL_TYPE_setParent_DEFINE(tagType) \
void* parent; \
inline void setParent(void* parent = 0, bool resetChildren = true) \
{ \
    this->parent = parent; \
    if (resetChildren) \
    { \
        _OD_MEMBERS(SET_PARENT, SEMICOLON) \
    } \
}

/***********************************************************************/

#define _UNIVERSIAL_TYPE_isCompatible_DEFINE(tagType) \
bool isCompatible(const tagType& other) const \
{ \
    return *this == other; \
}

#define _UNIVERSIAL_TYPE_operatorEqual_DEFINE(tagType) \
bool operator==(const tagType& other) const \
{ \
    Q_UNUSED(other); \
    return _OD_MEMBERS(COMPARE, AMPAMP) true; \
}

#define _UNIVERSIAL_TYPE_operatorNotEqual_DEFINE(tagType) \
bool operator!=(const tagType& other) const \
{ \
    return !(*this == other); \
}

#define _UNIVERSIAL_TYPE_isCompatible_operatorEqualNotEqual_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_isCompatible_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_operatorEqual_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_operatorNotEqual_DEFINE(tagType)

/***********************************************************************/

#define _UNIVERSIAL_TYPE_read_DEFINE(tagType) \
_NXML::XmlStatus read(const _NXML::XmlElement& node) \
{ \
    Q_UNUSED(node); \
    onBeforeRead(); \
    _NXML::XmlStatus status = _NXML::XmlElement::SUCCEEDED; \
    _OD_MEMBERS(READ, SEMICOLON) \
    onAfterRead(); \
    return status; \
} \
void read(QJsonObject obj) \
{ \
    Q_UNUSED(obj); \
    onBeforeRead(); \
    /*DefaultLogger_File << "reading  " << #tagType;*/ \
    _OD_MEMBERS(JSON_READ, SEMICOLON) \
    onAfterRead(); \
}

#define _UNIVERSIAL_TYPE_read1_DEFINE(tagType) \
_NXML::XmlStatus read(const _NXML::XmlElement& node) \
{ \
    Q_UNUSED(node); \
    _NXML::XmlStatus status = _NXML::XmlElement::SUCCEEDED; \
    _OD_MEMBERS(READ, SEMICOLON) \
    return status; \
} \
void read(QJsonObject obj) \
{ \
    Q_UNUSED(obj); \
    /*DefaultLogger_File << "reading  " << #tagType;*/ \
    _OD_MEMBERS(JSON_READ, SEMICOLON) \
}

#define _UNIVERSIAL_TYPE_write_DEFINE(tagType) \
void write(XmlStreamWriter& xmlWriter, bool forceToWriteOptionalValues = false) \
{ \
    Q_UNUSED(xmlWriter); \
    Q_UNUSED(forceToWriteOptionalValues); \
    /*onBeforeWrite();*/ \
    _OD_MEMBERS(WRITE, SEMICOLON) \
    onAfterWrite(); \
} \
void write(QJsonObject& obj, bool forceToWriteOptionalValues = false) \
{ \
    Q_UNUSED(obj); \
    Q_UNUSED(forceToWriteOptionalValues); \
    /*DefaultLogger_File << "writing  " << #tagType;*/ \
    onBeforeWrite(); \
    _OD_MEMBERS(JSON_WRITE, SEMICOLON) \
    onAfterWrite(); \
}

#define _UNIVERSIAL_TYPE_write1_DEFINE(tagType) \
void write(XmlStreamWriter& xmlWriter, bool forceToWriteOptionalValues = false) \
{ \
    Q_UNUSED(xmlWriter); \
    Q_UNUSED(forceToWriteOptionalValues); \
    _OD_MEMBERS(WRITE, SEMICOLON) \
} \
void write(QJsonObject& obj, bool forceToWriteOptionalValues = false) \
{ \
    Q_UNUSED(obj); \
    Q_UNUSED(forceToWriteOptionalValues); \
    /*DefaultLogger_File << "writing  " << #tagType;*/ \
    _OD_MEMBERS(JSON_WRITE, SEMICOLON) \
}

#define _UNIVERSIAL_TYPE_setTestData_DEFINE(tagType) \
void setTestData() \
{ \
    _OD_MEMBERS(SET_TEST_DATA, SEMICOLON) \
} \
void AddToGeoJsonTemplateData(QJsonArray& features, QJsonObject geomObject, QString tagName) \
{ \
    Q_UNUSED(features) \
    Q_UNUSED(geomObject) \
    Q_UNUSED(tagName) \
    _OD_MEMBERS(SAVE_GEO_JSON_DATA, SEMICOLON) \
} \
void saveGeoJsonTemplateData(QString path, QJsonObject geomObject) \
{ \
    QJsonObject featureCollection; \
    QJsonArray features; \
    AddToGeoJsonTemplateData(features, geomObject, #tagType); \
    featureCollection["type"] = "FeatureCollection"; \
    featureCollection["features"] = features; \
    QByteArray content = QJsonDocument(featureCollection).toJson(); \
    QString filePath = path + "/"; \
    filePath += #tagType; \
    filePath += ".geojson"; \
    QFile file(filePath); \
    file.open(QIODevice::WriteOnly); \
    file.write(content); \
    file.close(); \
}

#define _UNIVERSIAL_TYPE_updateGeoJSONData_DEFINE(tagType) \
bool updateGeoJSONData(_GeoJSONData& geojsonData, bool& inserted) \
{ \
    preUpdateGeoJSONData(geojsonData, inserted); \
    bool ret = updateGeoJSONData_Body(geojsonData, inserted); \
    postUpdateGeoJSONData(geojsonData, inserted); \
    return ret; \
} \
 \
void preUpdateGeoJSONData(_GeoJSONData& geojsonData, bool& inserted) \
{ \
    Q_UNUSED(geojsonData); \
    Q_UNUSED(inserted); \
} \
 \
bool updateGeoJSONData_Body(_GeoJSONData& geojsonData, bool& inserted) \
{ \
    qDebug() << #tagType << "          : updateGeoJSONData_Body"; \
    if (geojsonData.tag == #tagType) \
    { \
        if (geojsonData.operCommand != "" \
            && geojsonData.operCommand != "general") \
        { \
            return updateGeoJSONData_NonGeneral(geojsonData, inserted); \
        } \
        if (updateGeoJSONData_Itself_Pre(geojsonData, inserted)) \
            return true; \
        if (geojsonData.updateST) \
            updateST(geojsonData.st); \
        read(geojsonData.propsObj); \
        inserted = false; \
        return updateGeoJSONData_Itself_Post(geojsonData, inserted); \
    } \
    if (updateGeoJSONData_Children_Pre(geojsonData, inserted)) \
        return true; \
    if (geojsonData.isLine) \
    { \
        _OD_MEMBERS(UPDATE_GEO_JSON_DATA_LINE, SEMICOLON) \
    } \
    else \
    { \
        _OD_MEMBERS(UPDATE_GEO_JSON_DATA_POINT, SEMICOLON) \
    } \
    return updateGeoJSONData_Children_Post(geojsonData, inserted); \
} \
 \
bool updateGeoJSONData_NonGeneral(_GeoJSONData& geojsonData, bool& inserted) \
{ \
    Q_UNUSED(geojsonData); \
    Q_UNUSED(inserted); \
    return false; \
} \
 \
bool updateGeoJSONData_Itself_Pre(_GeoJSONData& geojsonData, bool& inserted) \
{ \
    Q_UNUSED(geojsonData); \
    Q_UNUSED(inserted); \
    return false; \
} \
 \
bool updateGeoJSONData_Itself_Post(_GeoJSONData& geojsonData, bool& inserted) \
{ \
    Q_UNUSED(geojsonData); \
    Q_UNUSED(inserted); \
    return true; \
} \
 \
bool updateGeoJSONData_Children_Pre(_GeoJSONData& geojsonData, bool& inserted) \
{ \
    Q_UNUSED(geojsonData); \
    Q_UNUSED(inserted); \
    return false; \
} \
 \
bool updateGeoJSONData_Children_Post(_GeoJSONData& geojsonData, bool& inserted) \
{ \
    Q_UNUSED(geojsonData); \
    Q_UNUSED(inserted); \
    return false; \
} \
 \
void postUpdateGeoJSONData(_GeoJSONData& geojsonData, bool& inserted) \
{ \
    Q_UNUSED(geojsonData); \
    Q_UNUSED(inserted); \
} \

/***********************************************************************/

#define _UNIVERSIAL_TYPE_POS_DEFINE(tagType) \
void calcAbsolutePosIncludingChildren(t_road& road) \
{ \
    this->calcAbsolutePos(road); \
    _OD_MEMBERS(CALC_ABS_POS, SEMICOLON) \
} \
 \
void calcRelativePosIncludingChildren(t_road& road) \
{ \
    this->calcRelativePos(road); \
    _OD_MEMBERS(CALC_REL_POS, SEMICOLON) \
}

#define _UNIVERSIAL_TYPE_empty_POS_DEFINE(tagType) \
void calcAbsolutePosIncludingChildren(t_road& road) \
{ \
    Q_UNUSED(road); \
} \
 \
void calcRelativePosIncludingChildren(t_road& road) \
{ \
    Q_UNUSED(road); \
}

/***********************************************************************/

#define _UNIVERSIAL_TYPE_read_write_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_read_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_write_DEFINE(tagType)

#define _UNIVERSIAL_TYPE_read1_write1_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_read1_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_write1_DEFINE(tagType)

/***********************************************************************/

#define _UNIVERSIAL_TYPE_isComp_opENE_RW1_TEST_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_isCompatible_operatorEqualNotEqual_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_read1_write1_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_setTestData_DEFINE(tagType)

/***********************************************************************/

#define _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_POS_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_setParent_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_isCompatible_operatorEqualNotEqual_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_read_write_DEFINE(tagType)

#define _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_setTestData_DEFINE(tagType)

#define _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_GeoJSON_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW_TEST_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_updateGeoJSONData_DEFINE(tagType)

/***********************************************************************/

#define _UNIVERSIAL_TYPE_parent_isComp_opENE_RW1_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_setParent_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_isCompatible_operatorEqualNotEqual_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_read1_write1_DEFINE(tagType)

#define _UNIVERSIAL_TYPE_parent_isComp_opENE_RW1_TEST_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_parent_isComp_opENE_RW1_DEFINE(tagType) \
    _UNIVERSIAL_TYPE_setTestData_DEFINE(tagType)

/***********************************************************************/

struct UniversialType
{
public:
    virtual void onBeforeRead(){}
    virtual void onAfterRead(){}
    virtual void onBeforeWrite() {}
    virtual void onAfterWrite() {}

};

}
