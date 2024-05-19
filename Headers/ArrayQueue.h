// ********************************************************
// Name: Abdullah Nazir
// Date: April 06, 2024
//
// class ArrayQueue
// This file contains implementation of data structure
// queue implemented with array by inheriting from abstract
// class Queue with extended features and functionalitites.
// ********************************************************

#ifndef H_ArrayQueue
#define H_ArrayQueue

#define DEFAULT_MAX_SIZE 100

#include "Queue.h"

template <typename T>
class ArrayQueue : public Queue<T>
{
public:
    ArrayQueue(int = DEFAULT_MAX_SIZE);
    // Parameterized constructor with default
    //  argument capacity.
    // The default capacity of the queue will
    //  be 100, if no capacity is provided
    //  explicitly.

    void display() const override;
    // Overriden function display to display
    //  all  values of the queue.

    void enqueue(T value) override;
    // Overriden function enqueue to add value to the
    //  end of the queue.

    T dequeue() override;
    // Overriden function dequeue to delete and return
    //  first value from the queue.

    T getFront() const override;
    // Overridden function front to get first value of
    //  the queue.

    T getRear() const override;
    // Overridden function rear to get last value of the
    //  queue.

    void clear();
    // Function to reset the queue.

    bool isEmpty() const override;
    // Overriden function isEmpty to check if the
    //  queue is empty or not.
    // True if empty, false otherwise.

    bool isFull() const override;
    // Overriden function isFull to check if the
    //  queue is full or not.
    // True is empty, false otherwise.

    ~ArrayQueue();
    // Destructor function to delete dynamic memory.

private:
    T *queuePtr;
    int front;
    int rear;
    int capacity;
    int currentSize;
};

#include "../Implementations/ArrayQueueImpl.cpp"

#endif