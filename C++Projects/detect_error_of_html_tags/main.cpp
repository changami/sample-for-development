#include <iostream>
#include "InputHTMLFile.h"

using std::string;
using std::cout;
using std::endl;

int main() {
    string inputFilePath = "";
    InputHTMLFile inputFile(inputFilePath);

    bool errorFlag = false;
    stack<string> stackForOpening = inputFile.getAllOpeningTypeOfTags();
    queue<string> queueForClosing = inputFile.getAllClosingTypeOfTags();

    while (!stackForOpening.empty() && !queueForClosing.empty()) {
        cout << stackForOpening.top() << ", " << queueForClosing.front() << endl;
        if (stackForOpening.top() != queueForClosing.front()) {
            errorFlag = true;
            break;
        }
        stackForOpening.pop();
        queueForClosing.pop();
    }
    if (!stackForOpening.empty() || !queueForClosing.empty()) {
        errorFlag = true;
    }

    if (errorFlag) {
        cout << "This file has error about tags." << endl;
    } else {
        cout << "There is no error!" << endl;
    }

    return 0;
}