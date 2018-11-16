#include "int_sorted.h"
#include <utility>
#include <stdio.h>
#include <algorithm>
#include <iostream>

int_sorted::int_sorted(const int* source, size_t size)
    :_buffer(source, size)
{
    std::sort(_buffer.begin(), _buffer.end());
};

size_t int_sorted::size() const
{
  return _buffer.size();  
};

int* int_sorted::insert(int value)
{
    int_buffer temp_buffer(_buffer.size()+1);

    int* insertpoint = _buffer.begin();

    for(const int* i = _buffer.begin(); i != _buffer.end(); i++)
    {
        if(value < *i) break;
        ++insertpoint;
    }
    
    int* temp_iter = temp_buffer.begin();

    for(int* i = _buffer.begin(); i != _buffer.end() + 1; i++, temp_iter++)
    {
        if(i == insertpoint)    
        {
            *temp_iter = value;
            temp_iter++;
        }
        *temp_iter = *i;
    }

    _buffer = std::move(temp_buffer); 

    return insertpoint;
};

const int* int_sorted::begin() const
{
    return _buffer.begin();
};

const int* int_sorted::end() const
{
    return _buffer.end();
};

/*int_sorted int_sorted::merge(const int_sorted& merge_with) const
{

};*/