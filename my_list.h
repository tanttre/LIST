#pragma once
#include "includes.h"

template<class T>
class list
{
public:
    list();
    ~list();
    void push_back(T data);
    int32_t GetSize() { return size; }
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
    int32_t size;
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
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    ++size;
}

template<class T>
T& list<T>::operator [] (const int index)
{
    int32_t count = 0;
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        ++count;
    }
}
