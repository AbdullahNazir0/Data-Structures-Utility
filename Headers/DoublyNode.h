// ********************************************************
// Programmer: Abdullah Nazir
// Date: May 21, 2024
//
// class DoublyNode
// This class inherits from abstract class Node.
// It has an additional next and prev pointer to store the
// address of next and previous Nodes.
// This class will be used to implement DoublyLinkedList
// class.
// ********************************************************

#ifndef H_DoublyNode
#define H_DoublyNode

#include "Node.h"

template <typename T>
class DoublyNode : public Node<T>
{
public:
    DoublyNode()
        : Node<T>(T()),
          next(nullptr),
          prev(nullptr) {}
    // Default constructor.

    DoublyNode(const T &value)
        : Node<T>(value),
          next(nullptr),
          prev(nullptr) {}
    // Parameterized constructor.

    DoublyNode *next;
    DoublyNode *prev;
};

#endif