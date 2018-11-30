#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
public:
    Shape() = delete;

    Shape(std::string colour);

    Shape(const Shape& src);

    virtual double getArea() const = 0; //Pure virtual funktion

    std::string getColour() const;

    void swap(Shape& swap_with);

private:
    std::string colour = "";
};

#endif