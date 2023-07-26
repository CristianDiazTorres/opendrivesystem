#include "OpenDRIVE/LaneSection.h"

namespace OpenDRIVE
{

    /**
    * Lane section class. Holds all the lane section information
    *
    *
    *
    *
    */

    /**
    * Constructor. Sets basic lane section parameters
    * @param s s-offset of the lane section
    */
    LaneSection::LaneSection (double s)
    {	this->s=s;	}

    bool LaneSection::IsCompatible(CONST LaneSection& other) CONST
    {
        if (this->s != other.s)
            return false;

        if (this->lanes.size() != other.lanes.size())
            return false;

        for (int i = 0; i < this->lanes.size(); i++)
        {
            if (!this->lanes[i].IsCompatible(other.lanes[i]))
                return false;
        }

        return true;
    }

    /**
    * Get the lane section final s-offset which is the s-offset of the last record of the lane section
    */
    double LaneSection::GetS2()
    {
        double lHighestS=0;

        for(const Lane& lane : this->lanes)
        {
            //width
            const LaneWidth& lWidth = lane.lane_widths.last();
            if (lWidth.s>lHighestS)
                lHighestS=lWidth.s;

            //road mark
            const LaneRoadMark& lRoadMark = lane.lane_road_marks.last();
            if(lRoadMark.s_offset>lHighestS)
                lHighestS=lRoadMark.s_offset;

            //material
            const LaneMaterial& lMaterial = lane.lane_materials.last();
            if(lMaterial.s_offset>lHighestS)
                lHighestS=lMaterial.s_offset;

            //visibility
            const LaneVisibility& lVisibility = lane.lane_visibilities.last();
            if(lVisibility.s_offset>lHighestS)
                lHighestS=lVisibility.s_offset;

            //speed
            const LaneSpeed& lSpeed = lane.lane_speeds.last();
            if(lSpeed.s_offset>lHighestS)
                lHighestS=lSpeed.s_offset;

            //access
            const LaneAccess& lAccess = lane.lane_accesses.last();
            if(lAccess.s_offset>lHighestS)
                lHighestS=lAccess.s_offset;

            //height
            const LaneHeight& lHeight = lane.lane_heights.last();
            if(lHeight.s_offset>lHighestS)
                lHighestS=lHeight.s_offset;
        }

        return this->s+lHighestS;

    }

    /**
    * Check if the tested s-offset is inside the lane section interval
    * @param A double s-offset value that has to be checked
    * @return Return true if the s-offset value belongs to current lane section, false otherwise
    */
    bool LaneSection::CheckInterval(double s_check)
    {
        if (s_check>=this->s)
            return true;
        else
            return false;
    }

    /**
    * Return the lane-0 index in the lanes QVector
    * @return An int value with the index
    */
    int LaneSection::GetZeroLaneIndex()
    {
        for (int i=0; i<this->lanes.size(); i++)
        {
            if(this->lanes[i].id==0)
                return i;
        }
        return 0;
    }

    /**
    * Return the number of left lanes
    * @return An int value with the number of left lanes
    */
    int LaneSection::GetLeftLaneCount() const
    {
        int count=0;
        for (int i=0;i<this->lanes.size();i++)
        {
            if(this->lanes[i].side==1)
                count++;
        }
        return count;
    }

    /**
    * Return the number of central lanes
    * @return An int value with the number of central lanes
    */
    int LaneSection::GetCenterLaneCount()
    {
        int count=0;
        for(int i=0; i<this->lanes.size(); i++)
        {
            if(this->lanes[i].side==0)
            {
                count++;
            }
        }
        return count;
    }

    /**
    * Return the number of right lanes
    * @return An int value with the number of right lanes
    */
    int LaneSection::GetRightLaneCount() const
    {
        int count=0;
        for (int i=0;i<this->lanes.size();i++)
        {
            if(this->lanes[i].side==-1)
                count++;
        }
        return count;
    }
}
