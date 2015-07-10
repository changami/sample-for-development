#include <iostream>
#include "linked_list.h"

LinkedList::LinkedList() {
    this->firstNode = nullptr;
    this->lastNode = nullptr;
}

LinkedList::~LinkedList() {
    // default
}

bool LinkedList::isEmpty() {
    return this->firstNode == nullptr;
}

void LinkedList::insertFirst(const int &data) {
    ListNode *newNode = getNewNode(data);

    if (isEmpty()) {
        this->firstNode = this->lastNode = newNode;
    } else {
        newNode->nextPtr = this->firstNode;
        this->firstNode = newNode;
    }
}

void LinkedList::insertLast(const int &data) {
    ListNode *newNode = getNewNode(data);

    if (isEmpty()) {
        this->firstNode = this->lastNode = newNode;
    } else {
        this->lastNode->nextPtr = newNode;
        this->lastNode = newNode;
    }
}

void LinkedList::print() {
    if (isEmpty()) {
        std::cout << "This list is empty..." << std::endl;
    } else {
        ListNode *currentPtr = this->firstNode;
        while (currentPtr != nullptr) {
            std::cout << currentPtr->data << " ";
            currentPtr = currentPtr->nextPtr;
        }
    }
}

bool LinkedList::removeFirst() {
    if (isEmpty()) {
        return false;
    }

    if (this->firstNode == this->lastNode) {
        delete(this->firstNode);
        this->firstNode = nullptr;
        this->lastNode = nullptr;
    } else {
        ListNode *temporaryNode = this->firstNode->nextPtr;
        delete(this->firstNode);
        this->firstNode = temporaryNode;
    }
    return true;
}

bool LinkedList::removeLast() {
    if (isEmpty()) {
        return false;
    }

    if (this->firstNode == this->lastNode) {
        delete (this->lastNode);
        this->firstNode = nullptr;
        this->lastNode = nullptr;
    } else {
        ListNode *currentNode = this->firstNode;
        while (currentNode->nextPtr != this->lastNode) {
            currentNode = currentNode->nextPtr;
        }
        currentNode->nextPtr = nullptr;
        delete (this->lastNode);
        this->lastNode = currentNode;
    }
    return true;
}

ListNode *LinkedList::getNewNode(const int &data) {
    return new ListNode(data);
}