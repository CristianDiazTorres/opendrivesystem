#include "XODR/OpenDRIVE/core/t_header.h"

namespace _NOD
{

void t_header::init(const Cell& cell)
{
    this->revMajor = 1;
    this->revMinor = 6;
    this->name = cell.getName();
    this->version = "1.0";
    this->date = _NOD::_date::currentDateTimeUtc();

    QRectF bound = cell.getCellBoundInMeters();
    this->north = bound.bottom();
    this->south = bound.top();
    this->east = bound.left();
    this->west = bound.right();

    this->geoReference_sequence.resize(1);

    CoordSys coordSys;
    coordSys.setFromCell(cell);
    this->geoReference_sequence[0].proj = coordSys.getProj4();
}

}
