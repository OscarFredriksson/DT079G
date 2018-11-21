#include <iostream>

#include "cylinder.h"

int main()
{
    Cylinder c(2,2);

    std::cout << c.getArea() << std::endl;

    return 0;
}