#include "BinaryTree.h"

void Node::addLeft(const int &left) {
    Node *leftNode;
    leftNode = new Node(left);
    this->left = leftNode;
}

void Node::addRight(const int &right) {
    Node *rightNode;
    rightNode = new Node(right);
    this->right = rightNode;
}

Node::Node() {
    this->data = NULL;
    this->left = NULL;
    this->right = NULL;
}

Node::Node(const int &root) {
    this->data = root;
    this->left = NULL;
    this->right = NULL;
}

Node::~Node() {
    if (this->right != NULL) delete this->right;
    if (this->left != NULL) delete this->left;
}

int Node::addData(const int &data) {
    int ret;

    if (this->data == NULL) {
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

bool Node::isData(const int &data) {
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

int Node::getData() {
    return this->data;
}

Node *Node::getLeft() {
    return this->left;
}

Node *Node::getRight() {
    return this->right;
}

bool Node::hasLeft() {
    return this->left != NULL;
}

bool Node::hasRight() {
    return this->right != NULL;
}

void Node::output() {
    std::cout << this->data << " ";
}

void Node::inOrderTraversal(Node *node) {
    if (node->left != NULL) {
        node->inOrderTraversal(node->left);
    }
    node->output();
    if (node->right != NULL) {
        node->inOrderTraversal(node->right);
    }
}

void Node::postOrderTraversal(Node *node) {
    if (node->left != NULL) {
        node->postOrderTraversal(node->left);
    }
    if (node->right != NULL) {
        node->postOrderTraversal(node->right);
    }
    node->output();
}

void Node::preOrderTraversal(Node *node) {
    node->output();
    if (node->left != NULL) {
        node->preOrderTraversal(node->left);
    }
    if (node->right != NULL) {
        node->preOrderTraversal(node->right);
    }
}