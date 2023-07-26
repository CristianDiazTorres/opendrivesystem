#include "OpenDRIVE/GeometryBlock.h"
#include "OpenDRIVE/GeometryLine.h"
#include "OpenDRIVE/GeometryArc.h"
#include "OpenDRIVE/GeometrySpiral.h"
#include "OpenDRIVE/GeometryPoly3.h"
#define _USE_MATH_DEFINES
#include <math.h>

//#define PI 3.14159265358979323846264338327950288
extern int fresnl(double, double*, double*);

namespace OpenDRIVE
{
	//***********************************************************************************
	//Base class for Geometry blocks
	//***********************************************************************************
	//-------------------------------------------------

    bool GeometryBlock::read(Common::DomElement node, int blockType)
    {
        switch (blockType)
        {
        case 0:
            {
                GeometryLine geometryLine;
                geometryLine.read(node);
                this->road_geoms << geometryLine;
            }
            break;

        case 1:
            {
                // TODO:??? arc, spiral, arc ? or spiral, arc, spiral
                GeometryArc geometryArc1;
                geometryArc1.read(node);
                this->road_geoms << geometryArc1;

                node = node.nextSiblingElement("geometry");
                GeometrySpiral geometrySpiral;
                geometrySpiral.read(node);
                this->road_geoms << geometrySpiral;

                node = node.nextSiblingElement("geometry");
                GeometryArc geometryArc2;
                geometryArc2.read(node);
                this->road_geoms << geometryArc2;
            }
            break;

        case 2:
            {
                GeometryLine geometryPoly3;
                geometryPoly3.read(node);
                this->road_geoms << geometryPoly3;
            }
            break;
        }

        return true;
    }

    void GeometryBlock::write(QDomDocument& doc, Common::DomElement& node) const
    {
        if (this->CheckIfLine())
        {
            ((const GeometryLine&)road_geoms[0]).write(doc, node);
        }
        else
        {
            // TODO:??? arc, spiral, arc ? or spiral, arc, spiral
            ((const GeometryArc&)road_geoms[0]).write(doc, node);
            ((const GeometrySpiral&)road_geoms[1]).write(doc, node);
            ((const GeometryArc&)road_geoms[2]).write(doc, node);
        }
    }

    /**
     * Getter for the overal block length (summ of geometry record lengths)
     */
    double GeometryBlock::GetBlockLength()
    {
        double lTotal = 0;
        for (int i = 0; i < this->road_geoms.size(); i++)
        {
            lTotal += this->road_geoms[i].length;
        }
        return lTotal;
    }

	/**
	 *  Checks if the block is a straight line block or a turn
	 */
    bool GeometryBlock::CheckIfLine() const
	{
		if (this->road_geoms.size() > 1) return false;
		else return true;
	}

	//-------------------------------------------------

	/**
	 * Recalculates the geometry blocks when one of the geometry records is modified
	 * Makes sure that every geometry records starts where the previous record ends
	 */
	void GeometryBlock::Recalculate(double s, double x, double y, double hdg)
	{
		double lS = s;
		double lX = x;
		double lY = y;
		double lHdg = hdg;

		if (this->road_geoms.size() == 1)
		{
            GeometryLine& lGeometryLine = (GeometryLine&)(this->road_geoms[0]);
            // Updates the line to reflect the changes of the previous block
            lGeometryLine.SetBase(lS, lX, lY, lHdg, lGeometryLine.length);
		}
		else if (this->road_geoms.size() == 3)
		{
            // TODO:??? arc, spiral, arc ? or spiral, arc, spiral
            GeometrySpiral& lGeometrySpiral1 = (GeometrySpiral&)(this->road_geoms[0]);
            GeometryArc& lGeometryArc = (GeometryArc&)(this->road_geoms[1]);
            GeometrySpiral& lGeometrySpiral2 = (GeometrySpiral&)(this->road_geoms[2]);

            // Updates the first spiral to reflect the changes of the previous block
            lGeometrySpiral1.SetBase(lS, lX, lY, lHdg, lGeometrySpiral1.length);

            // Reads the new coords of the spiral
            lS = lGeometrySpiral1.s2;
            lGeometrySpiral1.GetCoords(lS, lX, lY, lHdg);

            // Updates the arc to reflect the changes to the first spiral
            lGeometryArc.SetBase(lS, lX, lY, lHdg, lGeometryArc.length);

            // Reads the new coords of the arc
            lS = lGeometryArc.s2;
            lGeometryArc.GetCoords(lS, lX, lY, lHdg);

            // Updates the second spiral to reflect hte changes to the arc
            lGeometrySpiral2.SetBase(lS, lX, lY, lHdg, lGeometrySpiral2.length);
		}
	}

	//-------------------------------------------------

	/**
	 *  Gets the S at the end of the block
	 */
	double GeometryBlock::GetLastS2()
	{
		if (this->road_geoms.size() > 0)
            return this->road_geoms[this->road_geoms.size() - 1].s2;
		else
			return 0;
	}

	/**
	 *  Gets the coordinates at the end of the last geometry
	 */
	int GeometryBlock::GetLastCoords(double& s, double& retX, double& retY, double& retHDG)
	{
		int lSize = (int)this->road_geoms.size();
		if (lSize > 0)
		{
            RoadGeometry& lGeometry = this->road_geoms[lSize - 1];
            s = lGeometry.s2;
            lGeometry.GetCoords(s, retX, retY, retHDG);
		}
		else
		{
			s = 0;
			retX = 0;
			retY = 0;
			retHDG = 0;
		}
		return 0;
	}

	/**
	 *  Check if sample S belongs to this block
	 */
	bool GeometryBlock::CheckInterval(double s_check)
	{
		for (int i = 0; i < this->road_geoms.size(); i++)
		{
			//if the s_check belongs to one of the geometries
            if (this->road_geoms[i].CheckInterval(s_check))
				return true;
		}
		return false;
	}

	/**
	 *  Gets the coordinates at the sample S offset
	 */
	int GeometryBlock::GetCoords(double s_check, double& retX, double& retY)
	{
		double tmp;
		return GetCoords(s_check, retX, retY, tmp);
	}

	/**
	 *  Gets the coordinates and heading at the end of the last geometry
	 */
	int  GeometryBlock::GetCoords(double s_check, double& retX, double& retY, double& retHDG)
	{
		// go through all the elements
		for (int i = 0; i < this->road_geoms.size(); i++)
		{
			//if the s_check belongs to one of the geometries
            if (this->road_geoms[i].CheckInterval(s_check))
			{
				//get the x,y coords and return the type of the geometry
                this->road_geoms[i].GetCoords(s_check, retX, retY, retHDG);
                return this->road_geoms[i].geom_type;
			}
		}
		//if nothing found, return -999
		return -999;

	}

}
