#include "circle.h"
#include <iostream>

Circle::Circle(double radius, std::string colour)
    :radius(radius), Shape(colour)
{}

Circle::Circle(const Circle& src)
    :radius(src.radius), Shape(src.getColour())
{}

Circle& Circle::operator=(const Circle& rhs)
{
    Circle tmp(rhs);

    swap(tmp);

    return *this;
}

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

void Circle::swap(Circle& swap_with)
{
    Shape::swap(swap_with);
    
    std::swap(radius, swap_with.radius);
}

