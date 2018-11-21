#include "parallelepiped.h"

Parallelepiped::Parallelepiped(const Rectangle& src, double depth)
    :Rectangle(src), depth(depth)
{}

Parallelepiped::Parallelepiped(double height, double width, double depth, std::string colour)
    :Rectangle(height, width, colour), depth(depth)
{}

double Parallelepiped::getArea() const
{
    return 2* Rectangle::getArea() + 2*getWidth()*depth + 2*getHeight()*depth;
}

double Parallelepiped::getVolume() const
{
    return Rectangle::getArea() * depth;
}