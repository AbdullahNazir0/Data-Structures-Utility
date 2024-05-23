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

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::display() const
{
    if (!this->head)
    {
        std::cout << "Linked List is empty.\n";
        return;
    }

    DoublyNode<T> *temp = head;
    while (temp->next != nullptr)
    {
        std::cout << temp->data << "  <-> ";
        temp = temp->next;
    }
    std::cout << temp->data << "\n";
}

template <typename T>
void DoublyLinkedList<T>::displayReversed() const
{
    if (!this->head)
    {
        std::cout << "Linked List is empty.\n";
        return;
    }

    std::cout << "Linked List Data(Reverse Order): ";
    DoublyNode<T> *temp = tail;
    while (temp->prev != nullptr)
    {
        std::cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    std::cout << temp->data << "\n";
}

template <typename T>
void DoublyLinkedList<T>::displayFormatted() const
{
    if (!this->head)
    {
        std::cout << "Linked List is empty.\n";
        return;
    }

    std::cout << "[ ";
    DoublyNode<T> *temp = this->head;
    while (temp->next != nullptr)
    {
        std::cout << temp->data << " <-> ";
        temp = temp->next;
    }
    std::cout << temp->data << " ]\n";
}

template <typename T>
void DoublyLinkedList<T>::displayFormattedAndReversed() const
{
    if (!this->head)
    {
        std::cout << "Linked List is empty.\n";
        return;
    }

    std::cout << "[ ";
    DoublyNode<T> *temp = tail;
    while (temp->prev != nullptr)
    {
        std::cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    std::cout << temp->data << " ]\n";
}

template <typename T>
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
        DoublyNode<T> *temp = tail;
        while (temp)
        {
            if (count == targetIndex)
            {
                std::cout << temp->data << '\n';
                return;
            }
            temp = temp->prev;
            count++;
        }
    }
    else
    {
        int count = 0;
        DoublyNode<T> *temp = this->head;
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

template <typename T>
void DoublyLinkedList<T>::insertAtStart(Node<T> *node)
{
    if (!node)
    {
        std::cout << "Cannot insert an empty node.\n";
        return;
    }

    DoublyNode<T> *doublyNode = static_cast<DoublyNode<T> *>(node);
    if (!this->head)
    {
        this->head = doublyNode;
        tail = doublyNode;
        doublyNode->next = nullptr;
    }
    else
    {
        doublyNode->next = this->head;
        this->head = doublyNode;
    }
    this->nodesCount++;
}

template <typename T>
void DoublyLinkedList<T>::insertAtStart(const T &value)
{
    Node<T> *temp = new DoublyNode<T>(value);
    insertAtStart(temp);
}

template <typename T>
void DoublyLinkedList<T>::insertAtEnd(Node<T> *node)
{
    if (!node)
    {
        std::cout << "Cannot insert an empty node.\n";
        return;
    }

    DoublyNode<T> *doublyNode = static_cast<DoublyNode<T> *>(node);
    if (!this->head)
    {
        this->head = doublyNode;
        tail = doublyNode;
    }
    else
    {
        tail->next = doublyNode;
        doublyNode->prev = tail;
        tail = doublyNode;
    }
    this->nodesCount++;
}

template <typename T>
void DoublyLinkedList<T>::insertAtEnd(const T &value)
{
    Node<T> *temp = new DoublyNode<T>(value);
    insertAtEnd(temp);
}

template <typename T>
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
        DoublyNode<T> *doublyValue = static_cast<DoublyNode<T> *>(value);
        DoublyNode<T> *temp = this->head;
        for (int count = 0; count < index - 1; count++)
        {
            temp = temp->next;
        }
        doublyValue->next = temp->next;
        doublyValue->prev = temp;
        temp->next->prev = doublyValue;
        temp->next = doublyValue;
        this->nodesCount++;
    }
    else
    {
        DoublyNode<T> *doublyValue = static_cast<DoublyNode<T> *>(value);
        DoublyNode<T> *temp = this->head;
        for (int count = this->nodesCount; count > index + 1; count--)
        {
            temp = temp->prev;
        }
        doublyValue->next = temp->next;
        doublyValue->prev = temp;
        temp->next->prev = doublyValue;
        temp->next = doublyValue;
        this->nodesCount++;
    }
}

template <typename T>
void DoublyLinkedList<T>::insertAtIndex(const T &value, int index)
{

    Node<T> *valueNode = new DoublyNode<T>(value);
    insertAtIndex(valueNode, index);
}

template <typename T>
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

    DoublyNode<T> *temp = this->head;
    while (temp != nullptr)
    {
        if (temp == static_cast<DoublyNode<T> *>(nodeToCheck))
        {
            if (temp->prev == nullptr)
            {
                insertAtStart(value);
                return;
            }
            else
            {
                DoublyNode<T> *doublyValue = static_cast<DoublyNode<T> *>(value);
                doublyValue->next = temp;
                doublyValue->prev = temp->prev;
                temp->prev->next = doublyValue;
                temp->prev = doublyValue;
                this->nodesCount++;
                return;
            }
        }
        else
            temp = temp->next;
    }

    std::cout << "Node not found in Linked List.\n";
}

template <typename T>
void DoublyLinkedList<T>::insertBeforeNode(
    const T &value,
    Node<T> *nodeToCheck)
{
    Node<T> *valueNode = new DoublyNode<T>(value);
    insertBeforeNode(valueNode, nodeToCheck);
}

template <typename T>
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

    DoublyNode<T> *temp = this->head;
    while (temp != nullptr)
    {
        if (temp == static_cast<DoublyNode<T> *>(nodeToCheck))
        {
            if (temp->next == nullptr)
            {
                insertAtEnd(value);
                return;
            }
            else
            {
                DoublyNode<T> *doublyValue = static_cast<DoublyNode<T> *>(value);
                doublyValue->prev = temp;
                doublyValue->next = temp->next;
                temp->next = doublyValue;
                doublyValue->next->prev = doublyValue;
                this->nodesCount++;
                return;
            }
        }
        else
            temp = temp->next;
    }

    std::cout << "Node not found in Linked List.\n";
}

template <typename T>
void DoublyLinkedList<T>::insertAfterNode(
    const T &value,
    Node<T> *nodeToCheck)
{
    Node<T> *valueNode = new DoublyNode<T>(value);
    insertAfterNode(valueNode, nodeToCheck);
}

template <typename T>
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
        this->head = static_cast<DoublyNode<T> *>(valuesList);
        this->nodesCount = count;
    }
    else
    {
        DoublyNode<T> *temp = static_cast<DoublyNode<T> *>(valuesList);
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = this->head;
        this->head = static_cast<DoublyNode<T> *>(valuesList);
        // this->head->prev = temp;
        this->head->prev = temp;
        this->nodesCount += count;

        valuesList = nullptr; // releasing ownership.
    }
}

template <typename T>
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
        Node<T> *tempNode = new DoublyNode<T>(values[i]);
        tempList.insertAtEnd(tempNode);
    }
    while (tempList.head)
    {
        DoublyNode<T> *nodeToMove = tempList.head;
        tempList.head = tempList.head->next;

        if (!this->head)
        {
            this->head = nodeToMove;
            tail = nodeToMove;
            nodeToMove->prev = nullptr;
            nodeToMove->next = nullptr;
        }
        else
        {
            tail->next = nodeToMove;
            nodeToMove->prev = tail;
            nodeToMove->next = nullptr;
            tail = nodeToMove;
        }

        this->nodesCount++;
    }
}

template <typename T>
void DoublyLinkedList<T>::deleteFirst()
{
    if (!this->head)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }

    DoublyNode<T> *temp = this->head;
    this->head = this->head->next;
    if (!this->head)
        tail = nullptr;
    delete temp;
    this->nodesCount--;
}

template <typename T>
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
        tail = nullptr;
        return;
    }

    DoublyNode<T> *temp = this->head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    this->nodesCount--;
    temp->next = nullptr;
    tail = temp;
}

template <typename T>
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

    DoublyNode<T> *temp = this->head;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    DoublyNode<T> *toDelete = temp->next;
    temp->next = temp->next->next;
    if (!temp->next)
        tail = temp;
    delete toDelete;
    this->nodesCount--;
}

template <typename T>
void DoublyLinkedList<T>::deleteByValue(const T &value)
{
    if (!this->head)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }

    DoublyNode<T> *temp = this->head;
    while (temp->next)
    {
        if (temp->next->data == value)
        {
            DoublyNode<T> *toDelete = temp->next;
            temp->next = temp->next->next;
            if (this->head == toDelete)
                this->head = this->head->next;
            delete toDelete;
            if (!temp->next)
                tail = temp;
            this->nodesCount--;
            return;
        }
        temp = temp->next;
    }

    std::cout << "Cannot find " << value << " in Linked List.\n";
}

// template <typename T>
// void DoublyLinkedList<T>::deleteAllByValue(const T &value)
// {
//     if (!this->head)
//     {
//         std::cout << "Cannot delete from empty Linked List.\n";
//         return;
//     }

//     bool flag = false;
//     DoublyNode<T> *temp = this->head;
//     while (temp->next)
//     {
//         if (temp->next->data == value)
//         {
//             DoublyNode<T> *toDelete = temp->next;
//             temp->next = temp->next->next;
//             if (this->head == toDelete)
//                 this->head = this->head->next;
//             flag = true;
//             delete toDelete;
//             if (!temp->next)
//                 tail = temp;
//             this->nodesCount--;
//         }
//         temp = temp->next;
//     }

//     // if (this->head->data == value)
//     // {
//     //     DoublyNode<T> *toDelete = this->head;
//     //     this->head = this->head->next;
//     //     delete toDelete;
//     //     if (!this->head)
//     //         tail = nullptr;
//     //     this->nodesCount--;
//     //     flag = true;
//     // }

//     if (flag)
//         std::cout << "Delete all occurrences of "
//                   << value << " in Linked List.\n";
//     else
//         std::cout << "Cannot find " << value << " in Linked List.\n";
// }

template <typename T>
void DoublyLinkedList<T>::deleteAllByValue(const T &value)
{
    if (!this->head)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }

    bool flag = false;
    DoublyNode<T> *temp = this->head;
    while (temp && temp->next)
    {
        if (temp->next->data == value)
        {
            DoublyNode<T> *toDelete = temp->next;
            temp->next = temp->next->next;
            if (this->head == toDelete)
                this->head = this->head->next;
            flag = true;
            delete toDelete;
            if (!temp->next)
                tail = temp;
            this->nodesCount--;
        }
        temp = temp->next;
    }

    if (flag)
        std::cout << "Delete all occurrences of " << value << " in Linked List.\n";
    else
        std::cout << "Cannot find " << value << " in Linked List.\n";
}

template <typename T>
void DoublyLinkedList<T>::deleteBeforeNode(Node<T> *nodeToCheck)
{
    if (!this->head || !this->head->next)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }

    DoublyNode<T> *doublyNodeToCheck = static_cast<DoublyNode<T> *>(nodeToCheck);
    if (doublyNodeToCheck == this->head)
    {
        std::cout << "Cannot delete before the given node.\n";
        return;
    }

    if (doublyNodeToCheck == this->head->next)
    {
        deleteFirst();
        return;
    }

    DoublyNode<T> *temp = this->head;
    while (temp->next->next != nullptr)
    {
        if (temp->next->next == doublyNodeToCheck)
        {
            // logic to delete.
            DoublyNode<T> *nodeToDelete = temp->next;
            temp->next = doublyNodeToCheck;
            delete nodeToDelete;
            this->nodesCount--;
            return;
        }
        temp = temp->next;
    }

    std::cout << "Node not found.\n";
}

template <typename T>
void DoublyLinkedList<T>::deleteAfterNode(Node<T> *nodeToCheck)
{
    if (!this->head)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }

    DoublyNode<T> *temp = this->head;
    while (temp != nullptr)
    {
        if (temp == static_cast<DoublyNode<T> *>(nodeToCheck))
        {
            if (temp->next == nullptr)
            {
                std::cout << "No node to delete after given node.\n";
                return;
            }
            DoublyNode<T> *nodeToDelete = temp->next;
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

template <typename T>
void DoublyLinkedList<T>::clear()
{
    if (!this->head)
    {
        std::cout << "Cannot clear empty Linked List.\n";
    }
    DoublyNode<T> *temp = this->head;
    while (temp)
    {
        temp->data = T();
        temp = temp->next;
    }
}

template <typename T>
void DoublyLinkedList<T>::deleteList()
{
    if (!this->head)
        return;

    DoublyNode<T> *temp = this->head;
    while (temp)
    {
        DoublyNode<T> *nodeToDelete = temp;
        temp = temp->next;
        delete nodeToDelete;
    }
    this->head = nullptr;
    tail = nullptr;
    this->nodesCount = 0;
}

template <typename T>
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

    DoublyNode<T> *temp = this->head;
    DoublyNode<T> *prev = nullptr;
    for (int i = 0; i < startIndex; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    for (int i = startIndex; i < endIndex; i++)
    {
        DoublyNode<T> *nextNode = temp->next;
        delete temp;
        this->nodesCount--;
        if (prev)
            prev->next = nextNode;
        else
            this->head = nextNode;
        temp = nextNode;
    }

    if (!temp)
        tail = prev;
}

template <typename T>
Node<T> *DoublyLinkedList<T>::findNode(const T &value)
{
    DoublyNode<T> *temp = this->head;
    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr; // DoublyNode with the specified value not found
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    // DoublyNode<T> *current = this->head;
    // while (current)
    // {
    //     DoublyNode<T> *next = current->next;
    //     delete current;
    //     current = next;
    // }
    // this->head = nullptr;
    // tail = nullptr;
    // this->nodesCount = 0;

    deleteList();
}