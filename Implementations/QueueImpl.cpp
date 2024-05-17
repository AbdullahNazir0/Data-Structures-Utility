// ********************************************************
// Name: Abdullah Nazir
// Date: April 06, 2024
//
// Implementation file QueueImpl.cpp
// This file contains definitions of the functions declared
//  in the abstract class Queue .
// ********************************************************

#include "Queue.h"

template <typename T>
Queue<T>::Queue(int cap) : capacity(cap)
{
    currentSize = 0;
}

template <typename T>
int Queue<T>::getCapacity() const
{
    return capacity;
}

template <typename T>
int Queue<T>::getCurrentSize() const
{
    return currentSize;
}

template <typename T>
Queue<T>::~Queue() {}