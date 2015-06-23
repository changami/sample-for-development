#include "BinaryTree.h"

void Node::addLeft(string left) {
    Node *leftNode;
    leftNode = new Node(left);
    this->left = leftNode;
}

void Node::addRight(string right) {
    Node *rightNode;
    rightNode = new Node(right);
    this->right = rightNode;
}

Node::Node() {
    this->data = "";
    this->left = NULL;
    this->right = NULL;
}

Node::Node(string data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

Node::~Node() {
    if (this->right != NULL) delete this->right;
    if (this->left != NULL) delete this->left;
}

int Node::addData(string data) {
    int ret;

    if (this->data == "") {
        this->data = data;
        ret = 1;
    } else if (this->data > data) {
        if (this->left == NULL) {
            this->addLeft(data);
            ret = 1;
        } else {
            ret = this->left->addData(data);
        }
    } else if (this->data < data) {
        if (this->right == NULL) {
            this->addRight(data);
            ret = 1;
        } else {
            ret = this->right->addData(data);
        }
    } else {
        ret = 0;
    }

    return ret;
}

bool Node::isData(string data) {
    bool ret;

    if (this->data > data) {
        if (this->left == NULL) {
            ret = false;
        } else {
            ret = this->left->isData(data);
        }
    } else if (this->data < data) {
        if (this->right == NULL) {
            ret = false;
        } else {
            ret = this->right->isData(data);
        }
    } else {
        ret = true;
    }

    return ret;
}

void Node::output() {
    std::cout << this->data << std::endl;
}

void Node::sortedPrint(Node *node) {
    if (node->left != NULL) {
        node->sortedPrint(node->left);
    }
    node->output();
    if (node->right != NULL) {
        node->sortedPrint(node->right);
    }
}