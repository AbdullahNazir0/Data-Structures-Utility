#include <iostream>
#include "Headers/SinglyLinkedList.h"
#include "Headers/CircularLinkedList.h"
#include "Headers/DoublyLinkedList.h"

using namespace std;

int main()
{

    SinglyLinkedList<int> sll;
    sll.display();
    sll.insertAtEnd(1);
    sll.display();
    cout << "Test 1 passed.\n";

    CircularLinkedList<int> cll;
    cll.display();
    cll.insertAtEnd(1);
    cll.display();
    cout << "Test 2 passed.\n";

    DoublyLinkedList<int> dll;
    dll.display();
    dll.insertAtEnd(1);
    dll.display();
    cout << "Test 3 passed.\n";
    dll.insertAtStart(0);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtEnd(4);
    dll.insertAtEnd(5);
    dll.display();
    dll.displayReversed();

    dll.displayFormatted();

    int arr[5];
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}