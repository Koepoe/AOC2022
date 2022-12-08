#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

std::ifstream myfile;
int main() {
    std::vector <int> Calories;
    std::string a;
    int b;
    int count;
    myfile.open("InputDay1.txt");
    while (std::getline(myfile, a)) {
        b = atoi(a.c_str());
        if (b == 0) {
            Calories.push_back(count);
            count = 0;
        }
        count += b;
    }
    myfile.close(); 
    std::cout << *std::max_element(Calories.begin(), Calories.end()) << std::endl;
}
