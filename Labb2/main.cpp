#include <iostream>

#include "cylinder.h"

#include "rectangle.h"

int main()
{
   Rectangle a(2, 2, "gul");

   Rectangle b(1, 1);
   b = a;

   std::cout << b.getColour() << std::endl;
   std::cout << b.getArea() << std::endl;

    return 0;
}