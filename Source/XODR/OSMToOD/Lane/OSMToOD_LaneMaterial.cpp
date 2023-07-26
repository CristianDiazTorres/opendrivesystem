#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

void OSMToOpenDRIVE::convertLaneMaterial(DatabaseConnector& database_connector,
                                       const _NOSM::Way& osmWay,
                                       int osmLaneIndex,
                                       _NOD::t_road& odRoad,
                                       _NOD::t_road_lanes_laneSection_lr_lane& odLane)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(osmLaneIndex);
    Q_UNUSED(odRoad);

    if (osmWay.osm.contains(_SC_surface))
    {
        _NOD::t_road_lanes_laneSection_lr_lane_material odLaneMaterial;
        odLaneMaterial.sOffset = 0;
        odLaneMaterial.friction = 0;
        odLaneMaterial.roughness = 0;
        odLaneMaterial.surface = osmWay.osm[_SC_surface];

        odLane.material_sequence << odLaneMaterial;
    }
}

}
