#include "rectangle.h"

class Rounded_Rectangle: public Rectangle
{
public:
    Rounded_Rectangle(double height, double width, double corner_radius, std::string colour = "vit");

    Rounded_Rectangle(const Rectangle& src, double corner_radius);

    Rounded_Rectangle(const Rounded_Rectangle& src);   

    double getCornerRadius() const;

private:
    double corner_radius = 0;

};