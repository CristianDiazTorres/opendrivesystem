#include "XODR/OSMToOD/OSMToOD.h"
#include "XODR/Main/XODRSettingsOnPGDatabase.h"

namespace _NXODR
{

void OSMToOpenDRIVE::convertNodes(DatabaseConnector& database_connector, QVector<_NOSM::Node>& osmNodes, QVector<_NOD::t_road> &odRoads)
{
    for (_NOSM::Node& osmNode : osmNodes)
        convertNode(database_connector, osmNode, odRoads);
}

void OSMToOpenDRIVE::convertNode(DatabaseConnector& database_connector, _NOSM::Node& osmNode, QVector<_NOD::t_road> &odRoads)
{
    double minDist = 0;
    int nearestIndex = _NMath::getNearestIndex(osmNode.coord, odRoads, minDist);

    if (nearestIndex < 0)
        return;

    if (minDist > MAX_NODE_ROAD_DISTANCE)
        return;

    convertNode(database_connector, osmNode, odRoads[nearestIndex]);
}

void OSMToOpenDRIVE::convertNode(DatabaseConnector& database_connector, _NOSM::Node& osmNode, _NOD::t_road &odRoad)
{
    Q_UNUSED(database_connector);

    QList<QString> values = osmNode.osm.values();
    QString amenity = osmNode.osm[_SC_amenity];

    if (convertNode_Signal(database_connector, osmNode, amenity, values, odRoad))
        return;

    _NOD::t_road_objects_object od_object;
    bool converted =
            convertNode_Object_CROSSWALK(database_connector, osmNode, amenity, values, odRoad, od_object) ||
            convertNode_Object_STREETLAMP(database_connector, osmNode, amenity, values, odRoad, od_object) ||
            convertNode_Object_TRAFFICISLAND(database_connector, osmNode, amenity, values, odRoad, od_object) ||
            convertNode_Object_ROADMARK(database_connector, osmNode, amenity, values, odRoad, od_object) ||
            convertNode_Object_PARKINGSPACE(database_connector, osmNode, amenity, values, odRoad, od_object) ||

            convertNode_Object_RAILING(database_connector, osmNode, amenity, values, odRoad, od_object) ||
            convertNode_Object_GANTRY(database_connector, osmNode, amenity, values, odRoad, od_object) ||
            convertNode_Object_POLE(database_connector, osmNode, amenity, values, odRoad, od_object) ||
            convertNode_Object_TREE(database_connector, osmNode, amenity, values, odRoad, od_object) ||
            convertNode_Object_VEGETATION(database_connector, osmNode, amenity, values, odRoad, od_object) ||
            convertNode_Object_BARRIER(database_connector, osmNode, amenity, values, odRoad, od_object) ||
            convertNode_Object_OBSTACLE(database_connector, osmNode, amenity, values, odRoad, od_object) ||

            convertNode_Object_SOUNDBARRIER(database_connector, osmNode, amenity, values, odRoad, od_object) ||
            convertNode_Object_PATCH(database_connector, osmNode, amenity, values, odRoad, od_object) ||

            convertNode_Object_BUILDING(database_connector, osmNode, amenity, values, odRoad, od_object) ||

            convertNode_Object_CAR(database_connector, osmNode, amenity, values, odRoad, od_object) ||
            convertNode_Object_BIKE(database_connector, osmNode, amenity, values, odRoad, od_object) ||
            convertNode_Object_MOTORBIKE(database_connector, osmNode, amenity, values, odRoad, od_object) ||
            convertNode_Object_BUS(database_connector, osmNode, amenity, values, odRoad, od_object) ||
            convertNode_Object_TRAILER(database_connector, osmNode, amenity, values, odRoad, od_object) ||
            convertNode_Object_TRAIN(database_connector, osmNode, amenity, values, odRoad, od_object) ||
            convertNode_Object_TRAM(database_connector, osmNode, amenity, values, odRoad, od_object) ||
            convertNode_Object_VAN(database_connector, osmNode, amenity, values, odRoad, od_object) ||
            convertNode_Object_PEDESTRIAN(database_connector, osmNode, amenity, values, odRoad, od_object) ||

            convertNode_Object_WIND(database_connector, osmNode, amenity, values, odRoad, od_object);

    if (!converted)
        return;

    od_object.id = database_connector.getNewID();
    od_object.name = osmNode.osm[_SC_name];

    odRoad.calcST(osmNode.coord, od_object);

    od_object.zOffset = 0;
    od_object.validLength = 0;
    od_object.hdg = 0;
    od_object.pitch = 0;
    od_object.roll = 0;
    od_object.height = 0;
    od_object.length = 0;
    od_object.width = 0;
    od_object.radius = 0;

    if (XODRSettingsOnPGDatabase_getDefaultInstance.haveToWriteOSM())
    {
        _NOD::t_userData odUserData(_SC_osm);
        odUserData.osm_sequence << osmNode.osm;
        od_object.additionalData.userData_sequence << odUserData;
    }

    if (odRoad.objects_sequence.isEmpty())
        odRoad.objects_sequence.resize(1);
    odRoad.objects_sequence[0].object_sequence << od_object;
}

}
