#include "BinaryTree.h"

BinaryTree::BinaryTree() {
    this->root = new Node();
}

BinaryTree::BinaryTree(string data) {
    this->root = new Node(data);
}

BinaryTree::~BinaryTree() {
    delete this->root;
}

int BinaryTree::addData(string data) {
    return this->root->addData(data);
}

void BinaryTree::sortedPrint() {
    this->root->sortedPrint(this->root);
}
