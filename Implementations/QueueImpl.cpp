// ********************************************************
// Name: Abdullah Nazir
// Date: April 06, 2024
//
// Implementation file QueueImpl.cpp
// This file contains definitions of the functions declared
//  in the abstract class Queue .
// ********************************************************

#include "Queue.h"

template <class T>
Queue<T>::Queue(int cap) : capacity(cap)
{
    currentSize = 0;
}

template <class T>
int Queue<T>::getCapacity() const
{
    return capacity;
}

template <class T>
int Queue<T>::getCurrentSize() const
{
    return currentSize;
}

template <class T>
Queue<T>::~Queue() {}