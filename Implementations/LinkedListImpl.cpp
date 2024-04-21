// ********************************************************
// Name: Abdullah Nazir
// Date: April 20, 2024
//
// Implementation file LinkedListImpl.cpp
// This file contains definitions of the functions declared
//  in the abstract class LinkedList .
// ********************************************************

#include "../Headers/LinkedList.h"

template <class T>
LinkedList<T>::LinkedList()
{
    this->head = nullptr;
    this->nodesCount = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    if (this->head)
        delete this->head;
}