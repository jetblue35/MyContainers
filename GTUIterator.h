#ifndef GTUITERATOR_H
#define GTUITERATOR_H

#include "Knot.h"
#include <memory>

namespace MYNAMESPACE
{
    template<typename T>
    class GTUIterator
    {
    public:
        GTUIterator();
        GTUIterator(std::shared_ptr< Knot<T> >);
        T& operator *();
        T* operator ->();
        GTUIterator<T> operator ++();
        GTUIterator<T> operator ++(int);
        GTUIterator<T> operator --(int);
        GTUIterator<T> operator --();
        bool operator ==(const GTUIterator<T>&)const;
        bool operator !=(const GTUIterator<T>&)const;
    private:
        std::shared_ptr< Knot<T> > iter;    
    };

    template<typename T>
    GTUIterator<T>::GTUIterator()
    {
        iter = nullptr;
    }

    template<typename T>
    GTUIterator<T>::GTUIterator(std::shared_ptr< Knot<T> > obj)
    {
        iter = obj;
    }

    template<typename T>
    T& GTUIterator<T>::operator *()
    {
        return iter -> data;
    }

    template<typename T>
    T* GTUIterator<T>::operator ->()
    {
        return &(iter -> data);
    }

    template<typename T>
    GTUIterator<T> GTUIterator<T>::operator ++(int ignore)
    {
        std::shared_ptr< Knot<T> > temp;
        temp = iter;
        iter = iter -> next;
        return temp;
    }

    template<typename T>
    GTUIterator<T> GTUIterator<T>::operator ++()
    {
        return iter = iter -> next;
    }

    template<typename T>
    GTUIterator<T> GTUIterator<T>::operator --(int ignore)
    {
        std::shared_ptr< Knot<T> > temp;
        temp = iter;
        iter = iter -> prev;
        return temp;
    }

    template<typename T>
    GTUIterator<T> GTUIterator<T>::operator --()
    {
        return iter = iter -> prev;
    }

    template<typename T>
    bool GTUIterator<T>::operator ==(const GTUIterator<T>& otherObj)const
    {
        return iter == otherObj.iter;
    }

    template<typename T>
    bool GTUIterator<T>::operator !=(const GTUIterator<T>& otherObj)const
    {
        return iter != otherObj.iter;
    }
}

#endif