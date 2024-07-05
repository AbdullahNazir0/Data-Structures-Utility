#include <iostream>
#include "Headers/AVLTree.h"
using namespace std;

int main()
{

    AVLTree<int> avl;
    avl.displayInOrder();

    // 15, 6, 23, 4, 7, 17, 29, 3, 5, 8, 20
    avl.insert(15);
    avl.insert(6);
    avl.insert(23);
    avl.insert(4);
    avl.insert(7);
    avl.insert(17);
    avl.insert(29);
    avl.insert(3);
    avl.insert(5);
    avl.insert(8);
    avl.insert(20);
    // avl.insert(6);

    avl.displayInOrder();
    avl.displayPreOrder();
    avl.displayPostOrder();

    avl.remove(3);
    avl.remove(5);
    avl.remove(8);
    avl.remove(20);
    avl.remove(29);
    avl.remove(7);
    avl.remove(17);
    avl.remove(6);
    avl.remove(4);
    avl.remove(23);
    avl.remove(15);

    avl.displayInOrder();
    avl.displayPreOrder();
    avl.displayPostOrder();

    return (0);
}