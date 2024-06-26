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

    if (!this->root)
    {
        this->root = valueNode;
        return;
    }

    subInsert(temp, valueNode);
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
void BinaryTree<T>::displayInOrder() const
{
    if (this->root == nullptr)
    {
        std::cout << "Tree is empty.\n";
        return;
    }

    inOrder(this->root);
    std::cout << "\n";
}

template <typename T>
void BinaryTree<T>::displayPreOrder() const
{
    if (this->root == nullptr)
    {
        std::cout << "Tree is empty.\n";
        return;
    }

    preOrder(this->root);
    std::cout << "\n";
}

template <typename T>
void BinaryTree<T>::displayPostOrder() const
{
    if (this->root == nullptr)
    {
        std::cout << "Tree is empty.\n";
        return;
    }

    postOrder(this->root);
    std::cout << "\n";
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    if (this->root == nullptr)
        return;
}

// Private Functions.

template <typename T>
void BinaryTree<T>::subInsert(TreeNode<T> *node, TreeNode<T> *valueNode)
{
    if (!node)
    {
        node = valueNode;
        return;
    }
    if (!node->left)
    {
        node->left = valueNode;
        return;
    }
    if (!node->right)
    {
        node->right = valueNode;
        return;
    }
    subInsert(node->left, valueNode);
    subInsert(node->right, valueNode);
}

template <typename T>
void BinaryTree<T>::inOrder(TreeNode<T> *node) const
{
    if (node == nullptr)
        return;

    inOrder(node->left);
    std::cout << node->data << " ";
    inOrder(node->right);
}

template <typename T>
void BinaryTree<T>::preOrder(TreeNode<T> *node) const
{
    if (node == nullptr)
        return;

    std::cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

template <typename T>
void BinaryTree<T>::postOrder(TreeNode<T> *node) const
{
    if (node == nullptr)
        return;

    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->data << " ";
}