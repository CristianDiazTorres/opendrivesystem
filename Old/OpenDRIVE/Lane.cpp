#include "OpenDRIVE/Lane.h"

namespace OpenDRIVE
{
    /**
    * Lane class. Holds all the record data that describes a lane
    *
    *
    *
    *
    *
    */

    /**
    *	Constructor
    */
    Lane::Lane(int side, int id, QString type, bool level)
    {	this->side=side; this->id=id; this->type=type; this->level=level;	this->predecessor_exists=false; this->successor_exists=false;	}

    /**
    *	Check the intervals and return the index of the records that applies to the provided s-offset
    */
    int  Lane::CheckWidthInterval(double s_check)
    {

        int res=-1;
        //Go through all the width records
        for (int i=0;i<this->lane_widths.size();i++)
        {
            //check if the s_check belongs to the current record
            if (s_check >= this->lane_widths[i].s)
                res=i;	//assign it to the result id
            else
                break;	//if not, break;
        }
        return res;		//return the result: 0 to MaxInt as the index to the record containing s_check or -1 if nothing found
    }

    int Lane::CheckRoadMarkInterval(double s_check)
    {
        int res=-1;
        //Go through all the road mark records
        for (int i=0;i<this->lane_road_marks.size();i++)
        {
            //check if the s_check belongs to the current record
            if (s_check >= this->lane_road_marks[i].s_offset)
                res=i;	//assign it to the result id
            else
                break;	//if not, break;
        }
        return res;		//return the result: 0 to MaxInt as the index to the record containing s_check or -1 if nothing found
    }

    int Lane::CheckMaterialInterval(double s_check)
    {
        int res=-1;
        //Go through all the material records
        for (int i=0;i<this->lane_materials.size();i++)
        {
            //check if the s_check belongs to the current record
            if (s_check >= this->lane_materials[i].s_offset)
                res=i;	//assign it to the result id
            else
                break;	//if not, break;
        }
        return res;		//return the result: 0 to MaxInt as the index to the record containing s_check or -1 if nothing found
    }

    int Lane::CheckVisibilityInterval(double s_check)
    {
        int res=-1;
        //Go through all the visibility records
        for (int i=0;i<this->lane_visibilities.size();i++)
        {
            //check if the s_check belongs to the current record
            if (s_check >= this->lane_visibilities[i].s_offset)
                res=i;	//assign it to the result id
            else
                break;	//if not, break;
        }
        return res;		//return the result: 0 to MaxInt as the index to the record containing s_check or -1 if nothing found
    }

    int Lane::CheckSpeedInterval(double s_check)
    {
        int res=-1;
        //Go through all the speed records
        for (int i=0;i<this->lane_speeds.size();i++)
        {
            //check if the s_check belongs to the current record
            if (s_check >= this->lane_speeds[i].s_offset)
                res=i;	//assign it to the result id
            else
                break;	//if not, break;
        }
        return res;		//return the result: 0 to MaxInt as the index to the record containing s_check or -1 if nothing found
    }

    int Lane::CheckAccessInterval(double s_check)
    {
        int res=-1;
        //Go through all the access records
        for (int i=0;i<this->lane_accesses.size();i++)
        {
            //check if the s_check belongs to the current record
            if (s_check >= this->lane_accesses[i].s_offset)
                res=i;	//assign it to the result id
            else
                break;	//if not, break;
        }
        return res;		//return the result: 0 to MaxInt as the index to the record containing s_check or -1 if nothing found
    }

    int Lane::CheckHeightInterval(double s_check)
    {
        int res=-1;
        //Go through all the height records
        for (int i=0;i<this->lane_heights.size();i++)
        {
            //check if the s_check belongs to the current record
            if (s_check >= this->lane_heights[i].s_offset)
                res=i;	//assign it to the result id
            else
                break;	//if not, break;
        }
        return res;		//return the result: 0 to MaxInt as the index to the record containing s_check or -1 if nothing found
    }

    /**
    *	Evaluate the record and return the width value
    */
    double Lane::GetWidthValue(double s_check)
    {
        double retVal=0;
        //find the record where s_check belongs
        int index=CheckWidthInterval(s_check);
        //If found, return the type
        if (index>=0)
            retVal= this->lane_widths[index].GetValue(s_check);
        return retVal;
    }

    /**
    *	Evaluate the record and return the height object
    */
    LaneHeight Lane::GetHeightValue(double s_check)
    {
        //find the record where s_check belongs
        int index=CheckHeightInterval(s_check);
        //If found, return the type
        if (index>=0)
            return this->lane_heights[index];
        return LaneHeight(0,0,0);
    }


    /**
    *	Evaluate the road marks records and return the road mark object corresponding to the provided s-offset
    */
    LaneRoadMark Lane::GetRoadMarkValue(double s_check)
    {
        //find the record where s_check belongs
        int index=CheckRoadMarkInterval(s_check);
        //If found, return the params
        if (index>=0)
            return this->lane_road_marks[index];
        else
            return LaneRoadMark();
    }

}
