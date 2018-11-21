#include "circle.h"

class Cylinder: public Circle
{
public:
    Cylinder() = delete;

    Cylinder(double radius, double height, std::string colour = "vit");

    Cylinder(const Cylinder& src, double height);   //Copy construct

    double getHeight() const;

    double getVolume() const;

    double getArea() const;

private:
    double height = 0;
};