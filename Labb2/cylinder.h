#ifndef CYLINDER_H
#define CYLINDER_H

#include "circle.h"

class Cylinder: public Circle
{
public:
    Cylinder() = delete;

    Cylinder(double radius, double height, std::string colour = "vit");

    Cylinder(const Circle& src, double height);   //Copy construct

    Cylinder& operator=(const Cylinder& rhs);

    void swap(Cylinder& swap_with);

    double getHeight() const;

    double getVolume() const;

    double getArea() const override;

protected:
    double height = 0;
};

#endif