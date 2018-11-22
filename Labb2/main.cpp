#include <iostream>
#include "circle.h"
#include "cylinder.h"
#include "rectangle.h"
#include "parallelepiped.h"
#include "rounded_rectangle.h"
#include <vector>
#include <map>

void getData(std::vector<Shape*> shapes);

std::string tolower(std::string str);

int main()
{
    std::vector<Shape*> shapes;

    shapes.push_back(new Rectangle(2, 2, "yellow"));
    shapes.push_back(new Circle(1, "blue"));
    shapes.push_back(new Rounded_Rectangle(2,2,1, "white"));
    shapes.push_back(new Cylinder(1,1, "white"));
    shapes.push_back(new Parallelepiped(1,1,1, "blue"));

    getData(shapes);

    return 0;
}

void getData(std::vector<Shape*> shapes)
{
    double totalArea = 0;
    std::map<std::string, size_t> colours;

    for(auto shape: shapes)
    {
        totalArea += shape->getArea();
        
        std::string temp = tolower(shape->getColour());
        colours[temp]++;
    }
    std::cout << "Total area: " << totalArea << std::endl;
    
    
    std::cout << "Colours: " << std::endl;
    
    for(auto colour: colours)
        std::cout << colour.first << ": " << colour.second << " st" << std::endl; 
}

//Tar in en sträng och returnar strängen där samtliga tecken är omvandlade till lowercase.
std::string tolower(std::string str)   
{
    for(int i = 0; i<str.length();i++)  //Går igenom samtliga tecken i strängen och gör om de till lowercase
            str[i] = tolower(str[i]);
    
    /*
    *   tolower funktionen funktionen funkar ej för åäö därför används nedanstående metod
    *   för att göra dessa till lowercase.
    */
    while(str.find("Å") != std::string::npos)   //Sålänge ett eller flera "Å" kan hittas i strängen
        str.replace(str.find("Å"), 2, "å");     //Ersätt "Å" med "å"
    
    while(str.find("Ä") != std::string::npos)
        str.replace(str.find("Ä"), 2, "ä");
    
    while(str.find("Ö") != std::string::npos)
        str.replace(str.find("Ö"), 2, "ö");
    
    return str; //Returnerar den omvandlade strängen
}