// ********************************************************
// Name: Abdullah Nazir
// Date: July 08, 2024
//
// Implementation file MaxHeapImpl.cpp
// This file contains definitions of the functions declared
//  in the concrete class MaxHeap .
// ********************************************************

#include "../Headers/MaxHeap.h"

#include <iostream>

template <typename T>
MaxHeap<T>::MaxHeap(int maxSize) : Heap<T>(maxSize)
{
    this->heapArray = new T[this->maxSize];
}

template <typename T>
MaxHeap<T>::~MaxHeap()
{
    if (this->heapArray)
    {
        delete[] this->heapArray;
        this->heapArray = nullptr;
        this->heapSize = 0;
    }
}

template <typename T>
void MaxHeap<T>::insert(const T &value)
{
    if (isFull())
    {
        std::cout << "Cannot insert, max heap is full.\n";
        return;
    }

    heapArray[heapSize] = value;
    heapifyUp(heapSize);
    heapSize++;
}

template <typename T>
void MaxHeap<T>::display() const
{
    if (isEmpty())
    {
        std::cout << "Max heap is empty.\n";
        return;
    }

    for (int i = 0; i < heapSize; i++)
        std::cout << heapArray[i] << " ";
    std::cout << "\n";
}

template <typename T>
void MaxHeap<T>::deleteMax()
{
    if (isEmpty())
    {
        std::cout << "Cannot delete, max heap is empty.\n";
        return;
    }

    std::swap(heapArray[0], heapArray[heapSize - 1]);
    heapifyDown(0);
    heapSize--;
}

template <typename T>
void MaxHeap<T>::heapifyUp(int index)
{
    while (index != 0 && heapArray[index] > heapArray[parent(index)])
    {
        std::swap(heapArray[index], heapArray[parent(index)]);
        index = parent(index);
    }
}

template <typename T>
void MaxHeap<T>::heapifyDown(int index)
{
    int largest = index;
    int leftChild = left(index);
    int rightChild = right(index);

    if (leftChild < heapSize && heapArray[largest] < heapArray[leftChild])
        largest = leftChild;

    if (rightChild < heapSize && heapArray[largest] < heapArray[rightChild])
        largest = rightChild;

    if (largest != index)
    {
        std::swap(heapArray[index], heapArray[largest]);
        heapifyDown(largest);
    }
}

template <typename T>
void MaxHeap<T>::heapSort()
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