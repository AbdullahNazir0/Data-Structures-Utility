// ********************************************************
// Name: Abdullah Nazir
// Date: April 20, 2024
//
// Implementation file TreeImpl.cpp
// This file contains definitions of the functions declared
//  in the abstract class Tree .
// ********************************************************

#include "../Headers/Tree.h"

template <typename T>
Tree<T>::Tree() : root(nullptr) {}

template <typename T>
T Tree<T>::getRoot() const
{
    return (root->data);
}

template <typename T>
bool Tree<T>::isEmpty() const
{
    return (root == nullptr);
}

template <typename T>
Tree<T>::~Tree() {}