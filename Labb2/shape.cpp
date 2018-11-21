#include "shape.h"

Shape::Shape(std::string colour)
    :colour(colour)
{}

std::string Shape::getColour() const
{
    return colour;
}
