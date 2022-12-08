#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <valarray> 

int main() {
    std::vector <int> amount;
    std::vector <int> startTower;
    std::vector <int> endTower;
    std::ifstream myfile;
    std::string a;
    std::vector <std::vector <char>> allTowers = {
        {'G', 'T', 'R', 'W'},
        {'G', 'C', 'H', 'P', 'M', 'S', 'V', 'W'},
        {'C', 'L', 'T', 'S', 'G', 'M'},
        {'J', 'H', 'D', 'M', 'W', 'R', 'F'},
        {'P', 'Q', 'L', 'H', 'S', 'W', 'F', 'J'},
        {'P', 'J', 'D', 'N', 'F', 'M', 'S'},
        {'Z', 'B', 'D', 'F', 'G', 'C', 'S', 'J'},
        {'R', 'T', 'B'},
        {'H', 'N', 'W', 'L', 'C'},
    };
    myfile.open("InputDay5.txt");
    while (std::getline(myfile, a)) {
        std::stringstream ss;
        std::string temp;
        bool amountCheck = false;
        bool startTowerCheck = false;
        ss << a;
        while(!ss.eof()) {
            ss >> temp;
            int b;
            if (std::stringstream(temp) >> b) {
                if (!amountCheck) {
                    amount.push_back(b);
                    amountCheck = true;
                }
                else if(!startTowerCheck) {
                    startTower.push_back(b);
                    startTowerCheck = true;
                }
                else {
                    endTower.push_back(b);
                }
            }
            temp = "";
        }
    }
    for (int j = 0; j < amount.size(); j++) {
        std::vector <char> temp = {};
        for (int i = 0; i < amount.at(j); i++) {
            char n = allTowers.at(startTower.at(j) - 1).size(); 
            temp.push_back(allTowers.at(startTower.at(j) - 1).at(n -  1));
            allTowers.at(startTower.at(j) - 1).pop_back();
        }
        for (int k = temp.size() - 1; k >= 0; k--) {
            allTowers.at(endTower.at(j) - 1).push_back(temp.at(k));
        }
    }
    for (int i = 0; i < allTowers.size(); i++) {
        char w = allTowers.at(i).size();
        std::cout << allTowers.at(i).at(w - 1);
    } 
}