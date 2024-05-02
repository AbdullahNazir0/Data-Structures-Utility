// ********************************************************
// Programmer: Abdullah Nazir
// Date: April 20, 2024
//
// Struct Node
// This struct contains a data to hold data and a
// next pointer to store address of next node.
// This node will be used to implement Linked Lists.
// ********************************************************

#ifndef H_Node
#define H_Node

template <class T>
struct Node
{
    T data;
    Node *next;

    Node(const T &value)
    {
        data = value;
        next = nullptr;
    }
    virtual Node<T> *getPrev() const
    {
        return nullptr; // Default implementation for regular nodes
    }
    virtual void setPrev(Node<T> *value) {}
};

#endif // H_Node