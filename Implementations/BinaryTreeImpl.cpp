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
#include "../Headers/ArrayQueue.h" // for level-order insertion.

template <typename T>
BinaryTree<T>::BinaryTree()
{
    this->root = nullptr;
}

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

    helpInsert(this->root, valueNode);
}

template <typename T>
void BinaryTree<T>::insert(const T &value)
{
    TreeNode<T> *valueNode = new TreeNode<T>(value);

    insert(valueNode);
}

template <typename T>
void BinaryTree<T>::remove(const T &value)
{
    if (!this->root)
    {
        std::cout << "Cannot delete, binary tree is empty.\n";
        return;
    }

    helpRemove(this->root, value);
}

template <typename T>
void BinaryTree<T>::remove(TreeNode<T> *valueNode)
{
    if (!valueNode)
    {
        std::cout << "Cannot delete empty node.\n";
        return;
    }

    if (!this->root)
    {
        std::cout << "Cannot delete, binary tree is empty.\n";
        return;
    }

    helpRemove(this->root, valueNode->data);
}

template <typename T>
void BinaryTree<T>::displayInOrder() const
{
    if (this->root == nullptr)
    {
        std::cout << "Binary Tree is empty.\n";
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
        std::cout << "Binary Tree is empty.\n";
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
        std::cout << "Binary Tree is empty.\n";
        return;
    }

    postOrder(this->root);
    std::cout << "\n";
}

template <typename T>
int BinaryTree<T>::getTreeHeight() const
{
    if (!this->root)
        return (-1);

    return (treeHeight(this->root));
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    destroyTree(this->root);
}

// Private Functions.

template <typename T>
void BinaryTree<T>::helpInsert(TreeNode<T> *&node, TreeNode<T> *valueNode)
{
    if (!node)
    {
        node = valueNode;
        return;
    }

    ArrayQueue<TreeNode<T> *> queue;
    queue.enqueue(node);
    while (!queue.isEmpty())
    {
        TreeNode<T> *temp = queue.getFront();
        queue.dequeue();

        if (temp->left != nullptr)
            queue.enqueue(temp->left);
        else
        {
            temp->left = valueNode;
            return;
        }

        if (temp->right != nullptr)
            queue.enqueue(temp->right);
        else
        {
            temp->right = valueNode;
            return;
        }
    }
}

template <typename T>
void BinaryTree<T>::helpRemove(TreeNode<T> *&node, const T &value)
{
    if (!node)
        return;
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

template <typename T>
int BinaryTree<T>::treeHeight(TreeNode<T> *node) const
{
    if (!node)
        return (-1);

    int leftHeight = treeHeight(node->left);
    int rightHeight = treeHeight(node->right);

    return ((leftHeight > rightHeight ? leftHeight : rightHeight));
}

template <typename T>
void BinaryTree<T>::destroyTree(TreeNode<T> *&node)
{
    if (!node)
        return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete (node);
    node = nullptr;
}