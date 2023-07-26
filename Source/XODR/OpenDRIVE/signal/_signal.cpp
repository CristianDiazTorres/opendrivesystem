#include "XODR/OpenDRIVE/signal/e_road_signals_signal_reference_elementType.h"
#include "XODR/OpenDRIVE/signal/e_road_signals_signal_type.h"

namespace _NOD
{

_OD_STRING_ENUM_e_road_signals_signal_reference_elementType(DEFINE)
_OD_STRING_ENUM_e_road_signals_signal_type(DEFINE)

/**************************************************************/

class signal_initializer
{
    public:
    signal_initializer()
    {
        _OD_STRING_ENUM_e_road_signals_signal_reference_elementType(INIT)
        _OD_STRING_ENUM_e_road_signals_signal_type(INIT)
    }
};

static signal_initializer s_signalInitializer;

}
