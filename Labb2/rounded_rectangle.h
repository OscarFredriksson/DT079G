#ifndef ROUNDED_RECTANGLE_H
#define ROUNDED_RECTANGLE_H

#include "rectangle.h"

class Rounded_Rectangle: public Rectangle
{
public:
    Rounded_Rectangle(double height, double width, double corner_radius, std::string colour = "vit");

    Rounded_Rectangle(const Rectangle& src, double corner_radius);

    Rounded_Rectangle(const Rounded_Rectangle& src);   

    Rounded_Rectangle& operator=(const Rounded_Rectangle& rhs);

    void swap(Rounded_Rectangle& swap_with);

    double getCornerRadius() const;

    double getArea() const override;

private:
    double corner_radius = 0;

    static constexpr double pi = 3.14159265359; 
};

#endif