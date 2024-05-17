// ********************************************************
// Programmer: Abdullah Nazir
// Date: April 22, 2024
//
// Class SinglyLinkedList
// This class contains members and methodsto implement
// data structure singly linked list. This class
// is inherited from abstract class LinkedList .
// ********************************************************

#ifndef H_SinglyLinkedList
#define H_SinglyLinkedList

// #include "Node.h"
#include "LinkedList.h"

template <typename T>
class SinglyLinkedList : public LinkedList<T>
{
public:
    SinglyLinkedList();
    // Default constructor for SinglyLinkedList.
    // Initializes the tail pointer to nullptr
    //  and head will also be initialized to
    //  nullptr when LinkedList constructor will
    //  be called.

    void display() const override;
    // Function to display all contents of the singly
    //  linked list.
    // Overrides the display method of the base class.

    void displayFormatted() const override;
    // Function to display the contents of the singly
    //  linked list with formatting.
    // Overrides the displayFormatted method of the base
    //  class.

    void displayAtIndex(int) override;
    // Function to display the element at a specific
    //  index in the singly linked list.
    // Overrides the displayAtIndex method of the base
    //  class.

    void insertAtStart(const T &) override;
    // Function to insert a value at the beginning of
    //  the singly linked list.
    // Overrides the insertAtStart method of the base
    //  class.

    void insertAtStart(Node<T> *) override;
    // Function to insert a node at the beginning of
    //  the singly linked list.
    // Overrides the insertAtStart method of the base
    //  class.

    void insertAtEnd(const T &) override;
    // Function to insert a value at the end of the
    //  singly linked list.
    // Overrides the insertAtEnd method of the base
    //  class.

    void insertAtEnd(Node<T> *) override;
    // Function to insert a node at the end of the
    //  singly linked list.
    // Overrides the insertAtEnd method of the base
    //  class.

    void insertAtIndex(const T &, int) override;
    // Function to insert a value at a specific index
    //  in the singly linked list.
    // Overrides the insertAtIndex method of the base
    //  class.

    void insertAtIndex(Node<T> *, int) override;
    // Function to insert a node at a specific index
    //  in the singly linked list.
    // Overrides the insertAtIndex method of the base
    //  class.

    void insertBeforeNode(const T &, Node<T> *) override;
    // Function to insert a value before a specific
    //  node in the singly linked list.
    // Overrides the insertBeforeNode method of the
    //  base class.

    void insertBeforeNode(Node<T> *, Node<T> *) override;
    // Function to insert a node before a specific
    //  node in the singly linked list.
    // Overrides the insertBeforeNode method of the
    //  base class.

    void insertAfterNode(const T &, Node<T> *) override;
    // Function to insert a value after a specific
    //  node in the singly linked list.
    // Overrides the insertAfterNode method of the
    //  base class.

    void insertAfterNode(Node<T> *, Node<T> *) override;
    // Function to insert a node after a specific
    //  node in the singly linked list.
    // Overrides the insertAfterNode method of the
    //  base class.

    void insertMultiple(T *, int) override;
    // Function to insert multiple values into the
    //  singly linked list (start).
    // Overrides the insertMultiple method of the
    //  base class.

    void insertMultiple(Node<T> *, int) override;
    // Function to insert multiple nodes into the
    //  singly linked list (start).
    // Overrides the insertMultiple method of the
    //  base class.

    void deleteFirst() override;
    // Function to delete the first node from the
    //  singly linked list.
    // Overrides the deleteFirst method of the base
    //  class.

    void deleteLast() override;
    // Function to delete the last node from the
    //  singly linked list.
    // Overrides the deleteLast method of the base
    //  class.

    void deleteFromIndex(int) override;
    // Function to delete a node at a specific index
    //  from the singly linked list.
    // Overrides the deleteFromIndex method of the
    //  base class.

    void deleteByValue(const T &) override;
    // Function to delete the first node with a specific
    //  value from the singly linked list.
    // Overrides the deleteByValue method of the base
    //  class.

    void deleteAllByValue(const T &) override;
    // Function to delete all nodes with a specific
    //  value from the singly linked list.
    // Overrides the deleteAllByValue method of the
    //  base class.

    void deleteBeforeNode(Node<T> *) override;
    // Function to delete the node before a specific
    //  node from the singly linked list.
    // Overrides the deleteBeforeNode method of the
    //  base class.

    void deleteAfterNode(Node<T> *) override;
    // Function to delete the node after a specific
    //  node from the singly linked list.
    // Overrides the deleteAfterNode method of the
    //  base class.

    void clear() override;
    // Function to clear the singly linked list
    //  (remove all nodes but keep the list structure).
    // Overrides the clear method of the base class.

    void deleteList() override;
    // Function to delete the entire singly linked
    //  list (remove all nodes and deallocate memory).
    // Overrides the deleteList method of the base class.

    void deleteRange(int, int) override;
    // Function to delete nodes within a specified
    //  range of indices from the singly linked list.
    // Overrides the deleteRange method of the base class.

    ~SinglyLinkedList();
    // Destructor function for SinglyLinkedList.
    // Performs necessary cleanup, such as deleting all
    //  nodes and deallocating memory.

private:
    Node<T> *tail;
};

#include "../Implementations/SinglyLinkedListImpl.cpp"

#endif // H_SinglyLinkedList
