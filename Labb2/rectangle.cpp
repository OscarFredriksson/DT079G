#include "rectangle.h"

Rectangle::Rectangle(double height, double width, std::string colour)
    :height(height), width(width), Shape(colour)
{}

Rectangle::Rectangle(const Rectangle& src)   //Copy construct
    :height(src.height), width(src.width), Shape(src.getColour())
{}

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