#include "OSM/Way/Way.h"

namespace _NOSM
{

void Way::parseRoadMark()
{
    // Center
    copyValueIfDestNotExistSrcExists(_SC_road_marking_center_A, _SC_central_line);
    copyValueIfDestNotExistSrcExists(_SC_road_marking_center_A, _SC_central_reservation);
    copyValueIfDestNotExistSrcExists(_SC_road_marking_center_A, _SC_centreline);
    copyValueIfDestNotExistSrcExists(_SC_road_marking_center_A, _SC_divider);

    // Center color
    copyValueIfDestNotExistSrcExists(_SC_road_marking_center_color_A, _SC_centreline_color_A);

    // Center material
    copyValueIfDestNotExistSrcExists(_SC_road_marking_center_material_A, _SC_divider_material_A);

    // General color
    if (osm.contains(_SC_road_marking_colour_A))
    {
        copyValue(_SC_road_marking_color_A, _SC_road_marking_colour_A);
    }
    else if (osm.contains(_SC_road_marking))
    {
         if (osm[_SC_road_marking].contains(_SC_yellow))
         {
             osm[_SC_road_marking_color_A] = _SC_yellow;
         }
    }

    // Curb
    copyValueIfDestNotExistSrcExists(_SC_road_marking_curb_A, _SC_barrier);
    copyValueIfDestNotExistSrcExists(_SC_road_marking_curb_A, _SC_barrier_type_A);
    copyValueIfDestNotExistSrcExists(_SC_road_marking_curb_A, _SC_sloped_curb);
}

/*

central_line	continuous	4	0
central_line	dashed		70	0
central_line	no		28	0
central_line	yes		294	0

central_reservation	dashed_line	2	0

centreline	dash			78	0
centreline	dashed			28	0
centreline	double_solid		9	0
centreline	double_white		1	0
centreline	island			8	0
centreline	no			242	0
centreline	raised island		2	0
centreline	solid			70	0
centreline	solid|dash|solid	2	0
centreline	solid|solid		44	0
centreline	yes			329	0

centreline:color	yellow	10	0

cycleway:both:separation:left	dashed_line	11	0
cycleway:both:separation:left	solid_line	1	0

cycleway:both:separation:right	dashed_line		1	0
cycleway:both:separation:right	parking_lane;kerb	1	0

cycleway:lane	dashed			8	0
cycleway:lane	solid			3	0

cycleway:left:separation:left	cone		5	0
cycleway:left:separation:left	dashed_line	12	0
cycleway:left:separation:left	solid_line	3	0
cycleway:left:separation:left	vertical_panel	1	0

cycleway:left:separation:right	dashed_line		1	0
cycleway:left:separation:right	kerb			5	0
cycleway:left:separation:right	kerb;bollard		10	0
cycleway:left:separation:right	parking_lane;kerb	3	0

cycleway:right:separation:left	dashed_line			95	0
cycleway:right:separation:left	kerb				3	0
cycleway:right:separation:left	no				1	0
cycleway:right:separation:left	solid_line			123	0
cycleway:right:separation:left	solid_line;parking_lane		10	0
cycleway:right:separation:left	vertical_panel			71	0
cycleway:right:separation:left	vertical_panel;parking_lane	4	0

cycleway:right:separation:right	bus_lane			8	0
cycleway:right:separation:right	dashed_line			26	0
cycleway:right:separation:right	dashed_line;bus_lane		1	0
cycleway:right:separation:right	dashed_line;parking_lane	22	0
cycleway:right:separation:right	kerb				79	0
cycleway:right:separation:right	kerb;bollard			9	0
cycleway:right:separation:right	kerb;dashed_line		1	0
cycleway:right:separation:right	kerb;grass_verge		1	0
cycleway:right:separation:right	kerb;parking_lane		15	0
cycleway:right:separation:right	kerb;tree_row			6	0
cycleway:right:separation:right	not_required			2	0
cycleway:right:separation:right	parking_lane			14	0
cycleway:right:separation:right	parking_lane;kerb		1	0

cycleway:right:separation:right:lanes	||solid_line||kerb	1	0
cycleway:right:separation:right:lanes	|||solid_line||kerb	1	0

cycleway:separation:both	dashed_line	2	0

cycleway:separation:left	bollard		1	0
cycleway:separation:left	dashed_line	14	0
cycleway:separation:left	de:628-10	1	0
cycleway:separation:left	kerb		1	0
cycleway:separation:left	solid_line	6	0

cycleway:separation:right	dashed_line			4	0
cycleway:separation:right	dashed_line;bus_lane		3	0
cycleway:separation:right	dashed_line;parking_lane	8	0
cycleway:separation:right	kerb				3	0
cycleway:separation:right	parking_lane			3	0

divided	median	2	0
divided	no	3	0
divided	yes	8	0

divided_road	yes	1	0

divider	barrier			4	0
divider	center_turn		1	0
divider	dashed_line		214	0
divider	double_solic_line	1	0
divider	double_solid_line	39	0
divider	double_solid_yellow	7	0
divider	gap			3	0
divider	grass			1	0
divider	legal			50	0
divider	line			78	0
divider	median			81	0
divider	n			1	0
divider	no			109	0
divider	none			1	0
divider	painted_area		1	0
divider	physical		73	0
divider	solid_area		3	0
divider	solid_line		186	0
divider	yes			4	0

divider:backward	line	1	0

divider:left	solid_line	84	0

divider:material	grass	35	0

road_marking	solid_stop_line													24554	1
road_marking	centreline													10	0
road_marking	dash														1154	0
road_marking	dashed_crossing_edge												108	0
road_marking	dashed_give_way_line												46	0
road_marking	dashed_lane_divider												6	0
road_marking	dashed_road_edge												1	0
road_marking	dashes														3	0
road_marking	dash_road_edge													1	0
road_marking	dotted_line													5	0
road_marking	no														118	0
road_marking	no public access												1	0
road_marking	none														3	0
road_marking	solid_carriageway_divider											1	0
road_marking	solid_crossing_edge												708	0
road_marking	solid_crossing_edgew												1	0
road_marking	solid_lane_divider												1325	0
road_marking	solid_line													1	0
road_marking	solid_road_divide												3	0
road_marking	solid_road_divider												8	0
road_marking	solid_road_edge													191	0
road_marking	turn_dashes													24	0
road_marking	yellow_divider													121	0
road_marking	yellow_road_edge												37	0
road_marking	yes														87	0
road_marking	zebra														216	0
road_marking	zone														1	0

road_marking:basic_form	single_line_continuous	13	0
road_marking:basic_form	single_line_dashed	7	0

road_marking:colour	white	2	0
road_marking:colour	yellow	10	0

road_marking:line_length	1	2	0
road_marking:line_length	1.5	5	0

road_marking:line_width	0.12	20	0

road_marking:proportion_line_gab	1:1	5	0
road_marking:proportion_line_gab	1:2	2	0
road_marking:proportion_line_gab	no_gab	13	0

road_marking:right	solid_line	2	0

road_marking:right:colour	white	2	0

road_markings	no	2	0

separated	fixme	3	0
separated	no	2543	0
separated	yes	634	0

separation:both	grass_verge	1	0
separation:both	kerb		1	0
separation:both	surface		2	0
separation:both	tree_row	1	0

separation:left	bollard				8	0
separation:left	bollard;kerb			1	0
separation:left	dashed_line			20	0
separation:left	grass_strip;tree_row		2	0
separation:left	grass_verge			3	0
separation:left	kerb				27	0
separation:left	kerb;parking_lane		17	0
separation:left	no				13	0
separation:left	not_required			1	0
separation:left	parking_lane;bollard		9	0
separation:left	parking_lane;dashed_line	1	0
separation:left	parking_lane;kerb		5	0
separation:left	separation_kerb			16	0
separation:left	solid_line			13	0
separation:left	surface				5	0
separation:left	tree_row			11	0
separation:left	vertical_panel			3	0
separation:left	vertical_panel;parking_lane	4	0

separation:right	dashed_line	12	0
separation:right	grass_verge	5	0
separation:right	hedge		2	0
separation:right	kerb		51	0
separation:right	no		15	0
separation:right	railing		1	0
separation:right	solid_line	3	0
separation:right	surface		51	0
separation:right	tree_row	6	0

seperate	yes	96	0

seperated	no	4	0
seperated	yes	7	0

barrier	curb		351	1
barrier	kerb		217608	1

barrier:type	curb			1	0

curb	broken			1	0
curb	flush			98	0
curb	lowered			185	0
curb	lowered;sloped		1	0
curb	lowered_and_sloped	110	0
curb	median			1	0
curb	missing			3	0
curb	no			3	0
curb	none			1	0
curb	raised			28	0
curb	regular			373	0
curb	sloped			103	0
curb	soft			1	0
curb	yes			15	0

sloped_curb	0,03	1	0

footway:left:sloped_curb	0,04	1	0
footway:left:sloped_curb	0.13	1	0

footway:left:sloped_curb:end	0,015	1	0
footway:left:sloped_curb:end	8	6	0

footway:left:sloped_curb:start	0,001	1	0
footway:left:sloped_curb:start	8	6	0

footway:right:sloped_curb	0,035	1	0
footway:right:sloped_curb	0.13	1	0

footway:right:sloped_curb:end	0	11	0
footway:right:sloped_curb:end	8	6	0

footway:right:sloped_curb:start	0	7	0
footway:right:sloped_curb:start	8	6	0

highway:barrier	curb	94	0
highway:barrier	high	11	0
highway:barrier	yes	9	0


sidewalk:both:sloped_curb	0.10	2	0

sidewalk:both:sloped_curb:end	0.066	5	0
sidewalk:both:sloped_curb:end	15	1	0

sidewalk:both:sloped_curb:start	0.09	5	0
sidewalk:both:sloped_curb:start	15	1	0

sidewalk:left	kerb		11	0
sidewalk:left	kerb:raised	1	0
sidewalk:left	lane		50	0
sidewalk:left	left		6	0
sidewalk:left	no		2301	0
sidewalk:left	none		61	0
sidewalk:left	official	1	0
sidewalk:left	paved		1	0
sidewalk:left	paving_stones	2	0
sidewalk:left	raised		10	0
sidewalk:left	segregated=yes	1	0
sidewalk:left	separat		7	0
sidewalk:left	separate	5316	0
sidewalk:left	separated	6	0
sidewalk:left	seperate	14	0
sidewalk:left	seperated	6	0
sidewalk:left	shared		73	0
sidewalk:left	sidepath	44	0
sidewalk:left	sloped_curb	1	0

sidewalk:left:sloped_curb	0.02	4	0
sidewalk:left:sloped_curb	no	2	0

sidewalk:left:sloped_curb:end	.01	2	0
sidewalk:left:sloped_curb:end	8	2	0

sidewalk:left:sloped_curb:start	.01	1	0
sidewalk:left:sloped_curb:start	5	2	0

sidewalk:left:tactile_paving	no	10	0
sidewalk:left:tactile_paving	yes	4	0

sidewalk:left:tactile_paving:curb:end	yes	2	0

sidewalk:left:tactile_paving:curb:start	yes	2	0

sidewalk:right:sloped_curb	0	6	0
sidewalk:right:sloped_curb	2	5	0

sidewalk:right:sloped_curb:end	.01	2	0
sidewalk:right:sloped_curb:end	8	3	0

sidewalk:right:sloped_curb:start	.02	2	0
sidewalk:right:sloped_curb:start	8	1	0

sidewalk:sloped_curb:end	0.01	1	0
sidewalk:sloped_curb:end	0.04	2	0

sidewalk:sloped_curb:start	0.01	3	0
sidewalk:sloped_curb:start	0.04	1	0

slope:material	stone	3	0

sloped_curb	-0.06		2	0
sloped_curb	0.15		5	0
sloped_curb	at_grade	142	0
sloped_curb	both		1100	0
sloped_curb	left		3	0
sloped_curb	low		1	0
sloped_curb	no		422	0
sloped_curb	one		10	0
sloped_curb	right		8	0
sloped_curb	yes		1140	0

sloped_curb:end	.10	1	0
sloped_curb:end	0.08	1	0

sloped_curb:left	0.02	4	0
sloped_curb:left	no	1	0
sloped_curb:left	yes	1	0

sloped_curb:left:end	0.02	1	0
sloped_curb:left:start	0.02	1	0

sloped_curb:right	0.00	2	0
sloped_curb:right	no	1	0
sloped_curb:right	yes	1	0

sloped_curb:start	.01	1	0
sloped_curb:start	0.05	2	0

slopes	56	1	0

slopes:material	stone	5	0

slope_material	sheet_piles	2	0

*/


}
