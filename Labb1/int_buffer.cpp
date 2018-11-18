#include "int_buffer.h"
#include <utility>  //move
#include <algorithm>

int_buffer::int_buffer(size_t size) 
    : _size(size), _ptr(new int[size]){};
    
int_buffer::int_buffer(const int* source , size_t size)
    : _size(size), _ptr(new int[size])
{    
    std::copy(source, source + size, _ptr);
};

int_buffer::int_buffer(const int_buffer& rhs)
    : _size(rhs.size()), _ptr(new int[rhs.size()])
{
    std::copy(rhs.begin(), rhs.end(), begin());
};

int_buffer::int_buffer(int_buffer&& rhs)
{
    std::swap(_ptr, rhs._ptr);
    std::swap(_size, rhs._size);
};

int_buffer & int_buffer::operator=(const int_buffer& rhs)
{
    if (this == &rhs) return *this;

    int_buffer tmp(rhs);

    std::swap(_ptr, tmp._ptr);
    std::swap(_size, tmp._size);
    
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
    if(_ptr != nullptr) delete[] _ptr;
};

int* int_buffer::begin()
{
    return _ptr;
};

int* int_buffer::end() 
{
    return _ptr + _size;
};

const int* int_buffer::begin() const
{
    return _ptr;
};

const int* int_buffer::end() const
{
    return _ptr + _size;
};