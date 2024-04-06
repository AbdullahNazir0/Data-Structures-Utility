// ********************************************************
// Name: Abdullah Nazir
// Date: April 06, 2024
//
// Implementation file ArrayQueueImpl.cpp
// This file contains definitions of the functions declared
//  in the class ArrayQueue .
// ********************************************************

#include "ArrayQueue.h"

template <class T>
ArrayQueue<T>::ArrayQueue(int cap = 100) : Queue<T>(cap)
{
    front = -1;
    end = -1;
    currentSize = 0;
    stackPtr = new T[capacity];
}

template <class T>
void ArrayQueue<T>::display() const
{
    if (isEmpty())
    {
        std::cout << "Queue is empty.\n";
        return;
    }
    std::cout << "Queue data: ";
    for (int i = 0; i < currentSize; i++)
        std::cout << stackPtr[i] << " ";
    std::cout << "\n";
}

template <class T>
void ArrayQueue<T>::enqueue(T value)
{
    if (isFull())
        return;

    queuePtr[++rear] = value;
    currentSize++;
    if (front == -1)
        front++;
}

template <class T>
T ArrayQueue<T>::dequeue()
{
    if (isEmpty)
        return T();

    if (front == rear) // If array is empty but not at -1;
    {
        T temp = queuePtr[front];
        front = -1;
        rear = -1;
        return temp;
    }
    else
    {

        T temp = queuePtr[front--];
        currentSize--;
        return temp;
    }
}

template <class T>
T ArrayQueue<T>::peek() const
{
    if (isEmpty())
        return T();

    return queuePtr[front];
}

template <class T>
T ArrayQueue<T>::peekAt(int position) const
{
    if (isEmpty() || position > currentSize || position < 0)
        return T();

    return queuePtr[position];
}

template <class T>
T ArrayQueue<T>::atLast() const
{
    if (isEmpty)
        return T();

    return queuePtr[rear];
}

template <class T>
void ArrayQueue<T>::clear()
{
    if (isEmpty())
        return;

    front = -1;
    rear = -1;
    currentSize = 0;
}

template <class T>
bool ArrayQueue<T>::isEmpty() const
{
    return (currentSize == 0);
}

template <class T>
bool ArrayQueue<T>::isFull() const
{
    return (currentSize == capacity);
}

template <class T>
ArrayQueue<T>::~ArrayQueue()
{
    if (queuePtr)
        delete[] queuePtr;
}