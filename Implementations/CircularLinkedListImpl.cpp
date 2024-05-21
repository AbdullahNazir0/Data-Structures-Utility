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
#include <vector>

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
    Node<T> *prev = nullptr;
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
void CircularLinkedList<T>::insertMultiple(T *dataArray, int count) // Need to get array reference to calculate its size.
{
    if (!dataArray || count <= 0)
    {
        std::cout << "Cannot add empty data.\n";
        return;
    }

    // Function caller will be responsible for the validation.
    // if (dataArray.size() != count)
    // {
    //     std::cout << "Array items and count not match. (not inserted)\n";
    //     return;
    // }

    Node<T> *listToAdd = nullptr;
    Node<T> *temp = nullptr;
    for (int i = 0; i < count; i++)
    {
        Node<T> *newNode = new Node<T>(dataArray[i]);
        if (!listToAdd)
        {
            listToAdd = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    insertMultiple(listToAdd, count);
}

template <typename T>
void CircularLinkedList<T>::insertMultiple(Node<T> *dataNodes, int count)
{
    // Assuming that dataNodes is also a linked list.
    if (!dataNodes)
    {
        std::cout << "Cannot add empty linked list.\n";
        return;
    }

    if (!this->head)
    {
        this->head = dataNodes;
        Node<T> *temp = this->head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = this->head;
        this->nodesCount = count;
        return;
    }

    Node<T> *temp = dataNodes;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = this->head;
    Node<T> *tempMain = this->head;
    while (tempMain->next != this->head)
        tempMain = tempMain->next;
    tempMain->next = dataNodes;
    this->head = dataNodes;
    this->nodesCount += count;
    dataNodes = nullptr; // Taking ownership from dataNodes for the integrity of list.
}

template <typename T>
void CircularLinkedList<T>::deleteFirst()
{
    if (!this->head)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }
    if (this->head->next == this->head)
    {
        delete this->head;
        this->head = nullptr;
        this->nodesCount--; // 0
        return;
    }

    Node<T> *temp = this->head;
    while (temp->next != this->head)
        temp = temp->next;
    temp->next = this->head->next;
    Node<T> *nodeToDelete = this->head;
    this->head = this->head->next;
    delete nodeToDelete;
    this->nodesCount--;
}

template <typename T>
void CircularLinkedList<T>::deleteLast()
{
    if (!this->head)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }

    if (this->head->next == this->head)
    {
        delete this->head;
        this->head = nullptr;
        this->nodesCount--; // 0
        return;
    }

    Node<T> *temp = this->head;
    Node<T> *prev = nullptr;
    while (temp->next != this->head)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = this->head;
    if (prev == this->head)
        this->head->next = this->head;
    delete temp;
    this->nodesCount--;
}

template <typename T>
void CircularLinkedList<T>::deleteFromIndex(int)
{
}

template <typename T>
void CircularLinkedList<T>::deleteByValue(const T &value)
{
    if (!this->head)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }

    Node<T> *temp = this->head;
    Node<T> *prev = nullptr;
    do
    {
        if (temp->data == value)
        {
            if (temp == this->head)
            {
                deleteFirst();
                return;
            }
            else
            {
                prev->next = temp->next;
                delete temp;
                this->nodesCount--;
                return;
            }
        }
        prev = temp;
        temp = temp->next;
    } while (temp != this->head);

    std::cout << "Cannot find " << value << " in Linked List.\n";
}

template <typename T>
void CircularLinkedList<T>::deleteAllByValue(const T &value)
{
    if (!this->head)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }

    Node<T> *temp = this->head;
    Node<T> *prev = nullptr;
    bool flag = false;
    do
    {
        if (temp->data == value)
        {
            if (temp == this->head)
            {
                deleteFirst();
                flag = true;
            }
            else
            {
                prev->next = temp->next;
                delete temp;
                this->nodesCount--;
                flag = true;
                temp = prev->next;
            }
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    } while (temp != this->head);

    if (flag == false)
        std::cout << "Cannot find " << value << " in Linked List.\n";
}

template <typename T>
void CircularLinkedList<T>::deleteBeforeNode(Node<T> *)
{
}

template <typename T>
void CircularLinkedList<T>::deleteAfterNode(Node<T> *nodeToCheck)
{
    if (!this->head)
    {
        std::cout << "Cannot delete from empty Linked List.\n";
        return;
    }

    std::cout << " Node not found.\n ";
}

template <typename T>
void CircularLinkedList<T>::clear()
{
    if (!this->head)
    {
        std::cout << "Cannot clear empty linked list.\n";
        return;
    }

    Node<T> *temp = this->head;
    do
    {
        temp->data = T();
        temp = temp->next;
    } while (temp != this->head);
}

template <typename T>
void CircularLinkedList<T>::deleteList()
{
    if (!this->head)
    {
        std::cout << "Cannot delete empty linked list.\n";
        return;
    }

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

template <typename T>
void CircularLinkedList<T>::deleteRange(int start, int end)
{
    if (!this->head)
    {
        std::cout << "Cannot delete range from empty linked list.\n";
        return;
    }

    if (start < 0 || end > this->nodesCount || start >= end)
    {
        std::cout << "Invalid range.\n";
        return;
    }

    if (start == 0)
    {
        int count = 0;
        while (count < end)
        {
            deleteFirst();
            count++;
        }
        if (this->nodesCount == 0)
            this->head = nullptr;
        return;
    }

    Node<T> *temp = this->head;
    int count = 0;
    do
    {
        if (count == start - 1)
            break;
        temp = temp->next;
        count++;
    } while (temp != this->head);
    for (int i = start; i < end; i++)
    {
        Node<T> *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        this->nodesCount--;
    }

    if (this->nodesCount == 0)
    {
        this->head = nullptr;
    }
}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList()
{
    // if (!this->head)
    //     return;

    // Node<T> *temp = this->head;
    // do
    // {
    //     Node<T> *nodeToDelete = temp;
    //     temp = temp->next;
    //     delete nodeToDelete;
    // } while (temp != this->head);
    // this->head = nullptr;
    // this->nodesCount = 0;

    deleteList();
}