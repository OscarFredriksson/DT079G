#ifndef P_QUEUE_H
#define P_QUEUE_H

#include <vector>
#include <utility>
#include <algorithm>

template<class T>

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
        list.push_back(e);

        std::sort(list.begin(), list.end());
    }

    int size() const
    {
        return list.size();
    }

    bool empty() const
    {
        return list.empty();
    }

    T* begin() const
    {
        return list.begin();
    }

    T* end() const
    {
        return list.end();
    }

    T& operator[](size_t pos)
    {  
        return list[pos]; 
    }

    static bool less(T a1, T a2)
    {
        return a1 < a2;
    }
    

private:
    std::vector<T> list;
};

#endif