#ifndef PARALLELPIPED_H
#define PARALLELPIPED_H

#include "rectangle.h"

class Parallelepiped: public Rectangle
{
public:
    Parallelepiped() = delete;

    Parallelepiped(const Rectangle& src, double depth);

    Parallelepiped(double height, double width, double depth, std::string colour = "vit");

    double getArea() const;

    double getVolume() const;

private:
    double depth = 0;
};

#endif