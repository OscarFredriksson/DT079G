#include "p_queue.h"
#include <iostream>
#include <string>

void print(std::pair<int, std::string> e)
{
    std::cout << e.first << " " << e.second << std::endl;
}

int main()
{

    p_queue<std::pair<int, std::string>> list;
    
    list.push(std::make_pair(5, "Erik Pendel"));
    list.push(std::make_pair(6, "Jarl Wallenburg"));
    list.push(std::make_pair(3, "Joakim von Anka"));

    std::for_each(list.begin(), list.end(), print);

    return 0;
}

