#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle: public Shape
{
public:
    Circle() = delete;

    Circle(double radius, std::string colour = "vit");

    Circle(const Circle& src);

    double getRadius() const;

    double getArea() const;

    double getCircumference() const;

private:
    double radius = 0;

    static constexpr double pi = 3.1415;
};

#endif