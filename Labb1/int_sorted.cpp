#include "int_sorted.h"
#include <utility>
#include <stdio.h>
#include <algorithm>

int_sorted::int_sorted(const int* source, size_t size)
    :_buffer(source, size)
{
    if(size <= 1)   return; //Om storleken är 0 eller 1 behöver den inte sorteras

    //Sortera source och lägg över den sorterade int_sorted i en temporär instans
    int_sorted temp = sort(source, source + size);  
 
    _buffer = std::move(temp._buffer);  //Flytta den temporära till denna
}

size_t int_sorted::size() const
{
    return _buffer.size();  //Ta storleken för buffern
}

int* int_sorted::insert(int value)
{
    int_buffer temp_buffer(_buffer.size()+1);   //Skapa en temporär buffer att bygga upp den nya buffern i

    int* insertpoint = temp_buffer.begin(); //Sätter insertpunkten till den första adressen

    for(const int* i = _buffer.begin(); i != _buffer.end(); i++)    //Går igenom hela buffern
    {
        if(value < *i) break;   //När den hittar platsen för det nya värdet, avbryt loopningen
        
        insertpoint++;  //Flytta insertpunkten framåt i listan
    }
    
    *insertpoint = value;   //Sätt in det nya värdet där det ska vara

    const int* prev_iter = _buffer.begin();
    int* new_iter = temp_buffer.begin();

      
    //Loopa igenom båda buffrarna och kopiera över alla element från den gamla buffern till temp_buffer
    for(;prev_iter != _buffer.end(); ++prev_iter, ++new_iter)   
    {
        if(new_iter == insertpoint) ++new_iter; //När den når det insertade elementet, hoppa över detta

        *new_iter = *prev_iter; //Lägg över värdet
    }

    _buffer = std::move(temp_buffer);   //Byt ut buffern till den nyskapade 

    return insertpoint; //Returnera insertpunkten
}

const int* int_sorted::begin() const
{
    return _buffer.begin();
}

const int* int_sorted::end() const
{
    return _buffer.end();
}

int_sorted int_sorted::merge(const int_sorted& merge_with) const
{
    int_buffer merged(size() + merge_with.size());

    const int* iter1 = begin();
    const int* iter2 = merge_with.begin();
    int* merged_iter = merged.begin();

    for(;iter1 != end() && iter2 != merge_with.end(); merged_iter++)
    {
        if(*iter1 < *iter2)
        {
            *merged_iter = *iter1;
            iter1++;
        }
        else
        {
            *merged_iter = *iter2;
            iter2++;
        }
    }

    //Om det finns nått kvar i någon av buffrarna, skriv dessa till den nya
    for(;iter1 != end(); iter1++, merged_iter++) 
        *merged_iter = *iter1;
    
    for(;iter2 != merge_with.end(); iter2++, merged_iter++) 
        *merged_iter = *iter2;

    int_sorted ret(nullptr, 0);
    
    ret._buffer = std::move(merged);

    return ret;
}

int_sorted int_sorted::sort(const int* begin , const int* end)
{
    if (begin == end)   return int_sorted(nullptr, 0); 
    
    if (begin == end - 1)   return int_sorted(begin, 1);

    ptrdiff_t half = (end - begin) / 2; // pointer diff type

    const int* mid = begin + half;
    
    return sort(begin, mid).merge(sort(mid, end));
}