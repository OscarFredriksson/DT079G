#include "int_buffer.h"

int_buffer::int_buffer(size_t size) 
    : _size(size), _ptr(new int[size])
    {
        puts("constructor");
    };    //initiera _size med inargumentets värde
    

int_buffer::int_buffer(const int* source , size_t size)
    : _size(size), _ptr(new int[size])
{    
    for(int i = 0; i < size; i++)   _ptr[i] = source[i];
}

int_buffer::int_buffer(const int_buffer& rhs)
    : _size(rhs.size()), _ptr(new int[rhs.size()])
{
    puts("copy constructor");
    *this = rhs;
}

int_buffer::int_buffer(int_buffer&& rhs)
    : _size(rhs.size())
{
    puts("move constructor");
    *this = std::move(rhs);
}

int_buffer & int_buffer::operator=(const int_buffer& rhs)
{
    for(int i = 0; i < rhs.size(); i++) 
        _ptr[i] = *(rhs.begin() + i);
    
    return *this;
}

int_buffer & int_buffer::operator=(int_buffer&& rhs)
{
    _ptr = rhs.begin();
    rhs._ptr = nullptr;

    return *this;
}

size_t int_buffer::size() const
{
    return _size;
}

int_buffer::~int_buffer()
{
    puts("destructor");
    delete[] _ptr;
}

int* int_buffer::begin()
{
    return _ptr;
}

int* int_buffer::end() 
{
    return _ptr + _size - 1;
}

const int* int_buffer::begin() const
{
    return _ptr;
}

const int* int_buffer::end() const
{
    return _ptr + _size - 1;
}

