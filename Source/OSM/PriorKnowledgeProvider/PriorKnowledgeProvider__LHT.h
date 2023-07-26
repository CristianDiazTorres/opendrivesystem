
#pragma once

#include "OSM/PriorKnowledgeProvider/PriorKnowledgeProvider__Base.h"

namespace _NOSM
{

class PriorKnowledgeProvider__LHT : public PriorKnowledgeProvider__Base
{
public:
    virtual void fillDrivingSide(Way& way);

    virtual void fillLanesCountDirectional(Way& way);

    virtual void fillAccessLanes(Way& way);

};

}
