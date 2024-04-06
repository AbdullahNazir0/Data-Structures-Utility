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

template <class T>
ArrayStack<T>::ArrayStack(int cap) : Stack<T>(cap)
{
	top = -1;
	stackPtr = new T[capacity];
}

template <class T>
void ArrayStack<T>::display() const
{
	if (isEmpty())
	{
		std::cout << "Stack is empty.\n";
		return;
	}
	std::cout << "Stack data: ";
	for (int i = 0; i < currentSize; i++)
		std::cout << stackPtr[i] << " ";
	std::cout << std::endl;
}

template <class T>
void ArrayStack<T>::push(T value)
{
	if (isFull())
		return;
	stackPtr[++top] = value;
	currentSize++;
}

template <class T>
T ArrayStack<T>::pop()
{
	if (isEmpty())
		return T();
	T temp = stackPtr[top];
	top--;
	currentSize--;
	return temp;
}

template <class T>
T ArrayStack<T>::peek() const
{
	if (isEmpty())
		return T();
	return stackPtr[top];
}

template <class T>
void ArrayStack<T>::clear()
{
	if (isEmpty())
		return;

	top = -1;
	currentSize = 0;
}

template <class T>
bool ArrayStack<T>::isEmpty() const
{
	return (top == -1);
}

template <class T>
bool ArrayStack<T>::isFull() const
{
	return (top == capacity - 1);
}

template <class T>
ArrayStack<T>::~ArrayStack()
{
	if (stackPtr)
		delete[] stackPtr;
}
