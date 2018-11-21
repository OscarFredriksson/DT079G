#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle: public Shape
{
public:
    Rectangle() = default;

    Rectangle(double height, double width, std::string colour = "vit");

    Rectangle(const Rectangle& src);  //Copy construct

    double getHeight() const;
    
    double getWidth() const;

    double getArea() const;

private:
    double height = 0;
    double width = 0;
};

#endif