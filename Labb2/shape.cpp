#include "shape.h"

Shape::Shape(std::string colour)
    :colour(colour)
{}

Shape::Shape(const Shape& src)
    :colour(src.colour)
{}

std::string Shape::getColour() const
{
    return colour;
}

void Shape::swap(Shape& swap_with)
{
    std::swap(colour, swap_with.colour);
}