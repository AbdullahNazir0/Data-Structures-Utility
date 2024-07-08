// ********************************************************
// Name: Abdullah Nazir
// Date: July 08, 2024
//
// class MinHeap
// This file contains implementation of data structure
// min heap with extended features and functionalitites.
// This class is a concrete class derived from the abstract
// class Heap .
// ********************************************************

#ifndef H_MinHeap
#define H_MinHeap

#include "Heap.h"

template <typename T>
class MinHeap : public Heap<T>
{
public:
    using Heap<T>::heapArray;
    using Heap<T>::heapSize;
    using Heap<T>::maxSize;
    using Heap<T>::isFull;
    using Heap<T>::isEmpty;
    using Heap<T>::parent;
    using Heap<T>::left;
    using Heap<T>::right; // To bring in all members.

    MinHeap(int = 100); // default max size.
    ~MinHeap();

    void insert(const T &) override;
    void display() const override;
    void deleteMin();
    void heapifyUp(int) override;
    void heapifyDown(int) override;
    void heapSort() override;
};

#include "../Implementations/MinHeapImpl.cpp"

#endif