#include "OpenDRIVE/Road.h"
#define _USE_MATH_DEFINES
#include <math.h>

namespace OpenDRIVE
{

	//***********************************************************************************
	//Road segment
	//***********************************************************************************
	/**
	 * Constructor
	 */
	Road::Road()
	{
    }

	/**
	 * Constructor that initializes the road with basic properties
	 *
	 * @param name Name of the road
	 * @param length Length of the road
	 * @param id Unique ID of the road
	 * @param junction ID of the junction, this road might be a part of
	 */
    Road::Road(QString name, double length, QString id, QString junction, QString rule)
	{
        this->name = name;
        this->length = length;
        this->id = id;
        this->junction = junction;
        this->rule = rule;
	}

    bool Road::read(const Common::DomElement& node)
    {
        int checker = DOM_SUCCESS;

        checker += node.QueryStringAttribute("name", &name);
        checker += node.QueryDoubleAttribute("length", &length);
        checker += node.QueryStringAttribute("id", &id);
        checker += node.QueryStringAttribute("junction", &junction);
        checker += node.QueryStringAttribute("rule", &rule);
        if (checker != DOM_SUCCESS)
        {
            qDebug() << "Error parsing Road attributes";
            return false;
        }

        //Get links
        Common::DomElement subNode = node.firstChildElement("link");
        if (!subNode.isNull())
        {
            Common::DomElement subSubNode;
            subSubNode = subNode.firstChildElement("predecessor");
            if (!subSubNode.isNull())
            {
                this->predecessor.read(subSubNode);
            }

            subSubNode = subNode.firstChildElement("successor");
            if (!subSubNode.isNull())
            {
                this->successor.read(subSubNode);
            }

            subSubNode = subNode.firstChildElement("neighbor");
            if (!subSubNode.isNull())
            {
                this->neighbor1.read(subSubNode);
            }

            subSubNode = subNode.nextSiblingElement("neighbor");
            if (!subSubNode.isNull())
            {
                this->neighbor2.read(subSubNode);
            }
        }

        //Proceed to road Type
        subNode = node.firstChildElement("type");
        while (!subNode.isNull())
        {
            RoadType roadType;
            if (roadType.read(subNode))
                this->road_types << roadType;
            subNode = subNode.nextSiblingElement("type");
        }

        //Proceed to planView
        subNode = node.firstChildElement("planView");
        {
            //Get geometry
            Common::DomElement subSubNode = subNode.firstChildElement("geometry");

            while (!subSubNode.isNull())
            {
                Common::DomElement subSubNodeType = subSubNode.firstChildElement();
                GeometryBlock geomBlock;

                if (subSubNodeType.nodeValue().compare("line") == 0)
                {
                    //load a straight block
                    if (geomBlock.read(subSubNode, 0))
                        this->geom_blocks << geomBlock;
                }
                // TODO:??? arc, spiral, arc ? or spiral, arc, spiral
                else if (subSubNodeType.nodeValue().compare("arc") == 0)
                {
                    //load a turn block
                    if (geomBlock.read(subSubNode, 1))
                        this->geom_blocks << geomBlock;
                }
                else if (subSubNodeType.nodeValue().compare("poly3") == 0)
                {
                    //load a polynom spline block
                    if (geomBlock.read(subSubNode, 2))
                        this->geom_blocks << geomBlock;
                }

                subSubNode = subSubNode.nextSiblingElement("geometry");
            }
        }

        //Proceed to ElevationProfile
        subNode = node.firstChildElement("elevationProfile");
        if (!subNode.isNull())
        {
            Common::DomElement subSubNode = node.firstChildElement("elevation");
            while (!subSubNode.isNull())
            {
                Elevation elevation;
                if (elevation.read(subSubNode))
                    this->elevations << elevation;
                subSubNode = subSubNode.nextSiblingElement("elevation");
            }
        }

        //Proceed to LateralProfile
        subNode = node.firstChildElement("lateralProfile");
        if (!subNode.isNull())
        {
            Common::DomElement subSubNode = node.firstChildElement("superelevation");
            while (!subSubNode.isNull())
            {
                SuperElevation superElevation;
                if (superElevation.read(subSubNode))
                    this->super_elevations << superElevation;
                subSubNode = subSubNode.nextSiblingElement("superelevation");
            }

            subSubNode = node.firstChildElement("crossfall");
            while (!subSubNode.isNull())
            {
                Crossfall crossfall;
                if (crossfall.read(subSubNode))
                    this->crossfalls << crossfall;
                subSubNode = subSubNode.nextSiblingElement("crossfall");
            }
        }

        //Proceed to Lanes
        subNode = node.firstChildElement("lanes");
        {
            Common::DomElement subSubNode = subNode.firstChildElement("laneSection");
            while (!subSubNode.isNull())
            {
                LaneSection laneSection;
                if (laneSection.read(subSubNode))
                    this->lane_sections << laneSection;
                subSubNode = subSubNode.nextSiblingElement("laneSection");
            }
        }

        //Proceed to Objects
        subNode = node.firstChildElement("objects");
        if (!subNode.isNull())
        {
            Common::DomElement subSubNode = node.firstChildElement("object");
            while (!subSubNode.isNull())
            {
                Object object;
                if (object.read(subSubNode))
                    this->objects << object;
                subSubNode = subSubNode.nextSiblingElement("object");
            }
        }

        //Proceed to Signals
        subNode = node.firstChildElement("signals");
        if (!subNode.isNull())
        {
            //ReadSignals(road, subNode);
        }

        //Proceed to Surface
        subNode = node.firstChildElement("surface");
        if (!subNode.isNull())
            this->surface.read(subNode);

        return true;
    }

    void Road::write(QDomDocument& doc, Common::DomElement& node) const
    {
        Common::DomElement nodeRoad = doc.createElement("road");
        node.appendChild(nodeRoad);

        nodeRoad.setAttribute("name", this->name);
        nodeRoad.setDoubleAttribute("length", this->length);
        nodeRoad.setAttribute("id", this->id);
        nodeRoad.setAttribute("junction", this->junction);
        nodeRoad.setAttribute("rule", this->rule);

        Common::DomElement nodeLink = doc.createElement("link");
        nodeRoad.appendChild(nodeLink);

        this->predecessor.write(doc, nodeLink, "predecessor");
        this->successor.write(doc, nodeLink, "successor");
        this->neighbor1.write(doc, nodeLink);
        this->neighbor2.write(doc, nodeLink);

        for (const RoadType& road_type : this->road_types)
            road_type.write(doc, nodeRoad);

        Common::DomElement nodePlanView = doc.createElement("planView");
        nodeRoad.appendChild(nodePlanView);

        for (const GeometryBlock& geom_block : this->geom_blocks)
            geom_block.write(doc, nodePlanView);

        Common::DomElement nodeElevationProfile = doc.createElement("elevationProfile");
        nodeRoad.appendChild(nodeElevationProfile);

        for (const Elevation& elevation : this->elevations)
            elevation.write(doc, nodeElevationProfile);

        Common::DomElement nodeLateralProfile = doc.createElement("lateralProfile");
        nodeRoad.appendChild(nodeLateralProfile);

        for (const SuperElevation& superElevation: this->super_elevations)
            superElevation.write(doc, nodeLateralProfile);

        for (const Crossfall& crossfall : this->crossfalls)
            crossfall.write(doc, nodeLateralProfile);

        Common::DomElement nodeLanes = doc.createElement("lanes");
        nodeRoad.appendChild(nodeLanes);

        for (const LaneSection& laneSection : this->lane_sections)
           laneSection.write(doc, nodeLanes);

        Common::DomElement nodeObjects = doc.createElement("objects");
        nodeRoad.appendChild(nodeObjects);

        for (const Object& object : this->objects)
            object.write(doc, nodeObjects);

        Common::DomElement nodeSignals = doc.createElement("signals");
        nodeRoad.appendChild(nodeSignals);

        this->surface.write(doc, nodeRoad);
    }

	//-------------------------------------------------

	bool Road::IsCompatible(CONST Road& other) CONST
	{
		if (this->name != other.name ||
			this->length != other.length ||
			this->junction != other.junction)
			return false;

		if (this->road_types.size() != other.road_types.size() ||
			this->geom_blocks.size() != other.geom_blocks.size() ||
			this->elevations.size() != other.elevations.size() ||
			this->super_elevations.size() != other.super_elevations.size() ||
			this->crossfalls.size() != other.crossfalls.size() ||
			this->lane_sections.size() != other.lane_sections.size() ||
			this->objects.size() != other.objects.size() ||
            this->_signals.size() != other._signals.size())
			return false;

		for (int i = 0; i < this->lane_sections.size(); i++)
		{
			if (!this->lane_sections[i].IsCompatible(other.lane_sections[i]))
				return false;
		}

		return true;
	}

	void Road::Fuse(CONST Road& other)
	{
        this->id = other.id;
	}

	/**
	 * Recalculates the chordline geometry of the road
	 */
	void Road::RecalculateGeometry()
	{
		// Goes through geometry blocks and recalculates their coordinates and headings starting with the second record
		// so the second geometry will start at the coordinates where the first one ended
		double length = 0;
		int lGeometryVectorSize = (int)this->geom_blocks.size();
		if (lGeometryVectorSize > 0)
		{
			double lS = 0;
			double lX = 0;
			double lY = 0;
			double lHdg = 0;
            this->geom_blocks[0].GetLastCoords(lS, lX, lY, lHdg);
            length += this->geom_blocks[0].GetBlockLength();

			GeometryBlock* lGeometry;
			for (int i = 1; i < lGeometryVectorSize; i++)
			{
				lGeometry = &this->geom_blocks[i];
				lGeometry->Recalculate(lS, lX, lY, lHdg);
				lGeometry->GetLastCoords(lS, lX, lY, lHdg);
				length += lGeometry->GetBlockLength();
			}
		}

		this->length = length;
	}

	//-------------------------------------------------
	// EVALUATION METHODS

	/**
	 * Geometry evaluation
	 */
	bool Road::CheckGeometryInterval(double s_check)
	{
		QString tmp;
		return CheckGeometryInterval(s_check, tmp);
	}
	//-----------
	bool Road::CheckGeometryInterval(double s_check, QString& roadId)
	{
		for (int i = 0; i < this->geom_blocks.size(); i++)
		{
			if (this->geom_blocks[i].CheckInterval(s_check))
			{
				roadId = this->id;
				return true;
			}
		}
		roadId = "N/A";
		return false;
	}
	//-----------
	int Road::GetGeometryCoords(double s_check, double& retX, double& retY)
	{
		double tmp;
		return GetGeometryCoords(s_check, retX, retY, tmp);
	}
	//-------------
	int Road::GetGeometryCoords(double s_check, double& retX, double& retY, double& retHDG)
	{
		//go trough all of the blocks
		for (int i = 0; i < this->geom_blocks.size(); i++)
		{
			//Check the block and get coords.
			int res = this->geom_blocks[i].GetCoords(s_check, retX, retY, retHDG);
			// If the returned value is one of the geometry types (for 0=line,1=arc and 2=spiral) then the result has been found and parameters filled, so, return the value
			if (res >= 0)
				return res;
		}
		//if s_check does not belong to the road, return -999
		return -999;
	}
	//-----------

	/**
	 * Other evaluation
	 */
	int  Road::CheckRoadTypeInterval(double s_check)
	{
		int res = -1;
		//Go through all the road type records
		for (int i = 0; i < this->road_types.size(); i++)
		{
			//check if the s_check belongs to the current record
			if (s_check >= this->road_types[i].s)
				res = i;	//assign it to the result id
			else
				break;	//if not, break;
		}
		return res;		//return the result: 0 to MaxInt as the index to the record containing s_check or -1 if nothing found
	}
	//-----------
	QString  Road::GetRoadTypeValue(double s_check)
	{
		QString retType = "unknown";
		//find the record where s_check belongs
		int index = CheckRoadTypeInterval(s_check);
		//If found, return the type
		if (index >= 0)
            retType = this->road_types[index].type;
		return retType;
	}
	//-----------
	int  Road::CheckElevationInterval(double s_check)
	{
		int res = -1;
		//Go through all the road type records
		for (int i = 0; i < this->elevations.size(); i++)
		{
			//check if the s_check belongs to the current record
			if (this->elevations[i].CheckInterval(s_check))
				res = i;	//assign it to the result id
			else
				break;	//if not, break;
		}
		return res;		//return the result: 0 to MaxInt as the index to the record containing s_check or -1 if nothing found
	}
	//-----------
	double  Road::GetElevationValue(double s_check)
	{
		double retVal = 0;
		//find the record where s_check belongs
		int index = CheckElevationInterval(s_check);
		//If found, return the type
		if (index >= 0)
			retVal = (this->elevations[index].GetValue(s_check));
		return retVal;

	}
	//-----------
	int  Road::CheckSuperElevationInterval(double s_check)
	{
		int res = -1;
		//Go through all the road type records
		for (int i = 0; i < this->super_elevations.size(); i++)
		{
			//check if the s_check belongs to the current record
			if (this->super_elevations[i].CheckInterval(s_check))
				res = i;	//assign it to the result id
			else
				break;	//if not, break;
		}
		return res;		//return the result: 0 to MaxInt as the index to the record containing s_check or -1 if nothing found
	}
	//-----------
	double  Road::GetSuperElevationValue(double s_check)
	{
		double retVal = 0;
		//find the record where s_check belongs
		int index = CheckSuperElevationInterval(s_check);
		//If found, return the type
		if (index >= 0)
			retVal = (this->super_elevations[index].GetValue(s_check));

		return retVal;
	}
	//-----------
	int  Road::CheckCrossfallInterval(double s_check)
	{
		int res = -1;
		//Go through all the road type records
		for (int i = 0; i < this->crossfalls.size(); i++)
		{
			//check if the s_check belongs to the current record
			if (this->crossfalls[i].CheckInterval(s_check))
				res = i;	//assign it to the result id
			else
				break;	//if not, break;
		}
		return res;		//return the result: 0 to MaxInt as the index to the record containing s_check or -1 if nothing found
	}
	//-----------
	void  Road::GetCrossfallValue(double s_check, double& angleLeft, double& angleRight)
	{
		angleLeft = 0.0;
		angleRight = 0.0;
		//find the record where s_check belongs
		int index = CheckCrossfallInterval(s_check);
		//If found, return the type
		QString side;
		double angle = 0.0;
		if (index >= 0)
		{
			angle = (this->crossfalls[index].GetValue(s_check));
			side = (this->crossfalls[index].side);
		}

		if (side.compare("left") == 0)
		{
			angleLeft = -angle;
		}
		else if (side.compare("right") == 0)
		{
			angleRight = -angle;
		}
		else
		{
			angleLeft = -angle;
			angleRight = -angle;
		}
	}
	//-----------
	int  Road::CheckLaneSectionInterval(double s_check)
	{
		int res = -1;
		//Go through all the lane section records
		for (int i = 0; i < this->lane_sections.size(); i++)
		{
			//check if the s_check belongs to the current record
			if (this->lane_sections[i].CheckInterval(s_check))
				res = i;	//assign it to the result id
			else
				break;	//if not, break;
		}
		return res;		//return the result: 0 to MaxInt as the index to the record containing s_check or -1 if nothing found
	}


}
