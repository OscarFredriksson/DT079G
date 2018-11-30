#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle: public Shape
{
public:
    Circle() = delete;

    Circle(double radius, std::string colour = "vit");

    Circle(const Circle& src);

    Circle& operator=(const Circle& rhs);

    void swap(Circle& swap_with);

    double getRadius() const;

    virtual double getArea() const override;

    double getCircumference() const;

private:
    double radius = 0;

    static constexpr double pi = 3.14159265359;
};

#endif