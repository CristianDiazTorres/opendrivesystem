#include "OpenDRIVE/RoadGeometry.h"
#include "OpenDRIVE/GeometryLine.h"
#include "OpenDRIVE/GeometryArc.h"
#include "OpenDRIVE/GeometrySpiral.h"
#include "OpenDRIVE/GeometryPoly3.h"

namespace OpenDRIVE
{
    bool RoadGeometry::read(const Common::DomElement& node)
    {
        int checker = DOM_SUCCESS;
        checker += node.QueryDoubleAttribute("s", &s);
        checker += node.QueryDoubleAttribute("x", &x);
        checker += node.QueryDoubleAttribute("y", &y);
        checker += node.QueryDoubleAttribute("hdg", &hdg);
        checker += node.QueryDoubleAttribute("length", &length);

        if (checker != DOM_SUCCESS)
        {
            qDebug() << "Error parsing Geometry attributes";
            return false;
        }

        switch (this->geom_type)
        {
        case 0:
            return ((GeometryLine&)(*this)).readDerived(node);
        case 1:
            return ((GeometryArc&)(*this)).readDerived(node);
        case 2:
            return ((GeometrySpiral&)(*this)).readDerived(node);
        case 3:
            return ((GeometryPoly3&)(*this)).readDerived(node);
        }

        return false;
    }

    void RoadGeometry::write(QDomDocument& doc, Common::DomElement& node) const
    {
        Common::DomElement nodeGeometry = doc.createElement("geometry");
        node.appendChild(nodeGeometry);

        nodeGeometry.setDoubleAttribute("s", this->s);
        nodeGeometry.setDoubleAttribute("x", this->x);
        nodeGeometry.setDoubleAttribute("y", this->y);
        nodeGeometry.setDoubleAttribute("hdg", this->hdg);
        nodeGeometry.setDoubleAttribute("length", this->length);

        switch (this->geom_type)
        {
        case 0:
            ((GeometryLine&)(*this)).writeDerived(doc, nodeGeometry);
            break;
        case 1:
            ((GeometryArc&)(*this)).writeDerived(doc, nodeGeometry);
            break;
        case 2:
            ((GeometrySpiral&)(*this)).writeDerived(doc, nodeGeometry);
            break;
        case 3:
            ((GeometryPoly3&)(*this)).writeDerived(doc, nodeGeometry);
            break;
        }
    }

    void RoadGeometry::GetCoords(double s_check, double& retX, double& retY, double& retHDG)
    {
        switch (this->geom_type)
        {
        case 0:
            ((GeometryLine&)(*this)).GetCoordsDerived(s_check, retX, retY, retHDG);
            break;
        case 1:
            ((GeometryArc&)(*this)).GetCoordsDerived(s_check, retX, retY, retHDG);
            break;
        case 2:
            ((GeometrySpiral&)(*this)).GetCoordsDerived(s_check, retX, retY, retHDG);
            break;
        case 3:
            ((GeometryPoly3&)(*this)).GetCoordsDerived(s_check, retX, retY, retHDG);
            break;
        }
    }

    /**
     * Computes the required vars
     */
    void RoadGeometry::ComputeVars()
    {
        switch (this->geom_type)
        {
        case 0:
            ((GeometryLine&)(*this)).ComputeVarsDerived();
            break;
        case 1:
            ((GeometryArc&)(*this)).ComputeVarsDerived();
            break;
        case 2:
            ((GeometrySpiral&)(*this)).ComputeVarsDerived();
            break;
        case 3:
            ((GeometryPoly3&)(*this)).ComputeVarsDerived();
            break;
        }
    }

}
