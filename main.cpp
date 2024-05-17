#include <iostream>
#include "Headers/DoublyLinkedList.h"

using namespace std;

int main()
{
    // Create a DoublyLinkedList object
    DoublyLinkedList<int> list;

    // Test insertAtStart and insertAtEnd functions
    list.insertAtStart(1);
    list.insertAtEnd(3);
    list.insertAtStart(0);
    list.insertAtEnd(4);

    // Test insertAtIndex function
    list.insertAtIndex(2, 2);

    // Test insertBeforeNode function
    Node<int> *nodeToInsertBefore = list.findNode(3);
    if (nodeToInsertBefore)
        list.insertBeforeNode(2, nodeToInsertBefore);

    // Test insertAfterNode function
    Node<int> *nodeToInsertAfter = list.findNode(3);
    if (nodeToInsertAfter)
        list.insertAfterNode(4, nodeToInsertAfter);

    // Test insertMultiple function with array
    int values[] = {5, 6, 7};
    list.insertMultiple(values, 3);

    // Test display functions
    std::cout << "Original List:\n";
    list.display();
    std::cout << "Reversed List:\n";
    list.displayReversed();
    // list.display();
    std::cout << "Formatted List:\n";
    list.displayFormatted();
    std::cout << "Formatted and Reversed List:\n";
    list.displayFormattedAndReversed();

    // Test displayAtIndex function
    std::cout << "Data at index 3: ";
    list.displayAtIndex(3);

    return 0;
}
