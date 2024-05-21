// ********************************************************
// Name: Abdullah Nazir
// Date: May 18, 2024
//
// class LinkedListQueue
// This file contains implementation of data structure
// queue implemented with linked list by inheriting from
// abstract class Queue with extended features and
// functionalitites.
// ********************************************************

#ifndef H_LinkedListQueue
#define H_LinkedListQueue

#include "Queue.h"
#include "SinglyLinkedList.h"

template <typename T>
class LinkedListQueue : public Queue<T>
{
public:
    LinkedListQueue();
    // Default constructor.

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

    ~LinkedListQueue();
    // Destructor function to delete dynamic memory.

private:
    SinglyLinkedList<T> *queuePtr;
};

#include "../Implementations/LinkedListQueueImpl.cpp"

#endif