#ifndef PARALLELPIPED_H
#define PARALLELPIPED_H

#include "rectangle.h"

class Parallelepiped: public Rectangle
{
public:
    Parallelepiped() = delete;

    Parallelepiped(const Rectangle& src, double depth);

    Parallelepiped(double height, double width, double depth, std::string colour = "vit");

    Parallelepiped& operator=(const Parallelepiped& rhs);

    void swap(Parallelepiped& swap_with);

    double getDepth() const;

    double getArea() const override;

    double getVolume() const;

protected:
    double depth = 0;
};

#endif