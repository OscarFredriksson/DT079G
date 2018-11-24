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
        T ret = list.back().first;
        list.pop_back();
        return ret;
    }
    
    void push(T e)
    {
        list.push_back(std::make_pair(e, 5));

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
        return list.begin().first;
    }

    T* end() const
    {
        return list.end().first;
    }

    T& operator[](size_t pos)
    {  
        return list[pos].first; 
    }

private:
    std::vector<std::pair<T, int>> list;
};