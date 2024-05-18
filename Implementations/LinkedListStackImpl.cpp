// ********************************************************
// Name: Abdullah Nazir
// Date: May 18, 2024
//
// Implementation file LinkedListStackImpl.cpp
// This file contains definitions of the functions declared
//  in the class LinkedListStack .
// ********************************************************

#include "../Headers/LinkedListStack.h"
#include <iostream>

template <typename T>
LinkedListStack<T>::LinkedListStack()
{
    stackPtr = new SinglyLinkedList<T>();
}

template <typename T>
void LinkedListStack<T>::display() const
{
    if (isEmpty())
    {
        std::cout << "Stack is empty.\n";
        return;
    }

    stackPtr->display();
}

template <typename T>
void LinkedListStack<T>::push(T value)
{
    stackPtr->insertAtEnd(value);
    this->currentSize++;
    this->top++;
}

template <typename T>
T LinkedListStack<T>::pop()
{
    if (isEmpty())
    {
        std::cout << "Can't pop, stack is empty. (stack underflown)\n";
        return T();
    }
    T toReturn = stackPtr->valueAtIndex(this->top);
    this->currentSize--;
    this->top--;
    stackPtr->deleteLast();
    return toReturn;
}

template <typename T>
T LinkedListStack<T>::peek() const
{
    if (isEmpty())
    {
        std::cout << "Can't peek, stack is empty.\n";
        return T();
    }

    return (stackPtr->valueAtIndex(this->top));
}

template <typename T>
T LinkedListStack<T>::peekAt(int index) const
{
    if (index < 0 || index > this->top)
    {
        std::cout << "Can't peek, invalid index.\n";
        return T();
    }

    return (stackPtr->valueAtIndex(index));
}

template <typename T>
void LinkedListStack<T>::clear()
{
    this->currentSize == 0;
    this->top = -1;
    stackPtr->deleteList();
}

template <typename T>
bool LinkedListStack<T>::isEmpty() const
{
    return (this->top == -1);
}

template <typename T>
LinkedListStack<T>::~LinkedListStack()
{
    if (stackPtr)
        stackPtr->deleteList();
    this->currentSize = 0;
    this->top = -1;
    delete stackPtr;
}
