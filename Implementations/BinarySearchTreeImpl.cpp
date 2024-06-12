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
BinarySearchTree<T>::BinarySearchTree() {} // default constructor.

template <typename T>
void BinarySearchTree<T>::insert(TreeNode<T> *valueNode)
{
    if (!valueNode)
    {
        std::cout << "Cannot insert empty node.\n";
        return;
    }

    if (!this->root)
    {
        this->root = valueNode;
        return;
    }

    if (valueNode->data < this->root->data)
        subInsert(this->root->left, valueNode);
    else
        subInsert(this->root->right, valueNode);
}

template <typename T>
void BinarySearchTree<T>::insert(const T &value)
{
    TreeNode<T> *valueNode = new TreeNode<T>(value);

    insert(valueNode);
}

template <typename T>
void BinarySearchTree<T>::remove(const T &value)
{
    TreeNode<T> *valueNode = new TreeNode<T>(value);

    remove(valueNode);
}

template <typename T>
void BinarySearchTree<T>::remove(TreeNode<T> *valueNode)
{
    if (!valueNode)
    {
        std::cout << "Invalid node to delete.\n";
        return;
    }

    if (!this->root)
    {
        std::cout << "Cannot delete from empty tree.\n";
        return;
    }

    if (this->root->data == valueNode->data)
    {
        if (!this->root->left && !this->root->right)
        {
            delete (this->root);
            this->root = nullptr;
        }
        else if (!this->root->left && this->root->right)
        {
            TreeNode<T> *toDelete = this->root;
            this->root = this->root->right;
            delete (toDelete);
        }
        else if (this->root->left && !this->root->right)
        {
            TreeNode<T> *toDelete = this->root;
            this->root = this->root->left;
            delete (toDelete);
        }
        else
        {
            TreeNode<T> *ancestor = this->root;
            TreeNode<T> *current = this->root->right;
            if (current->left)
            {
                while (current->left)
                {
                    ancestor = current;
                    current = current->left;
                }

                if (current->right)
                    ancestor->left = current->right;
                else
                    ancestor->left = nullptr;
            }
            else
            {
                current = this->root->right;
                this->root->right = current->right;
                current->right = this->root->right;
            }

            current->left = this->root->left;
            current->right = this->root->right;

            delete (this->root);
            this->root = current;
        }
    }
    else if (this->root->data < valueNode->data)
        subRemove(this->root->right, valueNode);
    else
        subRemove(this->root->left, valueNode);
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

template <typename T> // destructor.
BinarySearchTree<T>::~BinarySearchTree()
{
    if (this->root == nullptr)
        return;

    destroyTree(this->root);
}

// private functions.
template <typename T>
void BinarySearchTree<T>::subInsert(TreeNode<T> *&node, TreeNode<T> *valueNode)
{
    if (!node)
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
void BinarySearchTree<T>::subRemove(TreeNode<T> *&node, TreeNode<T> *nodeToDelete)
{
    if (!node)
        return;

    if (node->data == nodeToDelete->data)
    {
        if (!node->left && !node->right)
        {
            delete (node);
            node = nullptr;
        }
        else if (node->left && !node->right)
        {
            TreeNode<T> *toDelete = node;
            node = node->left;
            delete (toDelete);
        }
        else if (!node->left && node->right)
        {
            TreeNode<T> *toDelete = node;
            node = node->right;
            delete (toDelete);
        }
        else
        {
            TreeNode<T> *ancestor = node;
            TreeNode<T> *current = node->right;
            if (current->left)
            {
                while (current->left)
                {
                    ancestor = current;
                    current = current->left;
                }

                if (current->right)
                    ancestor->left = current->right;
                else
                    ancestor->left = nullptr;
            }
            else
            {
                current = node->right;
                node->right = current->right;
                current->right = node->right;
            }

            current->left = node->left;
            current->right = node->right;

            delete (node);
            node = current;
        }
    }
    else if (node->data < nodeToDelete->data)
        subRemove(node->right, nodeToDelete);
    else
        subRemove(node->left, nodeToDelete);
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

template <typename T>
void BinarySearchTree<T>::destroyTree(TreeNode<T> *node)
{
    if (!node)
        return;

    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
    node = nullptr;
}