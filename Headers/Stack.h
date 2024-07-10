// ********************************************************
// Name: Abdullah Nazir
// Date: March 27, 2024
//
// abstract class Stack
// This file contains implementation of data structure
// stack abstract class. This class will be extended to
// ArrayStack and LinkedListStack.
// ********************************************************

#ifndef H_Stack
#define H_Stack

template <typename T>
class Stack
{
public:
	Stack();
	// Default constructor for abstract class
	//  Stack.
	// This constructor initializes top to -1
	//  and currentSize to 0.

	virtual void display() const = 0;
	// Pure virutal function to display all
	//  contents of the stack.
	// It will be implemented in the concrete
	//  class.

	virtual void push(T) = 0;
	// Pure virtual function to push a value
	//  in the stack.
	// It will be implemented in the concrete
	//  class.

	virtual T pop() = 0;
	// Pure virtual function to pop the last
	//  value from the stack.
	// Popped value will be returned.
	// It will be implemented in the concrete
	//  class.

	virtual T peek() const = 0;
	// Pure virtual function to return last
	//  value that is pointed by the top.
	// It will be implemented in the concrete
	//  class.

	virtual bool isEmpty() const = 0;
	// Pure virtual function to return true
	//  if the stack is empty and
	//  false otherwise.

	// will not be abstract funcion as linkedlist
	// stack dont have capacity.
	// virtual bool isFull() const = 0;
	// Pure virtual function to return true
	//  if the stack is full and
	//  false otherwise.

	int getTop() const;
	// Function to return top(index) of the
	//  stack.

	int getCurrentSize() const;
	// Function to return current size of
	//  the stack.

	~Stack();
	// Destructor function.

protected:
	int top;
	int currentSize;
};

#include "../Implementations/StackImpl.cpp"

#endif
