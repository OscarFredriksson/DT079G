#ifndef INT_BUFFER_H
#define INT_BUFFER_H
#endif

#include <cstdlib>

class int_buffer
{ 
public:
    
    //int_buffer() = default; //default constructor

    explicit int_buffer(size_t size)    
        :_size(size), _ptr(new int[size])    //initiera _size med inargumentets värde
        {};

    
    int_buffer(const int* source , size_t size); 
    
    int_buffer(const int_buffer& rhs); // copy construct
    
    int_buffer(int_buffer&& rhs); // moveconstruct
    
    int_buffer & operator=(const int_buffer& rhs); // copy assign
    
    int_buffer & operator=(int_buffer&& rhs);   // move assign
    
    size_t size() const;
    
    int* begin();
    
    int* end();
    
    const int* begin() const; 
    
    const int* end() const; 
    
    ~int_buffer();

private:

    int* _ptr = nullptr;
    size_t _size = 0;

};
