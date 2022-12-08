#include <iostream>
#include <vector>
#include <fstream>

bool ifDuplicates(std::vector <char> givenInput) {
    for (int i = 0; i < givenInput.size(); i++) {
        for (int j = i; j < givenInput.size() - 1; j++) {
            if (givenInput.at(i) == givenInput.at(j + 1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::string input;
    std::fstream myfile;
    std::vector <char> letters;
    myfile.open("InputDay6.txt");
    myfile >> input;
    bool notFound = false;
    for (int i = 0; i < input.length() - 3; i++) {
        letters = {};
        for (int j = 0; j < 4; j++) {
            letters.push_back(input.at(i + j));
        }
        if (!(ifDuplicates(letters))) {
            std::cout << i + 4 << std::endl;
            break;
        }
    }
}
