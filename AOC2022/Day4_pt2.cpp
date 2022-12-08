#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    std::string test = "";
    std::fstream myfile;
    std::string firstHalf;
    std::string secondHalf;
    int leftBound;
    int leftBound1;
    int rightBound;
    int rightBound1;
    int count = 0;
    myfile.open("InputDay4.txt");
    while (std::getline(myfile, test)) {
        firstHalf = test.substr(0, test.find(','));
        secondHalf = test.substr(test.find(',') + 1);
        leftBound = atoi(firstHalf.substr(0, firstHalf.find('-')).c_str());
        rightBound = atoi(firstHalf.substr(firstHalf.find('-') + 1).c_str());
        leftBound1 = atoi(secondHalf.substr(0, secondHalf.find('-')).c_str());
        rightBound1 = atoi(secondHalf.substr(secondHalf.find('-') + 1).c_str());
        if (leftBound >= leftBound1 && leftBound <= rightBound1) {
            count++;
        }
        else if (rightBound >= leftBound1 && rightBound <= rightBound1) {
            count++;
        }
        else if (leftBound1 >= leftBound && leftBound1 <= rightBound) {
            count++;
        }
        else if (rightBound1 > leftBound && rightBound1 <= rightBound) {
            count++;
        }
    }
    std::cout << count << std::endl;
}