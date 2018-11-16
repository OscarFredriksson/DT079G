#ifndef INT_BUFFER_H
#define INT_BUFFER_H
#endif

#include <cstddef>  //size_t

class int_buffer
{ 
public:
    
    int_buffer() = delete;

    explicit int_buffer(size_t size);

    int_buffer(const int* source , size_t size);    //resize constructor
    
    int_buffer(const int_buffer& rhs); //copy construct
    
    int_buffer(int_buffer&& rhs); //move construct
    
    int_buffer & operator=(const int_buffer& rhs); //copy assign
    
    int_buffer & operator=(int_buffer&& rhs);   //move assign
    
    size_t size() const;
    
    int* begin();
    
    int* end();
    
    const int* begin() const; 
    
    const int* end() const; 

    ~int_buffer();

    //int& operator[](size_t index);

private:

    int* _ptr = nullptr;
    size_t _size = 0;

};