#ifndef IMPLEMENT_LINKED_LIST_LINKEDLIST_H
#define IMPLEMENT_LINKED_LIST_LINKEDLIST_H

class ListNode {
public:
    ListNode(const int &);
    ~ListNode();
private:
    int data;
    ListNode *nextPtr;
    friend class LinkedList;
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    bool isEmpty();
    void insertFirst(const int &);
    void insertLast(const int &);
    bool removeFirst();
    bool removeLast();
    void print();

    ListNode *getNewNode(const int &);

private:
    ListNode *firstNode;
    ListNode *lastNode;
};

#endif //IMPLEMENT_LINKED_LIST_LINKEDLIST_H
