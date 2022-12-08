/* 
   A = Rock
   B = Paper
   C = Scissors
   
   X = Rock
   Y = Paper
   Z = Scissors
*/
#include <iostream>
#include <vector>
#include <fstream>

int main() {
    std::ifstream myfile;
    std::string a;
    int totalScore;
    myfile.open("InputDay2.txt");
    while (std::getline(myfile, a)) {
        if (a.at(2) == 'X') {
            if (a.at(0) == 'A') {
                totalScore += 3;
            }
            else if(a.at(0) == 'C') {
                totalScore += 6;
            }
            totalScore++;
        }
        else if (a.at(2) == 'Y') {
            if (a.at(0) == 'A') {
                totalScore += 6;
            }
            else if(a.at(0) == 'B') {
                totalScore += 3;
            }
            totalScore += 2;
        }
        else {
            if(a.at(0) == 'B') {
                totalScore += 6;
            }
            else if(a.at(0) == 'C') {
                totalScore += 3;
            }
            totalScore += 3;
        }
    }
    std::cout << totalScore << std::endl;
}