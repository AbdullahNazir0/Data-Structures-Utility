// ********************************************************
// Programmer: Abdullah Nazir
// Date: July 05, 2024
//
// Implementation file AVLTreeImpl.cpp
// This file contains implementations of the functions
//  declared in the class AVLTree .
// ********************************************************

#include "../Headers/AVLTree.h"
#include <iostream>

int maxInt(int a, int b)
{
    return (a > b ? a : b);
}

int maxInt(int a, int b, int c)
{
    return (maxInt(maxInt(a, b), c));
}

template <typename T>
AVLTree<T>::AVLTree()
{
    this->root = nullptr;
}

template <typename T>
void AVLTree<T>::insert(TreeNode<T> *valueNode)
{
    if (!this->root)
    {
        this->root = valueNode;
        return;
    }

    helpInsert(this->root, valueNode);
}

template <typename T>
void AVLTree<T>::insert(const T &value)
{
    TreeNode<T> *valueNode = new TreeNode<T>(value);

    if (!this->root)
    {
        this->root = valueNode;
        return;
    }

    helpInsert(this->root, valueNode);
}

template <typename T>
void AVLTree<T>::remove(const T &value)
{
    if (!this->root)
    {
        std::cout << "Cannot remove, AVL Tree is empty.\n";
        return;
    }

    helpRemove(this->root, value);
}

template <typename T>
void AVLTree<T>::remove(TreeNode<T> *valueNode)
{
    if (!valueNode)
    {
        std::cout << "Cannot insert empty node.\n";
        return;
    }

    if (!this->root)
    {
        std::cout << "Cannot remove, AVL Tree is empty.\n";
        return;
    }

    helpRemove(this->root, valueNode->data);
}

template <typename T>
void AVLTree<T>::displayInOrder() const
{
    if (!this->root)
    {
        std::cout << "AVL Tree is empty.\n";
        return;
    }

    inorder(this->root);
    std::cout << "\n";
}

template <typename T>
void AVLTree<T>::displayPreOrder() const
{
    if (!this->root)
    {
        std::cout << "AVL Tree is empty.\n";
        return;
    }

    preorder(this->root);
    std::cout << "\n";
}

template <typename T>
void AVLTree<T>::displayPostOrder() const
{
    if (!this->root) // this->root == nullptr
    {
        std::cout << "AVL Tree is empty.\n";
        return;
    }

    postorder(this->root);
    std::cout << "\n";
}

template <typename T>
void AVLTree<T>::searchValue(const T &value) const
{
    if (!this->root)
    {
        std::cout << "Cannot search empty AVL Tree.\n";
        return;
    }

    search(this->root, value);
}

template <typename T>
int AVLTree<T>::getTreeHeight() const
{
    return (nodeHeight(this->root));
}

template <typename T>
int AVLTree<T>::getNodeHeight(const T &value) const
{
    if (!this->root)
        return (-1);

    TreeNode<T> *node = searchNode(this->root, value);

    if (!node)
        return (-1);
    else
        return (nodeHeight(node));
}

template <typename T>
void AVLTree<T>::getMin() const
{
    if (!this->root)
    {
        std::cout << "No minimum, AVL Tree is empty.\n";
        return;
    }

    min(this->root);
}

template <typename T>
void AVLTree<T>::getMax() const
{
    if (!this->root)
    {
        std::cout << "No maximum, AVL Tree is empty.\n";
        return;
    }

    max(this->root);
}

template <typename T>
void AVLTree<T>::getSuccessor(const T &value) const
{
    TreeNode<T> *succ = successor(this->root, value);
    if (succ)
        std::cout << "Successor of " << value << " is " << succ->data << ".\n";
    else
        std::cout << "No successor for " << value << " in AVL Tree.\n";
}

template <typename T>
void AVLTree<T>::getPredecessor(const T &value) const
{
    TreeNode<T> *pred = predecessor(this->root, value);
    if (pred)
        std::cout << "Predecessor of " << value << " is " << pred->data << ".\n";
    else
        std::cout << "No predecessor for " << value << " in AVL Tree.\n";
}

template <typename T>
int AVLTree<T>::getDiameter() const
{
    if (!this->root)
        return (-1);

    return (diameter(this->root));
}

template <typename T>
AVLTree<T>::~AVLTree()
{
    if (!this->root)
        return;

    destroyTree(this->root);
}

// private functions definition
template <typename T>
void AVLTree<T>::helpInsert(TreeNode<T> *&node, TreeNode<T> *valueNode)
{
    if (!node) // base case
    {
        node = valueNode;
        return;
    }

    if (node->data > valueNode->data)
        helpInsert(node->left, valueNode);
    else if (node->data < valueNode->data)
        helpInsert(node->right, valueNode);
    else
    {
        std::cout << "Cannot insert duplicate value in AVL Tree.\n";
        return;
    }

    int balanceFactor = findBalanceFactor(node);

    // left left case
    if (balanceFactor > 1 && valueNode->data < node->left->data)
        rightRotate(node);

    // right right case
    if (balanceFactor < -1 && valueNode->data > node->right->data)
        leftRotate(node);

    // left right case
    if (balanceFactor > 1 && valueNode->data > node->left->data)
        leftRightRotate(node);

    // right left case
    if (balanceFactor < -1 && valueNode->data < node->right->data)
        rightLeftRotate(node);
}

template <typename T>
void AVLTree<T>::helpRemove(TreeNode<T> *&node, const T &value)
{
    if (!node)
        return;

    if (node->data > value) // root checker
        helpRemove(node->left, value);
    else if (node->data < value)
        helpRemove(node->right, value);
    else
    {
        if (!node->left && !node->right) // if leaf node
        {
            if (node == this->root)
                this->root = nullptr;
            delete (node);
            node = nullptr;
        }
        else if (node->left && !node->right) // if one child
        {
            if (node == this->root)
                this->root = node->left;
            TreeNode<T> *nodeToDelete = node;
            node = node->left;
            delete (nodeToDelete);
        }
        else if (!node->left && node->right) // if one child
        {
            if (node == this->root)
                this->root = node->right;
            TreeNode<T> *nodeToDelete = node;
            node = node->right;
            delete (nodeToDelete);
        }
        else // if two child
        {
            TreeNode<T> *successor = node->right;
            while (successor->left)
                successor = successor->left;

            node->data = successor->data;
            helpRemove(node->right, successor->data);
        }
    }

    if (!node) // if tree had only one node.
        return;

    int balanceFactor = findBalanceFactor(node);

    // left left case
    if (balanceFactor > 1 && findBalanceFactor(node->left) >= 0)
        rightRotate(node);

    // right right case
    if (balanceFactor < -1 && findBalanceFactor(node->left) < 0)
        leftRotate(node);

    // left right case
    if (balanceFactor > 1 && findBalanceFactor(node->right) <= 0)
        leftRightRotate(node);

    // right left case
    if (balanceFactor < -1 && findBalanceFactor(node->right) > 0)
        rightLeftRotate(node);
}

template <typename T>
void AVLTree<T>::inorder(TreeNode<T> *node) const
{
    if (!node)
        return;

    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

template <typename T>
void AVLTree<T>::preorder(TreeNode<T> *node) const
{
    if (!node)
        return;

    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

template <typename T>
void AVLTree<T>::postorder(TreeNode<T> *node) const
{
    if (!node)
        return;

    postorder(node->left);
    postorder(node->right);
    std::cout << node->data << " ";
}

template <typename T>
TreeNode<T> *AVLTree<T>::searchNode(TreeNode<T> *node, const T &value) const
{
    if (!node)
        return (nullptr);

    if (node->data == value)
        return (node);
    else if (node->data > value)
        searchNode(node->left, value);
    else
        searchNode(node->right, value);
}

template <typename T>
int AVLTree<T>::nodeHeight(TreeNode<T> *node) const
{
    if (!node)
        return (-1);
    // if you want to calculate height acc to number of nodes instead of edges, return (0);

    int leftHeight = nodeHeight(node->left);
    int rightHeight = nodeHeight(node->right);

    if (leftHeight >= rightHeight)
        return (leftHeight + 1);
    else
        return (rightHeight + 1);
}

template <typename T>
void AVLTree<T>::search(TreeNode<T> *node, const T &value) const
{
    if (!node)
        return;

    if (node->data == value)
        std::cout << value << " found in AVL Tree.\n";
    else if (node->data > value)
        search(node->left, value);
    else
        search(node->right, value);
}

template <typename T>
int AVLTree<T>::findBalanceFactor(TreeNode<T> *node) const
{
    if (!node)
        return (0);

    return (nodeHeight(node->left) - nodeHeight(node->right));
}

template <typename T>
void AVLTree<T>::leftRotate(TreeNode<T> *&node)
{
    if (!node)
        return;

    TreeNode<T> *pivot = node->right;
    TreeNode<T> *subTree = pivot->left;

    pivot->left = node;
    node->right = subTree;

    if (node == this->root)
        this->root = pivot;

    node = pivot;
}

template <typename T>
void AVLTree<T>::rightRotate(TreeNode<T> *&node)
{
    if (!node)
        return;

    TreeNode<T> *pivot = node->left;
    TreeNode<T> *subTree = pivot->right;

    pivot->right = node;
    node->left = subTree;

    if (node == this->root)
        this->root = pivot;

    node = pivot;
}

template <typename T>
void AVLTree<T>::leftRightRotate(TreeNode<T> *&node)
{
    if (!node)
        return;

    leftRotate(node->left);
    rightRotate(node);
}

template <typename T>
void AVLTree<T>::rightLeftRotate(TreeNode<T> *&node)
{
    if (!node)
        return;

    rightRotate(node->right);
    leftRotate(node);
}

template <typename T>
void AVLTree<T>::min(TreeNode<T> *node) const
{
    if (!node->left)
    {
        std::cout << "The minimum is " << node->data << "\n";
        return;
    }

    return (min(node->left));
}

template <typename T>
void AVLTree<T>::max(TreeNode<T> *node) const
{
    if (!node->right)
    {
        std::cout << "The maximum is " << node->data << "\n";
        return;
    }

    return (max(node->right));
}

template <typename T>
TreeNode<T> *AVLTree<T>::successor(TreeNode<T> *node, const T &value) const
{
    if (!node)
        return (nullptr);

    if (node->data <= value)
        return (successor(node->right, value));
    else
    {
        TreeNode<T> *leftSuccessor = successor(node->left, value);
        return (leftSuccessor ? leftSuccessor : node);
    }
}

template <typename T>
TreeNode<T> *AVLTree<T>::predecessor(TreeNode<T> *node, const T &value) const
{
    if (!node)
        return (nullptr);

    if (node->data >= value)
        return (predecessor(node->left, value));
    else
    {
        TreeNode<T> *rightPredecessor = predecessor(node->right, value);
        return (rightPredecessor ? rightPredecessor : node);
    }
}

template <typename T>
int AVLTree<T>::diameter(TreeNode<T> *node) const
{
    if (!node)
        return (0);

    int leftHeight = nodeHeight(node->left);
    int rightHeight = nodeHeight(node->right);

    int leftDiameter = diameter(node->left);
    int rightDiameter = diameter(node->right);

    int rootDiameter = leftHeight + rightHeight + 1;

    return maxInt(leftDiameter, rightDiameter, rootDiameter);
}

template <typename T>
void AVLTree<T>::destroyTree(TreeNode<T> *&node)
{
    if (!node)
        return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete (node);
    node = nullptr;
}