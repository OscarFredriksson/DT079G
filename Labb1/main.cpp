#include "int_buffer.h"
#include <iostream>

void print_buffer(int_buffer src);

void f(int_buffer buf);

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

    int i = 0;

    f(int_buffer(10));  //constructor körs  

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
    for(int* i = buf.begin(); i != buf.end(); i++)
    {
        *i = j;
        j++;
    }

    for(const int* i = buf.begin(); i != buf.end(); i++)
        std::cout << *i << std::endl;


}   //destructor körs