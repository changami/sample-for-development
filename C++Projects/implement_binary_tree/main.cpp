#include <iostream>
#include "BinaryTree.h"

int main() {

    string inputValue;
    BinaryTree bt;

    while (true) {
        std::cout <<
        "Please input a sort target word. Enter without inputting anything when you want to finish input." << std::endl;
        std::cout << "=>";
        getline(std::cin, inputValue);
        if (inputValue == "") {
            break;
        }
        bt.addData(inputValue);
    }

    bt.sortedPrint();

    return 0;
}