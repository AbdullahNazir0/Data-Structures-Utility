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
ArrayStack<T>::ArrayStack(int cap) : Stack<T>(cap)
{
	top = -1;
	this->currentSize = 0;
	this->stackPtr = new T[this->capacity];
}

// template <typename T>
// ArrayStack<T>::ArrayStack(const ArrayStack &obj)
// {
// 	this->capacity = obj.capacity;
// 	top = obj.top;
// 	this->currentSize = obj.currentSize;
// 	if (obj.stackPtr)
// 	{
// 		this->stackPtr = new T[this->capacity];
// 		for (int i = 0; i < this->currentSize; i++)
// 			this->stackPtr[i] = obj.stackPtr[i];
// 	}
// 	else
// 		this->stackPtr = nullptr;
// }

// template <typename T>
// ArrayStack<T>::ArrayStack(ArrayStack &&other) noexcept
// {
// 	this->capacity = other.capacity;
// 	this->currentSize = other.currentSize;
// 	top = other.top;
// 	this->stackPtr = other.stackPtr;

// 	other.stackPtr = nullptr;
// 	other.top = -1;
// 	other.capacity = 0;
// 	other.currentSize = 0;
// }

template <typename T>
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

template <typename T>
void ArrayStack<T>::push(T value)
{
	if (isFull())
		return;
	this->stackPtr[++top] = value;
	this->currentSize++;
}

template <typename T>
T ArrayStack<T>::pop()
{
	if (isEmpty())
		return T();
	T temp = this->stackPtr[top];
	top--;
	this->currentSize--;
	return temp;
}

template <typename T>
T ArrayStack<T>::peek() const
{
	if (isEmpty())
		return T();
	return this->stackPtr[top];
}

template <typename T>
void ArrayStack<T>::clear()
{
	if (isEmpty())
		return;

	top = -1;
	this->currentSize = 0;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const
{
	return (top == -1);
}

template <typename T>
bool ArrayStack<T>::isFull() const
{
	return (top == this->capacity - 1);
}

template <typename T>
ArrayStack<T> ArrayStack<T>::from(T *arr, int size)
{
	if (size <= 0 || !arr)
		return ArrayStack();
	int maxSize = DEFAULT_MAX_SIZE;
	if (size > DEFAULT_MAX_SIZE)
		maxSize = size;
	ArrayStack tempStack(maxSize);
	for (int i = 0; i < size; ++i)
		tempStack.push(arr[i]);

	return tempStack;
}

template <typename T>
ArrayStack<T>::~ArrayStack()
{
	if (this->stackPtr)
		delete[] this->stackPtr;
}
