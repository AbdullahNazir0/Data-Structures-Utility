// ********************************************************
// Programmer: Abdullah Nazir
// Date: July 05, 2024
//
// Class AVLTree
// This class contains members and methods to implement
// data structure self balancing tree: AVL tree. This class
//  is inherited from abstract class Tree .
// ********************************************************

#ifndef H_AVLTree
#define H_AVLTree

#include "Tree.h"

template <typename T>
class AVLTree : Tree<T>
{
public:
    AVLTree();
    // public functions.
    void insert(TreeNode<T> *) override;
    void insert(const T &) override;
    void remove(const T &) override;
    void remove(TreeNode<T> *) override;
    void displayInOrder() const override;
    void displayPreOrder() const override;
    void displayPostOrder() const override;
    void searchValue(const T &) const;
    int getTreeHeight() const;
    int getNodeHeight(const T &) const;
    void getMin() const;
    void getMax() const;
    void getSuccessor(const T &) const;
    void getPredecessor(const T &) const;
    int getDiameter() const;
    ~AVLTree();

private:
    // private helper functions.
    void helpInsert(TreeNode<T> *&, TreeNode<T> *);
    void helpRemove(TreeNode<T> *&, const T &);
    void inorder(TreeNode<T> *) const;
    void preorder(TreeNode<T> *) const;
    void postorder(TreeNode<T> *) const;
    TreeNode<T> *searchNode(TreeNode<T> *, const T &) const;
    int nodeHeight(TreeNode<T> *) const;
    void search(TreeNode<T> *, const T &) const;
    int findBalanceFactor(TreeNode<T> *) const;
    void leftRotate(TreeNode<T> *&);
    void rightRotate(TreeNode<T> *&);
    void leftRightRotate(TreeNode<T> *&);
    void rightLeftRotate(TreeNode<T> *&);
    void min(TreeNode<T> *) const;
    void max(TreeNode<T> *) const;
    TreeNode<T> *successor(TreeNode<T> *, const T &) const;
    TreeNode<T> *predecessor(TreeNode<T> *, const T &) const;
    int diameter(TreeNode<T> *) const;
    void destroyTree(TreeNode<T> *&);
};

#include "../Implementations/AVLTreeImpl.cpp"

#endif