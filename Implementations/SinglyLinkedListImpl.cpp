// ********************************************************
// Programmer: Abdullah Nazir
// Date: April 21, 2024
//
// Implementation file SinglyLinkedListImpl.cpp
// This file contains implementations of the functions
//  declared in the class SinglyLinkedList .
// ********************************************************

#include "../Headers/SinglyLinkedList.h"
#include <iostream>

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

template <typename T>
int SinglyLinkedList<T>::getNodesCount()
{
    return (this->nodesCount);
}

template <typename T>
T SinglyLinkedList<T>::getHeadData()
{
    if (!head)
    {
        return T();
    }

    return (head->data);
}

template <typename T>
T SinglyLinkedList<T>::getTailData()
{
    if (!head)
    {
        return T();
    }

    return (tail->data);
}

template <typename T>
void SinglyLinkedList<T>::display() const
{
    if (!head)
    {
        std::cout << "Linked List is empty.\n";
        return;
    }

    SinglyNode<T> *temp = head;
    while (temp->next != nullptr)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << temp->data << "\n";
}

template <typename T>
void SinglyLinkedList<T>::displayFormatted() const
{
    if (!head)
    {
        std::cout << "Linked List is empty.\n";
        return;
    }

    std::cout << "[ ";
    SinglyNode<T> *temp = head;
    while (temp->next != nullptr)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << temp->data << " ]\n";
}

template <typename T>
void SinglyLinkedList<T>::displayAtIndex(int index)
{
    if (index < 0 || index >= this->nodesCount)
    {
        std::cout << "Invalid index.\n";
        return;
    }

    int count = 0;
    SinglyNode<T> *temp = head;
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

template <typename T>
T SinglyLinkedList<T>::valueAtIndex(int index) const
{
    if (!head)
    {
        std::cout << "Can't return value, linked list is empty.\n";
        return T();
    }

    if (index < 0 || index >= this->nodesCount)
    {
        std::cout << "Invalid index.\n";
        return T();
    }

    int count = 0;
    SinglyNode<T> *temp = head;
    while (temp != nullptr)
    {
        if (count == index)
            return (temp->data);
        temp = temp->next;
        count++;
    }
}

template <typename T>
void SinglyLinkedList<T>::insertAtStart(Node<T> *node)
{
    if (!node)
    {
        std::cout << "Cannot insert an empty node.\n";
        return;
    }
    SinglyNode<T> *singlyNode = static_cast<singlyNode *>(node);
    if (!head)
    {
        head = singlyNode;
        tail = singlyNode;
        singlyNode->next = nullptr;
    }
    else
    {
        singlyNode->next = head;
        head = singlyNode;
    }
    this->nodesCount++;
}

template <typename T>
void SinglyLinkedList<T>::insertAtStart(const T &value)
{
    Node<T> *temp = new Node<T>(value);
    insertAtStart(temp);
}

template <typename T>
void SinglyLinkedList<T>::insertAtEnd(Node<T> *node)
{
    if (!node)
    {
        std::cout << "Cannot insert an empty node.\n";
        return;
    }
    if (!head)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
    this->nodesCount++;
}

template <typename T>
void SinglyLinkedList<T>::insertAtEnd(const T &value)
{
    Node<T> *temp = new Node<T>(value);
    insertAtEnd(temp);
}

template <typename T>
void SinglyLinkedList<T>::insertAtIndex(Node<T> *value, int index)
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
    else
    {
        Node<T> *temp = head;
        for (int count = 0; count < index - 1; count++)
        {
            temp = temp->next;
        }
        value->next = temp->next;
        temp->next = value;
        this->nodesCount++;
    }
}

template <typename T>
void SinglyLinkedList<T>::insertAtIndex(const T &value, int index)
{

    Node<T> *valueNode = new Node<T>(value);
    insertAtIndex(valueNode, index);
}

template <typename T>
void SinglyLinkedList<T>::insertBeforeNode(
    Node<T> *value,
    Node<T> *nodeToCheck)
{
    if (!head)
    {
        std::cout << "Linked List is empty. (Not inserted)\n";
        return;
    }
    if (!nodeToCheck)
    {
        std::cout << "Cannot add before an empty node.\n";
        return;
    }

    Node<T> *temp = head;
    Node<T> *prev = nullptr;
    while (temp != nullptr)
    {
        if (temp == nodeToCheck)
        {
            if (prev == nullptr) // If nodeToCheck is the head
                insertAtStart(value);
            else
            {
                Node<T> *newValue = new Node<T>(*value);
                prev->next = newValue;
                newValue->next = temp;
                this->nodesCount++;
                return;
            }
        }
        prev = temp;
        temp = temp->next;
    }

    std::cout << "Node not found in Linked List.\n";
}

template <typename T>
void SinglyLinkedList<T>::insertBeforeNode(
    const T &value,
    Node<T> *nodeToCheck)
{
    Node<T> *valueNode = new Node<T>(value);
    insertBeforeNode(valueNode, nodeToCheck);
}

template <typename T>
void SinglyLinkedList<T>::insertAfterNode(
    Node<T> *value,
    Node<T> *nodeToCheck)
{
    if (!head)
    {
        std::cout << "Linked List is empty. (Not added)\n";
        return;
    }

    Node<T> *temp = head;
    while (temp != nullptr)
    {
        if (temp == nodeToCheck)
        {
            if (tail == temp)
                tail = value;
            else
                value->next = temp->next;
            temp->next = value;
            this->nodesCount++;
            return;
        }
        temp = temp->next;
    }

    std::cout << "Node not found in Linked List.\n";
}

template <typename T>
void SinglyLinkedList<T>::insertAfterNode(
    const T &value,
    Node<T> *nodeToCheck)
{
    Node<T> *valueNode = new Node<T>(value);
    insertAfterNode(valueNode, nodeToCheck);
}

template <typename T>
void SinglyLinkedList<T>::insertMultiple(Node<T> *valuesList, int count)
{
    // Assuming that the valuesList is also a linked list.
    if (!valuesList)
    {
        std::cout << "Cannot insert empty Linked List.\n";
        return;
    }

    if (!head)
    {
        head = valuesList;
        this->nodesCount = count;
    }
    else
    {
        Node<T> *temp = valuesList;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = head;
        head = valuesList;
        this->nodesCount += count;

        valuesList = nullptr; // releasing ownership.
    }
}

template <typename T>
void SinglyLinkedList<T>::insertMultiple(T *values, int count)
{
    if (!values || count <= 0)
    {
        std::cout << "Cannot add empty data.\n";
        return;
    }

    Node<T> *temp = head;

    while (temp && temp->next)
    {
        temp = temp->next;
    }

    for (int i = 0; i < count; i++)
    {
        Node<T> *valueNode = new Node<T>(values[i]);
        if (!temp)
            head = valueNode;
        else
            temp->next = valueNode;
        temp = valueNode;
        this->nodesCount++;
    }
    tail = temp;
}

template <typename T>
void SinglyLinkedList<T>::deleteFirst()
{
    if (!head)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }

    Node<T> *temp = head;
    head = head->next;
    if (!head)
        tail = nullptr;
    delete temp;
    this->nodesCount--;
}

template <typename T>
void SinglyLinkedList<T>::deleteLast()
{
    if (!head)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }

    if (!head->next)
    {
        delete head;
        this->nodesCount--;
        head = nullptr;
        tail = nullptr;
        return;
    }

    Node<T> *temp = head;
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
void SinglyLinkedList<T>::deleteFromIndex(int index)
{
    if (!head)
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

    Node<T> *temp = head;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    Node<T> *toDelete = temp->next;
    temp->next = temp->next->next;
    if (!temp->next)
        tail = temp;
    delete toDelete;
    this->nodesCount--;
}

template <typename T>
void SinglyLinkedList<T>::deleteByValue(const T &value)
{
    if (!head)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }

    Node<T> *temp = head;
    while (temp->next)
    {
        if (temp->next->data == value)
        {
            Node<T> *toDelete = temp->next;
            temp->next = temp->next->next;
            if (head == toDelete)
                head = head->next;
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
// void SinglyLinkedList<T>::deleteAllByValue(const T &value)
// {
//     if (!head)
//     {
//         std::cout << "Cannot delete from empty Linked List.\n";
//         return;
//     }

//     bool flag = false;
//     Node<T> *temp = head;
//     while (temp->next)
//     {
//         if (temp->next->data == value)
//         {
//             Node<T> *toDelete = temp->next;
//             temp->next = temp->next->next;
//             if (head == toDelete)
//                 head = head->next;
//             flag = true;
//             delete toDelete;
//             if (!temp->next)
//                 tail = temp;
//             this->nodesCount--;
//         }
//         temp = temp->next;
//     }

//     // if (head->data == value)
//     // {
//     //     Node<T> *toDelete = head;
//     //     head = head->next;
//     //     delete toDelete;
//     //     if (!head)
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
void SinglyLinkedList<T>::deleteAllByValue(const T &value)
{
    if (!head)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }

    bool flag = false;
    Node<T> *temp = head;
    while (temp && temp->next)
    {
        if (temp->next->data == value)
        {
            Node<T> *toDelete = temp->next;
            temp->next = temp->next->next;
            if (head == toDelete)
                head = head->next;
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
void SinglyLinkedList<T>::deleteBeforeNode(Node<T> *nodeToCheck)
{
    if (!head || !head->next)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }

    if (nodeToCheck == head)
    {
        std::cout << "Cannot delete before the given node.\n";
        return;
    }

    if (nodeToCheck == head->next)
    {
        deleteFirst();
        return;
    }

    Node<T> *temp = head;
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

template <typename T>
void SinglyLinkedList<T>::deleteAfterNode(Node<T> *nodeToCheck)
{
    if (!head)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }

    Node<T> *temp = head;
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

template <typename T>
void SinglyLinkedList<T>::clear()
{
    if (!head)
    {
        std::cout << "Cannot clear empty Linked List.\n";
        return;
    }
    Node<T> *temp = head;
    while (temp)
    {
        temp->data = T();
        temp = temp->next;
    }
}

template <typename T>
void SinglyLinkedList<T>::deleteList()
{
    if (!head)
        return;

    Node<T> *temp = head;
    while (temp)
    {
        Node<T> *nodeToDelete = temp;
        temp = temp->next;
        delete nodeToDelete;
    }
    head = nullptr;
    tail = nullptr;
    this->nodesCount = 0;
}

template <typename T>
void SinglyLinkedList<T>::deleteRange(int startIndex, int endIndex)
{
    if (!head)
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

    Node<T> *temp = head;
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
            head = nextNode;
        temp = nextNode;
    }

    if (!temp)
        tail = prev;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    Node<T> *current = head;
    while (current)
    {
        Node<T> *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    this->nodesCount = 0;
}