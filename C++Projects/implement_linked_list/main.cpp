#include <iostream>
#include "linked_list.h"

const char INSERT_FIRST = '1';
const char INSERT_LAST = '2';
const char REMOVE_FIRST = '3';
const char REMOVE_LAST = '4';

void description() {
    std::cout << "Please input number of your choice." << std::endl;
    std::cout << "1: Insert the number to top of list." << std::endl;
    std::cout << "2: Insert the number to end of list." << std::endl;
    std::cout << "3: Remove the number from top of list." << std::endl;
    std::cout << "4: Remove the number from end of list." << std::endl;
    std::cout << "Else: end this program." << std::endl;
}

char questionAndReceiveChoice() {
    description();

    std::cout << std::endl << "=> ";

    char answer;
    std::cin >> answer;
    std::cout << std::endl; // for format

    return answer;
}

int receiveInputNumber() {
    std::cout << "Please input the number you want to store." << std::endl;
    std::cout << "=> ";

    int input;
    std::cin >> input;
    std::cout << std::endl; // for format

    return input;
}

void insertFirst(LinkedList *ll, int target) {
    ll->insertFirst(target);
    std::cout << "insert this number: " << target << std::endl;
    ll->print();
    std::cout << std::endl; // for format
}

void insertLast(LinkedList *ll, int target) {
    ll->insertLast(target);
    std::cout << "insert this number: " << target << std::endl;
    ll->print();
    std::cout << std::endl; // for format
}

void removeFirst(LinkedList *ll) {
    if (ll->removeFirst()) {
        std::cout << "Removed a number from top." << std::endl;
        std::cout << "remainder: ";
        ll->print();
        std::cout << std::endl;
    } else {
        std::cout << "Nothing to do..." << std::endl << std::endl;
    }
}

void removeLast(LinkedList *ll) {
    if (ll->removeLast()) {
        std::cout << "Removed a number from end." << std::endl;
        std::cout << "remainder: ";
        ll->print();
        std::cout << std::endl;
    } else {
        std::cout << "Nothing to do..." << std::endl << std::endl;
    }
}

int main() {
    LinkedList linkedList;

    bool done = false;
    while (!done) {
        switch (questionAndReceiveChoice()) {
            case INSERT_FIRST:
                insertFirst(&linkedList, receiveInputNumber());
                break;
            case INSERT_LAST:
                insertLast(&linkedList, receiveInputNumber());
                break;
            case REMOVE_FIRST:
                removeFirst(&linkedList);
                break;
            case REMOVE_LAST:
                removeLast(&linkedList);
                break;
            default:
                std::cout << "Thank you for using this program." << std::endl;
                done = true;
                break;
        }
    }

    return 0;
}