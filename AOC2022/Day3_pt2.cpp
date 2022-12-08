#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <bits/stdc++.h>

char findCommon(std::string elf1, std::string elf2, std::string elf3) { 
    std::vector<std::array<bool, 3>> inString;
    std::array<bool, 3> compString{ false,false,false };
    for (int x = 0;x<124;x++)
        inString.push_back(compString);

    for (auto c : elf1) {
        inString[c][0] = true;
    }
    for (auto c : elf2) {
        inString[c][1] = true;
    }
    for (auto c : elf3) {
        inString[c][2] = true; 
    }
    for (int x = 0; x<inString.size();x++)
        if (inString[x][0] && inString[x][1] && inString[x][2]) {
            return x;
        }
}

int main() {
    std::ifstream myfile;
    myfile.open("InputDay3.txt");
    int number;
    int total;
    std::vector <std::string> first;
    std::vector <std::string> second;
    std::vector <std::string> third;
    std::vector <char> Similarities;
    std::string ruckSack;
    while (std::getline(myfile, ruckSack)) {
        first.push_back(ruckSack);
        std::getline(myfile, ruckSack);
        second.push_back(ruckSack);
        std::getline(myfile, ruckSack);
        third.push_back(ruckSack);
    }

    for (int i = 0; i < first.size(); i++) {
        Similarities.push_back(findCommon(first.at(i), second.at(i), third.at(i)));
    }

    for (int i = 0; i < Similarities.size(); i++) {
        char letter = Similarities.at(i);
        if (std::islower(letter)) {
            number = letter - 96;
        }
        else {
            number = letter - 38;
        }   
        total += number;
    }
    std::cout << total; 
}