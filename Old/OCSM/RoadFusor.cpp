#include "OCSM/RoadFusor.h"

namespace OCSM
{
	OpenDRIVE::OpenDRIVE RoadFusor::Fuse(OpenDRIVE::OpenDRIVE& created_content, OpenDRIVE::OpenDRIVE& matched_content)
	{
		created_content.Fuse(matched_content);
		return created_content;
	}

}