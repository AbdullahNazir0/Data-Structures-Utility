// ********************************************************
// Programmer: Abdullah Nazir
// Date: May 17, 2024
//
// Class CircularLinkedList
// This class contains members and methods to implement
// data structure circular linked list(singly). This class
// is inherited from abstract class LinkedList .
// ********************************************************

#ifndef H_CircularLinkedList
#define H_CircularLinkedList

#include "LinkedList.h"

template <typename T>
class CircularLinkedList : public LinkedList<T>
{
public:
    CircularLinkedList();
    // Default constructor for CircularLinkedList.

    void display() const override;
    // Function to display all contents of the circular
    //  linked list.
    // Overrides the display method of the base class.

    void displayFormatted() const override;
    // Function to display the contents of the circular
    //  linked list with formatting.
    // Overrides the displayFormatted method of the base
    //  class.

    void displayAtIndex(int) override;
    // Function to display the element at a specific
    //  index in the circular linked list.
    // Overrides the displayAtIndex method of the base
    //  class.

    void insertAtStart(const T &) override;
    // Function to insert a value at the beginning of
    //  the circular linked list.
    // Overrides the insertAtStart method of the base
    //  class.

    void insertAtStart(Node<T> *) override;
    // Function to insert a node at the beginning of
    //  the circular linked list.
    // Overrides the insertAtStart method of the base
    //  class.

    void insertAtEnd(const T &) override;
    // Function to insert a value at the end of the
    //  circular linked list.
    // Overrides the insertAtEnd method of the base
    //  class.

    void insertAtEnd(Node<T> *) override;
    // Function to insert a node at the end of the
    //  circular linked list.
    // Overrides the insertAtEnd method of the base
    //  class.

    void insertAtIndex(const T &, int) override;
    // Function to insert a value at a specific index
    //  in the circular linked list.
    // Overrides the insertAtIndex method of the base
    //  class.

    void insertAtIndex(Node<T> *, int) override;
    // Function to insert a node at a specific index
    //  in the circular linked list.
    // Overrides the insertAtIndex method of the base
    //  class.

    void insertBeforeNode(const T &, Node<T> *) override;
    // Function to insert a value before a specific
    //  node in the circular linked list.
    // Overrides the insertBeforeNode method of the
    //  base class.

    void insertBeforeNode(Node<T> *, Node<T> *) override;
    // Function to insert a node before a specific
    //  node in the circular linked list.
    // Overrides the insertBeforeNode method of the
    //  base class.

    void insertAfterNode(const T &, Node<T> *) override;
    // Function to insert a value after a specific
    //  node in the circular linked list.
    // Overrides the insertAfterNode method of the
    //  base class.

    void insertAfterNode(Node<T> *, Node<T> *) override;
    // Function to insert a node after a specific
    //  node in the circular linked list.
    // Overrides the insertAfterNode method of the
    //  base class.

    void insertMultiple(T *, int) override;
    // Function to insert multiple values into the
    //  circular linked list (start).
    // Overrides the insertMultiple method of the
    //  base class.

    void insertMultiple(Node<T> *, int) override;
    // Function to insert multiple nodes into the
    //  circular linked list (start).
    // Overrides the insertMultiple method of the
    //  base class.

    void deleteFirst() override;
    // Function to delete the first node from the
    //  circular linked list.
    // Overrides the deleteFirst method of the base
    //  class.

    void deleteLast() override;
    // Function to delete the last node from the
    //  circular linked list.
    // Overrides the deleteLast method of the base
    //  class.

    void deleteFromIndex(int) override;
    // Function to delete a node at a specific index
    //  from the circular linked list.
    // Overrides the deleteFromIndex method of the
    //  base class.

    void deleteByValue(const T &) override;
    // Function to delete the first node with a specific
    //  value from the circular linked list.
    // Overrides the deleteByValue method of the base
    //  class.

    void deleteAllByValue(const T &) override;
    // Function to delete all nodes with a specific
    //  value from the circular linked list.
    // Overrides the deleteAllByValue method of the
    //  base class.

    void deleteBeforeNode(Node<T> *) override;
    // Function to delete the node before a specific
    //  node from the circular linked list.
    // Overrides the deleteBeforeNode method of the
    //  base class.

    void deleteAfterNode(Node<T> *) override;
    // Function to delete the node after a specific
    //  node from the circular linked list.
    // Overrides the deleteAfterNode method of the
    //  base class.

    void clear() override;
    // Function to clear the circular linked list
    //  (remove all nodes but keep the list structure).
    // Overrides the clear method of the base class.

    void deleteList() override;
    // Function to delete the entire circular linked
    //  list (remove all nodes and deallocate memory).
    // Overrides the deleteList method of the base class.

    void deleteRange(int, int) override;
    // Function to delete nodes within a specified
    //  range of indices from the circular linked list.
    // Overrides the deleteRange method of the base class.

    ~CircularLinkedList();
    // Destructor function for CircularLinkedList.
    // Performs necessary cleanup, such as deleting all
    //  nodes and deallocating memory.
};

#include "../Implementations/CircularLinkedListImpl.cpp"

#endif // H_CircularLinkedList