#ifndef GTUVECTOR_H
#define GTUVECTOR_H

#include "InheritedIterable.h"

namespace MYNAMESPACE
{
    template<typename T>
    class GTUVector:public InheritedIterable<T>
    {
    public:
        GTUVector(int newSize = 0);
        GTUVector(const GTUVector<T>&);
        const GTUVector<T>& operator=(const GTUVector<T>&);
        ~GTUVector();
        T& operator [](int);
        const T& operator [](int)const;
        GTUIterator<T> add(T);
        GTUIterator<T> add(GTUIterator<T>&, T);
    };

    //GTUVector Constructor.
    template<typename T>
    GTUVector<T>::GTUVector(int newSize):InheritedIterable<T>(newSize)
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
            //this -> tail = temp -> next;
            this -> tail = temp;
        }
    }
    //GTUVector Copy Constructor.
    template<typename T>
    GTUVector<T>::GTUVector(const GTUVector& otherObj):InheritedIterable<T>(otherObj)
    {}
    
    //GTUVector Assignment Operator.
    template<typename T>
    const GTUVector<T>& GTUVector<T>::operator =(const GTUVector<T>& otherObj)
    {
        InheritedIterable<T>::operator=(otherObj);
        return *this;
    }
    
    //GTUVector Destructor.
    template<typename T>
    GTUVector<T>::~GTUVector()
    {
        this -> clear();
    }

    //GTUVector index operator.
    template<typename T>
    T& GTUVector<T>::operator [](int index)
    {
        std::shared_ptr< Knot<T> > temp = this -> head;
        for(int i = 0; i < index; ++i)
            temp = temp -> next;
        return temp -> data;    
    }

    //GTUVector index operator for constant obj.
    template<typename T>
    const T& GTUVector<T>::operator [](int index)const
    {
        std::shared_ptr< Knot<T> > temp = this -> head;
        for(int i = 0; i < index; ++i)
            temp = temp -> next;
        return temp -> data;
    }

    //GTUVector add function.
    template<typename T>
    GTUIterator<T> GTUVector<T>::add(T element)
    {
        if(this -> size() == InheritedIterable<T>::MAXSIZE)
            std::cerr << "The vector has maximum capacity!" << std::endl;

        std::shared_ptr< Knot<T> > newKnot(new Knot<T>(element));
        if(!this -> size())
        {
            this -> head = newKnot;
            newKnot -> next = this -> tail;
            this -> tail -> prev = newKnot;
        }
        else
        {
            newKnot -> next = this -> tail;
            newKnot -> prev = this -> tail -> prev;
            this -> tail -> prev -> next = newKnot;
            this -> tail -> prev = newKnot;
        }

        this -> setSize(this -> size() + 1);
        return GTUIterator<T>(this -> head);    
    }

    //GTUVector add function with given position.
    template<typename T>
    GTUIterator<T> GTUVector<T>::add(GTUIterator<T>& tarPos, T element)
    {
        if(this -> size() == InheritedIterable<T>::MAXSIZE)
            std::cerr << "The vector has maximum capacity!" << std::endl;

        std::shared_ptr< Knot<T> > newKnot(new Knot<T>(element));

        if(tarPos == this -> begin())
        {
            if(!this -> size())
                newKnot -> next = this -> tail;
            else
                newKnot -> next = this -> head;

            this -> tail -> prev = newKnot;
            this -> head = newKnot;        
        }
        else if(tarPos == this -> end())
        {
            add(element);
            this -> setSize(this -> size() - 1);
        }    
        else
        {
            std::shared_ptr< Knot<T> > temp = this -> head;
            for(auto iter = this -> begin(); iter != tarPos; ++iter, temp = temp -> next)
            {
                if(iter == this -> end())
                    std::cerr << "Invalid iterator!" << std::endl;
            }
            newKnot -> prev = temp -> prev;
            newKnot -> next = temp;
            temp -> prev -> next = newKnot;
            temp -> prev = newKnot;
        }

        this -> setSize(this -> size() + 1);
        return GTUIterator<T>(this -> head);
    }
}


#endif