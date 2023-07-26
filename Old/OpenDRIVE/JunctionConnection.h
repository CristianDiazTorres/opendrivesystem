#ifndef __OPENDRIVE_JUNCTIONCONNECTION_H__
#define __OPENDRIVE_JUNCTIONCONNECTION_H__

#include "OpenDRIVE/JunctionLaneLink.h"

namespace OpenDRIVE
{
	/**
	 * Junction connection class. Holds all the information for a connection record
	 */
    struct JunctionConnection
	{

		/**
		 * Connection parameters
		 */
		QString id;
		QString incoming_road;
		QString connecting_road;
		QString contact_point;	//Possible values: start / end

		/**
		 * Lane linkage parameters QVector
		 */
        QVector<JunctionLaneLink> junction_lane_links;

	public:

		int mLastAddedJunctionLaneLink;

		/**
		 * Constructor. Sets basic junction connection parameters
		 * @param id ID within the junction
		 * @param incomingRoad ID of the incoming road
		 * @param connectingRoad ID of the connecting path
		 * @param contactPoint Contact point on the connecting road (start / end)
		 */
		JunctionConnection(QString id, QString incomingRoad, QString connectingRoad, QString contactPoint);
        JunctionConnection(){}

        bool read(const Common::DomElement& node);
        void write(QDomDocument& doc, Common::DomElement& node) const;
	};
}

#endif // __OPENDRIVE_JUNCTIONCONNECTION_H__
