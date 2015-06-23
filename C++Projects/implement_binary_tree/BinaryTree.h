#ifndef IMPLEMENT_BINARY_TREE_BINARYTREE_H
#define IMPLEMENT_BINARY_TREE_BINARYTREE_H


#include <iostream>

using std::string;

class Node {
    string data;
    Node *left;
    Node *right;

    void addLeft(string);

    void addRight(string);

public:
    Node();

    Node(string);

    ~Node();

    int addData(string);

    bool isData(string);

    void output();

    void sortedPrint(Node *);
};

class BinaryTree {
    Node *root;
public:
    BinaryTree();

    BinaryTree(string);

    ~BinaryTree();

    int addData(string);

    void sortedPrint();
};

#endif //IMPLEMENT_BINARY_TREE_BINARYTREE_H
