#ifndef H_ArrayStack
#define H_ArrayStack

#include "Stack.h"

template <class T>
class ArrayStack : public Stack<T>
{
public:
	ArrayStack(int = 100);
	// Parameterized consturctor with default
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

	bool isEmpty() const override;
	// Overriden function isEmpty to check if the
	//  stack is empty or not.
	// True if empty, false otherwise.

	bool isFull() const override;
	// Overriden function isFull to check if the
	//  stack is full or not.
	// True is empty, false otherwise.

	~ArrayStack();
	// Destructor function to delete dynamic memory.

private:
	int top;
};

#include "../Implementations/ArrayStackImpl.cpp"

#endif
