#include <iostream>
#include <fstream>
#include <vector>

int bestTree(std::vector <std::vector <char>> forest, int x, int y) {
    int right = 0;
    int left = 0;
    int up = 0;
    int down = 0;
    int nextCoord = x + 1;
    //right
    while (nextCoord != forest.at(0).size()) {
        if (forest.at(y).at(x) <= forest.at(y).at(nextCoord)) {
            break;
        }
        nextCoord++;
        right++;
    }
    if (nextCoord != forest.size()) {
        right++;
    }
    // down
    nextCoord = y + 1;
    while (nextCoord != forest.size()) {
        if (forest.at(y).at(x) <= forest.at(nextCoord).at(x)) {
            break;
        }
        nextCoord++;
        down++;
    }
    if (nextCoord != forest.size()) {
        down++;
    }
    // up
    nextCoord = y - 1;
    while (nextCoord != -1) {
        if (forest.at(y).at(x) <= forest.at(nextCoord).at(x)) {
            break;
        }
        nextCoord--;
        up++;
    }
    if (nextCoord != -1) {
        up++;
    }
    // left
    nextCoord = x - 1;
    while (nextCoord != -1) {
        if (forest.at(y).at(x) <= forest.at(y).at(nextCoord)) {
            break;
        }
        nextCoord--;
        left++;
    }
    if (nextCoord != -1) {
        left++;
    }
    int scenicScore = 0;
    scenicScore = down * right * up * left;
    return scenicScore;
}

int main() {
    std::fstream myfile;
    std::string inputLine;
    int count;
    std::vector <std::vector <char>> trees;
    std::vector <char> tempVect;
    myfile.open("InputDay8.txt");
    while (std::getline(myfile, inputLine)) {
        tempVect = {};
        for (int i = 0; i < inputLine.length(); i++) {
            tempVect.push_back(inputLine.at(i));
        }
        trees.push_back(tempVect);
    }
    int max = 0;
    for (int i = 0; i < trees.size(); i++) {
        for (int j = 0; j < trees.at(i).size(); j++) {
            if (bestTree(trees, j, i) > max) {
                max = bestTree(trees, j, i);
            }
        } 
    }
    std::cout << max << std::endl;
}   