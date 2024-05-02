// ********************************************************
// Programmer: Abdullah Nazir
// Date: April 30, 2024
//
// Implementation file DoublyLinkedListImpl.cpp
// This file contains implementations of the functions
//  declared in the class DoublyLinkedList .
// ********************************************************

#include "../Headers/DoublyLinkedList.h"
#include <iostream>

template <class T>
Node<T> *DoublyLinkedList<T>::findNode(const T &value)
{
    Node<T> *temp = this->head;
    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr; // Node with the specified value not found
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    this->tail = nullptr;
}

template <class T>
void DoublyLinkedList<T>::display() const
{
    if (!this->head)
    {
        std::cout << "Linked List is empty.\n";
        return;
    }

    std::cout << "Linked List Data: ";
    Node<T> *temp = this->head;
    while (temp->next != nullptr)
    {
        std::cout << temp->data << "  <-> ";
        temp = temp->next;
    }
    std::cout << temp->data << "\n";
}

template <class T>
void DoublyLinkedList<T>::displayReversed() const
{
    if (!this->head)
    {
        std::cout << "Linked List is empty.\n";
        return;
    }

    std::cout << "Linked List Data(Reverse Order): ";
    Node<T> *temp = this->tail;
    while (temp->getPrev() != nullptr)
    {
        std::cout << temp->data << " <-> ";
        temp = temp->getPrev();
    }
    std::cout << temp->data << "\n";
}

template <class T>
void DoublyLinkedList<T>::displayFormatted() const
{
    if (!this->head)
    {
        std::cout << "Linked List is empty.\n";
        return;
    }

    std::cout << "[ ";
    Node<T> *temp = this->head;
    while (temp->next != nullptr)
    {
        std::cout << temp->data << " <-> ";
        temp = temp->next;
    }
    std::cout << temp->data << " ]\n";
}

template <class T>
void DoublyLinkedList<T>::displayFormattedAndReversed() const
{
    if (!this->head)
    {
        std::cout << "Linked List is empty.\n";
        return;
    }

    std::cout << "[ ";
    Node<T> *temp = this->tail;
    while (temp->getPrev() != nullptr)
    {
        std::cout << temp->data << " <-> ";
        temp = temp->getPrev();
    }
    std::cout << temp->data << " ]\n";
}

template <class T>
void DoublyLinkedList<T>::displayAtIndex(int index)
{
    if (index < 0 || index >= this->nodesCount)
    {
        std::cout << "Invalid index.\n";
        return;
    }

    if (index >= this->nodesCount / 2)
    {
        int count = 0;
        int targetIndex = this->nodesCount - index;
        Node<T> *temp = this->tail;
        while (temp)
        {
            if (count == targetIndex)
            {
                std::cout << temp->data << '\n';
                return;
            }
            temp = temp->getPrev();
            count++;
        }
    }
    else
    {
        int count = 0;
        Node<T> *temp = this->head;
        while (temp)
        {
            if (count == index)
            {
                std::cout << temp->data << '\n';
                return;
            }
            temp = temp->next;
            count++;
        }
    }
}

template <class T>
void DoublyLinkedList<T>::insertAtStart(Node<T> *node)
{
    if (!node)
    {
        std::cout << "Cannot insert an empty node.\n";
        return;
    }
    if (!this->head)
    {
        this->head = node;
        this->tail = node;
        node->next = nullptr;
    }
    else
    {
        node->next = this->head;
        this->head = node;
    }
    this->nodesCount++;
}

template <class T>
void DoublyLinkedList<T>::insertAtStart(const T &value)
{
    Node<T> *temp = new DoublyNode<T>(value);
    insertAtStart(temp);
}

template <class T>
void DoublyLinkedList<T>::insertAtEnd(Node<T> *node)
{
    if (!node)
    {
        std::cout << "Cannot insert an empty node.\n";
        return;
    }
    if (!this->head)
    {
        this->head = node;
        this->tail = node;
    }
    else
    {
        this->tail->next = node;
        node->setPrev(this->tail);
        this->tail = node;
    }
    this->nodesCount++;
}

template <class T>
void DoublyLinkedList<T>::insertAtEnd(const T &value)
{
    Node<T> *temp = new DoublyNode<T>(value);
    insertAtEnd(temp);
}

template <class T>
void DoublyLinkedList<T>::insertAtIndex(Node<T> *value, int index)
{
    if (index < 0 || index > this->nodesCount)
    {
        std::cout << "Invalid index.\n";
        return;
    }
    if (index == 0)
        insertAtStart(value);
    else if (index == this->nodesCount)
        insertAtEnd(value);
    else if (index <= this->nodesCount / 2)
    {
        Node<T> *temp = this->head;
        for (int count = 0; count < index - 1; count++)
        {
            temp = temp->next;
        }
        value->next = temp->next;
        value->setPrev(temp);
        temp->next->setPrev(value);
        temp->next = value;
        this->nodesCount++;
    }
    else
    {
        Node<T> *temp = this->head;
        for (int count = this->nodesCount; count > index + 1; count--)
        {
            temp = temp->getPrev();
        }
        value->next = temp->next;
        value->setPrev(temp);
        temp->next->setPrev(value);
        temp->next = value;
        this->nodesCount++;
    }
}

template <class T>
void DoublyLinkedList<T>::insertAtIndex(const T &value, int index)
{

    Node<T> *valueNode = new DoublyNode<T>(value);
    insertAtIndex(valueNode, index);
}

template <class T>
void DoublyLinkedList<T>::insertBeforeNode(
    Node<T> *value,
    Node<T> *nodeToCheck)
{
    if (!this->head)
    {
        std::cout << "Linked List is empty. (Not inserted)\n";
        return;
    }
    if (!nodeToCheck)
    {
        std::cout << "Cannot add before an empty node.\n";
        return;
    }

    Node<T> *temp = this->head;
    while (temp != nullptr)
    {
        if (temp == nodeToCheck)
        {
            if (temp->getPrev() == nullptr)
            {
                insertAtStart(value);
                return;
            }
            else
            {
                value->next = temp;
                value->setPrev(temp->getPrev());
                temp->getPrev()->next = value;
                temp->setPrev(value);
                this->nodesCount++;
                return;
            }
        }
        else
            temp = temp->next;
    }

    std::cout << "Node not found in Linked List.\n";
}

template <class T>
void DoublyLinkedList<T>::insertBeforeNode(
    const T &value,
    Node<T> *nodeToCheck)
{
    Node<T> *valueNode = new DoublyNode<T>(value);
    insertBeforeNode(valueNode, nodeToCheck);
}

template <class T>
void DoublyLinkedList<T>::insertAfterNode(
    Node<T> *value,
    Node<T> *nodeToCheck)
{
    if (!this->head)
    {
        std::cout << "Linked List is empty. (Not added)\n";
        return;
    }
    if (!nodeToCheck)
    {
        std::cout << "Cannot add after an empty node.\n";
        return;
    }

    Node<T> *temp = this->head;
    while (temp != nullptr)
    {
        if (temp == nodeToCheck)
        {
            if (temp->next == nullptr)
            {
                insertAtEnd(value);
                return;
            }
            else
            {
                value->setPrev(temp);
                value->next = temp->next;
                temp->next = value;
                value->next->setPrev(value);
                this->nodesCount++;
                return;
            }
        }
        else
            temp = temp->next;
    }

    std::cout << "Node not found in Linked List.\n";
}

template <class T>
void DoublyLinkedList<T>::insertAfterNode(
    const T &value,
    Node<T> *nodeToCheck)
{
    Node<T> *valueNode = new DoublyNode<T>(value);
    insertAfterNode(valueNode, nodeToCheck);
}

template <class T>
void DoublyLinkedList<T>::insertMultiple(Node<T> *valuesList, int count)
{
    // Assuming that the valuesList is also a linked list.
    if (!valuesList)
    {
        std::cout << "Cannot insert empty Linked List.\n";
        return;
    }

    if (!this->head)
    {
        this->head = valuesList;
        this->nodesCount = count;
    }
    else
    {
        Node<T> *temp = valuesList;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = this->head;
        this->head = valuesList;
        // this->head->getPrev() = temp;
        this->head->setPrev(temp);
        this->nodesCount += count;

        valuesList = nullptr; // releasing ownership.
    }
}

template <class T>
void DoublyLinkedList<T>::insertMultiple(T *values, int count)
{
    if (!values || count <= 0)
    {
        std::cout << "Cannot add empty data.\n";
        return;
    }

    DoublyLinkedList<T> tempList;
    for (int i = 0; i < count; i++)
    {
        Node<T> *tempNode = new DoublyNode(values[i]);
        tempList.insertAtEnd(tempNode);
    }
    while (tempList.head)
    {
        Node<T> *nodeToMove = tempList.head;
        tempList.head = tempList.head->next;

        if (!this->head)
        {
            this->head = nodeToMove;
            this->tail = nodeToMove;
            nodeToMove->setPrev(nullptr);
            nodeToMove->next = nullptr;
        }
        else
        {
            this->tail->next = nodeToMove;
            nodeToMove->setPrev(this->tail);
            nodeToMove->next = nullptr;
            this->tail = nodeToMove;
        }

        this->nodesCount++;
    }
}

// - > continue from here

template <class T>
void DoublyLinkedList<T>::deleteFirst()
{
    if (!this->head)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }

    Node<T> *temp = this->head;
    this->head = this->head->next;
    if (!this->head)
        this->tail = nullptr;
    delete temp;
    this->nodesCount--;
}

template <class T>
void DoublyLinkedList<T>::deleteLast()
{
    if (!this->head)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }

    if (!this->head->next)
    {
        delete this->head;
        this->nodesCount--;
        this->head = nullptr;
        this->tail = nullptr;
        return;
    }

    Node<T> *temp = this->head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    this->nodesCount--;
    temp->next = nullptr;
    this->tail = temp;
}

template <class T>
void DoublyLinkedList<T>::deleteFromIndex(int index)
{
    if (!this->head)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }

    if (index < 0 || index >= this->nodesCount)
    {
        std::cout << "Invalid index.\n";
        return;
    }

    if (index == 0)
    {
        deleteFirst();
        return;
    }

    if (index == this->nodesCount - 1)
    {
        deleteLast();
        return;
    }

    Node<T> *temp = this->head;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    Node<T> *toDelete = temp->next;
    temp->next = temp->next->next;
    if (!temp->next)
        this->tail = temp;
    delete toDelete;
    this->nodesCount--;
}

template <class T>
void DoublyLinkedList<T>::deleteByValue(const T &value)
{
    if (!this->head)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }

    Node<T> *temp = this->head;
    while (temp->next)
    {
        if (temp->next->data == value)
        {
            Node<T> *toDelete = temp->next;
            temp->next = temp->next->next;
            if (this->head == toDelete)
                this->head = this->head->next;
            delete toDelete;
            if (!temp->next)
                this->tail = temp;
            this->nodesCount--;
            return;
        }
        temp = temp->next;
    }

    std::cout << "Cannot find " << value << " in Linked List.\n";
}

// template <class T>
// void DoublyLinkedList<T>::deleteAllByValue(const T &value)
// {
//     if (!this->head)
//     {
//         std::cout << "Cannot delete from empty Linked List.\n";
//         return;
//     }

//     bool flag = false;
//     Node<T> *temp = this->head;
//     while (temp->next)
//     {
//         if (temp->next->data == value)
//         {
//             Node<T> *toDelete = temp->next;
//             temp->next = temp->next->next;
//             if (this->head == toDelete)
//                 this->head = this->head->next;
//             flag = true;
//             delete toDelete;
//             if (!temp->next)
//                 this->tail = temp;
//             this->nodesCount--;
//         }
//         temp = temp->next;
//     }

//     // if (this->head->data == value)
//     // {
//     //     Node<T> *toDelete = this->head;
//     //     this->head = this->head->next;
//     //     delete toDelete;
//     //     if (!this->head)
//     //         this->tail = nullptr;
//     //     this->nodesCount--;
//     //     flag = true;
//     // }

//     if (flag)
//         std::cout << "Delete all occurrences of "
//                   << value << " in Linked List.\n";
//     else
//         std::cout << "Cannot find " << value << " in Linked List.\n";
// }

template <class T>
void DoublyLinkedList<T>::deleteAllByValue(const T &value)
{
    if (!this->head)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }

    bool flag = false;
    Node<T> *temp = this->head;
    while (temp && temp->next)
    {
        if (temp->next->data == value)
        {
            Node<T> *toDelete = temp->next;
            temp->next = temp->next->next;
            if (this->head == toDelete)
                this->head = this->head->next;
            flag = true;
            delete toDelete;
            if (!temp->next)
                this->tail = temp;
            this->nodesCount--;
        }
        temp = temp->next;
    }

    if (flag)
        std::cout << "Delete all occurrences of " << value << " in Linked List.\n";
    else
        std::cout << "Cannot find " << value << " in Linked List.\n";
}

template <class T>
void DoublyLinkedList<T>::deleteBeforeNode(Node<T> *nodeToCheck)
{
    if (!this->head || !this->head->next)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }

    if (nodeToCheck == this->head)
    {
        std::cout << "Cannot delete before the given node.\n";
        return;
    }

    if (nodeToCheck == this->head->next)
    {
        deleteFirst();
        return;
    }

    Node<T> *temp = this->head;
    while (temp->next->next != nullptr)
    {
        if (temp->next->next == nodeToCheck)
        {
            // logic to delete.
            Node<T> *nodeToDelete = temp->next;
            temp->next = nodeToCheck;
            delete nodeToDelete;
            this->nodesCount--;
            return;
        }
        temp = temp->next;
    }

    std::cout << "Node not found.\n";
}

template <class T>
void DoublyLinkedList<T>::deleteAfterNode(Node<T> *nodeToCheck)
{
    if (!this->head)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }

    Node<T> *temp = this->head;
    while (temp != nullptr)
    {
        if (temp == nodeToCheck)
        {
            if (temp->next == nullptr)
            {
                std::cout << "No node to delete after given node.\n";
                return;
            }
            Node<T> *nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
            if (temp->next == nullptr)
                tail = temp;
            this->nodesCount--;
            return;
        }
        temp = temp->next;
    }

    std::cout << "Node not found.\n";
}

template <class T>
void DoublyLinkedList<T>::clear()
{
    if (!this->head)
    {
        std::cout << "Cannot clear empty Linked List.\n";
    }
    Node<T> *temp = this->head;
    while (temp)
    {
        temp->data = T();
        temp = temp->next;
    }
}

template <class T>
void DoublyLinkedList<T>::deleteList()
{
    if (!this->head)
    {
        std::cout << "Cannot delete empty Linked List.\n";
        return;
    }

    Node<T> *temp = this->head;
    while (temp)
    {
        Node<T> *nodeToDelete = temp;
        temp = temp->next;
        delete nodeToDelete;
    }
    this->head = nullptr;
    this->tail = nullptr;
    this->nodesCount = 0;
}

template <class T>
void DoublyLinkedList<T>::deleteRange(int startIndex, int endIndex)
{
    if (!this->head)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }
    if (startIndex < 0 ||
        endIndex < 0 ||
        startIndex >= endIndex ||
        endIndex >= this->nodesCount)
    {
        std::cout << "Invalid range.\n";
        return;
    }

    Node<T> *temp = this->head;
    Node<T> *prev = nullptr;
    for (int i = 0; i < startIndex; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    for (int i = startIndex; i < endIndex; i++)
    {
        Node<T> *nextNode = temp->next;
        delete temp;
        this->nodesCount--;
        if (prev)
            prev->next = nextNode;
        else
            this->head = nextNode;
        temp = nextNode;
    }

    if (!temp)
        this->tail = prev;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Node<T> *current = this->head;
    while (current)
    {
        Node<T> *next = current->next;
        delete current;
        current = next;
    }
    this->head = nullptr;
    this->tail = nullptr;
    this->nodesCount = 0;
}