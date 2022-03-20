#ifndef GTUITERATORCONST_H
#define GTUITERATORCONST_H

#include "Knot.h"
#include <memory>

namespace MYNAMESPACE
{
    template<typename T>
    class GTUIteratorConst
    {
    public:
        GTUIteratorConst();
        GTUIteratorConst(std::shared_ptr< Knot<T> >);
        const T& operator *();
        const T* operator ->();
        GTUIteratorConst<T> operator ++();
        GTUIteratorConst<T> operator ++(int);
        GTUIteratorConst<T> operator --(int);
        GTUIteratorConst<T> operator --();
        bool operator ==(const GTUIteratorConst<T>&)const;
        bool operator !=(const GTUIteratorConst<T>&)const;
    private:
        std::shared_ptr< Knot <T> > iter;    
    };

    template<typename T>
    GTUIteratorConst<T>::GTUIteratorConst()
    {
        iter = nullptr;
    }
    
    template<typename T>
    GTUIteratorConst<T>::GTUIteratorConst(std::shared_ptr< Knot<T> > obj)
    {
        iter = obj;
    }

    template<typename T>
    const T& GTUIteratorConst<T>::operator *()
    {
        return iter -> data;
    }

    template<typename T>
    const T* GTUIteratorConst<T>::operator ->()
    {
        return &(iter -> data);
    }

    template<typename T>
    GTUIteratorConst<T> GTUIteratorConst<T>::operator ++(int ignore)
    {
        std::shared_ptr< Knot<T> > temp;
        temp = iter;
        iter = iter -> next;
        return temp;
    }

    template<typename T>
    GTUIteratorConst<T> GTUIteratorConst<T>::operator ++()
    {
        return iter = iter -> next;
    }

    template<typename T>
    GTUIteratorConst<T> GTUIteratorConst<T>::operator --(int ignore)
    {
        std::shared_ptr< Knot<T> > temp;
        temp = iter;
        iter = iter -> prev;
        return temp;
    }

    template<typename T>
    GTUIteratorConst<T> GTUIteratorConst<T>::operator --()
    {
        return iter = iter -> prev;
    }

    template<typename T>
    bool GTUIteratorConst<T>::operator ==(const GTUIteratorConst<T>& otherObj)const
    {
        return iter == otherObj.iter;
    }

    template<typename T>
    bool GTUIteratorConst<T>::operator !=(const GTUIteratorConst<T>& otherObj)const
    {
        return iter != otherObj.iter;
    }
}

#endif