#include "int_sorted.h"
#include <utility>
#include <stdio.h>

int_sorted::int_sorted(const int* source, size_t size)
    :_buffer(source, size)
{
    //bubble sort
    /*for (int* i = _buffer.begin(); i != _buffer.end()-1; i++)       
  
        for (int* j = _buffer.begin(); j != _buffer.end() - i + _buffer.end() -1; j++)  
            
            if (*j > *(j+1)) 
            {
                int* temp = j;
                j = j + 1;
                (j + 1) = temp; 
            }*/
};

size_t int_sorted::size() const
{
  return _buffer.size();  
};

int* int_sorted::insert(int value)
{

};

const int* int_sorted::begin() const
{
    return _buffer.begin();
};

const int* int_sorted::end() const
{
    return _buffer.end();
};

int_sorted int_sorted::merge(const int_sorted& merge_with) const
{

};