#include "int_sorted.h"

int_sorted::int_sorted(const int* source, size_t size)
    :_buffer(source, size){};

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