#include "OpenDRIVE/Content.h"
#include <QFile>

namespace OpenDRIVE
{

	//***********************************************************************************
	//OpenDRIVE Structure
	//***********************************************************************************

    bool Content::read(QString fileName)
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
            return false;

        QByteArray buffer = file.readAll();
        file.close();

        //Read and load File
        QDomDocument doc(fileName);
        bool loadOkay = doc.setContent(buffer);
        if (loadOkay)
        {
            Common::DomElement rootNode = doc.firstChildElement();
            //read header
            int checker = DOM_SUCCESS;
            Q_UNUSED(checker);
            Common::DomElement node = rootNode.firstChildElement("header");
            header.read(node);

            //read roads
            node = rootNode.firstChildElement("road");
            while (!node.isNull())
            {
                Road road;
                if (road.read(node))
                    this->roads << road;
                node = node.nextSiblingElement("road");
            }

            //read junctions
            node = rootNode.firstChildElement("junction");
            while (!node.isNull())
            {
                Junction junction;
                if (junction.read(node))
                    this->junctions << junction;
                node = node.nextSiblingElement("junction");
            }

            return true;
        }

        //failed to read the file
        qDebug() << "Could not read file: " << fileName;
        return false;
    }

    bool Content::write(QString fileName) const
    {
        // XML document
        QDomDocument doc;

        doc.appendChild(doc.createProcessingInstruction("xml", "version=\"1.0\" standalone=\"yes\""));

        Common::DomElement rootNode = doc.createElement("OpenDRIVE");
        doc.appendChild(rootNode);

        // Write header
        header.write(doc, rootNode);

        // Write roads
        for (const Road& road : this->roads)
            road.write(doc, rootNode);

        // Write junctions
        for (const Junction& junction : this->junctions)
            junction.write(doc, rootNode);

        // Saves the XML structure to the file
        QByteArray xml_content = doc.toByteArray();
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
            return false;
        file.write(xml_content);
        return true;
    }

	bool Content::IsCompatible(CONST Content& other) CONST
	{
		if (this->roads.size() != other.roads.size() ||
			this->junctions.size() != other.junctions.size())
			return false;

		for (int i = 0; i < this->roads.size(); i++)
		{
			if (!this->roads[i].IsCompatible(other.roads[i]))
				return false;
		}

		return true;
	}

	void Content::Fuse(CONST Content& other)
	{
		for (int i = 0; i < this->roads.size(); i++)
		{
			for (int j = 0; j < other.roads.size(); j++)
			{
				this->roads[i].Fuse(other.roads[j]);
			}
		}
	}
}
