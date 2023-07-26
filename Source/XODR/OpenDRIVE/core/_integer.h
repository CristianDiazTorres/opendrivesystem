#pragma once

#include "XODR/OpenDRIVE/internal/_internal.h"

namespace _NOD
{
/*
    2.3.5. Use of IDs
    The following rules apply to the use of IDs in OpenDRIVE:

        IDs shall be unique within a class.

        Lane IDs shall be unique within a lane section.

        Only defined IDs may be referenced.
*/

typedef integer        _positiveInteger; // > 0
typedef integer        _nonNegativeInteger; // >= 0
typedef integer        _negativeInteger; // < 0

typedef integer        _junctionId; // string

// Unique ID within the junction
typedef integer        _junctionConnectionId; // string

typedef integer        _junctionControllerId; // string
typedef integer        _junctionGroupId; // string

typedef integer        _laneId;

typedef integer        _objectId; // string
typedef integer        _bridgeId; // string
typedef integer        _tunnelId; // string
typedef integer        _outlineId; // _nonNegativeInteger
typedef integer        _outlinePointId; // _nonNegativeInteger

typedef integer        _switchId; // string
typedef integer        _trackId; // string
typedef integer        _stationId; // string
typedef integer        _platformId; // string

typedef integer        _roadId; // string

typedef integer        _signalId; // string
typedef integer        _controllerId; // string

typedef integer        _elementId; // string (_roadId, unknown, _objectId, _signalId)

}
