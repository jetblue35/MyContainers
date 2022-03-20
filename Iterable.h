#ifndef GTUITERABLE_H
#define GTUITERABLE_H

#include "GTUIterator.h"
#include "GTUIteratorConst.h"

namespace MYNAMESPACE
{
    template <typename T>
    class Iterable
    {
    public:
        virtual bool empty()const = 0;
        virtual int size()const = 0;
        virtual void erase(GTUIterator<T>&) = 0;
        virtual void clear() = 0;
        virtual GTUIterator<T> begin() = 0;
        virtual GTUIterator<T> end() = 0;
        virtual GTUIteratorConst<T> cbegin() = 0;
        virtual GTUIteratorConst<T> cend() = 0;
        virtual ~Iterable(){};
    };
}

#endif