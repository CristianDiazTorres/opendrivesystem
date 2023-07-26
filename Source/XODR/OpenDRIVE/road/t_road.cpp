#include "XODR/OpenDRIVE/road/t_road.h"

namespace _NOD
{

bool t_road::isSimilar(const t_road& other) const
{
    return _NMath::calcDistance(planView.geometry_sequence, other.planView.geometry_sequence) < 5;
}

// @incomplete
void t_road::setCurvatureSlope(const XY& pos, double curvature, double slope)
{
    Q_UNUSED(pos);
    Q_UNUSED(curvature);

    double minDist = DOUBLE_MAX;
    int index = -1;

    Q_UNUSED(minDist);
    Q_UNUSED(index);

    for (int i = 0; i < planView.geometry_sequence.size(); i ++)
    {
        //???????????????????????
        //double dist = planView.geometry_sequence[i].dis
    }

    lateralProfile_sequence.resize(1);
    lateralProfile_sequence[0].superelevation_sequence.resize(1);
    lateralProfile_sequence[0].superelevation_sequence[0].a = slope;
    lateralProfile_sequence[0].superelevation_sequence[0].b = 0;
    lateralProfile_sequence[0].superelevation_sequence[0].c = 0;
    lateralProfile_sequence[0].superelevation_sequence[0].d = 0;
}

void t_road::preUpdateGeoJSONData(_GeoJSONData& geojsonData, bool& inserted)
{
    Q_UNUSED(inserted)

    qDebug() << "road id : " << this->id;

    if (geojsonData.isLine)
    {
        geojsonData.sts.resize(geojsonData.points.size());
        for (int i = 0; i < geojsonData.points.size(); i ++)
            calcST(geojsonData.points[i], geojsonData.sts[i]);
        geojsonData.st = geojsonData.sts.first();
    }
    else
    {
        calcST(geojsonData.point, geojsonData.st);
    }
}

bool t_road::updateGeoJSONData_NonGeneral(_GeoJSONData& geojsonData, bool& inserted)
{
    Q_UNUSED(geojsonData);
    Q_UNUSED(inserted);

    if (!geojsonData.isLine)
    {
        if (geojsonData.operCommand == "move")
        {
            calcAbsolutePosIncludingChildren(*this);

            Q_ASSERT(!planView.geometry_sequence.isEmpty());

            QPointF delta = geojsonData.point - planView.geometry_sequence[0];
            for (t_road_planView_geometry& geom : planView.geometry_sequence)
                geom += delta;

            calcRelativePosIncludingChildren(*this);

            return true;
        }
    }

    return false;
}

void t_road::postUpdateGeoJSONData(_GeoJSONData& geojsonData, bool& inserted)
{
    Q_UNUSED(geojsonData)
    Q_UNUSED(inserted)

    this->length = planView.geometry_sequence.last().s + planView.geometry_sequence.last().length;
}

}
