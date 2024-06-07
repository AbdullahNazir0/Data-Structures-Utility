// ********************************************************
// Programmer: Abdullah Nazir
// Date: June 02, 2024
//
// Implementation file BinarySearchTreeImpl.cpp
// This file contains implementations of the functions
//  declared in the class BinarySearchTree .
// ********************************************************

#include "../Headers/BinarySearchTree.h"
#include <iostream>

// public functions.
template <typename T>
BinarySearchTree<T>::BinarySearchTree() {}
template <typename T>
void BinarySearchTree<T>::insert(TreeNode<T> *valueNode)
{
    if (valueNode == nullptr)
    {
        std::cout << "Cannot insert empty node.\n";
        return;
    }
    if (this->root == nullptr)
    {
        this->root = valueNode;
        return;
    }

    subInsert(this->root, valueNode);
}
template <typename T>
void BinarySearchTree<T>::insert(const T &value)
{
    TreeNode<T> *valueNode = new TreeNode<T>(value);

    insert(valueNode);
}
template <typename T>
void BinarySearchTree<T>::remove(const T &)
{
}
template <typename T>
void BinarySearchTree<T>::remove(TreeNode<T> *)
{
}
template <typename T>
void BinarySearchTree<T>::displayInOrder() const
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
void BinarySearchTree<T>::displayPreOrder() const
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
void BinarySearchTree<T>::displayPostOrder() const
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
BinarySearchTree<T>::~BinarySearchTree()
{
    if (this->root == nullptr)
        return;
}

// private functions.
template <typename T>
void BinarySearchTree<T>::subInsert(TreeNode<T> *node, TreeNode<T> *valueNode)
{
    if (node == nullptr)
    {
        node = valueNode;
        return;
    }

    if (valueNode->data < node->data)
        subInsert(node->left, valueNode);
    else if (valueNode->data > node->data)
        subInsert(node->right, valueNode);
    else
    {
        std::cout << "Cannot insert duplicate value in binary search tree.\n";
        return;
    }
}
template <typename T>
void BinarySearchTree<T>::subRemove(TreeNode<T> *node, TreeNode<T> *nodeToDelete)
{
}
template <typename T>
void BinarySearchTree<T>::inOrder(TreeNode<T> *node) const
{
    if (node == nullptr)
        return;

    inOrder(node->left);
    std::cout << node->data << " ";
    inOrder(node->right);
}
template <typename T>
void BinarySearchTree<T>::preOrder(TreeNode<T> *node) const
{
    if (node == nullptr)
        return;

    std::cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}
template <typename T>
void BinarySearchTree<T>::postOrder(TreeNode<T> *node) const
{
    if (node == nullptr)
        return;

    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->data << " ";
}