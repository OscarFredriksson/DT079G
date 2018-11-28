#include "cylinder.h"

Cylinder::Cylinder(double radius, double height, std::string colour)
    :Circle(radius, colour), height(height)
{}

Cylinder::Cylinder(const Circle& src, double height)  //Copy construct
    :Circle(src), height(height)
{}

Cylinder& Cylinder::operator=(const Cylinder& rhs)
{
    Cylinder tmp(rhs);

    swap(tmp);

    return *this;
}

void Cylinder::swap(Cylinder& swap_with)
{
    Circle::swap(swap_with);
    
    std::swap(height, swap_with.height);
}

double Cylinder::getVolume() const
{
    return Circle::getArea() * height;
}

double Cylinder::getArea() const override
{
    return 2 * Circle::getArea() + getCircumference() * height;
}