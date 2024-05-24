// ********************************************************
// Programmer: Abdullah Nazir
// Date: May 24, 2024
//
// class TreeNode
// This class inherits from abstract class Node.
// It has an additional left and right pointer to point
// to its child nodes
// This class will be used to implement Binary Trees and
// Binary Search Trees.
// ********************************************************

#ifndef H_TreeNode
#define H_TreeNode

#include "Node.h"

template <typename T>
class TreeNode : public Node<T>
{
public:
    TreeNode()
        : Node<T>(T()),
          left(nullptr),
          right(nullptr) {}
    // Default constructor.

    TreeNode(const T &value)
        : Node<T>(value),
          left(nullptr),
          right(nullptr) {}
    // Parameterized constructor.

    TreeNode<T> *left;
    TreeNode<T> *right;
};

#endif // H_TreeNode