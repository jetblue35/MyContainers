#ifndef KNOT_H
#define KNOT_H

#include <memory>

namespace MYNAMESPACE
{
    template<typename T>
    class Knot
    {
    public:
        Knot(){}
        Knot(T&);
        T data;
        std::shared_ptr< Knot<T> > next;    
        std::shared_ptr< Knot<T> > prev;    
    };
    template<typename T>
    Knot<T>::Knot(T& newData)
    {
        data = newData;
        prev = nullptr;
        next = nullptr;
    }
    
}



#endif