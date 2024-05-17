// ********************************************************
// Programmer: Abdullah Nazir
// Date: April 07, 2024

// Implementation file TowerOfHanoiImpl.cpp
// This file contains definitions for the functions used
//  in the implementation of tower of hanoi.
// ********************************************************

#include "TowerOfHanoi.h"

template <typename T>
void towerOfHanoi(int numberOfDisks, ArrayStack<T> &source, ArrayStack<T> &auxiliary, ArrayStack<T> &destination)
{
    if (numberOfDisks == 1)
        destination.push(source.pop());
    else
    {
        towerOfHanoi(numberOfDisks - 1, source, auxiliary, destination);
        destination.push(source.pop());
        towerOfHanoi(numberOfDisks - 1, auxiliary, destination, source);
    }
}