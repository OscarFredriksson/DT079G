#ifndef INT_SORTED_H
#define INT_SORTED_H
#endif

#include "int_buffer.h"

#include <cstdlib>  //size_t


class int_sorted
{ 
public:
    
    int_sorted() = delete;  //Ta bort default-konstruktorn

    int_sorted(const int* source , size_t size);    //konstruktorn tar source och dess size och ser till att den konstruerade int_sorted innehåller samma element, men sorterad
    
    size_t size() const;    //Returnerar antal element
    
    int* insert(int value); //returnerar insertpunkten
    
    const int* begin() const;   //Returnerar adressen till första elementet
    
    const int* end() const;     //Returnerar adressen till sista elementet
    
    int_sorted merge(const int_sorted& merge_with) const;   //Mergear this med merge_with, returnerar mergead int_sorted

private:
    int_buffer _buffer;

    int_sorted sort(const int* begin, const int* end);  //Merge sort
};
