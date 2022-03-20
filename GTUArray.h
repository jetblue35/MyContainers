#ifndef GTUARRAY_H
#define GTUARRAY_H

#include "InheritedIterable.h"

namespace MYNAMESPACE
{
    template<typename T, std::size_t SIZE>
    class GTUArray:public InheritedIterable<T>
    {
    public:    
        GTUArray();
        GTUArray(std::initializer_list<T>);
        //GTUArray(const GTUArray<T, SIZE>&);
        const GTUArray<T, SIZE>& operator=(const GTUArray<T, SIZE>&);
        //GTUIterator<T> add(T);
        T& operator[](int);
        const T& operator[](int)const;
        T& at(int);
        const T& at(int)const;
        T front();
        T back();
        void fill(T);
        ~GTUArray();
    };
    //GTUArray Constructor.
    template<typename T, std::size_t SIZE>
    GTUArray<T, SIZE>::GTUArray():InheritedIterable<T>(SIZE)
    {
        if(this -> size())
        {
            std::shared_ptr< Knot<T> > newHead(new Knot<T>());
            std::shared_ptr< Knot<T> > temp = newHead;

            for(int i = 0; i < this -> size() - 1; ++i)
            {
                std::shared_ptr< Knot<T> > newKnot(new Knot<T>());
                temp -> next = newKnot;
                newKnot -> prev = temp;
                temp = temp -> next;
            }
            this -> head = newHead;
            this -> tail = temp;
        }
    }
    //GTUArray Destructor.
    template<typename T, std::size_t SIZE>
    GTUArray<T, SIZE>::~GTUArray()
    {
        this -> clear();
    }
    //GTUArray assignment operator.
    template<typename T, std::size_t SIZE>
    const GTUArray<T, SIZE>& GTUArray<T, SIZE>::operator=(const GTUArray<T, SIZE>& newObj)
    {
        InheritedIterable<T>::operator=(newObj);
        return *this;
    }
    //GTUArray index operator.
    template<typename T, std::size_t SIZE>
    T& GTUArray<T, SIZE>::operator[](int index)
    {
        std::shared_ptr< Knot<T> > temp = this -> head;
        for(int i = 0; i < index; ++i)
            temp = temp -> next;
        return temp -> data;
    }
    
    //GTUArray index operator for constant obj.
    template<typename T, std::size_t SIZE>
    const T& GTUArray<T, SIZE>::operator[](int index)const
    {
        std::shared_ptr< Knot<T> > temp = this -> head;
        for(int i = 0; i < index; ++i)
            temp = temp -> next;
        return temp -> data;
    }
    //GTUArray Constructor with initialize list.
    template<typename T, std::size_t SIZE>
    GTUArray<T, SIZE>::GTUArray(std::initializer_list<T> l):InheritedIterable<T>(SIZE)
    {
        if(this -> size())
        {
            std::shared_ptr< Knot<T> > newHead(new Knot<T>());
            std::shared_ptr< Knot<T> > temp = newHead;

            for(auto i = 0, iter = std::begin(l); i < this -> size() && iter != std::end(l); ++i, ++iter)
            {
                std::shared_ptr< Knot<T> > newKnot(new Knot<T>());
                temp -> data = *iter;
                temp -> next = newKnot;
                newKnot -> prev = temp;
                temp = temp -> next;
            }
            this -> head = newHead;
            this -> tail = temp;
        }
    }
    //GTUArray at function (Checks the range, but does not fully work.).
    template<typename T, std::size_t SIZE>
    T& GTUArray<T, SIZE>::at(int index)
    {
        if(index < 0 || index >= this -> size())
            std::cerr << "Out of array range!" << std::endl;
        else
        {
            std::shared_ptr< Knot<T> > temp = this -> head;
            for(int i = 0; i < index; ++i)
                temp = temp -> next;
            return temp -> data;
        }     
    }
    //GTUArray at function (Checks the range, but does not fully work.).
    template<typename T, std::size_t SIZE>
    const T& GTUArray<T, SIZE>::at(int index)const
    {
        if(index < 0 || index >= this -> size())
            std::cerr << "Out of array range!" << std::endl;
        else
        {
            std::shared_ptr< Knot<T> > temp = this -> head;
            for(int i = 0; i < index; ++i)
                temp = temp -> next;
            return temp -> data;
        }
    }
    
    //GTUArray front function, returns begin of the array.
    template<typename T, std::size_t SIZE>
    T GTUArray<T, SIZE>::front()
    {
        GTUIterator<T> iter;
        iter = this -> begin();
        return *iter;
    }
    //GTUArray back function, returns end of the array.
    template<typename T, std::size_t SIZE>
    T GTUArray<T, SIZE>::back()
    {
        GTUIterator<T> iter = this -> end();
        --iter;
        return *iter;
    }
    //GTUArray fill function, fills the array with given element.
    template<typename T, std::size_t SIZE>
    void GTUArray<T, SIZE>::fill(T element)
    {
        for(auto iter = this -> begin(); iter != this -> end(); ++iter)
            *iter = element;
    }
}

#endif