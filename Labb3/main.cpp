#include "p_queue.h"
#include <iostream>
#include <string>
#include <cstdlib> //srand
#include <ctime>

struct Order
{
    Order(unsigned int price, const std::string& broker):
        price(price),
        broker(broker)
    {}

    std::string broker;
    unsigned int price;
};

struct less
{
    bool operator()(Order a, Order b)
    {
        return a.price < b.price;
    }
};

int main()
{
    srand(time(NULL));

    p_queue<Order, less> buyOrders;
    p_queue<Order, less> sellOrders;

    for(int i = 0; i < 3; i++)
    {
        std::string broker;
        if(i == 0)  broker = "Erik Pendel";
        if(i == 1)  broker = "Jarl Wallenburg";
        if(i == 2)  broker = "Joakim Von Anka";

        for(int j = 0; j < 7; j++)
        {
            unsigned int random = rand() % 16 + 15;
            buyOrders.push(Order(random, broker));
            random = rand() % 16 + 15;
            sellOrders.push(Order(random, broker));
        
        }
    }

    while(!buyOrders.empty() && !sellOrders.empty())
    {
        if(sellOrders.top().price <= buyOrders.top().price) 
        {
            Order buyOrder = buyOrders.pop();
            Order sellOrder = sellOrders.pop();

            std::cout << buyOrder.broker << " köpte av " << sellOrder.broker << " för " << buyOrder.price << "kr." << std::endl; 
        } 
        else buyOrders.pop();
    }

    return 0;
}