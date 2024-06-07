// ********************************************************
// Programmer: Abdullah Nazir
// Date: June 02, 2024
//
// Class BinarySearchTree
// This class contains members and methods to implement
// data structure binary search tree. This class is inherited
// from abstract class Tree .
// ********************************************************

#ifndef H_BinarySearchTree
#define H_BinarySearchTree

#include "Tree.h"

template <typename T>
class BinarySearchTree : public Tree<T>
{
    public:
        BinarySearchTree();
        void insert(TreeNode<T> *) override;
        void insert(const T &) override;
        void remove(const T &) override;
        void remove(TreeNode<T> *) override;
        void displayInOrder() const override;
        void displayPreOrder() const override;
        void displayPostOrder() const override;
        ~BinarySearchTree();

    private:
        void subInsert(TreeNode<T> *, TreeNode<T> *);
        void subRemove(TreeNode<T> *, TreeNode<T> *);
        void inOrder(TreeNode<T> *) const;
        void preOrder(TreeNode<T> *) const;
        void postOrder(TreeNode<T> *) const;
};

#include "../Implementations/BinarySearchTreeImpl.cpp"

#endif