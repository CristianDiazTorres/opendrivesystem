
#ifndef __OCSM_H__
#define __OCSM_H__

#include "Common/Common.h"

namespace OCSM
{

    /*
     * 2.2 Description of high level software architecture
     *	The main class of the OCSM is the OpenDRIVECreator.
     *	It contains a Process() method that essentially executes the activity described in section 2.1.
     *	The interface with the database (DatabaseConnector) could be implemented in several ways.
     *	One possible implementation is to simply use local file system.
     *	The Open DRIVECreator can use objects deriving from the ExternalSourceProvider.
     *	The OSMM could be used as backend to implement this interface.
     *
     * 3.1 Functional System Level Requirements
     *	OCSM-1: the Module shall read a measurement file.
     *	OCSM-2: the Module shall reconstruct the ego trajectory.
     *	OCSM-3: the Module shall make use of external sources if needed, to build the road description.
     *	OCSM-4: the Module shall ask the database whether there already exists an OpenDRIVE file for an SGA which covers a given position
     *	OCSM-5: the Module shall write an OpenDRIVE 1containing a road that describes the road where the ego vehicle was driven while recording the measurements.
     *	OCSM-6: the Module shall cut an OpenDRIVE file into several OpenDRIVE files if the extent of the OpenDRIVE 1leexceed the extent allowed by the SGA.
     *	OCSM-7: the Module shall obtain the OpenDRIVE 1leof a given SGA (provided that the file exists in the database)
     *	OCSM-8: the Module shall 1nd which road corresponds to a given path (provided that the road already exists in an OpenDRIVE 1leof the database).
     */

    class OCSM
    {
    public:
        void SetDatabaseRootPath(ConstQString& root_path);
        void Process(ConstQString& file_path, int point_count);

    };

}

#endif // __OCSM_H__

