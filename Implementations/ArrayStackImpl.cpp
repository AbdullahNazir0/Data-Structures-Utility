#include "../Headers/ArrayStack.h"

#include <iostream>

template <class T>
ArrayStack<T>::ArrayStack(int cap) : Stack<T>(cap)
{
	top = -1;
	Stack<T>::stackPtr = new T[Stack<T>::capacity];
}

template <class T>
void ArrayStack<T>::display() const
{
	std::cout << "Stack data: ";
	for (int i = 0; i < Stack<T>::currentSize; i++)
		std::cout << Stack<T>::stackPtr[i] << " ";
	std::cout << std::endl;
}

template <class T>
void ArrayStack<T>::push(T value)
{
	if (isFull())
		return;
	Stack<T>::stackPtr[++top] = value;
	Stack<T>::currentSize++;
}

template <class T>
T ArrayStack<T>::pop()
{
	if (isEmpty())
		return T();
	T temp = Stack<T>::stackPtr[top];
	top--;
	Stack<T>::currentSize--;
	return temp;
}

template <class T>
T ArrayStack<T>::peek() const
{
	if (isEmpty())
		return T();
	return Stack<T>::stackPtr[top];
}

template <class T>
bool ArrayStack<T>::isEmpty() const
{
	return (top == -1);
}

template <class T>
bool ArrayStack<T>::isFull() const
{
	return (top == Stack<T>::capacity - 1);
}

template <class T>
ArrayStack<T>::~ArrayStack()
{
	if (Stack<T>::stackPtr)
		delete[] Stack<T>::stackPtr;
}
