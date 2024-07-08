// ********************************************************
// Name: Abdullah Nazir
// Date: July 08, 2024
//
// Implementation file MinHeapImpl.cpp
// This file contains definitions of the functions declared
//  in the concrete class MinHeap .
// ********************************************************

#include "../Headers/MinHeap.h"

#include <iostream>

template <typename T>
MinHeap<T>::MinHeap(int maxSize) : Heap<T>(maxSize)
{
    this->heapArray = new T[this->maxSize];
}

template <typename T>
MinHeap<T>::~MinHeap()
{
    if (this->heapArray)
    {
        delete[] this->heapArray;
        this->heapArray = nullptr;
        this->heapSize = 0;
    }
}

template <typename T>
void MinHeap<T>::insert(const T &value)
{
    if (isFull())
    {
        std::cout << "Cannot insert, min heap is full.\n";
        return;
    }

    heapArray[heapSize] = value;
    heapifyUp(heapSize);
    heapSize++;
}

template <typename T>
void MinHeap<T>::display() const
{
    if (isEmpty())
    {
        std::cout << "Min heap is empty.\n";
        return;
    }

    for (int i = 0; i < heapSize; i++)
        std::cout << heapArray[i] << " ";
    std::cout << "\n";
}

template <typename T>
void MinHeap<T>::deleteMin()
{
    if (isEmpty())
    {
        std::cout << "Cannot delete, min heap is empty.\n";
        return;
    }

    std::swap(heapArray[0], heapArray[heapSize - 1]);
    heapifyDown(0);
    heapSize--;
}

template <typename T>
void MinHeap<T>::heapifyUp(int index)
{
    while (index != 0 && heapArray[index] < heapArray[parent(index)])
    {
        std::swap(heapArray[index], heapArray[parent(index)]);
        index = parent(index);
    }
}

template <typename T>
void MinHeap<T>::heapifyDown(int index)
{
    int smallest = index;
    int leftChild = left(index);
    int rightChild = right(index);

    if (leftChild < heapSize && heapArray[leftChild] < heapArray[smallest])
        smallest = leftChild;

    if (rightChild < heapSize && heapArray[rightChild] < heapArray[smallest])
        smallest = rightChild;

    if (smallest != index)
    {
        std::swap(heapArray[index], heapArray[smallest]);
        heapifyDown(smallest);
    }
}

template <typename T>
void MinHeap<T>::heapSort()
{
    int originalSize = heapSize;

    for (int i = heapSize - 1; i > 0; i--)
    {
        std::swap(heapArray[0], heapArray[i]);
        heapSize--;
        heapifyDown(0);
    }

    heapSize = originalSize;
}