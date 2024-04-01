// ********************************************************
// Name: Abdullah Nazir
// Date: March 09, 2024
//
// Implementation file ArraysImpl.cpp
// This file contains definitions of the functions declared
//  in the class Array .
// ********************************************************

// #include "Arrays.h"
#include "./Headers/Arrays.h"
#include <iterator>

template<class T>
Array<T>::Array() : size(1), isSorted(false)
{
	arr = new T[1];
}

template<class T>
Array<T>::Array(T value[], int arraySize) : size(arraySize), isSorted(false)
{
	arr = new T[size];
	for(int i = 0; i < size; i++)
		arr[i] = value[i];
	
}

template<class T>
Array<T>::Array(const Array<T> &other) : size(other.size), isSorted(other.isSorted)
{
	arr = new T[size];
	for(int i = 0; i < size; i++)
		arr[i] = other.arr[i];
}

template<class T>
Array<T>::~Array()
{
	delete[]arr;
}

template<class T>
int Array<T>::length() const
{
	return size;
}

template<class T>
void Array<T>::displayFormatted() const
{
	std::cout << "[\n";
	for(int i = 0; i < size; i++) 
		std::cout << arr[i] << ",\n";
	std::cout << "]\n";
}

template<class T>
bool Array<T>::isEmpty() const
{
	return(size == 0);
}

template<class T>
bool Array<T>::isPresent(T value) const
{
	if(size == 0)
		return false;
	for(int i = 0; i < size; i++)
	{
		if (arr[i] == value)
			return true;
	}
	return false;
}

template<class T>
void Array<T>::operator= (const Array<T> &other)
{
	size = other.size;
	isSorted = other.isSorted;
	if(size == 0)
		arr = nullptr;
	else 
	{
		for(int i = 0; i < size; i++)
			arr[i] = other.arr[i];
	}
}

template<class T>
bool Array<T>::operator== (const Array<T> &other) const
{
	if(size != other.size)
		return false;
	else
	{
		for(int i = 0; i < size; i++)
		{
			if(arr[i] != other.arr[i])
				return false;
		}
		return true;
	}
}

template<class T>
T Array<T>::operator[] (int index) const
{
	if(index < 0)
	{
		std::cout << "Invalid Index\n";
		return T();
	}
	if(index > size - 1)
	{
		std::cout << "Out of bound error\n";
		return T();
	}

	return arr[index];
}

template<class T>
void Array<T>::sortInAscending()
{
	if(size == 0)
	{
		std::cout << "Empty Array can not be sorted.\n";
		return;
	}

	if(isSorted == true)
	{
		std::cout << "Array already sorted\n";
		return;
	}

	for(int i = 0; i < size - 1; i++)
	{
		bool flag = false;
		for(int j = 0; j < size - 1 - i; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = true;
			}
		}
		if(flag == false)
			break;
	}

	isSorted = true;
}

template<class T>
void Array<T>::sortInDescending()
{
	if(size == 0)
	{
		std::cout << "Empty Array can not be sorted.\n";
		return;
	}

	if(isSorted == true)
	{
		std::cout << "Array already sorted\n";
		return;
	}

	for(int i = 0; i < size - 1; i++)
	{
		bool flag = false;
		for(int j = 0; j < size - 1 - i; j++)
		{
			if(arr[j] < arr[j + 1])
			{
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = true;
			}
		}
		if(flag == false)
			break;
	}

	isSorted = true;
}

template<class T>
void Array<T>::fillWith(T value, int index)
{
	if(index < 0)
	{
		std::cout << "Invalid index.\n";
		return;
	}

	if(index > size)
	{
		T *temp = new T[index + 1] {value};
		size = index + 1;
		if(isSorted)
			isSorted = false;
		delete[]arr;
		arr = temp;
	}
	else 
	{
		for(int i = 0; i < index + 1; i++)
			arr[i] = value;
		if(isSorted)
			isSorted = false;
	}	

}

template<class T>
void Array<T>::swapWith(T value, int index)
{
	if(index < 0)
	{
		std::cout << "Invalid index\n";
		return;
	}
	if(index > size)
	{
		std::cout << "Array out of bound.\n";
		return;
	}

	arr[index] = value;
	if(isSorted)
		isSorted = false;

}

template<class T>
void Array<T>::swapAll(T oldValue, T newValue)
{
	for(int i = 0; i < size; i++)
	{
		if(arr[i] == oldValue)
			arr[i] = newValue;
	}
}

template<class T>
T* Array<T>::slice(int startIndex, int endIndex) const
{
	if(startIndex < 0 || startIndex > size - 1)
	{
		std::cout << "Starting index out of"
				"bound.\n";
		return(new T());
	}
	if(endIndex < 1 || endIndex > size)
	{
		std::cout << "Ending index out of bound.\n";
		return(new T());
	}
	if(startIndex >= endIndex)
	{
		std::cout << "Starting index can not be "
				"greater than or equal "
				"to ending index\n";
		return(new T());
	}

	T* temp = new T[endIndex - startIndex];
	for(int i = startIndex; i < endIndex; i++)
		temp[i] = arr[i];

	return temp;
}

template<class T>
void Array<T>::join(const Array<T> &other)
{
	if(other.size == 0)
	{
		std::cout << "Cannot join empty array.\n";
		return;
	}
	T* temp = new T[size + other.size];
	for(int i = 0; i < size; i++)
		temp[i] = arr[i];
	for(int i = size; i < size + other.size; i++)
		temp[i] = other.arr[i - size];
	delete[]arr;
	arr = temp;
	if(isSorted)
		isSorted = false;
}

template<class T>
int Array<T>::searchByValue(T value) const
{
	for(int i = 0; i < size; i++)
	{
		if(arr[i] == value)
			return i;
	}
	return T();
}

template <class T>
void Array<T>::insertAtStart(T element)
{
	T* temp = new T[size + 1];
	temp[0] = element;
	for(int i = 0; i < size; i++)
		temp[i + 1] = arr[i];
	delete[]arr;
	arr = temp;
	size++;
	if(isSorted)
		isSorted = false;
}

template<class T>
void Array<T>::insertAtIndex(T element, int index)
{
	if(index < 0)
	{
		std::cout << "Invalid index.\n";
		return;
	}
	if(index > size)
	{
		std::cout << "Index out of bound.\n";
		return;
	}
	if(size == 0)
		arr[0] = element;
	else
	{
		T* temp = new T[size + 1];
		for(int i = 0, j = 0; i < size + 1; i++)
		{
			if(i == index)
				temp[i] = element;
			else
			{
				temp[i] = arr[j];
				j++;
			}
		}
	}
}

template<class T>
void Array<T>::insertAtEnd(T element)
{
	T* temp = new T[size + 1];
	for(int i = 0; i < size; i++)
		temp[i] = arr[i];
	temp[size] = element;
	delete[]arr;
	arr = temp;
	size++;
	if(isSorted)
		isSorted = false;
}

template<class T>
T Array<T>::deleteFirst()
{
	if(size == 0)
	{
		std::cout << "Cannot delete from empty "
				"array\n";
		return(T());
	}

	T temp = arr[0];
	for(int i = 0; i < size - 1; i++)
		arr[i] = arr[i + 1];
	size--;
	return(temp);
}

template<class T>
T Array<T>::deleteLast()
{
	if(size == 0)
	{
		std::cout << "Cannot delete from empty "
				"array.\n";
		return(T());
	}

	size--;
	return(arr[size]);
}

template<class T>
T Array<T>::deleteAtIndex(int index)
{
	if(size == 0)
	{
		std::cout << "Cannot delete from empty "
				"array.\n";
		return(T());
	}
	if(index < 0)
	{
		std::cout << "Invalid index.\n";
		return(T());
	}
	if(index > size)
	{
		std::cout << "Index out of bound.\n";
		return(T());
	}
	
	T temp = arr[index];
	for(int i = index; i < size - 1; i++)
		arr[i] = arr[i + 1];
	size--;
	return(temp);
}

template<class T>
void Array<T>::deleteByValue(T value)
{
	if(size == 0)
	{
		std::cout << "Cannot delete from empty "
				"array\n";
		return;
	}
	for(int i = 0; i < size; i++)
	{
		if(arr[i] == value)
		{
			for(int j = i; j < size - 1; j++)
				arr[j] = arr[j + 1];
			size--;
			return;
		}
	}
	std::cout << "Value not found in array.\n";

}

template<class T>
Array<T> Array<T>::toArray(T other[], int arraySize)
{
	Array<T> temp(other, arraySize);
	return temp;
}

template<class T>
std::istream& operator>> (
		std::istream& in,
		Array<T> &arr
		)
{
	for(int i = 0; i < arr.size; i++)
		in >> arr.arr[i];
	return in;
}

template<class T>
std::ostream& operator<< (
		std::ostream &out,
		const Array<T> &arr
		)
{
	out << "[";
	for(int i = 0; i < arr.size; i++)
		out << arr.arr[i] << ", ";
	out << "]\n";
	return out;
}
