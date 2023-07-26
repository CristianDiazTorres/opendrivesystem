#include "OSM/Way/Way.h"

namespace _NOSM
{

/*
junction	circular							17373	1
junction	crossing							34	1
junction	intersection							231	1
junction	jughandle							3073	1
junction	roundabout							655322	1
junction	spui								4465	1
junction	yes								32445	1
junction	filter								0	1
junction	 roundabout							1	0
junction	*								1	0
junction	1								2	0
junction	104b								1	0
junction	128								1	0
junction	15a								1	0
junction	3								1	0
junction	=intersection							1	0
junction	alfhilds väg							1	0
junction	ap								2	0
junction	apporach							2	0
junction	appraoch							2	0
junction	approach							1660	0
junction	asphalt								1	0
junction	avenida barreiros						1	0
junction	bergalundsvägen							2	0
junction	bidirectional-roundabout					1	0
junction	bokbacken							1	0
junction	box_junction							4	0
junction	braid								7	0
junction	calle almez							1	0
junction	calle etia							1	0
junction	calle oro							1	0
junction	calle pradera poniente						1	0
junction	calle topacio							1	0
junction	caribou court							1	0
junction	carretera palomas-tlapa						1	0
junction	cfi								8	0
junction	ciircular							6	0
junction	circle								7	0
junction	cloverleaf							297	0
junction	connector							8	0
junction	ddi								156	0
junction	diamond								1228	0
junction	diverging diamond interchange					6	0
junction	diverging_diamond						13	0
junction	do								1	0
junction	double_trumpet							62	0
junction	entrada a la avenida nutibara desde la avenida bolivariana	2	0
junction	entrada desde avenida bolivariana				6	0
junction	entrada desde avenira bolivariana hacia glorieta		3	0
junction	exchange							1	0
junction	exit								2	0
junction	farm								1	0
junction	folded_diamond							271	0
junction	footway								1	0
junction	gap								3	0
junction	gate								3	0
junction	geumak-ro							1	0
junction	give_way							1	0
junction	gullbergsvägen							3	0
junction	gyratory							60	0
junction	h								4	0
junction	half_diamond							85	0
junction	half_folded_diamond						173	0
junction	interchange							513	0
junction	interesection							1	0
junction	j								2	0
junction	jönsagårdsvägen							1	0
junction	junction							1	0
junction	junction_area							1	0
junction	korsvägen							1	0
junction	leaf								7	0
junction	level_crossing							1	0
junction	lidalsbacken							1	0
junction	lindängsgatan							1	0
junction	link								7	0
junction	logical								27	0
junction	lottas väg							1	0
junction	merging								1	0
junction	michigan_left							24	0
junction	mini_roundabout							17	0
junction	mini_roundbouat							3	0
junction	motorway_junction						1	0
junction	motorway_link							4	0
junction	naryan chowk							1	0
junction	no								31	0
junction	normal								25	0
junction	offramp								206	0
junction	offroad								2	0
junction	off_ramp							8	0
junction	oneway								2	0
junction	onramp								200	0
junction	onroad								2	0
junction	on_ramp								5	0
junction	parclo								538	0
junction	physical							27	0
junction	place marengo							1	0
junction	priority							5	0
junction	privada oro							1	0
junction	r								1	0
junction	ramp								23	0
junction	rci								10	0
junction	residential							9	0
junction	retail								1	0
junction	retail and residence						1	0
junction	ro								3	0
junction	rondabout							4	0
junction	rou								3	0
junction	roud								1	0
junction	rounadabout							1	0
junction	round								2	0
junction	round about							1	0
junction	roundaboutm							1	0
junction	roundabouto							1	0
junction	roundaboutv							3	0
junction	roundabout_link							20	0
junction	salida desde glorieta hacia av. bolivariana sur			5	0
junction	separate							15	0
junction	slip								2	0
junction	solhemsvägen							1	0
junction	split_diamond							44	0
junction	square								1	0
junction	t								4	0
junction	t-junction							3	0
junction	teardrop							47	0
junction	teardrop_roundabout						15	0
junction	tertiary							2	0
junction	throughabout							5	0
junction	traffic circle							3	0
junction	traffic lights							2	0
junction	traffic_circle							15	0
junction	traffic_signals							203	0
junction	true								50	0
junction	trumpet								165	0
junction	turnaround							182	0
junction	turning_circle							12	0
junction	turning_loop							13	0
junction	t_junction							12	0
junction	t_junction_ne_tertiary_into_secondary				1	0
junction	undefined							3	0
junction	unpaved								1	0
junction	utmålsvägen							1	0
junction	weaving								2	0
junction	x_junction							12	0
junction	y-junction							8	0
junction	yrs								2	0
junction	y_juncion							1	0
junction	y_junctin							1	0
junction	y_junction							994	0
junction	z?junction							3	0
junction	zes								1	0
*/

void Way::parseJunction()
{
    // junction=roundabout
    if (osm.contains(_SC_junction))
    {
        if (osm[_SC_junction] == _SC_ro ||
            osm[_SC_junction] == _SC_rondabout ||
            osm[_SC_junction] == _SC_rou ||
            osm[_SC_junction] == _SC_roud ||
            osm[_SC_junction] == _SC_rounadabout ||
            osm[_SC_junction] == _SC_round ||
            osm[_SC_junction] == _SC_round_about__1 ||
            osm[_SC_junction] == _SC_roundaboutm ||
            osm[_SC_junction] == _SC_roundabouto ||
            osm[_SC_junction] == _SC_roundaboutv ||
            osm[_SC_junction] == _SC_roundabout_link)
        {
            osm[_SC_junction] = _SC_roundabout;
        }

        if (osm[_SC_junction] == _SC_roundabout ||
            osm[_SC_junction] == _SC_mini_roundabout ||
            osm[_SC_junction] == _SC_mini_roundbouat ||
            osm[_SC_junction] == _SC_teardrop_roundabout)
        {
            setIfNotContain(_SC_oneway, _SC_yes);
        }
    }
}

}
