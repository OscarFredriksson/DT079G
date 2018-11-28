#include "p_queue.h"
#include <iostream>

int main()
{

    p_queue<int> list;
    
    list.push(5);
    list.push(6);
    list.push(3);

    std::cout << list.size() << std::endl;

    for(int i = 0; i < list.size(); i++)
        std::cout << list[i] << std::endl;

    return 0;
}

