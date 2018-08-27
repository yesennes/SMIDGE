#include "geometry.h"
#include "surface.h"
#include <vector>

namespace SMIDGE{
    class Plane : public Surface{

        public:
        Plane(const std::string& name);
    };

    enum class Axis{
        X, Y, Z
    };

    /**
     * Descibes a plane perpendicular to a given axis, offest from the origin by a specified 
     * amount
     */
    class AxisPlane : public Plane{
        Axis axis;
        double offset;
        public:
        AxisPlane(const std::string& name, Axis axis, double offset);

        Axis getAxis() const;
        void setAxis(Axis axis);

        double getOffset() const;
        void setOffset(double offset);

        std::vector<double>& getParams(std::vector<double>& toFill) const;
        std::string getSurfaceType() const;
    };

    class VectorPlane : public Plane{
        double xCoeff;
        double yCoeff;
        double zCoeff;
        double offset;

        public:
        VectorPlane(const std::string& name, double xCoeff, double yCoeff, double zCoeff, double offset);

        double getXCoeff() const;
        void setXCoeff(double xCoeff);

        double getYCoeff() const;
        void setYCoeff(double yCoeff);

        double getZCoeff() const;
        void setZCoeff(double zCoeff);

        double getOffset() const;
        void setOffset(double offset);

        std::vector<double>& getParams(std::vector<double>& toFill) const;
        std::string getSurfaceType() const;
    };

    class PointsPlane : public Plane{
        point point1;
        point point2;
        point point3;

        public:
        PointsPlane(const std::string& name, const point& point1, const point& point2, const point& point3);

        point getPoint1() const;
        void setPoint1(const point& point1);

        point getPoint2() const;
        void setPoint2(const point& point2);

        point getPoint3() const;
        void setPoint3(const point& point3);

        std::vector<double>& getParams(std::vector<double>& toFill) const;
        std::string getSurfaceType() const;
    };
}
