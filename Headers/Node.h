// ********************************************************
// Programmer: Abdullah Nazir
// Date: April 20, 2024
//
// class Node
// This class contains a data to hold data for
// the node. This class is an abstract class.
// This node concrete classes will be used to implement
// Linked Lists.
// ********************************************************

#ifndef H_Node
#define H_Node

template <typename T>
class Node
{
public:
    Node() : data(T()) {}
    // Default constructor.

    Node(const T &value)
    {
        data = value;
    }
    // Parameterized constructor.

    virtual ~Node() {}
    // Virtual destructor.

    T data;
};

#endif // H_Node