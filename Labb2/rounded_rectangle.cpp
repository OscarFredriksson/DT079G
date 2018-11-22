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