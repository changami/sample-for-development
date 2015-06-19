#include "InputHTMLFile.h"

InputHTMLFile::InputHTMLFile(string filePath) {
    ifs.open(filePath);
}

InputHTMLFile::~InputHTMLFile() {
    ifs.close();
}

void InputHTMLFile::moveFirst() {
    ifs.clear();
    ifs.seekg(0, ios::beg);
}

string InputHTMLFile::fetchNextOpeningTag() {
    int fileChar;
    string returnString = "";

    while ((fileChar = ifs.get()) != EOF) {
        if (fileChar == '<' && ifs.peek() != '/' && ifs.peek() != '!' && ifs.peek() != '=' && !isspace(ifs.peek())) {
            ifs.seekg(-1, ios::cur);
            while ((fileChar = ifs.get()) != EOF) {
                returnString += fileChar;
                if (fileChar == '>')break;
            }
        }
        if (returnString != "")break;
    }
    if (fileChar == EOF) {
        returnString = "";
    }

    return returnString;
}

string InputHTMLFile::fetchNextClosingTag() {
    int fileChar;
    string returnString = "";

    while ((fileChar = ifs.get()) != EOF) {
        if (fileChar == '<' && ifs.peek() == '/') {
            ifs.seekg(-1, ios::cur);
            while ((fileChar = ifs.get()) != EOF) {
                returnString += fileChar;
                if (fileChar == '>')break;
            }
        }
        if (returnString != "")break;
    }
    if (fileChar == EOF) {
        returnString = "";
    }

    return returnString;
}

stack<string> InputHTMLFile::getAllOpeningTags() {
    string targetStoring;
    stack<string> st;

    moveFirst();
    while ((targetStoring = fetchNextOpeningTag()) != "") {
        st.push(targetStoring);
    }

    return st;
}

queue<string> InputHTMLFile::getAllClosingTags() {
    string targetStoring;
    queue<string> st;

    moveFirst();
    while ((targetStoring = fetchNextClosingTag()) != "") {
        st.push(targetStoring);
    }

    return st;
}

string InputHTMLFile::getTypeOfTag(string tag) {
    string returnString = "";

    bool opening = false;
    if (tag[1] != '/') {
        opening = true;
    }

    if (opening) {
        for (int i = 1; !isspace(tag[i]) && tag[i] != '>'; ++i) {
            returnString += tag[i];
        }
    } else {
        for (int i = 2; !isspace(tag[i]) && tag[i] != '>'; ++i) {
            returnString += tag[i];
        }
    }
    return returnString;
}

stack<string> InputHTMLFile::getAllOpeningTypeOfTags() {
    stack<string> preserveForReverse;

    stack<string> returnStack = getAllOpeningTags();

    while (!returnStack.empty()) {
        preserveForReverse.push(returnStack.top());
        returnStack.pop();
    }

    // reversing for keep index
    while (!preserveForReverse.empty()) {
        returnStack.push(getTypeOfTag(preserveForReverse.top()));
        preserveForReverse.pop();
    }

    return returnStack;
}

queue<string> InputHTMLFile::getAllClosingTypeOfTags() {
    queue<string> returnQueue;

    queue<string> allTags = getAllClosingTags();
    while (!allTags.empty()) {
        returnQueue.push(getTypeOfTag(allTags.front()));
        allTags.pop();
    }

    return returnQueue;
}
