// ********************************************************
// Programmer: Abdullah Nazir
// Date: April 30, 2024
//
// Class DoublyLinkedList
// This class contains members and methods to implement
// data structure doubly linked list. This class
// is inherited from abstract class LinkedList .
// ********************************************************

#ifndef H_DoublyLinkedList
#define H_DoublyLinkedList

#include "LinkedList.h"
#include "DoublyNode.h"

template <typename T>
class DoublyLinkedList : LinkedList<T>
{
public:
    DoublyLinkedList();
    // Default constructor for DoublyLinkedList.
    // Initializes the head tail pointer to nullptr.

    void display() const override;
    // Function to display all contents of the doubly
    //  linked list.
    // Overrides the display method of the base class.

    void displayReversed() const;
    // Function to display all contents of the doubly
    //  linked list in reverse order.

    void displayFormatted() const override;
    // Function to display the contents of the doubly
    //  linked list with formatting.
    // Overrides the displayFormatted method of the base
    //  class.

    void displayFormattedAndReversed() const;
    // Function to display all contents of the doubly
    //  linked list in reverse order with formatting.

    void displayAtIndex(int) override;
    // Function to display the element at a specific
    //  index in the doubly linked list.
    // Overrides the displayAtIndex method of the base
    //  class.

    void insertAtStart(const T &) override;
    // Function to insert a value at the beginning of
    //  the doubly linked list.
    // Overrides the insertAtStart method of the base
    //  class.

    void insertAtStart(Node<T> *) override;
    // Function to insert a node at the beginning of
    //  the doubly linked list.
    // Overrides the insertAtStart method of the base
    //  class.

    void insertAtEnd(const T &) override;
    // Function to insert a value at the end of the
    //  doubly linked list.
    // Overrides the insertAtEnd method of the base
    //  class.

    void insertAtEnd(Node<T> *) override;
    // Function to insert a node at the end of the
    //  doubly linked list.
    // Overrides the insertAtEnd method of the base
    //  class.

    void insertAtIndex(const T &, int) override;
    // Function to insert a value at a specific index
    //  in the doubly linked list.
    // Overrides the insertAtIndex method of the base
    //  class.

    void insertAtIndex(Node<T> *, int) override;
    // Function to insert a node at a specific index
    //  in the doubly linked list.
    // Overrides the insertAtIndex method of the base
    //  class.

    void insertBeforeNode(const T &, Node<T> *) override;
    // Function to insert a value before a specific
    //  node in the doubly linked list.
    // Overrides the insertBeforeNode method of the
    //  base class.

    void insertBeforeNode(Node<T> *, Node<T> *) override;
    // Function to insert a node before a specific
    //  node in the doubly linked list.
    // Overrides the insertBeforeNode method of the
    //  base class.

    void insertAfterNode(const T &, Node<T> *) override;
    // Function to insert a value after a specific
    //  node in the doubly linked list.
    // Overrides the insertAfterNode method of the
    //  base class.

    void insertAfterNode(Node<T> *, Node<T> *) override;
    // Function to insert a node after a specific
    //  node in the doubly linked list.
    // Overrides the insertAfterNode method of the
    //  base class.

    void insertMultiple(T *, int) override;
    // Function to insert multiple values into the
    //  doubly linked list (start).
    // Overrides the insertMultiple method of the
    //  base class.

    void insertMultiple(Node<T> *, int) override;
    // Function to insert multiple nodes into the
    //  doubly linked list (start).
    // Overrides the insertMultiple method of the
    //  base class.

    void deleteFirst() override;
    // Function to delete the first node from the
    //  doubly linked list.
    // Overrides the deleteFirst method of the base
    //  class.

    void deleteLast() override;
    // Function to delete the last node from the
    //  doubly linked list.
    // Overrides the deleteLast method of the base
    //  class.

    void deleteFromIndex(int) override;
    // Function to delete a node at a specific index
    //  from the doubly linked list.
    // Overrides the deleteFromIndex method of the
    //  base class.

    void deleteByValue(const T &) override;
    // Function to delete the first node with a specific
    //  value from the doubly linked list.
    // Overrides the deleteByValue method of the base
    //  class.

    void deleteAllByValue(const T &) override;
    // Function to delete all nodes with a specific
    //  value from the doubly linked list.
    // Overrides the deleteAllByValue method of the
    //  base class.

    void deleteBeforeNode(Node<T> *) override;
    // Function to delete the node before a specific
    //  node from the doubly linked list.
    // Overrides the deleteBeforeNode method of the
    //  base class.

    void deleteAfterNode(Node<T> *) override;
    // Function to delete the node after a specific
    //  node from the doubly linked list.
    // Overrides the deleteAfterNode method of the
    //  base class.

    void clear() override;
    // Function to clear the doubly linked list
    //  (remove all nodes but keep the list structure).
    // Overrides the clear method of the base class.

    void deleteList() override;
    // Function to delete the entire doubly linked
    //  list (remove all nodes and deallocate memory).
    // Overrides the deleteList method of the base class.

    void deleteRange(int, int) override;
    // Function to delete nodes within a specified
    //  range of indices from the doubly linked list.
    // Overrides the deleteRange method of the base class.

    Node<T> *findNode(const T &value);
    // Function to find node with a given value.
    // The function will return the node pointer
    //  that has given value. And will return nullptr, if
    //  no such node is found

    ~DoublyLinkedList();
    // Destructor function for doublyLinkedList.
    // Performs necessary cleanup, such as deleting all
    //  nodes and deallocating memory.

private:
    DoublyNode<T> *head;
    DoublyNode<T> *tail;
};

#include "../Implementations/DoublyLinkedListImpl.cpp"

#endif