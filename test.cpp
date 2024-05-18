#include <iostream>
#include "./Headers/LinkedListStack.h"
#include "./Headers/ArrayStack.h"

using namespace std;

int main()
{

    LinkedListStack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    stack.display();

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    stack.display();

    return 0;
}