// ********************************************************
// Programmer: Abdullah Nazir
// Date: May 21, 2024
//
// class SinglyNode
// This class inherits from abstract class Node.
// It has an additional next pointer to store the
// address of next Node.
// This class will be used to implement SinglyLinkedList
// and CircularLinkedList class.
// ********************************************************

#ifndef H_SinglyNode
#define H_SinglyNode

#include "Node.h"

template <typename T>
class SinglyNode : public Node<T>
{
public:
    SinglyNode()
        : Node<T>(T()),
          next(nullptr) {}
    // Default constructor.

    SinglyNode(const T &value)
        : Node<T>(value),
          next(nullptr) {}
    // Parameterized constructor.

    SinglyNode *next;
};

#endif