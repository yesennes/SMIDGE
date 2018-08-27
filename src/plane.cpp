#include "plane.h"
#include "geometry.h"
using namespace std;
namespace SMIDGE{
    Plane::Plane(const std::string& name) : Surface(name){
    }

    AxisPlane::AxisPlane(const std::string& name, Axis axis, double offset) : Plane(name), axis(axis), offset(offset){
    }

    Axis AxisPlane::getAxis() const{
        return axis;
    }

    void AxisPlane::setAxis(Axis axis){
        this->axis = axis;
    }

    double AxisPlane::getOffset() const{
        return offset;
    }

    void AxisPlane::setOffset(double offset){
        this->offset = offset;
    }

    std::vector<double>& AxisPlane::getParams(std::vector<double>& toFill) const{
        toFill.push_back(offset);
        return toFill;
    }

    std::string AxisPlane::getSurfaceType() const{
        return axis == Axis::X ? "px" : (axis == Axis::Y ? "py" : "px");
    }

    VectorPlane::VectorPlane(const std::string& name, double xCoeff, double yCoeff, double zCoeff, double offset)
        : Plane(name), xCoeff(xCoeff), yCoeff(yCoeff), zCoeff(zCoeff), offset(offset){
    }

    double VectorPlane::getXCoeff() const{
        return xCoeff;
    }

    void VectorPlane::setXCoeff(double xCoeff){
        this->xCoeff = xCoeff;
    }

    double VectorPlane::getYCoeff() const{
        return yCoeff;
    }

    void VectorPlane::setYCoeff(double yCoeff){
        this->yCoeff = yCoeff;
    }

    double VectorPlane::getZCoeff() const{
        return zCoeff;
    }

    void VectorPlane::setZCoeff(double zCoeff){
        this->zCoeff = zCoeff;
    }

    double VectorPlane::getOffset() const{
        return offset;
    }

    void VectorPlane::setOffset(double offset){
        this->offset = offset;
    }

    std::vector<double>& VectorPlane::getParams(std::vector<double>& toFill) const{
        toFill.push_back(xCoeff);
        toFill.push_back(yCoeff);
        toFill.push_back(zCoeff);
        toFill.push_back(offset);
        return toFill;
    }

    std::string VectorPlane::getSurfaceType() const{
        return "plane";
    }

    PointsPlane::PointsPlane(const string& name, const point& point1, const point& point2, const point& point3) : Plane(name),
        point1(point1), point2(point2), point3(point3){
    }

    point PointsPlane::getPoint1() const{
        return point1;
    }

    void PointsPlane::setPoint1(const point& point1){
        this->point1 = point1;
    }

    point PointsPlane::getPoint2() const{
        return point2;
    }

    void PointsPlane::setPoint2(const point& point2){
        this->point2 = point2;
    }

    point PointsPlane::getPoint3() const{
        return point3;
    }

    void PointsPlane::setPoint3(const point& point3){
        this->point3 = point3;
    }

    std::vector<double>& PointsPlane::getParams(std::vector<double>& toFill) const{
        toFill.push_back(std::get<0>(point1));
        toFill.push_back(std::get<1>(point1));
        toFill.push_back(std::get<2>(point1));
        toFill.push_back(std::get<0>(point2));
        toFill.push_back(std::get<1>(point2));
        toFill.push_back(std::get<2>(point2));
        toFill.push_back(std::get<0>(point3));
        toFill.push_back(std::get<1>(point3));
        toFill.push_back(std::get<2>(point3));
        return toFill;
    }

    std::string PointsPlane::getSurfaceType() const{
        return "plane";
    }
}
