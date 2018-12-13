#ifndef P_QUEUE_H
#define P_QUEUE_H

#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <functional>

template<typename T, typename Comp>
class p_queue
{
public:
    p_queue() = default;

    void push(T e)
    {     
        auto pos = std::find_if(list.begin(), list.end(), less(e));
        list.insert(pos, e);
    }

    T pop()
    {
        T ret = list.front();
        list.erase(list.begin());
        return ret;
    }

    T top()
    {
        return list.front();
    }

    size_t size() const
    {
        return list.size();
    }

    bool empty() const
    {
        return list.empty();
    }

private:
    std::vector<T> list;

    struct less
    {
        less(const T& value): value(value) 
            {}
        bool operator()(const T& e) const
        {
            Comp comp;
            return comp(value, e);
        }
        T value;
    };
};

#endif