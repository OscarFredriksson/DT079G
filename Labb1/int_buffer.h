#include <cstdlib>

class int_buffer
{ 
public:
    
    explicit int_buffer(size_t size); // size_t is defined in cstdlib
    
    int_buffer(const int* source , size_t size); 
    
    int_buffer(const int_buffer& rhs); // copy construct
    
    int_buffer(int_buffer&& rhs); // moveconstruct
    
    int_buffer & operator=(const int_buffer& rhs); // copy assign
    
    int_buffer & operator=(int_buffer&& rhs);

    // move assign
    size_t size() const;
    
    int* begin();
    
    int* end();
    
    const int* begin() const; 
    
    const int* end() const; 
    
    ~int_buffer();
};




int_buffer a;