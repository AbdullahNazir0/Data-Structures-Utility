// ********************************************************
// Programmer: Abdullah Nazir
// Date: April 20, 2024
//
// Abstract Class LinkedList
// This class contains members and methodsto implement
// data structure linked list abstract class. This class
// will be extended to SinglyLinkedList, DoublyLinkedList
// and CircularLinkedList.
// ********************************************************

#ifndef H_LinkedList
#define H_LinkedList

#include "Node.h"

template <class T>
class LinkedList
{
public:
    LinkedList();
    // Default constructor function for LinkedList.

    virtual void display() const = 0;
    // Pure virtual function to display all contents of
    //  the linked list.
    // It will be implemented in the concrete class.

    virtual void displayFormatted() const = 0;
    // Pure virtual function to display the contents of
    //  the linked list with formatting.
    // It will be implemented in the concrete class.

    virtual void displayReversed() const = 0;
    // Pure virtual function to display the contents of
    //  the linked list in reverse order.
    // It will be implemented in the concrete class.

    virtual void displayAtIndex(int) = 0;
    // Pure virtual function to display the element at a
    //  specific index in the linked list.
    // It will be implemented in the concrete class.

    // Insertions
    virtual void insertAtStart(T) = 0;
    // Pure virtual function to insert a value at the
    //  beginning of the linked list.
    // It will be implemented in the concrete class.

    virtual void insertAtStart(Node *) = 0;
    // Pure virtual function to insert a node at the
    //  beginning of the linked list.
    // It will be implemented in the concrete class.

    virtual void insertAtEnd(T) = 0;
    // Pure virtual function to insert a value at the
    //  end of the linked list.
    // It will be implemented in the concrete class.

    virtual void insertAtEnd(Node *) = 0;
    // Pure virtual function to insert a node at the
    //  end of the linked list.
    // It will be implemented in the concrete class.

    virtual void insertAtIndex(T, int) = 0;
    // Pure virtual function to insert a value at a
    //  specific index in the linked list.
    // It will be implemented in the concrete class.

    virtual void insertAtIndex(Node *, int) = 0;
    // Pure virtual function to insert a node at a
    //  specific index in the linked list.
    // It will be implemented in the concrete class.

    virtual void insertBeforeNode(T, Node *) = 0;
    // Pure virtual function to insert a value before
    //  a specific node in the linked list.
    // It will be implemented in the concrete class.

    virtual void insertBeforeNode(Node *, Node *) = 0;
    // Pure virtual function to insert a node before a
    //  specific node in the linked list.
    // It will be implemented in the concrete class.

    virtual void insertAfterNode(T, Node *) = 0;
    // Pure virtual function to insert a value after a
    //  specific node in the linked list.
    // It will be implemented in the concrete class.

    virtual void insertAfterNode(Node *, Node *) = 0;
    // Pure virtual function to insert a node after a
    //  specific node in the linked list.
    // It will be implemented in the concrete class.

    virtual void insertMultiple(T *, int) = 0;
    // Pure virtual function to insert multiple values
    //  into the linked list.
    // It will be implemented in the concrete class.

    virtual void insertMultiple(Node *, int) = 0;
    // Pure virtual function to insert multiple nodes
    //  into the linked list.
    // It will be implemented in the concrete class.

    virtual void deleteFirst() = 0;
    // Pure virtual function to delete the first node
    //  from the linked list.
    // It will be implemented in the concrete class.

    virtual void deleteLast() = 0;
    // Pure virtual function to delete the last node
    //  from the linked list.
    // It will be implemented in the concrete class.

    virtual void deleteFromIndex(int) = 0;
    // Pure virtual function to delete a node at a
    //  specific index from the linked list.
    // It will be implemented in the concrete class.

    virtual void deleteByValue(T) = 0;
    // Pure virtual function to delete the first node
    //  with a specific value from the linked list.
    // It will be implemented in the concrete class.

    virtual void deleteAllByValue(T) = 0;
    // Pure virtual function to delete all nodes with a
    //  specific value from the linked list.
    // It will be implemented in the concrete class.

    virtual void deleteBeforeNode(Node *) = 0;
    // Pure virtual function to delete the node before a
    //  specific node from the linked list.
    // It will be implemented in the concrete class.

    virtual void deleteAfterNode(Node *) = 0;
    // Pure virtual function to delete the node after a
    //  specific node from the linked list.
    // It will be implemented in the concrete class.

    virtual void clear() = 0;
    // Pure virtual function to clear the linked list
    //  (remove all nodes but keep the list structure).
    // It will be implemented in the concrete class.

    virtual void deleteList() = 0;
    // Pure virtual function to delete the entire linked
    //  list (remove all nodes and deallocate memory).
    // It will be implemented in the concrete class.

    virtual void deleteRange(int, int) = 0;
    // Pure virtual function to delete nodes within a
    //  specified range of indices from the linked list.
    // It will be implemented in the concrete class.

    ~LinkedList();
    // Destructor Function for LinkedList.

protected:
    Node *head;
};

#include "../Implementations/LinkedListImpl.cpp"

#endif // H_LinkedList
