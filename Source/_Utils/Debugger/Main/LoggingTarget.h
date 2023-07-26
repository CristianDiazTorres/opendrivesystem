#pragma once

#include "Debugger/Internal/Internal.h"

namespace _NDebug
{

enum LoggingTarget
{
    LD_QDebug = 1
    , LD_File = 2
    , LD_Slot = 4
    , LD_PGDB = 8

    , LD_QDebug_File = LD_QDebug | LD_File

    , LD_QDebug_File_Slot = LD_QDebug_File | LD_Slot

    , LD_NotPGDB = LD_QDebug_File_Slot

    , LD_QDebug_File_Slot_PGDB = LD_QDebug_File_Slot | LD_PGDB

    , LD_File_Slot = LD_File | LD_Slot

    , LD_All = LD_QDebug_File_Slot_PGDB
};

}
