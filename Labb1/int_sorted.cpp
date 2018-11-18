#include "int_sorted.h"
#include <utility>
#include <stdio.h>
#include <algorithm>
#include <iostream>

int_sorted::int_sorted(const int* source, size_t size)
    :_buffer(source, size)
{
    if(size < 2)    return;

    int_sorted temp = sort(source, source + size);
 
    _buffer = std::move(temp._buffer);
}

size_t int_sorted::size() const
{
  return _buffer.size();  
}

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
}

const int* int_sorted::begin() const
{
    return _buffer.begin();
}

const int* int_sorted::end() const
{
    return _buffer.end();
}

int_sorted int_sorted::merge(const int_sorted& merge_with) const
{
    int_buffer merged(size() + merge_with.size());

    const int* iter1 = begin();
    const int* iter2 = merge_with.begin();
    int* merged_iter = merged.begin();

    for(;iter1 != end() && iter2 != merge_with.end(); merged_iter++)
    {
        if(*iter1 < *iter2)
        {
            *merged_iter = *iter1;
            iter1++;
        }
        else
        {
            *merged_iter = *iter2;
            iter2++;
        }
    }
    //Om det finns nått kvar i någon av buffrarna, skriv dessa till den nya
    for(;iter1 != end(); iter1++, merged_iter++) 
        *merged_iter = *iter1;
    
    for(;iter2 != merge_with.end(); iter2++, merged_iter++) 
        *merged_iter = *iter2;

    int_sorted ret(nullptr, 0);
    
    ret._buffer = std::move(merged);

    return ret;
}

int_sorted int_sorted::sort(const int* begin , const int* end)
{
    if (begin == end)   return int_sorted(nullptr, 0); 
    
    if (begin == end - 1)   return int_sorted(begin, 1);

    ptrdiff_t half = (end - begin) / 2; // pointer diff type

    const int* mid = begin + half;
    
    return sort(begin, mid).merge(sort(mid, end));
}