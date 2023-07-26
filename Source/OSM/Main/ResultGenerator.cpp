/*
 * This file is part of OSM module and header of ResultGenerator submodule.
 * Developed for the OpenStreet Data Management System.
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.
 */


#include "OSM/Main/ResultGenerator.h"
#include <QDir>
#include <QDateTime>
#include <QJsonDocument>
#include "Common/Main/JsonArray.h"
#include "Common/Main/File.h"

#define WAY_JSON_FILE				"/Result_Ways"
#define NODE_JSON_FILE				"/Result_Nodes"

namespace _NOSM
{

/* output with JSON format */
void ResultGenerator::writeJsonParserOutput(WayVec& ways, const QString& jsonPath)
{
    _NCM::writeToFile(jsonPath + WAY_JSON_FILE + QDateTime::currentDateTime().toString().replace(':', '-') + ".json", getJSONData(ways));
}

void ResultGenerator::writeJsonParserOutput(NodeVec& nodes, const QString& jsonPath)
{
    _NCM::writeToFile(jsonPath + NODE_JSON_FILE + QDateTime::currentDateTime().toString().replace(':', '-') + ".json", getJSONData(nodes));
}

QByteArray ResultGenerator::getJSONData(WayVec& ways)
{
    QJsonDocument doc(_NCM::toJsonArrayOfObject(ways));
    return doc.toJson();
}

QByteArray ResultGenerator::getJSONData(NodeVec& nodes)
{
    QJsonDocument doc(_NCM::toJsonArrayOfObject(nodes));
    return doc.toJson();
}
}
