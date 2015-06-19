#ifndef DETECT_ERROR_OF_HTML_TAGS_INPUTHTMLFILE_H
#define DETECT_ERROR_OF_HTML_TAGS_INPUTHTMLFILE_H

#include <iostream>
#include <fstream>
#include <stack>
#include <queue>

using std::string;
using std::ifstream;
using std::ios;
using std::stack;
using std::queue;

class InputHTMLFile {
    ifstream ifs;
public:
    InputHTMLFile(string);

    ~InputHTMLFile();

    void moveFirst();

    string fetchNextOpeningTag();

    string fetchNextClosingTag();

    stack<string> getAllOpeningTags();

    queue<string> getAllClosingTags();

    string getTypeOfTag(string);

    stack<string> getAllOpeningTypeOfTags();

    queue<string> getAllClosingTypeOfTags();
};


#endif //DETECT_ERROR_OF_HTML_TAGS_INPUTHTMLFILE_H
