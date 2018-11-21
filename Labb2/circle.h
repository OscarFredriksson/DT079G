#include "shape.h"

class Circle: public Shape
{
public:
    int getRadius() const;

private:
    int radius = 0;
};