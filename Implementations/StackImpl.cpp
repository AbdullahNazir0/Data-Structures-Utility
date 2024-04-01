#include "../Headers/Stack.h"

template <class T>
Stack<T>::Stack(int cap) : capacity(cap)
{
	currentSize = 0;
}

template <class T>
int Stack<T>::getCapacity() const
{
	return capacity;
}

template <class T>
int Stack<T>::getCurrentSize() const
{
	return currentSize;
}

template <class T>
Stack<T>::~Stack() {}
