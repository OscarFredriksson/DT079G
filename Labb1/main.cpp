#include "int_buffer.h"
#include <iostream>

int main()
{

    /*int a[5];
    int b[10];

    for(int i = 0; i < 9; i++)  b[i] = a[i];

    std::cout << b[6] << std::endl;*/

    int test_source[5] = {5,2,1,2,5};
    
    int_buffer test_buffer(test_source, 10);

    int* iter = test_buffer.begin();
    for(int i = 0; i < 10; iter++, i++)
        std::cout << *iter << std::endl;


    return 0;
}