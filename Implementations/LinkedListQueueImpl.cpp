// ********************************************************
// Name: Abdullah Nazir
// Date: May 18, 2024
//
// Implementation file LinkedListQueueImpl.cpp
// This file contains definitions of the functions declared
//  in the class LinkedListQueue .
// ********************************************************

#include "../Headers/LinkedListQueue.h"

template <typename T>
LinkedListQueue<T>::LinkedListQueue()
{
    queuePtr = new SinglyLinkedList<T>;
}

template <typename T>
void LinkedListQueue<T>::display() const
{
    if (isEmpty())
    {
        std::cout << "Queue is empty.\n";
        return;
    }

    queuePtr->display();
}

template <typename T>
void LinkedListQueue<T>::enqueue(T value)
{
    queuePtr->insertAtEnd(value);
}

template <typename T>
T LinkedListQueue<T>::dequeue()
{
    if (isEmpty())
    {
        std::cout << "Can't dequeue, queue is empty. (queue underflown)\n";
        return T();
    }

    queuePtr->deleteFirst();
}

template <typename T>
T LinkedListQueue<T>::getFront() const
{
    if (isEmpty())
    {
        std::cout << "Can't return front, queue is empty.\n";
    }

    return (queuePtr->getHeadData());
}

template <typename T>
T LinkedListQueue<T>::getRear() const
{
    if (isEmpty())
    {
        std::cout << "Can't return rear, queue is empty.\n";
    }

    return (queuePtr->getTailData());
}

template <typename T>
void LinkedListQueue<T>::clear()
{
    queuePtr->deleteList();
}

template <typename T>
bool LinkedListQueue<T>::isEmpty() const
{
    return (queuePtr->getNodesCount() == 0);
}

template <typename T>
LinkedListQueue<T>::~LinkedListQueue()
{
    queuePtr->deleteList();
    delete queuePtr;
}