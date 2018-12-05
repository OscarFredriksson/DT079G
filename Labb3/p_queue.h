#ifndef P_QUEUE_H
#define P_QUEUE_H

#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <functional>
#include <cstdlib>



template<typename T>
class p_queue
{
public:
    p_queue() = default;

    T pop()
    {
        T ret = list.back();
        list.pop_back();
        return ret;
    }

    void push(T e)
    {        
        auto pos = find_pos(begin(), end(), e);

        list.insert(pos, e);
    }

    typename std::vector<T>::iterator begin()
    {
        return list.begin();
    }

    typename std::vector<T>::iterator end()
    {
        return list.end();
    }

    template<typename InputIt>
    InputIt find_pos(InputIt begin, InputIt end, T e)
    {
        while(begin != end)
        {
            if(less(*begin, e)) return begin;
            
            begin++;
        }
        return end;
    }

    size_t size() const
    {
        return list.size();
    }

    bool empty() const
    {
        return list.empty();
    }

    T& operator[](size_t pos)
    {  
        return list[pos]; 
    }
 
 
    bool less(T a, T b) const
    {
        return a < b;
    }


    /*bool less(T a, T b) const
    {
        return a < b;
    }*/

private:
    std::vector<T> list;
};

#endif