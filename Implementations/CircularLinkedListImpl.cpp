// ********************************************************
// Programmer: Abdullah Nazir
// Date: May 17, 2024
//
// Implementation file CircularLinkedListImpl.cpp
// This file contains implementations of the functions
//  declared in the class CircularLinkedList .
// ********************************************************

#include "../Headers/CircularLinkedList.h"
#include <iostream>

template <typename T>
CircularLinkedList<T>::CircularLinkedList()
{
    // Base class already initializes head to nullptr
    //  and nodesCount to 0.
}

template <typename T>
void CircularLinkedList<T>::display() const
{
    if (!this->head)
    {
        std::cout << "Linked List is empty.\n";
        return;
    }

    std::cout << "Linked List Data: ";
    Node<T> *temp = this->head;
    while (temp->next != this->head)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << temp->data << "\n";
}

template <typename T>
void CircularLinkedList<T>::displayFormatted() const
{
    if (!this->head)
    {
        std::cout << "Linked List is empty.\n";
        return;
    }

    std::cout << "[ ";
    Node<T> *temp = this->head;
    while (temp->next != this->head)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << temp->data << " ]\n";
}

template <typename T>
void CircularLinkedList<T>::displayAtIndex(int index)
{
    if (!this->head)
    {
        std::cout << "Can't find index, linked list is empty.\n";
        return;
    }
    if (index < 0 || index >= this->nodesCount)
    {
        std::cout << "Invalid index.\n";
        return;
    }

    int count = 0;
    Node<T> *temp = this->head;
    do
    {
        if (count == index)
        {
            std::cout << temp->data << '\n';
            return;
        }
        temp = temp->next;
        count++;

    } while (temp != this->head);
}

template <typename T>
void CircularLinkedList<T>::insertAtStart(const T &data)
{
    Node<T> *newNode = new Node<T>(data);

    insertAtStart(newNode);
}

template <typename T>
void CircularLinkedList<T>::insertAtStart(Node<T> *dataNode)
{
    if (!this->head)
    {
        this->head = dataNode;
        this->head->next = this->head;
    }
    else
    {
        dataNode->next = this->head;
        Node<T> *temp = this->head;
        while (temp->next != this->head)
        {
            temp = temp->next;
        }
        temp->next = dataNode;
        this->head = dataNode;
    }
    this->nodesCount++;
}

template <typename T>
void CircularLinkedList<T>::insertAtEnd(const T &data)
{
    Node<T> *newNode = new Node<T>(data);

    insertAtEnd(newNode);
}

template <typename T>
void CircularLinkedList<T>::insertAtEnd(Node<T> *dataNode)
{
    if (!this->head)
    {
        this->head = dataNode;
        this->head->next = this->head;
    }
    else
    {
        Node<T> *temp = this->head;
        while (temp->next != this->head)
            temp = temp->next;
        temp->next = dataNode;
        dataNode->next = this->head;
    }
    this->nodesCount++;
}

template <typename T>
void CircularLinkedList<T>::insertAtIndex(
    const T &data,
    int index)
{
    Node<T> *newNode = new Node<T>(data);

    insertAtIndex(newNode, index);
}

template <typename T>
void CircularLinkedList<T>::insertAtIndex(
    Node<T> *dataNode,
    int index)
{
    if (index < 0 || index > this->nodesCount)
    {
        std::cout << "Invalid index.\n";
        return;
    }
    if (index == 0)
        insertAtStart(dataNode);

    int count = 0;
    Node<T> *temp = this->head;
    do
    {
        if (count == index - 1)
        {
            dataNode->next = temp->next;
            temp->next = dataNode;
            this->nodesCount++;
            return;
        }
        temp = temp->next;
        count++;
    } while (temp != this->head);
}

template <typename T>
void CircularLinkedList<T>::insertBeforeNode(
    const T &data,
    Node<T> *nodeToCheck)
{
    Node<T> *newNode = new Node<T>(data);

    insertBeforeNode(newNode, nodeToCheck);
}

template <typename T>
void CircularLinkedList<T>::insertBeforeNode(
    Node<T> *dataNode,
    Node<T> *nodeToCheck)
{
    if (!this->head)
    {
        std::cout << "Linked List is empty. (not inserted)\n";
        return;
    }

    if (nodeToCheck == this->head)
    {
        insertAtStart(dataNode);
        return;
    }

    Node<T> *temp = this->head->next;
    Node<T> *prev = this->head;
    while (temp != this->head)
    {
        if (temp == nodeToCheck)
        {
            prev->next = dataNode;
            dataNode->next = temp;
            this->nodesCount++;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    std::cout << "Node not found in Linked List.\n";
}

template <typename T>
void CircularLinkedList<T>::insertAfterNode(
    const T &data,
    Node<T> *nodeToCheck)
{
    Node<T> *newNode = new Node<T>(data);

    insertAfterNode(newNode, nodeToCheck);
}

template <typename T>
void CircularLinkedList<T>::insertAfterNode(
    Node<T> *dataNode,
    Node<T> *nodeToCheck)
{
    if (!this->head)
    {
        std::cout << "Linked List is empty. (not inserted)\n";
        return;
    }

    // --> no need for this check.
    // if(nodeToCheck->next == this->head) // check for last node.
    // {
    //     insertAtEnd(dataNode);
    //     return;
    // }

    Node<T> *temp = this->head;
    do
    {
        if (temp == nodeToCheck)
        {
            dataNode->next = temp->next;
            temp->next = dataNode;
            this->nodesCount++;
            return;
        }
        temp = temp->next;
    } while (temp != this->head);

    std::cout << "Node not found in Linked List.\n";
}

template <typename T>
void CircularLinkedList<T>::insertMultiple(T *dataArray, int count)
{
    if (!dataArray || count <= 0)
    {
        std::cout << "Cannot add empty data.\n";
        return;
    }

    int size = sizeof(dataArray) / sizeof(dataArray[0]);
    if (size != count)
    {
        std::cout << "Array items and count not match. (not inserted)\n";
        return;
    }

    // continue from here. ->
}

template <typename T>
void CircularLinkedList<T>::insertMultiple(Node<T> *, int)
{
}

template <typename T>
void CircularLinkedList<T>::deleteFirst()
{
}

template <typename T>
void CircularLinkedList<T>::deleteLast()
{
}

template <typename T>
void CircularLinkedList<T>::deleteFromIndex(int)
{
}

template <typename T>
void CircularLinkedList<T>::deleteByValue(const T &)
{
}

template <typename T>
void CircularLinkedList<T>::deleteAllByValue(const T &)
{
}

template <typename T>
void CircularLinkedList<T>::deleteBeforeNode(Node<T> *)
{
}

template <typename T>
void CircularLinkedList<T>::deleteAfterNode(Node<T> *)
{
}

template <typename T>
void CircularLinkedList<T>::clear()
{
}

template <typename T>
void CircularLinkedList<T>::deleteList()
{
}

template <typename T>
void CircularLinkedList<T>::deleteRange(int, int)
{
}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList()
{
    if (!this->head)
        return;

    Node<T> *temp = this->head;
    do
    {
        Node<T> *nodeToDelete = temp;
        temp = temp->next;
        delete nodeToDelete;
    } while (temp != this->head);
    this->head = nullptr;
    this->nodesCount = 0;
}