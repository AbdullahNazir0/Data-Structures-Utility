#include <iostream>
#include "Headers/MaxHeap.h"
#include "Headers/MinHeap.h"

using namespace std;

int main()
{

    MinHeap<int> min_heap;
    MaxHeap<int> max_heap;

    min_heap.insert(10);
    min_heap.insert(30);
    min_heap.insert(20);
    min_heap.insert(40);
    min_heap.insert(50);

    max_heap.insert(10);
    max_heap.insert(30);
    max_heap.insert(20);
    max_heap.insert(40);
    max_heap.insert(50);

    cout << "Min Heap: ";
    min_heap.display();

    cout << "Max Heap: " ;
    max_heap.display();

    min_heap.heapSort();
    max_heap.heapSort();

    cout << "Min Heap: ";
    min_heap.display();

    cout << "Max Heap: ";
    max_heap.display();

    return (0);
}