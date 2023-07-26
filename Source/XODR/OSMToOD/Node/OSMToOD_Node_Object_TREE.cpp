#include "XODR/OSMToOD/OSMToOD.h"

namespace _NXODR
{

bool OSMToOpenDRIVE::convertNode_Object_TREE(OSMToOpenDRIVE_CONVERTNODE_PARAMS)
{
    Q_UNUSED(database_connector);
    Q_UNUSED(osmNode);
    Q_UNUSED(amenity);
    Q_UNUSED(values);
    Q_UNUSED(odRoad);

    if (OSMToOpenDRIVE_CONTAINS_KEY(_SC_tree) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_trees) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_natural_tree_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_natural_1_tree_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_abandoned_tree_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_abandoned_natural_tree_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_barrier_tree_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_razed_tree_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_razed_natural_tree_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY(_SC_ruins_tree_A) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_natural, _SC_tree) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_natural_1, _SC_tree) ||
        OSMToOpenDRIVE_CONTAINS_KEY_CONTAINS_VALUE(_SC_natura, _SC_tree) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_old_natural_A, _SC_tree) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_old_natural, _SC_tree) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_plant, _SC_tree) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_abandoned, _SC_tree) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_abandoned_natural_A, _SC_tree) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_barrier, _SC_tree) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_barrier_type_A, _SC_tree) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_blazed_natural_A, _SC_tree) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_dead_natural_A, _SC_tree) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_demolished, _SC_tree) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_demolished_natural_A, _SC_tree) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_destroyed_natural_A, _SC_tree) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_forest, _SC_tree) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_gone_natural_A, _SC_tree) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_razed, _SC_tree) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_razed_natural_A, _SC_tree) ||
        OSMToOpenDRIVE_CONTAINS_KEY_EQUAL_VALUE(_SC_ruins, _SC_tree))
    {
        od_object.type = _NOD::e_objectType::TREE;
        return true;
    }

    return false;
}

}
