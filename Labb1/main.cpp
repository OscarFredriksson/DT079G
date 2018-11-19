#include "int_sorted.h"
#include <iostream>
#include <random>

void f(int_buffer buf);

void print_buffer(int_buffer src)
{
    std::cout << std::endl;
    for(int* i = src.begin(); i != src.end(); i++)
        std::cout << *i << std::endl;
}

void print_sorted(int_sorted src)
{
    std::cout << std::endl;
    for(const int* i = src.begin(); i != src.end(); i++)
        std::cout << *i << std::endl;
}

void selection_sort(int* begin, int* end);

void test_insert();

int main()
{
    //f(int_buffer(10));

    int test_source[6] = {5,2,1,2,7,5};
    int_buffer test_buffer(test_source, 6);

    test_insert();

    return 0;
}

void f(int_buffer buf)
{
    //constructor för buf körs
    int j = 1;
    for(int* i = buf.begin(); i != buf.end(); i++)  //Icke-konstanta begin och end funktioner körs här
    {
        *i = j;
        j++;
    }

    for(const int* i = buf.begin(); i != buf.end(); i++)    //Icke-konstanta begin och end funktioner körs även här
        std::cout << *i << std::endl;

    //destructor för buf körs
}

void selection_sort(int* begin, int* end)
{
    for(int* i = begin; i != end; i++)
    {
        int* min = i;

        for(int* j = i; j != end; j++)
            if(*j < *min) 
                min = j;
  
    std::swap(*i, *min);
    }
}

void test_insert()
{
    std::random_device rd;
    std::mt19937 seed(rd());
    std::uniform_int_distribution<int> rndm(1, 500);


    int_sorted test(nullptr, 0);

    for(int i = 0; i < 200; i++)
        test.insert(rndm(seed));

    print_sorted(test);
}