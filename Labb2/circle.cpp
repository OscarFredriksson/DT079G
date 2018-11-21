#include "circle.h"

Circle::Circle(double radius, std::string colour)
    :radius(radius), Shape(colour)
{}

Circle::Circle(const Circle& src)
    :radius(src.radius), Shape(src.getColour())
{}

double Circle::getRadius() const
{
    return radius;
}

double Circle::getArea() const
{
    return radius * radius * pi;
}

double Circle::getCircumference() const
{
    return 2 * radius * pi;
}