#include <iostream>
#include <fstream>
#include <vector>

std::vector <std::vector <bool>> isVisible(std::vector <std::string> forest) {
    int count = 0;
    std::vector <std::vector <bool>> visibleTrees (forest.size(), std::vector <bool>(forest.at(0).size()));
    for (int i = 0; i < forest.size(); ++i) {
        int height = -1;
        for (int j = 0; j < forest.at(0).size(); ++j) {
            if (forest.at(i).at(j) > height) {
                height = forest.at(i).at(j);
                visibleTrees.at(i).at(j) = true;
            }
        }
        height = -1;
        for (int j = forest.at(0).size() - 1; j >= 0; --j) {
            if (forest.at(i).at(j) > height) {
                height = forest.at(i).at(j);
                visibleTrees.at(i).at(j) = true;
            }
        }
    }
    for (int i = 0; i < forest.at(0).size(); ++i) {
        int height = -1;
        for (int j = 0; j < forest.size(); ++j) {
            if (forest.at(j).at(i) > height) {
                height = forest.at(j).at(i);
                visibleTrees.at(j).at(i) = true;
            }
        }
        height = -1;
        for (int j = forest.size() - 1; j >= 0; --j) {
            if (forest.at(j).at(i) > height) {
                height = forest.at(j).at(i);
                visibleTrees.at(j).at(i) = true;
            }
        }
    }
    return visibleTrees;
}

int main() {
    std::fstream myfile;
    std::string inputLine;
    int count;
    std::vector <std::string> trees;
    myfile.open("InputDay8.txt");
    while (std::getline(myfile, inputLine)) {
        trees.push_back(inputLine);
    }
    for (int i = 0; i < trees.size(); i++) {
        std::cout << trees.at(i) << std::endl;
    }
    std::vector <std::vector <bool>> allVisibleTrees = isVisible(trees);
    for (int n = 0; n < allVisibleTrees.size(); n++) {
        for (int m = 0; m < allVisibleTrees.at(n).size(); m++) {
            if (allVisibleTrees.at(n).at(m)) {
                count++;
            }
        }
    }
    std::cout << count;
}   