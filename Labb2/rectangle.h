#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle: public Shape
{
public:
    Rectangle() = default;

    Rectangle(double height, double width, std::string colour = "vit");

    Rectangle(const Shape& src, double height, double width);

    Rectangle(const Rectangle& src);  //Copy construct

    Rectangle& operator=(const Rectangle& rhs);

    void swap(Rectangle& swap_with);

    double getHeight() const;
    
    double getWidth() const;

    virtual double getArea() const override;

protected:
    double height = 0;
    double width = 0;
};

#endif