#include <iostream>
#include "TowerOfHanoi.h"
#include "../../Headers/ArrayStack.h"

using namespace std;

int main()
{

    ArrayStack<int> source(5), auxiliary(5), destination(5);

    source.push(1);
    source.push(2);
    source.push(3);
    source.push(4);
    source.push(5);

    cout << "Source ";
    source.display();
    cout << "Auxialiary ";
    auxiliary.display();
    cout << "Destination ";
    destination.display();

    towerOfHanoi<int>(5, source, auxiliary, destination);

    cout << "Source ";
    source.display();
    cout << "Auxialiary ";
    auxiliary.display();
    cout << "Destination ";
    destination.display();

    return 0;
}