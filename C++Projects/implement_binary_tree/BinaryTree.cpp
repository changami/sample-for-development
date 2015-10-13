#include "BinaryTree.h"

BinaryTree::BinaryTree() {
    this->root = new Node();
}

BinaryTree::BinaryTree(const int &data) {
    this->root = new Node(data);
}

BinaryTree::~BinaryTree() {
    delete this->root;
}

int BinaryTree::addData(const int &data) {
    return this->root->addData(data);
}

void BinaryTree::inOrderPrint() {
    this->root->inOrderTraversal(this->root);
    std::cout << std::endl;
}

void BinaryTree::postOrderPrint() {
    this->root->postOrderTraversal(this->root);
    std::cout << std::endl;
}

void BinaryTree::preOrderPrint() {
    this->root->preOrderTraversal(this->root);
    std::cout << std::endl;
}

void BinaryTree::find(const int &target) {
    bool done = false;
    Node *targetRoot;
    targetRoot = this->root;

    while (!done) {
        targetRoot->preOrderTraversal(targetRoot);
        std::cout << std::endl;

        if (targetRoot->getData() == target) {
            std::cout << "There is in this tree!: " << targetRoot->getData() << std::endl;
            std::cout << std::endl;
            done = true;
        } else if (targetRoot->getData() > target && targetRoot->hasLeft()) {
            targetRoot = targetRoot->getLeft();
        } else if (targetRoot->getData() < target && targetRoot->hasRight()) {
            targetRoot = targetRoot->getRight();
        } else {
            std::cout << "Not found in this tree.: " << target << std::endl;
            std::cout << std::endl;
            done = true;
        }
    }
}