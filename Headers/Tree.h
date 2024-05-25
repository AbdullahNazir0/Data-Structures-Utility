// ********************************************************
// Programmer: Abdullah Nazir
// Date: May 25, 2024
//
// Abstract Class Tree
// This class contains members and methods to implement
// data structure Tree abstract class. This class
// will be extended to Binary, Binary Search, AVL and
// Red-Black trees.
// ********************************************************

#ifndef H_Tree
#define H_Tree

#include "TreeNode.h"

template <typename T>
class Tree
{
public:
    Tree();
    virtual void insert(TreeNode<T> *) = 0;
    virtual void insert(const T &) = 0;
    virtual void remove(const T &) = 0;
    virtual void remove(TreeNode<T> *) = 0;
    virtual void displayInOrder() const = 0;
    virtual void displayPreOrder() const = 0;
    virtual void displayPostOrder() const = 0;
    T getRoot() const;
    bool isEmpty() const;
    ~Tree();

protected:
    TreeNode<T> *root;
};

#include "../Implementations/TreeImpl.cpp"

#endif // H_Tree