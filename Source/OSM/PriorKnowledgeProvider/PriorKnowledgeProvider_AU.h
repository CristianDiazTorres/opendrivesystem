
#pragma once

#include "OSM/PriorKnowledgeProvider/PriorKnowledgeProvider__LHT.h"

namespace _NOSM
{

class PriorKnowledgeProvider_AU : public PriorKnowledgeProvider__LHT
{
public:
    virtual bool fillLanesCount_Oneway(Way& way);
    virtual bool fillLanesCount_Bidirectional(Way& way);
    virtual void fillLanesCount_Other(Way& way);

    virtual void fillWidthLanes(Way& way);

    virtual void fillRoadMark(Way& way);
};

}
