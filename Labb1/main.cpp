//#include "int_buffer.h"
#include "int_sorted.h"
#include <iostream>

void print_buffer(int_buffer src);

void f(int_buffer buf);

void print_sorted(int_sorted src)
{
    std::cout << std::endl;
    for(const int* i = src.begin(); i != src.end(); i++)
        std::cout << *i << std::endl;
}

int main()
{
    //f(int_buffer(10));  //constructor körs 

    int test_source[5] = {5,2,1,2,5};
    int_buffer test_buffer(test_source, 5);

    int_sorted test_sorted(test_buffer.begin(), test_buffer.size()); 

    //print_sorted(test_sorted);
    //std::cout << std::endl;

    test_sorted.insert(7);

    print_sorted(test_sorted);

    int_sorted merge_with(test_buffer.begin(), test_buffer.size());

    merge_with.insert(4);
    merge_with.insert(19);
    merge_with.insert(-2);

    print_sorted(merge_with);

    test_sorted = test_sorted.merge(merge_with);

    print_sorted(test_sorted);

    return 0;
}

void print_buffer(int_buffer src)
{
    for(int* i = src.begin(); i != src.end(); i++)
        std::cout << *i << std::endl;
}

void f(int_buffer buf)
{
    int j = 1;
    for(int* i = buf.begin(); i != buf.end(); i++)  //Icke-konstanta begin och end funktioner körs här
    {
        *i = j;
        j++;
    }

    for(const int* i = buf.begin(); i != buf.end(); i++)    //Icke-konstanta begin och end funktioner körs även här
        std::cout << *i << std::endl;

    //destructor körs
}   