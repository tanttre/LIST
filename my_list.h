#pragma once
#include "includes.h"

template<class T>
class list
{
public:
    list();
    ~list();

    void pop_front();
    void push_back(T data);
    void clear();
    void push_front(T data);
    void insert(T value, int32_t index);
    void remove(int32_t index);
    void pop_back();

    size_t size() { return size };
    T& operator [] (const int index);
private:
    template<class T>
    class Node
    {
    public:
        Node* pNext;
        T data;
        Node(T data = T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    size_t size;
    Node<T>* head;
};

template<class T>
list<T>::list()
{
    size = 0;
    head = nullptr;
}

template<class T>
list<T>::~list()
{
    clear();
}

template<class T>
void list<T>::pop_front()
{
    Node<T>* TEMP = head;
    head = head->pNext;
    delete TEMP;
    --size;
}

template<class T>
void list<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T>* current = this->head;
        while (current->pNext != nullptr)
            current = current->pNext;
        current->pNext = new Node<T>(data);
    }
    ++size;
}

template<class T>
void list<T>::clear()
{
    while (size)
        pop_front();
}

template<class T>
T& list<T>::operator [] (const int index)
{
    size_t count = 0;
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
            return current->data;
        current = current->pNext;
        ++count;
    }
}

template<class T>
void list<T>::push_front(T data)
{
    head = new Node<T>(data, head);
    ++size;
}

template<class T>
void list<T>::insert(T value, int32_t index)
{
    if (index == 0)
    {
        push_front(value);
    }
    else
    {
        Node<T>* previous = this->head;
        for (size_t i = 0; i < index - 1; ++i)
            previous = previous->pNext;
        previous->pNext = new Node<T>(value, previous->pNext);
        ++size;
    }
}

template<class T>
void list<T>::remove(int32_t index)
{
    if (index == 0)
    {
        push_front();
    }
    else
    {
        Node<T>* previous = this->head;
        for (size_t i = 0; i < index - 1; ++i)
            previous = previous->pNext;
        Node<T>* toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        --size;
    }
}

template<class T>
void list<T>::pop_back()
{
    remove(size-1);
}