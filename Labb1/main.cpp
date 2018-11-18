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

int_sorted sort(const int* begin , const int* end);

void selection_sort(int* begin, int* end);

int main()
{
    //f(int_buffer(10));

    int test_source[6] = {5,2,1,2,7,5};
    int_buffer test_buffer(test_source, 6);

    //int_sorted test = sort(test_buffer.begin(), test_buffer.end());

    //print_sorted(test);

    /*int_sorted test_sorted = sort(test_buffer.begin(), test_buffer.end());

    print_sorted(test_sorted);*/

    /*int_sorted test2(test_buffer.begin(), test_buffer.size());

    int_sorted test3(nullptr, 0);
    test3 = std::move(test_sorted); 

    print_sorted(test3);

    int_buffer buffer2(test_buffer);

    int_sorted merge_with(test_buffer.begin(), test_buffer.size());

    merge_with.insert(4);
    merge_with.insert(19);
    merge_with.insert(-2);
    merge_with.insert(5);

    print_sorted(merge_with);

    test_sorted = test_sorted.merge(merge_with);

    print_sorted(test_sorted);*/

    //int_sorted test_sorted(test_buffer.begin(), 6);

    int_sorted test_sorted = sort(test_buffer.begin(), test_buffer.end());

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

int_sorted sort(const int* begin , const int* end)
{
    if (begin == end)   return int_sorted(nullptr, 0); 
    if (begin == end -1)    return int_sorted(begin, 1);

    ptrdiff_t half = (end - begin) / 2; // pointer diff type

    const int* mid = begin + half;
    
    return sort(begin, mid).merge(sort(mid, end));
}

void selection_sort(int* begin, int* end)
{
    for(int* i = begin; i != end; i++)
    {
        int* min = i;

        for(int* j = i; i != end; j++)
            if(*j < *min) 
                min = j;
        
    //if(min != i)    
    std::swap(i, min);
    }
}