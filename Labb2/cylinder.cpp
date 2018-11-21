#include "cylinder.h"

Cylinder::Cylinder(double radius, double height, std::string colour)
    :Circle(radius, colour), height(height)
{}

Cylinder::Cylinder(const Cylinder& src, double height)  //Copy construct
    :Circle(src), height(height)
{}

double Cylinder::getVolume() const
{
    return Circle::getArea() * height;
}

double Cylinder::getArea() const
{
    return 2 * Circle::getArea() + getCircumference() * height;
}