#include <iostream>
#include "Headers/BinarySearchTree.h"

using namespace std;

template <typename T>
using BST = BinarySearchTree<T>;

int main()
{

    BST<int> bst;
    bst.displayInOrder();

    // 15, 6, 23, 4, 7, 17, 29, 3, 5, 8, 20
    bst.insert(15);
    bst.insert(6);
    bst.insert(23);
    bst.insert(4);
    bst.insert(7);
    bst.insert(17);
    bst.insert(29);
    bst.insert(3);
    bst.insert(5);
    bst.insert(8);
    bst.insert(20);
    // bst.insert(6);

    bst.displayInOrder();
    bst.displayPreOrder();
    bst.displayPostOrder();

    bst.remove(3);
    bst.remove(5);
    bst.remove(8);
    bst.remove(20);
    bst.remove(29);
    bst.remove(7);
    bst.remove(17);
    bst.remove(6);
    bst.remove(4);
    bst.remove(23);
    bst.remove(15);

    bst.displayInOrder();
    bst.displayPreOrder();
    bst.displayPostOrder();

    return (0);
}