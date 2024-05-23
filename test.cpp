#include <iostream>
#include "Headers/SinglyLinkedList.h"
#include "Headers/CircularLinkedList.h"
#include "Headers/DoublyLinkedList.h"

using namespace std;

int main()
{

    SinglyLinkedList<int> sll;
    cout << "Test 1 passed.\n";

    CircularLinkedList<int> cll;
    cout << "Test 2 passed.\n";

    DoublyLinkedList<int> dll;
    cout << "Test 3 passed.\n";

    return 0;
}