#include "int_buffer.h"

int_buffer::int_buffer(size_t size) 
    :_size(size), _ptr(new int[size]){};    //initiera _size med inargumentets värde
    

int_buffer::int_buffer(const int* source , size_t size)
    :_size(size), _ptr(new int[size])
{    
    for(int i = 0; i < size; i++) _ptr[i] = source[i];
}

size_t int_buffer::size() const
{
    return _size;
}

int_buffer::~int_buffer()
{
    delete[] _ptr;
}

int* int_buffer::begin()
{
    return _ptr;
}

int* int_buffer::end() 
{
    return _ptr + _size -1;
}

const int* int_buffer::begin() const
{
    return _ptr;
}

const int* int_buffer::end() const
{
    return _ptr + _size -1;
}