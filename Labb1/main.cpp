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

int_sorted merge_sort(const int* begin , const int* end);

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

int_sorted merge_sort(const int* begin , const int* end)
{
    if (begin == end)   return int_sorted(nullptr, 0); 
    
    if (begin == end - 1)   return int_sorted(begin, 1);

    ptrdiff_t half = (end - begin) / 2; // pointer diff type

    const int* mid = begin + half;
    
    return merge_sort(begin, mid).merge(merge_sort(mid, end));
}

void test_insert()
{
    /*std::random_device rd;
    std::mt19937 seed(rd());
    std::uniform_int_distribution<int> rndm(1, 500);*/


    int_sorted test(nullptr, 0);

    for(int i = 0; i < 200; i++)
        test.insert(rand() % 500);    //rndm(seed));

    print_sorted(test);
}

void test_sorts()
{
    std::cout << std::endl;

    const int size = 40000;  //00;

    int src[size];

    for(int i = 0; i < size; i++)
        src[i] = rand();

    int_buffer to_sort(src, size);


    //Start selection sort
    auto startselection = std::chrono::high_resolution_clock::now();
    
    selection_sort(to_sort.begin(), to_sort.end());
    
    auto finishselection = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedselection = finishselection - startselection;
    
    std::cout << "Selection sort took: " << elapsedmerge.count() << "s." << std::endl;
    
    
    to_sort = int_buffer(src, size);

    //Start merge sort
    auto startmerge = std::chrono::high_resolution_clock::now();
    
    merge_sort(to_sort.begin(), to_sort.end());
    
    auto finishmerge = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedmerge = finishmerge - startmerge;
    
    std::cout << "Merge sort took: " << elapsedmerge.count() << "s." << std::endl;

    
    to_sort = int_buffer(src, size);

    //Start std::sort
    auto startstd = std::chrono::high_resolution_clock::now();
    
    std::sort(to_sort.begin(), to_sort.end());
    
    auto finishstd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedstd = finishstd - startstd;
    
    std::cout << "std::sort took: " << elapsedstd.count() << "s." << std::endl;

    std::cout << std::endl;
}