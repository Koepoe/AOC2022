#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

int getIntFromString(std::string input) {
    std::stringstream ss;
    std::string temp;
    int numb;
    ss << input;
    while (!(ss.eof())) {
        ss >> temp;
        if (std::stringstream(temp) >> numb) {
            return numb;
        }
        temp = "";
    }
}

int main() {
    std::fstream myfile;
    myfile.open("InputDay9.txt");
    std::string inputLine;
    int currCycle = 0;
    int xRegister = 1;
    int total = 0;
    int sum = 0;
    while (std::getline(myfile, inputLine)) {
        int number = getIntFromString(inputLine);
        if (inputLine == "noop") {
            currCycle++;
            if ((currCycle == 20) || (currCycle == 60) || (currCycle == 100) || (currCycle == 140) || (currCycle == 180) || (currCycle == 220)) {
                sum = xRegister * currCycle;
                total += sum;
            }
        }
        else {
            for (int i = 0; i < 2; i++) {
                currCycle++;
                if ((currCycle == 20) || (currCycle == 60) || (currCycle == 100) || (currCycle == 140) || (currCycle == 180) || (currCycle == 220)) {
                    sum = xRegister * currCycle;
                    total += sum;
                    if (i == 0) {
                        continue;
                    }
                    else {
                        xRegister += number;
                    }
                }
                else {
                    if (i == 1) {
                        xRegister += number;
                    }
                }
            }
        }
    }
    std::cout << total << std::endl; 
}