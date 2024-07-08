// ********************************************************
// Name: Abdullah Nazir
// Date: July 08, 2024
//
// class Heap
// This file contains implementation of data structure
// heap with extended features and functionalitites.
// This class is an abstract class. Concrete classes will
// be derived from this class i.e MinHeap and MaxHeap .
// ********************************************************

#ifndef H_Heap
#define H_Heap

template <typename T>
class Heap
{
public:
    Heap();
    Heap(int);
    ~Heap();

    virtual void insert(const T &) = 0;
    virtual void display() const = 0;
    bool isEmpty() const;
    bool isFull() const;
    virtual void heapifyUp(int) = 0;
    virtual void heapifyDown(int) = 0;
    virtual void heapSort() = 0;

    int parent(int);
    int left(int);
    int right(int);

protected:
    T *heapArray;
    int heapSize;
    int maxSize;
};

#include "../Implementations/HeapImpl.cpp"

#endif