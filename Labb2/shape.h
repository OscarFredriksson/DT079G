#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
public:
    Shape() = delete;

    Shape(std::string colour);

    Shape(const Shape& src);

    virtual double getArea() const = 0; //Pure virtual function

    std::string getColour() const;

    void swap(Shape& swap_with);

protected:
    std::string colour = "";
};

#endif