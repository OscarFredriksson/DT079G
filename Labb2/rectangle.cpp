#include "rectangle.h"

Rectangle::Rectangle(double height, double width, std::string colour)
    :height(height), width(width), Shape(colour)
{}

Rectangle::Rectangle(const Shape& src, double height, double width)
    :Shape(src), height(height), width(width)
{}

Rectangle::Rectangle(const Rectangle& src)   //Copy construct
    :height(src.height), width(src.width), Shape(src.getColour())
{}

Rectangle& Rectangle::operator=(const Rectangle& rhs)
{
    Rectangle tmp(rhs);

    swap(tmp);

    return *this;
}

double Rectangle::getHeight() const
{
    return height;
}

double Rectangle::getWidth() const
{
    return width;
}

double Rectangle::getArea() const
{
    return height * width;
}

void Rectangle::swap(Rectangle& swap_with)
{
    Shape::swap(swap_with);

    std::swap(height, swap_with.height);
    std::swap(width, swap_with.width);
}