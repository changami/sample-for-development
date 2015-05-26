#include <iostream>

using namespace std;

int subtract(int a, int b) {
    return a - b;
}

string subtract(string a, string b) {
    // Don't use library method.
    int aLength = 0, bLength = 0;
    for (char aChar : a) {
        aLength++;
    }
    for (char bChar : b) {
        bLength++;
    }

    int index = 0;
    string returnString;
    for (int i = 0; i < aLength; i++) {
        if (a[i] == b[index]) {
            index++;
        } else {
            if (index != 0) {
                for (int j = i - index; j < i; ++j) {
                    returnString += a[j];
                }
            }
            returnString += a[i];
            index = 0;
        }
        if (index == bLength) {
            index = 0;
        }
    }
    return returnString;
}

template<class T>
T maximum(T a, T b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    cout << subtract(2, 2) << endl;
    cout << subtract("This is a pen.", "his is ") << endl;
    cout << maximum(1, 3) << endl;
    cout << maximum(19.4, 7.7) << endl;

    return 0;
}