// ********************************************************
// Name: Abdullah Nazir
// Date: July 08, 2024
//
// Implementation file HeapImpl.cpp
// This file contains definitions of the functions declared
//  in the abstract class Heap .
// ********************************************************

#include "../Headers/Heap.h"

template <typename T>
Heap<T>::Heap() {}

template <typename T>
Heap<T>::Heap(int maxSize) : maxSize(maxSize), heapSize(0), heapArray(nullptr) {}

template <typename T>
Heap<T>::~Heap()
{
    if (heapArray)
    {
        delete[] (heapArray);
        heapArray = nullptr;
        heapSize = 0;
    }
}

template <typename T>
bool Heap<T>::isEmpty() const
{
    return (heapSize == 0);
}

template <typename T>
bool Heap<T>::isFull() const
{
    return (heapSize == maxSize);
}

template <typename T>
int Heap<T>::parent(int index)
{
    return ((index - 1) / 2);
}

template <typename T>
int Heap<T>::left(int index)
{
    return (index * 2 + 1);
}

template <typename T>
int Heap<T>::right(int index)
{
    return (index * 2 + 2);
}
