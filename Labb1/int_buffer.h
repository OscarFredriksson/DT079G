#ifndef INT_BUFFER_H
#define INT_BUFFER_H
#endif

#include <cstddef>  //size_t

class int_buffer
{ 
public:
    
    int_buffer() = delete;  //Ta bort default-konstruktorn

    explicit int_buffer(size_t size);   //"default" konstruktor

    int_buffer(const int* source , size_t size);    //resize konstruktor
    
    int_buffer(const int_buffer& rhs); //copy konstruktor
    
    int_buffer(int_buffer&& rhs); //move konstruktor
    
    int_buffer & operator=(const int_buffer& rhs); //copy assignment

    int_buffer & operator=(int_buffer&& rhs);   //move assignment
    
    size_t size() const;    //Returnerar antal element
    
    int* begin();   //Returnerar adressen till första elementet
    
    int* end();     //Returnerar adressen till sista elementet
    
    const int* begin() const;   //Samma som föregående, men för konstanta object
    
    const int* end() const;

    ~int_buffer();

private:
    int* _ptr = nullptr;
    size_t _size = 0;   

    void swap(int_buffer& swap_with);   //Swaps two buffers
};