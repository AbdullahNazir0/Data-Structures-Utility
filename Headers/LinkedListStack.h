// ********************************************************
// Name: Abdullah Nazir
// Date: May 18, 2024
//
// class LinkedListStack
// This file contains implementation of data structure
// stack implemented with linked list by inheriting from
// abstract class Stack with extended features and
// functionalitites.
// ********************************************************

#ifndef H_LinkedListStack
#define H_LinkedListStack

#include "Stack.h"
#include "../Headers/SinglyLinkedList.h"

template <typename T>
class LinkedListStack : Stack<T>
{
public:
    LinkedListStack();
    // Default constructor.

    void display() const override;
    // Overriden function display to display
    //  all values of the stack.

    void push(T value) override;
    // Overriden function push to add value to the
    //  end of the stack.

    T pop() override;
    // Overriden function pop to delete and return
    //  last value from the stack.

    T peek() const override;
    // Overriden function peek to return last value
    //  of the stack pointed by the top.

    T peekAt(int) const;
    // Function to return value at a specific index
    //  of the stack, given by the user.

    void clear();
    // Function to reset the stack.

    bool isEmpty() const override;
    // Overriden function isEmpty to check if the
    //  stack is empty or not.
    // True if empty, false otherwise.

    ~LinkedListStack();
    // Destructor function to delete dynamic memory.

private:
    SinglyLinkedList<T> *stackPtr;
};

#include "../Implementations/LinkedListStackImpl.cpp"

#endif