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


#include "OSM/ResultGenerator.h"
#include "Common/Json.h"

#define WAY_JSON_PATH				"Result_Ways.json"
#define NODE_JSON_PATH				"Result_Nodes.json"

namespace _NOSM
{

/* output with JSON format */
void ResultGenerator::JsonParserOutput(WayVec& ways)
{
    File file(WAY_JSON_PATH);
    file.open(QIODevice::WriteOnly);
    file.write(GetJSONData(ways));
}

void ResultGenerator::JsonParserOutput(NodeVec& nodes)
{
    File file(NODE_JSON_PATH);
    file.open(QIODevice::WriteOnly);
    file.write(GetJSONData(nodes));
}

ByteArray ResultGenerator::GetJSONData(WayVec& ways)
{
    JsonDocument doc(_NCM::ToJsonArrayOfObject(ways));
    return doc.toJson(JsonDocument::Indented);
}

ByteArray ResultGenerator::GetJSONData(NodeVec& nodes)
{
    JsonDocument doc(_NCM::ToJsonArrayOfObject(nodes));
    return doc.toJson(JsonDocument::Indented);
}
}
