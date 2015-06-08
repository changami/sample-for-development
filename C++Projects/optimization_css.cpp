#include <iostream>
#include <fstream>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::ios;
using std::ios_base;
using std::ofstream;
using std::ifstream;

enum DefinedType {
    ID, CLASS, TAG, UNKNOWN
};

struct DefinedStruct {
    string name;
    DefinedType type;
};

class Block {
    std::vector<DefinedStruct> structs;
    string body;
public:
    unsigned long structCount = 0;

    Block() { }

    void setDefinedStruct(DefinedStruct d) {
        structCount++;
        structs.resize(structCount);
        structs[structCount - 1].name = d.name;
        structs[structCount - 1].type = d.type;
    }

    DefinedStruct getDefinedStruct(int index) {
        if (index > structCount) {
            cout << "out of index." << endl;
            exit(0);
        }
        return structs[index];
    }

    void setBody(string b) {
        body = b;
    }

    string getBody() {
        return body;
    }

    bool include(DefinedStruct targetStruct) {
        // name and type
        for (int i = 0; i < structCount; ++i) {
            if (structs[i].name == targetStruct.name && structs[i].type == targetStruct.type) {
                return true;
            }
        }
        return false;
    }

    bool equal(Block block) {
        // name and type
        for (int i = 0; i < structCount; ++i) {
            for (int j = 0; j < block.structCount; ++j) {
                if (structs[i].name != block.structs[j].name) return false;
                if (structs[i].type != block.structs[j].type) return false;
            }
        }
        // body
        if (body != block.body) return false;
        // Everything is equal.
        return true;
    }

    bool isEmpty() {
        return body == "";
    }
};

class FileObject {
    ifstream fin;
    ofstream fout;
public:
    FileObject(string filePath, ios_base::openmode mode) {
        if (mode == ios::in) {
            fin.open(filePath);
            if (fin.fail()) {
                cout << "Failed to open the file..." << endl;
            }
        } else {
            fout.open(filePath, ios::app);
            if (fout.fail()) {
                cout << "Failed to open the file..." << endl;
            }
        }
    }

    ~FileObject() {
        fin.close();
        fout.close();
    }

    void moveFirst() {
        fin.clear();
        fin.seekg(0, ios::beg);
        fout.clear();
        fout.seekp(0, ios::beg);
    }

    void append(Block b) {
        fout.seekp(0, ios::end);
        for (int i = 0; i < b.structCount; ++i) {
            switch (b.getDefinedStruct(i).type) {
                case DefinedType::ID:
                    fout << "." << b.getDefinedStruct(i).name << " ";
                    break;
                case DefinedType::CLASS:
                    fout << "#" << b.getDefinedStruct(i).name << " ";
                    break;
                default:
                    fout << b.getDefinedStruct(i).name << " ";
                    break;
            }
        }
        fout << b.getBody() << endl;
    }

    DefinedStruct fetchDefinedStruct() {
        int tagStateCount = 0, idStateCount = 0, classStateCount = 0;
        int tagLength = 1, idLength = 4, classLength = 7;
        string tagStatement = "<", idStatement = "id=\"", classStatement = "class=\"";
        char idEndChar = '\"', classEndChar = '\"';
        int fileChar;
        string targetName = "";

        while ((fileChar = fin.get()) != EOF) {
            // omit line break char
            if (fileChar == '\n') continue;
            if (tagStateCount == tagLength) {
                // End point of tag
                if (fileChar == '!' || fileChar == ' ' || fileChar == '>' || fileChar == '/' || fileChar == '=') {
                    tagStateCount = 0;
                    if (targetName == "") {
                        continue;
                    } else {
                        struct DefinedStruct resultObject;
                        resultObject.name = targetName;
                        resultObject.type = DefinedType::TAG;
                        return resultObject;
                    }
                }
                targetName += fileChar;
                continue;
            } else if (idStateCount == idLength) {
                // End point of id
                if (fileChar == idEndChar) {
                    idStateCount = 0;
                    if (targetName == "") {
                        continue;
                    } else {
                        struct DefinedStruct resultObject;
                        resultObject.name = targetName;
                        resultObject.type = DefinedType::ID;
                        return resultObject;
                    }
                }
                targetName += fileChar;
                continue;
            } else if (classStateCount == classLength) {
                // End point of class
                if (fileChar == classEndChar) {
                    classStateCount = 0;
                    if (targetName == "") {
                        continue;
                    } else {
                        struct DefinedStruct resultObject;
                        resultObject.name = targetName;
                        resultObject.type = DefinedType::CLASS;
                        return resultObject;
                    }
                }
                targetName += fileChar;
                continue;
            }

            // increments and reset counts
            if (fileChar == tagStatement[tagStateCount]) {
                tagStateCount++;
            } else if (fileChar == idStatement[idStateCount]) {
                idStateCount++;
            } else if (fileChar == classStatement[classStateCount]) {
                classStateCount++;
            } else {
                tagStateCount = 0;
                idStateCount = 0;
                classStateCount = 0;
            }
        }
        // last object
        DefinedStruct returnObject;
        returnObject.name = "";
        return returnObject;
    }

    // maybe this method should be separated to inherited class.
    Block fetchDefinedBlock() {
        bool skipFlag = false;
        int previousChar = 0, fileChar, parenthesesCount = 0;
        string definedName = "", bodyStatement = "";
        Block returnObject;
        while ((fileChar = fin.get()) != EOF) {
            // ignore comment
            if (previousChar == '/' && fileChar == '*') {
                skipFlag = true;
                previousChar = 0;
                definedName = "";
                continue;
            } else if (previousChar == '*' && fileChar == '/') {
                skipFlag = false;
                previousChar = 0;
                continue;
            }
            previousChar = fileChar;
            if (skipFlag)continue;

            if (fileChar == '{') {
                parenthesesCount++;
            } else if (fileChar == '}') {
                parenthesesCount--;
                if (parenthesesCount == 0) {
                    bodyStatement += fileChar;
                }
            } else if (parenthesesCount == 0) {
                if (fileChar != ' '
                    && fileChar != '>'
                    && fileChar != ','
                    && fileChar != '\n'
                        ) {
                    definedName += (char) fileChar;
                } else {
                    if (definedName != "") {
                        DefinedStruct definedStruct;
                        switch (definedName[0]) {
                            case '@':
                                definedStruct.name = definedName;
                                definedStruct.type = DefinedType::UNKNOWN;
                                break;
                            case ':':
                                definedStruct.name = definedName;
                                definedStruct.type = DefinedType::UNKNOWN;
                                break;
                            case '#':
                                definedStruct.name = definedName.erase(0, 1);
                                definedStruct.type = DefinedType::CLASS;
                                break;
                            case '.':
                                definedStruct.name = definedName.erase(0, 1);
                                definedStruct.type = DefinedType::ID;
                                break;
                            default:
                                definedStruct.name = definedName;
                                definedStruct.type = DefinedType::TAG;
                                break;
                        }
                        definedName = "";
                        returnObject.setDefinedStruct(definedStruct);
                    }
                }
            }
            // defined body
            if (parenthesesCount != 0) {
                bodyStatement += (char) fileChar;
            } else if (bodyStatement != "") {
                returnObject.setBody(bodyStatement);
                return returnObject;
            }
        }
        return returnObject;
    }
};

int main() {
    string HTMLFilePath = "";
    FileObject htmlOrg(HTMLFilePath, ios_base::in);

    string CSSFilePath = "";
    FileObject cssOrg(CSSFilePath, ios_base::in);

    string newCSSFilePath = "";
    FileObject cssNew(newCSSFilePath, ios_base::out);

    DefinedStruct defined;
    Block b, compareBlock;
    bool thereIsInCSS = false, thereIsInHTML = false;
    int outputCount = 0;

    while (!(b = cssOrg.fetchDefinedBlock()).isEmpty()) {
        while (!(compareBlock = cssNew.fetchDefinedBlock()).isEmpty()) {
            if (b.equal(compareBlock)) {
                thereIsInCSS = true;
                break;
            }
        }
        if (!thereIsInCSS) {
            while ((defined = htmlOrg.fetchDefinedStruct()).name != "") {
                if (b.include(defined)) {
                    thereIsInHTML = true;
                    break;
                }
            }
        }
        if (/* WriteFlag */!thereIsInCSS && thereIsInHTML) {
            cout << "Writing the block of " << ++outputCount << endl;
            cssNew.append(b);
        }
        htmlOrg.moveFirst();
        cssNew.moveFirst();
        thereIsInCSS = false;
        thereIsInHTML = false;
    }
    return 0;
}