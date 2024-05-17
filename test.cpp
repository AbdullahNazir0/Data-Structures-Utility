#include <iostream>
#include "./Headers/CircularLinkedList.h"
#include "./Headers/Node.h"

using namespace std;

int main()
{

    cout << "First Test Passed..\n";

    CircularLinkedList<int> list;

    list.display();
    // list.displayFormatted();

    cout << "Second Test Passed..\n";

    // list.insertAtStart(5);
    // list.insertAtStart(4);
    // list.insertAtStart(3);
    // list.insertAtStart(2);
    // list.insertAtStart(1);

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);

    list.display();
    // list.displayFormatted();

    cout << "Third Test Passed..\n";

    cout << "At index 2: ";
    list.displayAtIndex(2);

    cout << "Fourth test passed..\n";

    list.insertAtIndex(2, 2);
    list.insertAtIndex(5, 5);
    list.insertAtIndex(5, 7);

    list.display();
    // list.displayFormatted();

    cout << "Fifth test passed..\n";

    Node<int> *node = new Node<int>(10);
    list.insertAtEnd(node);

    list.display();
    // list.displayFormatted();

    cout << "Sixth test passed..\n";

    // list.insertBeforeNode(7, node);
    list.insertAfterNode(7, node);

    list.display();
    // list.displayFormatted();

    cout << "Seventh test passed..\n";

    return 0;
}