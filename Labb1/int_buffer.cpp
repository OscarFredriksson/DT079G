#include "int_buffer.h"
#include <utility>  //move
#include <stdio.h>  //puts

int_buffer::int_buffer(size_t size) 
    : _size(size), _ptr(new int[size])
{
    //puts("constructor");
};
    
int_buffer::int_buffer(const int* source , size_t size)
    : _size(size), _ptr(new int[size])
{    
    for(int i = 0; i < size; i++)   _ptr[i] = source[i];
};

int_buffer::int_buffer(const int_buffer& rhs)
    : _size(rhs.size()), _ptr(new int[rhs.size()])
{
    for(size_t i = 0; i < rhs.size(); i++) 
        _ptr[i] = *(rhs.begin() + i);
};

int_buffer::int_buffer(int_buffer&& rhs)
    : _size(rhs.size())
{
    (*this) = std::move(rhs);
};

int_buffer & int_buffer::operator=(const int_buffer& rhs)
{
    if (this == &rhs) return *this;

    int_buffer tmp(rhs);

    std::swap(*this, tmp);
    
    return *this;
};

int_buffer& int_buffer::operator=(int_buffer&& rhs)
{
    if (this == &rhs) return *this;
    
    delete[] _ptr;

    _ptr = rhs._ptr;
    rhs._ptr = nullptr;

    _size = rhs.size();
    rhs._size = 0;

    return *this;
};

size_t int_buffer::size() const
{
    return _size;
};

int_buffer::~int_buffer()
{
    //puts("destructor");
    delete[] _ptr;
};

int* int_buffer::begin()
{
    //puts("begin");
    return _ptr;
};

int* int_buffer::end() 
{
    //puts("end");
    return _ptr + _size;
};

const int* int_buffer::begin() const
{
    //puts("const begin");
    return _ptr;
};

const int* int_buffer::end() const
{
    //puts("const end");
    return _ptr + _size;
};

/*& int_buffer::operator[](size_t index)
{
    return _ptr[index];
}*/