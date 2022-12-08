#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

std::string find_intersection(std::string & first, std::string & second)
{
    std::sort(std::begin(first),std::end(first));
    std::sort(std::begin(second), std::end(second));

    std::string result;

    std::set_intersection(
        std::begin(first), std::end(first),
        std::begin(second), std::end(second),
        std::back_inserter(result)
    );

    return result; 
}

int main() {
    std::ifstream myfile;
    myfile.open("InputDay3.txt");
    int number;
    int total;
    std::string firstHalf;
    std::string secondHalf;
    std::vector <std::string> Similarities;
    std::string ruckSack;
    while (std::getline(myfile, ruckSack)) {
        firstHalf = ruckSack.substr(0, (ruckSack.length() / 2));
        secondHalf = ruckSack.substr(ruckSack.length() / 2, ruckSack.length() / 2);
        Similarities.push_back(find_intersection(firstHalf, secondHalf));
    }
    for (int i = 0; i < Similarities.size(); i++) {
        char letter = Similarities.at(i).at(0);
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