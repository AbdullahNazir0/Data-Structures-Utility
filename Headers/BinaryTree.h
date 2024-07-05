// ********************************************************
// Programmer: Abdullah Nazir
// Date: May 25, 2024
//
// Class BinaryTree
// This class contains members and methods to implement
// data structure binary tree. This class is inherited
// from abstract class Tree .
// ********************************************************

#ifndef H_BinaryTree
#define H_BinaryTree

#include "Tree.h"

template <typename T>
class BinaryTree : public Tree<T>
{
public:
    BinaryTree();
    void insert(TreeNode<T> *) override;
    void insert(const T &) override;
    void remove(const T &) override;
    void remove(TreeNode<T> *) override;
    void displayInOrder() const override;
    void displayPreOrder() const override;
    void displayPostOrder() const override;
    int getTreeHeight() const;
    ~BinaryTree();

private:
    void helpInsert(TreeNode<T> *&, TreeNode<T> *);
    void helpRemove(TreeNode<T> *&, const T &);
    void inOrder(TreeNode<T> *) const;
    void preOrder(TreeNode<T> *) const;
    void postOrder(TreeNode<T> *) const;
    int treeHeight(TreeNode<T> *) const;
    void destroyTree(TreeNode<T> *&);
};

#include "../Implementations/BinaryTreeImpl.cpp"

#endif // H_BinaryTree