#include "OSM/Way/Way.h"
#include "Debugger/Main/Logger.h"

namespace _NOSM
{

void Way::parseOneway()
{
    // Adjust oneway
    if (osm.contains(_SC_oneway))
    {
        QString& oneway = osm[_SC_oneway];
        DefaultLogger_File << "Oneway : " << oneway;

        if (oneway == _SC_true || oneway == "1")
        {
            oneway = _SC_yes;
        }
        else if (oneway == _SC_false || oneway == "0")
        {
            oneway = _SC_no;
        }
        else if (oneway == _SC_reverse)
        {
            oneway = "-1";
        }
    }
    else if (osm[_SC_bidirectional] == _SC_yes)
    {
        osm[_SC_oneway] = _SC_no;
    }
}

}
