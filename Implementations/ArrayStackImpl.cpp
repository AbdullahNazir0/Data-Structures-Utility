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
	this->stackPtr = new T[this->capacity];
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
	for (int i = 0; i < this->currentSize; i++)
		std::cout << this->stackPtr[i] << " ";
	std::cout << std::endl;
}

template <class T>
void ArrayStack<T>::push(T value)
{
	if (isFull())
		return;
	this->stackPtr[++top] = value;
	this->currentSize++;
}

template <class T>
T ArrayStack<T>::pop()
{
	if (isEmpty())
		return T();
	T temp = this->stackPtr[top];
	top--;
	this->currentSize--;
	return temp;
}

template <class T>
T ArrayStack<T>::peek() const
{
	if (isEmpty())
		return T();
	return this->stackPtr[top];
}

template <class T>
void ArrayStack<T>::clear()
{
	if (isEmpty())
		return;

	top = -1;
	this->currentSize = 0;
}

template <class T>
bool ArrayStack<T>::isEmpty() const
{
	return (top == -1);
}

template <class T>
bool ArrayStack<T>::isFull() const
{
	return (top == this->capacity - 1);
}

template <class T>
ArrayStack<T> ArrayStack<T>::from(T *arr)
{
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	if (arrSize == 0)
		return ArrayStack();
	int maxSize = DEFAULT_MAX_SIZE;
	if (arrSize > DEFAULT_MAX_SIZE)
		maxSize = arrSize;
	ArrayStack tempStack = ArrayStack(maxSize);
	for (int i = 0; i < arrSize; i++)
	{
		tempStack.push(arr[i]);
	}
	return tempStack;
}

template <class T>
ArrayStack<T>::~ArrayStack()
{
	if (this->stackPtr)
		delete[] this->stackPtr;
}
