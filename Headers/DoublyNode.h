// ********************************************************
// Programmer: Abdullah Nazir
// Date: April 30, 2024
//
// Struct DoublyNode
// This struct inherits from Node that contains data and a
// pointer to next node. This struct also has a extra
// pointer to store address of next node.
// This node will be used to implement Doubly Linked List.
// ********************************************************

#ifndef H_DoublyNode
#define H_DoublyNode

#include "Node.h"

template <typename T>
struct DoublyNode : public Node<T>
{
    Node<T> *prev;

    DoublyNode(const T &value) : Node<T>(value)
    {
        prev = nullptr;
    }
    // Override getPrev to return the correct prev pointer
    virtual Node<T> *getPrev() const override
    {
        return prev;
    }
    virtual void setPrev(Node<T> *value) override
    {
        prev = value;
    }
};

#endif