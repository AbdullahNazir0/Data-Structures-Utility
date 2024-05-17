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
Stack<T>::Stack(int cap) : capacity(cap)
{
	currentSize = 0;
}

template <typename T>
int Stack<T>::getCapacity() const
{
	return capacity;
}

template <typename T>
int Stack<T>::getCurrentSize() const
{
	return currentSize;
}

template <typename T>
Stack<T>::~Stack() {}
