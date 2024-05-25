// ********************************************************
// Programmer: Abdullah Nazir
// Date: May 25, 2024
//
// Implementation file BinaryTreeImpl.cpp
// This file contains implementations of the functions
//  declared in the class BinaryTree .
// ********************************************************

#include "../Headers/BinaryTree.h"
#include <iostream>

template <typename T>
BinaryTree<T>::BinaryTree() {}

template <typename T>
void BinaryTree<T>::insert(TreeNode<T> *valueNode)
{
    if (!valueNode)
    {
        std::cout << "Can't insert empty node.\n";
        return;
    }

    subInsert(root, valueNode);
}

template <typename T>
void BinaryTree<T>::insert(const T &value)
{
    TreeNode<T> *valueNode = new TreeNode<T>(value);

    insert(valueNode);
}

template <typename T>
void BinaryTree<T>::remove(const T &) {}

template <typename T>
void BinaryTree<T>::remove(TreeNode<T> *) {}

template <typename T>
void BinaryTree<T>::displayInOrder() const {}

template <typename T>
void BinaryTree<T>::displayPreOrder() const {}

template <typename T>
void BinaryTree<T>::displayPostOrder() const {}

template <typename T>
BinaryTree<T>::~BinaryTree() {}

template <typename T>
void BinaryTree<T>::subInsert(TreeNode<T> *&node, TreeNode<T> *&valueNode)
{
    if (node == nullptr)
    {
        node = valueNode;
        valueNode = nullptr; // Taking ownership.
        return;
    }
    else
    {
        if (node->left == nullptr)
        {
            node->left = valueNode;
            valueNode = nullptr; // Taking ownership.
            return;
        }
        else if (node->right == nullptr)
        {
            node->right = valueNode;
            valueNode = nullptr; // Taking ownership.
            return;
        }
        else
        {
            
        }
    }
}