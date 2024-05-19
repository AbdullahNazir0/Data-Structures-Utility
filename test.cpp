#include <iostream>
#include "./Headers/ArrayQueue.h"

using namespace std;

int main()
{

    ArrayQueue<int> queue;

    std::cout << "Test 1 passed..\n";

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    queue.display();

    cout << queue.getFront() << '\n';

    cout << queue.getRear() << '\n';

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    queue.display();

    queue.clear();

    queue.display();

    queue.clear();

    return 0;
}