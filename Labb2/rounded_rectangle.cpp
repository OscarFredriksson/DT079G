#include "rounded_rectangle.h"

Rounded_Rectangle::Rounded_Rectangle(double height, double width, double corner_radius, std::string colour)
    :Rectangle(height, width, colour), corner_radius(corner_radius)
{}

Rounded_Rectangle::Rounded_Rectangle(const Rectangle& src, double corner_radius)
    :Rectangle(src), corner_radius(corner_radius)
{}

Rounded_Rectangle::Rounded_Rectangle(const Rounded_Rectangle& src)
    :Rectangle(src.getWidth(), src.getHeight()), corner_radius(src.getCornerRadius())
{}

Rounded_Rectangle& Rounded_Rectangle::operator=(const Rounded_Rectangle& rhs)
{
    Rounded_Rectangle tmp(rhs);

    swap(tmp);

    return *this;
}

void Rounded_Rectangle::swap(Rounded_Rectangle& swap_with)
{
    Rectangle::swap(swap_with);

    std::swap(corner_radius, swap_with.corner_radius);
}

double Rounded_Rectangle::getCornerRadius() const
{
    return corner_radius;
}

double Rounded_Rectangle::getArea() const
{
    const int squared_corners = 4 * corner_radius * corner_radius;   //Remove the squared corners
    
    const int rounded_corners = corner_radius * corner_radius * pi; //Replace with the rounded

    return getWidth() * getHeight() - squared_corners + rounded_corners;
}