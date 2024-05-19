// ********************************************************
// Name: Abdullah Nazir
// Date: April 06, 2024
//
// abstract class Queue
// This file contains implementation of data structure
// queue abstract class. This class will be extended to
// ArrayQueue and LinkedListQueue.
// ********************************************************

#ifndef H_Queue
#define H_Queue

template <typename T>
class Queue
{
public:
    Queue() {}
    // Default constructor.

    virtual void display() const = 0;
    // Pure virutal function to display all
    //  contents of the queue.
    // It will be implemented in the concrete
    //  class.

    virtual void enqueue(T) = 0;
    // Pure virtual function to enqueue a value
    //  at the end of the queue.
    // It will be implemented in the concrete
    //  class.

    virtual T dequeue() = 0;
    // Pure virtual function to dequeue the first
    //  value from the queue.
    // Dequeued value will be returned.
    // It will be implemented in the concrete
    //  class.

    virtual T getFront() const = 0;
    // Pure virtual function to return first
    //  value that is pointed by the front.
    // It will be implemented in the concrete
    //  class.

    virtual T getRear() const = 0;
    // Pure virtual function to return last
    //  value that is pointed by the rear.
    // It will be implemented in the concrete
    //  class.

    virtual bool isEmpty() const = 0;
    // Pure virtual function to return true
    //  if the queue is empty and
    //  false otherwise.

    virtual bool isFull() const = 0;
    // Pure virtual function to return true
    //  if the queue is full and
    //  false otherwise.

    ~Queue() {}
    // Destructor function.
};

#endif