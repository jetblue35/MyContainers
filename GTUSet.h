#ifndef GTUSET_H
#define GTUSET_H

#include "InheritedIterable.h"
namespace MYNAMESPACE
{
    template<typename T>
    class GTUSet:public InheritedIterable<T>
    {
    public:
        GTUSet(int newSize = 0);
        GTUSet(const GTUSet<T>&);
        const GTUSet<T>& operator=(const GTUSet<T>&);
        GTUIterator<T> add(T);
        int search(T);
        //GTUSet<T> intersect(GTUSet<T>&);
        ~GTUSet();
    };
    
    //GTUSet Constructor.
    template<typename T>
    GTUSet<T>::GTUSet(int newSize):InheritedIterable<T>(newSize)
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
    
    //GTUSet Copy Constructor.
    template<typename T>
    GTUSet<T>::GTUSet(const GTUSet& newObj):InheritedIterable<T>(newObj)
    {}

    //GTUSet assignment operator.
    template<typename T>
    const GTUSet<T>& GTUSet<T>::operator =(const GTUSet<T>& newObj)
    {
        InheritedIterable<T>::operator =(newObj);
        return *this;
    }

    //GTUSet Destructor.
    template<typename T>
    GTUSet<T>::~GTUSet()
    {
        this -> clear();
    }
    
    //GTUSet add function (Checks the same element rule).
    template<typename T>
    GTUIterator<T> GTUSet<T>::add(T element)
    {
        if(this -> size() == InheritedIterable<T>::MAXSIZE)
            std::cerr << "The set has maximum capacity!" << std::endl;
        std::shared_ptr< Knot<T> > newKnot(new Knot<T>(element));
        bool hasData = false;

        if(!this -> size())
        {
            this -> head = newKnot;
            newKnot -> next = this -> tail;
            this -> tail -> prev = newKnot;
        }
        else
        {
            GTUIterator<T> newIter = newKnot;

            for(auto iter = this -> begin(); iter != this -> end() && !hasData; ++iter)
            {
                if(*newIter == *iter)
                {
                    std::cerr << "The set already has this data!!!" << std::endl;
                    hasData = true;
                }
            }
                
            if(!hasData)
            {
                newKnot -> next = this -> tail;
                newKnot -> prev = this -> tail -> prev;
                this -> tail -> prev -> next = newKnot;
                this -> tail -> prev = newKnot;
            }        
        }
        if(!hasData)
            this -> setSize(this -> size() + 1);
        return GTUIterator<T>(this -> head);        
    }
    
    //GTUSet search function (returns element's index).
    template<typename T>
    int GTUSet<T>::search(T element)
    {
        int count = 0;
        std::shared_ptr< Knot<T> > newKnot(new Knot<T>(element));
        GTUIterator<T> newIter = newKnot;
        
        for(auto iter = this -> begin(); iter != this -> end(); ++iter)
        {
            count++;
            if(*newIter == *iter)
                break;
        }
        return count - 1;
    }
}

#endif