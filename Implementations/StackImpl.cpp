// ********************************************************
// Name: Abdullah Nazir
// Date: March 27, 2024
//
// Implementation file StackImpl.cpp
// This file contains definitions of the functions declared
//  in the abstract class Stack .
// ********************************************************

#include "../Headers/Stack.h"

template <typename T>
Stack<T>::Stack()
{
	top = -1;
	currentSize = 0;
}

template <typename T>
int Stack<T>::getTop() const
{
	return top;
}

template <typename T>
int Stack<T>::getCurrentSize() const
{
	return currentSize;
}

template <typename T>
Stack<T>::~Stack() {}