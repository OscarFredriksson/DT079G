#include "circle.h"
#include "cylinder.h"
#include "rectangle.h"
#include "parallelepiped.h"
#include "rounded_rectangle.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

void getData(std::vector<Shape*> shapes);

int main()
{
    std::vector<Shape*> shapes;

    shapes.push_back(new Rectangle(2, 2, "yellow"));
    shapes.push_back(new Circle(1, "blue"));
    shapes.push_back(new Rounded_Rectangle(2,2,1, "white"));
    shapes.push_back(new Cylinder(1,1, "white"));
    shapes.push_back(new Parallelepiped(1,1,1, "BLUE"));
    shapes.push_back(new Rectangle(2, 2, "green"));

    getData(shapes);

    return 0;
}

void getData(std::vector<Shape*> shapes)
{
    std::cout << std::endl;

    double totalArea = 0;
    std::map<std::string, size_t> colours;

    for(auto shape: shapes)
    {
        totalArea += shape->getArea();
        
        std::string temp = shape->getColour();
        std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

        colours[temp]++;
    }
    std::cout << "Total area: " << totalArea << std::endl;
    
    std::cout << "Colours: " << std::endl;
    
    for(auto colour: colours)
        std::cout << colour.first << ": " << colour.second << std::endl; 

    std::cout << std::endl;
}