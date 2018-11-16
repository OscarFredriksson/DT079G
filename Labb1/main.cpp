//#include "int_buffer.h"
#include "int_sorted.h"
#include <iostream>

void print_buffer(int_buffer src);

void f(int_buffer buf);

void print_sorted(int_sorted src)
{
    for(const int* i = src.begin(); i != src.end(); i++)
        std::cout << *i << std::endl;
}

int main()
{
    /*int test_source[5] = {5,2,1,2,5};
    
    int_buffer test_buffer(test_source, 5);

    int_buffer copy_test(test_buffer);
 
    int_buffer test2 = test_buffer;

    int_buffer test3(std::move(test2));

    print_buffer(test3);

    std::cout << std::endl;

    print_buffer(test2);*/

    //int i = 0;

    //f(int_buffer(10));  //constructor körs 

    int test_source[5] = {5,2,1,2,5};
    int_buffer test_buffer(test_source, 5);

    //int_buffer tmp = test_buffer;

    //print_buffer(tmp);

    int_sorted test_sorted(test_buffer.begin(), test_buffer.size()); 

    print_sorted(test_sorted);
    std::cout << std::endl;

    test_sorted.insert(3);

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