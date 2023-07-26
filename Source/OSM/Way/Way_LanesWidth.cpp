#include "OSM/Way/Way.h"

namespace _NOSM
{

void Way::parseLanesWidth()
{
    // width:lanes & lanes:width
    copyValueIfDestNotExistSrcExists(_SC_width_lanes_A, _SC_lanes_width_A);
}

}
