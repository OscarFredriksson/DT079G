#include "int_buffer.h"
#include <utility>  //move
#include <algorithm>

int_buffer::int_buffer(size_t size)     //"Default" konstruktor
    : _size(size), _ptr(new int[size])
{};
    
int_buffer::int_buffer(const int* source , size_t size) //Resize konstruktor
    : _size(size), _ptr(new int[size])
{    
    std::copy(source, source + size, _ptr);
};

int_buffer::int_buffer(const int_buffer& rhs)   //Copy konstruktor
    : _size(rhs.size()), _ptr(new int[rhs.size()])
{
    std::copy(rhs.begin(), rhs.end(), begin());
};

int_buffer::int_buffer(int_buffer&& rhs)    //Move konstruktor
    :_ptr(rhs._ptr), _size(rhs._size)
{
    rhs._ptr = nullptr; //Förhindra att destruktorn frigör samma minne flera gånger
    rhs._size = 0;
};

int_buffer & int_buffer::operator=(const int_buffer& rhs)   //Copy assign
{
    int_buffer tmp(rhs);

    swap(tmp);
    
    return *this;
};

int_buffer& int_buffer::operator=(int_buffer&& rhs) //Move assign
{
    swap(rhs); 

    return *this;
};

size_t int_buffer::size() const
{
    return _size;
};

int_buffer::~int_buffer()
{    
   if(_ptr != nullptr)  delete[] _ptr;
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

void int_buffer::swap(int_buffer& swap_with)
{
    std::swap(_size, swap_with._size);
    std::swap(_ptr, swap_with._ptr);
};
