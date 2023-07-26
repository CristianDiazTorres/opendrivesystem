/*
 * This file is part of OSM module and implemention of PriorKnowledgeProvider submodule.
 * Developed for the OpenStreet Data Management System.
 *
 * This module is submodule for provide lanes of way detail property.
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
#include "OSM/PriorKnowledgeProvider/PriorKnowledgeProvider.h"
#include "OSM/PriorKnowledgeProvider/PriorKnowledgeProvider__LHT.h"
#include "OSM/PriorKnowledgeProvider/PriorKnowledgeProvider__RHT.h"
#include "OSM/PriorKnowledgeProvider/PriorKnowledgeProvider_AU.h"
#include "OSM/Way/Way.h"

namespace _NOSM
{

void PriorKnowledgeProvider::fillWayAttrs(Way &way)
{
    QString country = way.osm[_SC_addr_country_A];
    if (country == _SC_AU)
    {
        PriorKnowledgeProvider_AU().fillWayAttrs(way);
    }
    else if (way.isLHT())
    {
        PriorKnowledgeProvider__LHT().fillWayAttrs(way);
    }
    else
    {
        PriorKnowledgeProvider__RHT().fillWayAttrs(way);
    }

}

}
