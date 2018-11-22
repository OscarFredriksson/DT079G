#include "parallelepiped.h"

Parallelepiped::Parallelepiped(const Rectangle& src, double depth)
    :Rectangle(src), depth(depth)
{}

Parallelepiped::Parallelepiped(double height, double width, double depth, std::string colour)
    :Rectangle(height, width, colour), depth(depth)
{}

double Parallelepiped::getDepth() const
{
    return depth;
}

Parallelepiped& Parallelepiped::operator=(const Parallelepiped& rhs)
{
    Parallelepiped tmp(rhs);

    swap(tmp);

    return *this;
}

void Parallelepiped::swap(Parallelepiped& swap_with)
{
    Rectangle::swap(swap_with);
    
    std::swap(depth, swap_with.depth);
}

double Parallelepiped::getArea() const
{
    return 2* Rectangle::getArea() + 2*getWidth()*depth + 2*getHeight()*depth;
}

double Parallelepiped::getVolume() const
{
    return Rectangle::getArea() * depth;
}