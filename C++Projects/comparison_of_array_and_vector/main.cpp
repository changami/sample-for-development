#include <iostream>
#include <vector>

int main() {
    // create an array => 7
    int mArray[7] = {1, 2, 3, 4, 5, 6, 7};
    // create a vector => same size as array
    std::vector<int> mVector = {1, 2, 3, 4, 5, 6, 7};

    // add an item to vector
    mVector.push_back(8);

    // print the array
    for (int i = 0; i < sizeof(mArray) / sizeof(mArray[0]); ++i) {
        std::cout << mArray[i] << " ";
    }
    std::cout << std::endl;
    // print the vector
    for (int i = 0; i < mVector.size(); ++i) {
        std::cout << mVector[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}