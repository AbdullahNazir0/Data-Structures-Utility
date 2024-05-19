// ********************************************************
// Name: Abdullah Nazir
// Date: March 27, 2024
//
// Implementation file ArrayStackImpl.cpp
// This file contains definitions of the functions declared
//  in the class ArrayStack .
// ********************************************************

#include "../Headers/ArrayStack.h"
#include <iostream>

template <typename T>
ArrayStack<T>::ArrayStack(int cap) : capacity(cap)
{
	stackPtr = new T[capacity];
}

template <typename T>
void ArrayStack<T>::display() const
{
	if (isEmpty())
	{
		std::cout << "Stack is empty.\n";
		return;
	}
	
	for (int i = 0; i <= this->top; i++)
		std::cout << stackPtr[i] << " ";
	std::cout << "\n";
}

template <typename T>
void ArrayStack<T>::push(T value)
{
	if (isFull())
	{
		std::cout << "Can't push, stack is full. (stack\n)";
		return;
	}

	stackPtr[++this->top] = value;
	this->currentSize++;
}

template <typename T>
T ArrayStack<T>::pop()
{
	if (isEmpty())
	{
		std::cout << "Can't pop, stack is empty. (stack underflown)\n";
		return T();
	}
	T temp = stackPtr[this->top];
	this->top--;
	this->currentSize--;
	return temp;
}

template <typename T>
T ArrayStack<T>::peek() const
{
	if (isEmpty())
	{
		std::cout << "Can't peek, stack is empty.\n";
		return T();
	}
	return stackPtr[this->top];
}

template <typename T>
void ArrayStack<T>::clear()
{
	if (isEmpty())
	{
		std::cout << "Can't clear, stack is empty.\n";
		return;
	}

	this->top = -1;
	this->currentSize = 0;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const
{
	return (this->top == -1);
}

template <typename T>
bool ArrayStack<T>::isFull() const
{
	return (this->top == capacity - 1);
}

template <typename T>
ArrayStack<T> *ArrayStack<T>::from(T *arr, int size)
{
	if (size <= 0 || !arr)
	{
		std::cout << "Invalid size or empty array found. (empty stack is returned\n";
		return new ArrayStack();
	}
	int maxSize = DEFAULT_MAX_SIZE;
	if (size > DEFAULT_MAX_SIZE)
		maxSize = size;
	ArrayStack<T> *tempStack = new ArrayStack<T>(maxSize);
	for (int i = 0; i < size; i++)
		tempStack->push(arr[i]);

	return tempStack;
}

template <typename T>
ArrayStack<T>::~ArrayStack()
{
	if (stackPtr)
		delete[] stackPtr;
}
