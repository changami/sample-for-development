#include <iostream>
#include "BinaryTree.h"

/*
 * Creating to use BinaryTree Program.
 *
 * 10 Integers input,
 * (1) inOrderTraversal : left, node, right
 * (2) postOrderTraversal : left, rigth, node
 * (3) preOrderTraversal : node, left, right
 * (4) Add a new node
 * (5) Find a node
 */

const char DISPLAY_INORDER = '1';
const char DISPLAY_POSTORDER = '2';
const char DISPLAY_PREORDER = '3';
const char ADD_NODE = '4';
const char FIND_NODE = '5';

void description() {
    std::cout << "Please input number of your choice." << std::endl;
    std::cout << "1: Display inOrderTraversal about the Tree." << std::endl;
    std::cout << "2: Display postOrderTraversal about the Tree." << std::endl;
    std::cout << "3: Display preOrderTraversal about the Tree." << std::endl;
    std::cout << "4: Add a new node to the Tree." << std::endl;
    std::cout << "5: Find a node from the Tree. !!I've not implemented!!" << std::endl;
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

int main() {

    int inputValue;
    BinaryTree bt;

    std::cout <<
    "First, Please input 10 numbers as sort targets." << std::endl;
    for (int i = 1; i <= 10; ++i) {
        std::cout << i << ": ";
        std::cin >> inputValue;
        bt.addData(inputValue);
    }
    std::cout << std::endl;

    bool done = false;
    while (!done) {
        switch (questionAndReceiveChoice()) {
            case DISPLAY_INORDER:
                bt.inOrderPrint();
                std::cout << std::endl;
                break;
            case DISPLAY_POSTORDER:
                bt.postOrderPrint();
                std::cout << std::endl;
                break;
            case DISPLAY_PREORDER:
                bt.preOrderPrint();
                std::cout << std::endl;
                break;
            case ADD_NODE:
                std::cout << "input your number: =>";
                std::cin >> inputValue;
                bt.addData(inputValue);
                break;
            case FIND_NODE:
                std::cout << "input searching number: =>";
                std::cin >> inputValue;
                bt.find(inputValue);
                break;
            default:
                std::cout << "Thank you for using this program." << std::endl;
                done = true;
                break;
        }
    }

    return 0;
}