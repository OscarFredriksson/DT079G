#include "p_queue.h"
#include <iostream>
#include <string>

struct sellOrder
{
    std::string name;
    double price;
};

struct buyOrder
{
    std::string name;
    double price;
};

int main()
{

    p_queue<int> list;
    
    list.push(5);
    list.push(6);
    list.push(3);

    std::cout << p_queue<int>::less(list[1], list[2]) << std::endl;


    //for(int i = 0; i < list.size(); i++)
    //    std::cout << list[i] << std::endl;



    return 0;
}

