/*
    X = Lose
    Y = Draw
    Z = Win
*/

#include <iostream>
#include <vector>
#include <fstream>

int main() {
    std::ifstream myfile;
    std::string a;
    int totalScore;
    myfile.open("InputDay2.txt");
    while(std::getline(myfile, a)) {
        if (a.at(2) == 'X') {
            // Verliezen
            if (a.at(0) == 'A') {
                totalScore += 3;
            }
            else if (a.at(0) == 'B') {
                totalScore += 1;
            }
            else {
                totalScore += 2;
            }
        }
        else if (a.at(2) == 'Y') {
            // Gelijkspel
            if (a.at(0) == 'A') {
                totalScore += 4;
            }
            else if (a.at(0) == 'B') {
                totalScore += 5;
            }
            else {
                totalScore += 6;
            }
        }
        else {
            // Winnen
            if (a.at(0) == 'A') {
                totalScore += 8;
            }
            else if (a.at(0) == 'B') {
                totalScore += 9;
            }
            else {
                totalScore += 7;
            }
        }
    }
    std::cout << totalScore << std::endl;
}