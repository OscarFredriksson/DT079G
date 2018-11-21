#include "shape.h"

class Rectangle: public Shape
{
public:
    int getHeight() const;
    int getWidth() const;


private:
    int height = 0;
    int width = 0;

};