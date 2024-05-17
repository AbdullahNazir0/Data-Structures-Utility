// ********************************************************
// Programmer: Abdullah Nazir
// Date: April 07, 2024

// Functions for Tower of Hanoi
// This file contains prototypes for the functions used
//  in the implementation of tower of hanoi.
// ********************************************************

#ifndef H_TowerOfHanoi
#define H_TowerOfHanoi

#include "../../Headers/ArrayStack.h"

template <typename T>
void towerOfHanoi(int, ArrayStack<T> &, ArrayStack<T> &, ArrayStack<T> &);

#include "TowerOfHanoiImpl.cpp"

#endif