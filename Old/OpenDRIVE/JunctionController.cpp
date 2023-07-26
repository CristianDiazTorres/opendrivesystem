#include "OpenDRIVE/JunctionController.h"

namespace OpenDRIVE
{
	/**
	* Junction controller class. Holds all the information for a priority record
	*/

	/**
	* Constructor. Initializes the parameters
	* @param id ID of the controller to add
	* @param type Type of control
	*/
	JunctionController::JunctionController(QString id, QString type)
	{
		this->id = id; this->type = type;
	}

}
