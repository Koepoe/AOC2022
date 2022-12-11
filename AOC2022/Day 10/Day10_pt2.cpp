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
    myfile.open("InputDay10.txt");
    std::string inputLine;
    int currCycle = 0;
    int xRegister = 1;
    int currPixel = 0;
    std::vector <std::string> image;
    while (std::getline(myfile, inputLine)) {
        int number = getIntFromString(inputLine);
        if (inputLine == "noop") {
            if (std::abs(currPixel - xRegister) < 2) {
                image.push_back("#");
            }
            else {
                image.push_back(".");
            }
            currPixel++;
            if (currPixel == 40) {
                currPixel = 0;
                image.push_back("\n");
            }
            currCycle++;
        }
        else {
            for (int i = 0; i < 2; i++) {
                if (std::abs(currPixel - xRegister) < 2) {
                    image.push_back("#");
                }
                else {
                    image.push_back(".");
                }
                currPixel++;
                if (currPixel == 40) {
                    currPixel = 0;
                    image.push_back("\n");
                }
                currCycle++;
                if (i == 1) {
                    xRegister += number;
                }
            }
        }
    }
    for (int i = 0; i < image.size(); i++) {
        for (int j = 0; j < image.at(i).size(); j++) {
            std::cout << image.at(i).at(j);
        }
    }
}