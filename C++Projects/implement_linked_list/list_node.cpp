#include <iostream>
#include "linked_list.h"

ListNode::ListNode(const int &data) {
    this->data = data;
    this->nextPtr = nullptr;
}

ListNode::~ListNode() {
    // default
}