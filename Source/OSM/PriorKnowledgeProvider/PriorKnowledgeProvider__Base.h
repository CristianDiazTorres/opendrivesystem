
#pragma once

namespace _NOSM
{

struct Way;

class PriorKnowledgeProvider__Base
{
public:
    virtual void fillWayAttrs(Way& way);

    virtual void fillDrivingSide(Way& way) = 0;

    virtual void fillDirection(Way& way);

    virtual void fillLanesCount(Way& way);
    virtual bool fillLanesCount_Oneway(Way& way);
    virtual bool fillLanesCount_Bidirectional(Way& way);
    virtual void fillLanesCount_Other(Way& way);

    virtual void fillLanesCountDirectional(Way& way) = 0;

    virtual void fillWidthLanes(Way& way);

    virtual void fillElevationLanes(Way& way);

    virtual void fillMaxspeedLanes(Way& way);

    virtual void fillAccessLanes(Way& way) = 0;

    virtual void fillRuleLanes(Way& way);

    virtual void fillRoadMark(Way& way);
};

}
