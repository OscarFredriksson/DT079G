#include <iostream>
#include <vector>
#include "car.h"
#include <chrono>
#include <random>
#include <algorithm>
#include <array>
#include <numeric>

struct MyPrint 
{
    void operator()(const Car& car)
    {
        std::cout << "Name: " << car.getName() << " Speed: " << car.getSpeed() << std::endl;
    }
};

struct greater
{
    greater(const int value): value(value) {}

    bool operator()(const Car& e)
    {
        return e.getSpeed() > value;
    }
    const int value;
};

struct MyBinOp
{
    MyBinOp(size_t size): size(size) {};

    double operator()(const Car& e)
    {
        return (e.getSpeed())/size; 
    }
    size_t size;
};

struct MyUnOp
{
    double operator()(const Car& e)
    {
        return e.getSpeed();
    }
};

struct MyFunc
{
    MyFunc(double mean): mean(mean){}
    double operator()(const double e)
    {
        return e - mean;
    }
    double mean;
};

int main()
{
    //Seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine gen(seed);
    std::uniform_real_distribution<double> dist(50.0, 250.0);

    std::array<Car, 6> car_arr = {  Car("BMW",   dist(gen)),
                                    Car("Saab",  dist(gen)),
                                    Car("Volvo", dist(gen)),
                                    Car("Volvo", dist(gen)),
                                    Car("Fiat",  dist(gen)),
                                    Car("Honda", dist(gen))};

    std::vector<Car> cars(car_arr.begin(), car_arr.end());

    MyPrint printer;

    std::cout << "1. Printing all cars:" << std::endl;
    std::cout << "\t";
    std::for_each(cars.begin(), cars.end(), printer);
    std::cout << std::endl;

    const int value = 85.0;
    std::cout << "2. Finding car with speed greater than " << value << ", found:" << std::endl;
    std::cout << "\t";
    auto found = std::find_if(cars.begin(), cars.end(), greater(value));
    if(found != cars.end())
        printer(*found);
    std::cout << std::endl;


    std::cout << "3. Finding adjacent cars with same name, found:" << std::endl;
    std::cout << "\t";
    auto found2 = std::adjacent_find(cars.begin(), cars.end());
    if(found2 != cars.end())
        printer(*found2);
    else
        std::cout << "Found none" << std::endl;
    std::cout << std::endl;


    std::cout << "4. Checking if the vector is equal to the original array, result:" << std::endl;
    std::cout << "\t";
    if(std::equal(cars.begin(), cars.end(), car_arr.begin()))
        std::cout << "Equal!" << std::endl;
    else
        std::cout << "Not equal" << std::endl;
    std::cout << std::endl;

    
    std::cout << "5. Finding subarray in vector, found:" << std::endl;
    std::cout << "\t";
    auto found3 = std::search(cars.begin(), cars.end(), car_arr.begin() + 1, car_arr.begin() + 3);
    
    if(found3 != cars.end())    std::for_each(found3, cars.begin() + 3, printer);
    std::cout << std::endl;


    std::cout << "6. Mean value of all cars speed:" << std::endl;
    std::cout << "\t";
    MyBinOp op(cars.size());
    auto mean = std::accumulate(cars.begin(), cars.end(), 0.0, [&](double x, const Car& e)
    {
        return x += op(e);
    });
    std::cout << mean << std::endl << std::endl;

    std::vector<double> v2(cars.size());
    std::transform(cars.begin(), cars.end(), v2.begin(), MyUnOp());    

    MyFunc func(mean);
    std::transform(v2.begin(), v2.end(), v2.begin(), func);

    std::sort(v2.begin(), v2.end());

    std::cout << "9. New vector:" << std::endl;

    std::cout << "\t";
    auto print = [](const double e)
    {
        std::cout << e << " ";
    };

    std::for_each(v2.begin(), v2.end(), print);
    std::cout << std::endl << std::endl;

    return 0;    
}