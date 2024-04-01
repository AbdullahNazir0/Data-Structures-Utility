// ********************************************************
// Name: Abdullah Nazir
// Date: March 09, 2024
//
// class Array
// This file contains implementation of data structure 
// array with extended features and functionalitites. 
// ********************************************************

#ifndef H_arrays
#define H_arrays

#include <iostream>

template<class T>
class Array {
	public:
		Array();
		// Default constructor to initialize the 
		//  size to 0 and array to 1 and isSorted
		//  to false.

		Array(T value[], int arraySize);
		// Parameterized constructor.
		
		Array(const Array<T> &other);
		// Copy constructor to copy the contents.

		~Array();
		// Destructor Function to delete the arr.

		int length() const;
		// Function to get length of the array.
		// It will return the size of the array.

		void displayFormatted() const;
		// Function to display the contents of 
		//  array in a more appealing format i.e.
		//  [
		//    t1,
		//    t2,
		//    t3
		//  ]
		
		bool isEmpty() const;
		// Function to check if the array is empty.

		bool isFull() const;
		// Function to check if the array is full.

		bool isPresent(T value) const;
		// Function to check if an element is 
		//  present in the array.
		
		void operator= (const Array<T> &other);
		// Function to implement assignment (=)
		//  operator for the array.
		// The assignment will be deep copy.

		bool operator== (const Array<T> &other) const;
		// Function to implement equal to operator 
		//  (==) to check if two arrays are equal 
		//  or not.
		// Equal arrays will have same size and 
		//  same elements.

		T operator[] (int index) const;
		// Function to implement square brackets
		//  ([]) for the array to access a specific
		//  element of the array.

		void sortInAscending();
		// Function to sort the array in ascending 
		//  order.

		void sortInDescending();
		// Function to sort the array in descending
		//  order.

		void fillWith(T value, int index);
		// This function will fill the array with
		//  the given value for all elements from 
		//  start to the given index.
		// It will regrow or shrink the array as 
		//  needed.

		void swapWith(T value, int index);
		// Function to swap the value at a given 
		//  index with the given new value.

		void swapAll(T newValue, T oldValue);
		// Function to swap all occurances of a 
		//  value with a new given value.

		T* slice(int startIndex, int endIndex) const;
		// Function to return a subarray of the 
		//  array from given starting and ending
		//  point.
		// The returned array will be built-in
		//  array.

		void join(const Array<T> &other);
		// Function to join the array with given 
		//  new array.
		// The new array will be added to the end.

		int searchByValue(T value) const;
		// Function to search given value in array.
		// If Present it will return the index.
		// If not, it will return -1 with 
		//  displaying not found.

		void insertAtStart(T element);
		// Function to insert element at the start
		//  of the array.

		void insertAtIndex(T element, int index);
		// Function to insert element at an index
		//  given by the user.

		void insertAtEnd(T element);
		// Function to insert element at the end of
		//  the array.

		T deleteFirst();
		// Function to delete first element of the 
		//  array.

		T deleteLast();
		// Function to delete last element of the 
		//  array.

		T deleteAtIndex(int index);
		// Function to delete element of the array 
		//  at index given by the user.
		// If not present, it will print index
		//  not found.
		
		void deleteByValue(T value);
		// Function to delete the user given value 
		//  in the array.
		// If not present, it will print value
		//  not found.

		static Array<T> toArray(T other[], int arraySize);
		// Function to convert a built-in array to 
		//  this Array data structure.

	private:
		
		friend std::ostream& operator<< (
			std::ostream &out, 
			const Array<T> &arr
		);
		// Function to overload insertion 
		//  operators to display the array in 
		//  default format i.e. 
		//  [t1, t2, t3]

		friend std::istream& operator>> (
					std::istream &in, 
					Array<T> &arr
				);
		// Function to overload extraction operators
		//  to take input from user.
	
		T *arr;
		int size;
		bool isSorted;

};

template<class T>
std::istream& operator>> (
		std::istream& in, 
		Array<T> &arr
		);

template<class T>
std::ostream& operator<< (
		std::ostream& out, 
		const Array<T> &arr
		);

#include "../Implementations/ArraysImpl.cpp"

#endif
