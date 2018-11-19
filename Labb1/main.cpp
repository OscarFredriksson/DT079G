#include "int_sorted.h"
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>

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

void test_sorts();

int main()
{
    srand(time(NULL));

    //f(int_buffer(10));

    //test_insert();

    test_sorts();

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
    int_sorted test(nullptr, 0);

    for(int i = 0; i < 200; i++)
        test.insert(rand() % 500);

    print_sorted(test);
}

void test_sorts()
{
    std::cout << std::endl;

    const int size = 400000;

    int src[size];

    for(int i = 0; i < size; i++)
        src[i] = rand();

    int_buffer to_sort(src, size);

    

    //Start merge sort
    auto start = std::chrono::high_resolution_clock::now();
    
    //merge_sort(to_sort.begin(), to_sort.end());
    int_sorted srt(src, size);

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    
    std::cout << "Merge sort took: " << elapsed.count() << "s." << std::endl;

    
    to_sort = int_buffer(src, size);

    //Start std::sort
    start = std::chrono::high_resolution_clock::now();
    
    std::sort(to_sort.begin(), to_sort.end());
    
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    
    std::cout << "std::sort took: " << elapsed.count() << "s." << std::endl;

    
    to_sort = int_buffer(src, size);

    //Start selection sort
    start = std::chrono::high_resolution_clock::now();
    
    selection_sort(to_sort.begin(), to_sort.end());
    
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    
    std::cout << "Selection sort took: " << elapsed.count() << "s." << std::endl;
    
    

    
    std::cout << std::endl;
}