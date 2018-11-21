#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
public:
    Shape() = delete;

    Shape(std::string colour);

    std::string getColour() const;

private:
    std::string colour = "";
};

#endif