#ifndef __OPENDRIVE_JUNCTION_H__
#define __OPENDRIVE_JUNCTION_H__

#include "OpenDRIVE/JunctionConnection.h"
#include "OpenDRIVE/JunctionPriorityRoad.h"
#include "OpenDRIVE/JunctionController.h"

namespace OpenDRIVE
{
	/**
	 * Junction class. Holds all the junction information
	 */
    struct Junction
	{

		/**
		 * Junction parameters
		 */
		QString name;
		QString id;

		/**
		 * Vector based parameters of the junction
		 */
		QVector<JunctionConnection> junction_connections;
		QVector<JunctionPriorityRoad> junction_priority_roads;
		QVector<JunctionController> junction_contollers;

	public:

        bool read(const Common::DomElement& node);
        void write(QDomDocument& doc, Common::DomElement& node) const;

		/**
		 * Constructor. Sets basic junction parameters
		 * @param name Name of the junction
		 * @param id Unique ID of the junction
		 */
		Junction(QString name, QString id);
        Junction(){}

		bool IsCompatible(CONST Junction& other) CONST;

	};
}

#endif // __OPENDRIVE_JUNCTION_H__
