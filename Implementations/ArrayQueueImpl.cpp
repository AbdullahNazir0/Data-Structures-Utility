// ********************************************************
// Name: Abdullah Nazir
// Date: April 06, 2024
//
// Implementation file ArrayQueueImpl.cpp
// This file contains definitions of the functions declared
//  in the class ArrayQueue .
// ********************************************************

#include "../Headers/ArrayQueue.h"
#include <iostream>

template <typename T>
ArrayQueue<T>::ArrayQueue(int cap)
    : capacity(cap),
      front(-1),
      rear(-1),
      currentSize(0)
{
    queuePtr = new T[capacity];
}

template <typename T>
void ArrayQueue<T>::display() const
{
    if (isEmpty())
    {
        std::cout << "Queue is empty.\n";
        return;
    }

    if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
            std::cout << queuePtr[i] << " ";
    }
    else
    {
        for (int i = front; i < capacity; ++i)
            std::cout << queuePtr[i] << " ";
        for (int i = 0; i <= rear; ++i)
            std::cout << queuePtr[i] << " ";
    }
    std::cout << "\n";
}

template <typename T>
void ArrayQueue<T>::enqueue(T value)
{
    if (isFull())
    {
        std::cout << "Can't enqueue, queue is full. (Queue overflown)\n";
        return;
    }

    rear = (rear + 1) % capacity;
    queuePtr[rear] = value;
    currentSize++;
    if (currentSize == 1)
        front = rear;
}

template <typename T>
T ArrayQueue<T>::dequeue()
{
    if (isEmpty())
    {
        std::cout << "Can't dequeue, queue is empty. (Queue underflown)\n";
        return T();
    }

    T temp = queuePtr[front];
    if (front == rear) // If array is empty but not at -1;
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % capacity;
    }
    currentSize--;
    return temp;
}

template <typename T>
T ArrayQueue<T>::getFront() const
{
    if (isEmpty())
    {
        std::cout << "Can't get front, queue is empty.\n";
        return T();
    }

    return queuePtr[front];
}

template <typename T>
T ArrayQueue<T>::getRear() const
{
    if (isEmpty())
    {
        std::cout << "Can't get rear, queue is empty.\n";
        return T();
    }

    return queuePtr[rear];
}

template <typename T>
void ArrayQueue<T>::clear()
{
    front = -1;
    rear = -1;
    currentSize = 0;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const
{
    return (front == -1);
}

template <typename T>
bool ArrayQueue<T>::isFull() const
{
    return (currentSize == capacity);
}

template <typename T>
ArrayQueue<T>::~ArrayQueue()
{
    if (queuePtr)
        delete[] queuePtr;
}