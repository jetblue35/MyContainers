#ifndef INHERITEDITERABLE_H
#define INHERITEDITERABLE_H

#include "Iterable.h"
#include "Knot.h"
namespace MYNAMESPACE
{
    template<typename T>
    class InheritedIterable:public Iterable<T>
    {
    public:
        InheritedIterable(int newSize = 0);
        InheritedIterable(const InheritedIterable<T>&);
        const InheritedIterable<T>& operator =(const InheritedIterable<T>&);
        virtual ~InheritedIterable();

        virtual bool empty()const;
        virtual int size()const;
        virtual void erase(GTUIterator<T>&);
        virtual void clear();
        virtual GTUIterator<T> begin();
        virtual GTUIterator<T> end();
        virtual GTUIteratorConst<T> cbegin();
        virtual GTUIteratorConst<T> cend();

    protected:
        void setSize(int);
        std::shared_ptr< Knot<T> > head;
        std::shared_ptr< Knot<T> > tail;
        const int MAXSIZE = 10000;
        int capacity;
    };
    
    template<typename T>
    InheritedIterable<T>::InheritedIterable(int newSize)
    {
        tail = std::make_shared< Knot<T> >();
        setSize(newSize);
    }

    template<typename T>
    InheritedIterable<T>::InheritedIterable(const InheritedIterable<T>& newObj)
    {
        tail = std::make_shared< Knot<T> >();
        setSize(newObj.size());

        if(size())
        {
            std::shared_ptr< Knot<T> > newHead(new Knot<T>());
            std::shared_ptr< Knot<T> > temp = newHead;

            for(int i = 0; i < size() - 1; ++i)
            {
                std::shared_ptr< Knot<T> >  newKnot(new Knot<T>());
                temp -> next = newKnot;
                newKnot -> prev = temp;
                temp = temp -> next;
            }
            head = newHead;
            tail = temp -> next;

            std::shared_ptr< Knot<T> > myHead = head;
            std::shared_ptr< Knot<T> > otherHead = newObj.head;
            for(int j = 0; j < size(); ++j)
            {
                myHead -> data = otherHead -> data;
                myHead = myHead -> next;
                otherHead = otherHead -> next;
            }
        }
    }
    template<typename T>
    const InheritedIterable<T>& InheritedIterable<T>::operator =(const InheritedIterable<T>& newObj)
    {
        clear();
        setSize(newObj.size());
        if(size())
        {
            std::shared_ptr< Knot<T> > newHead(new Knot<T>());
            std::shared_ptr< Knot<T> > temp = newHead;
            for(int i = 0; i < size() - 1; ++i)
            {
                std::shared_ptr< Knot<T> > newKnot(new Knot<T>());
                temp -> next = newKnot;
                newKnot -> prev = temp;
                temp = temp -> next;
            }
            head = newHead;
            tail = temp -> next;

            std::shared_ptr< Knot<T> > myHead = head;
            std::shared_ptr< Knot<T> > otherHead = newObj.head;
            for(int j = 0; j < size(); ++j)
            {
                myHead -> data = otherHead -> data;
                myHead = myHead -> next;
                otherHead = otherHead -> next;
            }
        }
        return *this;
    }
    template<typename T>
    InheritedIterable<T>::~InheritedIterable()
    {
        tail = nullptr;
    }
    template<typename T>
    bool InheritedIterable<T>::empty()const
    {
        if(!size())
            return true;
        return false;    
    }
    template<typename T>
    int InheritedIterable<T>::size()const
    {
        return capacity;
    }
    template<typename T>
    void InheritedIterable<T>::erase(GTUIterator<T>& givenIT)
    {
        if(size() == 1)
        {
            if(givenIT == begin() || givenIT == end())
            {
                head = nullptr;
                tail -> prev = nullptr;
                setSize(size() - 1);
            }
        }
        else if(size() > 0)
        {
            if(givenIT == begin())
            {
                head -> next -> prev = nullptr;
                head = head -> next;
                setSize(size() - 1);
            }
            else
            {
                std::shared_ptr< Knot<T> > temp = head;
                for(auto iter = begin(); iter != givenIT; ++iter, temp = temp -> next)
                    if(iter == end())
                        exit(1);
                        //cerr << "The data is not inside this container!" << endl;

                temp -> prev -> next = temp -> next;
                temp -> next -> prev = temp -> prev;
                temp -> next = nullptr;
                temp -> prev = nullptr;
                setSize(size() - 1);         
            }
        }
    }
    template<typename T>
    void InheritedIterable<T>::clear()
    {
        std::shared_ptr< Knot<T> > temp;
        while(head != nullptr)
        {
            temp = head;
            head = head -> next;
            temp -> prev = nullptr;
            temp -> next = nullptr;
        }
        head = nullptr;
        setSize(0);
    }
    template<typename T>
    void InheritedIterable<T>::setSize(int newSize)
    {
        if(newSize < 0 || newSize > MAXSIZE)
            newSize = 0;
        capacity = newSize;    
    }
    template<typename T>
    GTUIterator<T> InheritedIterable<T>::begin()
    {
        return GTUIterator<T>(head);
    }
    template<typename T>
    GTUIterator<T> InheritedIterable<T>::end()
    {
        return GTUIterator<T>(tail);
    }

    template<typename T>
    GTUIteratorConst<T> InheritedIterable<T>::cbegin()
    {
        return GTUIteratorConst<T>(head);
    }
    template<typename T>
    GTUIteratorConst<T> InheritedIterable<T>::cend()
    {
        return GTUIteratorConst<T>(tail);
    }
}

#endif