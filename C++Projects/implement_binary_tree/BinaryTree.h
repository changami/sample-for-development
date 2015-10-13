#ifndef IMPLEMENT_BINARY_TREE_BINARYTREE_H
#define IMPLEMENT_BINARY_TREE_BINARYTREE_H


#include <iostream>

class Node {
    int data;
    Node *left;
    Node *right;

    void addLeft(const int &);

    void addRight(const int &);

public:
    Node();

    Node(const int &);

    ~Node();

    int addData(const int &);

    bool isData(const int &);

    int getData();

    Node *getLeft();

    Node *getRight();

    bool hasLeft();

    bool hasRight();

    void output();

    void inOrderTraversal(Node *);

    void postOrderTraversal(Node *);

    void preOrderTraversal(Node *);
};

class BinaryTree {
    Node *root;
public:
    BinaryTree();

    BinaryTree(const int &);

    ~BinaryTree();

    int addData(const int &);

    void inOrderPrint();

    void postOrderPrint();

    void preOrderPrint();

    void find(const int &);
};

#endif //IMPLEMENT_BINARY_TREE_BINARYTREE_H
