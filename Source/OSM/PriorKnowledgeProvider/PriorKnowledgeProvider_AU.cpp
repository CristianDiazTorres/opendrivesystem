
#include "OSM/PriorKnowledgeProvider/PriorKnowledgeProvider_AU.h"
#include "OSM/Way/Way.h"

// https://wiki.openstreetmap.org/wiki/Australian_Tagging_Guidelines
// https://wiki.openstreetmap.org/wiki/Australian_data_catalogue
// https://en.wikipedia.org/wiki/Highways_in_Australia
// https://en.wikipedia.org/wiki/Freeways_in_Australia
// https://vicroadsopendata-vicroadsmaps.opendata.arcgis.com/datasets/road-width-and-number-of-lanes/data?selectedAttribute=NUMBER_OF_TRAFFIC_LANES

namespace _NOSM
{

bool PriorKnowledgeProvider_AU::fillLanesCount_Oneway(Way& way)
{
    Q_ASSERT(way.laneCount <= 0);

    // https://wiki.openstreetmap.org/wiki/Australian_Tagging_Guidelines
    way.laneCount = 1; // Default value
    return true;
}

bool PriorKnowledgeProvider_AU::fillLanesCount_Bidirectional(Way& way)
{
    Q_ASSERT(way.laneCount <= 0);

    // https://wiki.openstreetmap.org/wiki/Australian_Tagging_Guidelines
    way.laneCount = 2; // Default value
    return true;
}

void PriorKnowledgeProvider_AU::fillLanesCount_Other(Way& way)
{
    Q_ASSERT(way.laneCount <= 0);

    // https://wiki.openstreetmap.org/wiki/Australian_Tagging_Guidelines
    way.laneCount = 2; // Default value
}

/*
Urban arterial road widths

Element                         Lane width (m)  Comments

General traffic lane            3.5             General traffic lane widths to be used for all roads
                                3.0-3.4         For use on low speed roads with low truck volumes

Service road lane               3.4-5.5         Range of lane widths on service roads (refer to Section 4.11)

Wide kerbside lane              4.2             Locations where there are high truck volumes (addtional width provided for trucks)
                                4.2-4.5         Locations where motorists and cyclists use the same lane (refer Section 4.8.11 and Commentary 6)

HOV lane                        3.5-4.5         Bus lane (refer Section 4.9.2)
                                3.3             Tram/light rail vehicle lane (refer Section 4.9.3)

Minimum width between kerbe     5.0-6.5         Width of a single lane suitable for use in a left turn slip lane,
and channel (to provide                         or two lane, two way divided road with a raised median
for passing of broken down      2 * 4.0 (8.0)   Width of two lanes that provide for two lines of traffic to
vehicles)                                       (slowly) pass a broken down vehicle.



Urban freeway widths

Element                         Lane width (m)  Comments
Traffic lane(1)                 3.5             General traffic lane width

Lane width on interchange       3.5-4.5         Range of lane widths on interchange ramps, (refer to the Guide to
ramps                                           Road Design Part 4C (Austroads 2015e))

Left shoulder(2)                2.0-3.0(3)      Range of left shoulder widths
(sealed for the full width)     3.0             Minimum shoulder width adjacent to a safety barrier
                                                Minimum shoulder widths on freeways of three or more lanes

Median shoulder(2)              1.0-3.0(3)      Range of shoulder widths
(sealed for the full width)     3.0             Minimum shoulder width adjacent to a safety barrier
                                                Minimum shoulder widths on freeways of three or more lanes.


Divided carriageway rural road widths
Element                         Design AADT
                                < 20 000        > 20 000
Traffic lanes(1)                3.5             3.5

Shoulder
Left                            2.5             3.0
Median                          1.0             1.0

Shoulder seal(2, 3)
Left                            1.5             3.0
Median                          1.0             1.0

example: 2 km, 0.6, 12'6" (feet inch)

*/
void PriorKnowledgeProvider_AU::fillWidthLanes(Way &way)
{
    PriorKnowledgeProvider__LHT::fillWidthLanes(way);
}

// https://austroads.com.au/publications/asset-management/ap-r578-18/media/AP-578-18_Harmonisation_of_Pavement_Markings_and_National_Pavement_Marking_Specification.pdf

void PriorKnowledgeProvider_AU::fillRoadMark(Way& way)
{
    PriorKnowledgeProvider__LHT::fillRoadMark(way);
}

}
