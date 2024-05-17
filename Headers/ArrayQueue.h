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

#include "Queue.h"

template <typename T>
class ArrayQueue : public Queue<T>
{
    ArrayQueue(int = 100);
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

    T peek() const override;
    // Overriden function peek to return first value
    //  of the queue pointed by the front.

    T peekAt(int) const;
    // Function to return value at a specific index
    //  of the queue, given by the user.

    T atLast() const;
    // Function to return last value of the queue
    //  pointed by the rear.

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
    int front;
    int rear;
};

#include "../Implementations/ArrayQueueImpl.cpp"

#endif