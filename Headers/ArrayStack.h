// ********************************************************
// Name: Abdullah Nazir
// Date: March 27, 2024
//
// class ArrayStack
// This file contains implementation of data structure
// stack implemented with array by inheriting from abstract
// class Stack with extended features and functionalitites.
// ********************************************************

#ifndef H_ArrayStack
#define H_ArrayStack

#define DEFAULT_MAX_SIZE 100;

#include "Stack.h"

template <class T>
class ArrayStack : public Stack<T>
{
public:
	ArrayStack(int = DEFAULT_MAX_SIZE);
	// Parameterized constructor with default
	//  argument capacity.
	// The default capacity of the stack will
	//  be 100, if no capacity is provided
	//  explicitly.

	void display() const override;
	// Overriden function display to display
	//  all  values of the stack.

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

	bool isFull() const override;
	// Overriden function isFull to check if the
	//  stack is full or not.
	// True is empty, false otherwise.

	static ArrayStack<T> from(T *);
	// Function to return an ArrayStack from the
	//  given array.
	// This function takes an array as parameter
	//  and return a stack with this array.

	~ArrayStack();
	// Destructor function to delete dynamic memory.

private:
	int top;
};

#include "../Implementations/ArrayStackImpl.cpp"

#endif
