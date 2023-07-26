#include "XODR/OpenDRIVE/lane/t_road_lanes_laneSection_lr_lane.h"

namespace _NOD
{

void t_road_lanes_laneSection_lr_lane::setDefaultValues()
{
    this->type = e_laneType::DRIVING;
    this->width_sequence.resize(1);
    this->width_sequence[0].sOffset = 0;
    this->width_sequence[0].a = 3.5;
    this->width_sequence[0].b = 0;
    this->width_sequence[0].c = 0;
    this->width_sequence[0].d = 0;
}

}
