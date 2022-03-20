#ifndef GLOBAL_H
#define GLOBAL_H

namespace MYNAMESPACE
{
    template<typename Iter, typename Val>
    Iter find(Iter first, Iter last, const Val& value)
    {
        for(; first != last; ++first)
            if(value == *first)
                return first;
        return last;        
    }
    template<typename Iter, typename F>
    Iter find_if(Iter first, Iter last, F function)
    {
        for(; first != last; ++first)
            if(function(*first))
                return first;
        return last;        
    }
    template<typename Iter, typename F>
    F for_each(Iter first, Iter last, F function)
    {
        for(; first != last; ++first)
            function(*first);
        return function;    
    }
}

#endif