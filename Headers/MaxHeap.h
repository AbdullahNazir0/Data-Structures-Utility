// ********************************************************
// Name: Abdullah Nazir
// Date: July 08, 2024
//
// class MaxHeap
// This file contains implementation of data structure
// max heap with extended features and functionalitites.
// This class is a concrete class derived from the abstract
// class Heap .
// ********************************************************

#ifndef H_MaxHeap
#define H_MaxHeap

#include "Heap.h"

template <typename T>
class MaxHeap : public Heap<T>
{
public:

    using Heap<T>::heapArray;
    using Heap<T>::heapSize;
    using Heap<T>::maxSize;
    using Heap<T>::isFull;
    using Heap<T>::isEmpty;
    using Heap<T>::parent;
    using Heap<T>::left;
    using Heap<T>::right;

    MaxHeap(int = 100); // default max size.
    ~MaxHeap();

    void insert(const T &) override;
    void display() const override;
    void deleteMax();
    void heapifyUp(int) override;
    void heapifyDown(int) override;
    void heapSort() override;
};

#include "../Implementations/MaxHeapImpl.cpp"

#endif