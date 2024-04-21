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
};

#endif // H_Node